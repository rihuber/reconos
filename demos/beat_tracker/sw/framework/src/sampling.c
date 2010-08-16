#include "../header/particle_filter.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef ONLYPC
#include <cyg/infra/diag.h>
#include <cyg/infra/cyg_type.h>
#include <cyg/kernel/kapi.h>
#include <xcache_l.h>
#include <reconos/reconos.h>
#include <reconos/resources.h>
#endif
#include "../header/timing.h"


#ifndef ONLYPC

//! sw threads for sampling (s)
cyg_thread * sw_thread_s;

//! hw thread for sampling (s)
cyg_thread * hw_thread_s;

//! Stacks for every thread
char ** sw_thread_s_stack;
char ** hw_thread_s_stack;

//! thread handles to every thread
cyg_handle_t * sw_thread_s_handle;
cyg_handle_t * hw_thread_s_handle;

//! ressources array for the sampling hw thread
reconos_res_t * res_s;


//! struct definition with all informations needed by the hw sampling
typedef struct information_struct_s{

  volatile particle *   particles;
  volatile int number_of_particles;
  volatile int particle_size;
  volatile int max_number_of_particles;
  volatile int block_size;
  volatile int * parameter;
  volatile int number_of_parameter;

} information_struct_s;

//! pointer to struct with all information needed by hw sampling
information_struct_s * information_s;


//! attributes for a hw thread
rthread_attr_t * hw_thread_s_attr;

//! number of sw threads
int sw_number_of_threads_s = 0;

//! number of hw threads
int hw_number_of_threads_s = 0;




/**
   sample sw thread

    @param data: input data for sw thread
*/
void sampling_sw_thread (cyg_addrword_t data){

  //unsigned int thread_number = (unsigned int) data;
    int from, to;
    int done;
    int i;
    int new_message = FALSE;
    int message = 1;
    int message_to_deliver = FALSE;
    timing_t time_start_s = 0, time_stop_s = 0, time_sampling_sw = 0;
    int number_of_measurements_s = 0;
    
    while (42) {

      // 1) if there is no message to delivered, check for new message
      while (message_to_deliver == FALSE && new_message == FALSE){

            message = (int) cyg_mbox_get( mb_sampling_handle[0] );
            if (message > 0 && message <= number_of_blocks){
 
	      //printf("\n[Sampling Thread No. %d] Nachricht %d erhalten", (int) thread_number, message);
	          //diag_printf("\n[Sampling] Nachricht %d erhalten", message);
	          new_message = TRUE;
		  time_start_s = gettime();
            }
      }

 #ifdef USE_CACHE  
       XCache_EnableDCache( 0xF0000000 );
#endif     

      // 2) if a new message has arrived, sample the particles
      while (new_message == TRUE){

	  new_message = FALSE;

    	  from = (message - 1) * block_size;
          to   = from + block_size - 1;
          if ((N - 1) < to)
	       to = N - 1; 
      
          // sample particles
          for (i=from; i<=to; i++){
          
                  // predict particle
                  prediction (&particles[i]);
          }

          message_to_deliver = TRUE;
      }

#ifdef USE_CACHE  
       XCache_EnableDCache( 0xF0000000 );
#endif
  
      time_stop_s = gettime();
    
      // 3) if a message should be delivered, deliver it
      while ( message_to_deliver == TRUE){

            done = cyg_mbox_tryput( mb_sampling_done_handle[0], ( void * ) message );
           if (done > 0){
	     //printf("\n[Sampling Thread No. %d] Nachricht %d geschickt", (int) thread_number, message);
	     //printf("\n[Sampling] Nachricht %d geschickt", message);
              message_to_deliver = FALSE;
              time_sampling_sw = calc_timediff( time_start_s, time_stop_s );
              number_of_measurements_s++;
              //diag_printf("\nSampling SW: %d, \tmessage %d, \ttime: %d", number_of_measurements_s, message, time_sampling_sw);
           }
      }
          
   }
}



/**
 terminates sw threads
*/
void sample_sw_delete(void){
  
  int i;

  // terminate all sw threads
  for (i=0; i<sw_number_of_threads_s;i++){

       while (!cyg_thread_delete(sw_thread_s_handle[i]))
                cyg_thread_release(sw_thread_s_handle[i]);
  }
}


/**
   creates sample SW threads (and deletes 'old' sw threads)

   @param number_of_threads: number of threads for sampling step
*/
void set_sample_sw (unsigned int number_of_threads){

     int i;

     // terminate old sw threads if needed
     if (sw_number_of_threads_s > 0){

           sample_sw_delete();

           // free all variables
           for (i=0; i<sw_number_of_threads_s;i++){
  
              free(sw_thread_s_stack[i]);
           }

           free(sw_thread_s);
           free(sw_thread_s_stack);
           free(sw_thread_s_handle);
     }
 
     // create sw threads variables
     sw_thread_s = (cyg_thread *) malloc (number_of_threads * sizeof(cyg_thread));

     // create sw thread stacks 
     sw_thread_s_stack = (char **) malloc (number_of_threads * sizeof (char *));
     for (i=0; i<number_of_threads; i++){
          
          sw_thread_s_stack[i] = (char *) malloc (STACK_SIZE * sizeof(char));     
     }
 
     // create sw handles
     sw_thread_s_handle = (cyg_handle_t *) malloc (number_of_threads * sizeof(cyg_handle_t));

     // set number of sw threads
     sw_number_of_threads_s = number_of_threads;
   
     // create and resume sw sampling threads in eCos
     for (i = 0; i < number_of_threads; i++){
     

          // create sw sampling threads
          cyg_thread_create(PRIO,                   // scheduling info (eg pri)  
                      sampling_sw_thread,           // entry point function     
                      ( cyg_addrword_t ) i,         // entry data                
                      "SAMPLING",                   // optional thread name      
                      sw_thread_s_stack[i],         // stack base                
                      STACK_SIZE,                   // stack size,       
                      &sw_thread_s_handle[i],       // returned thread handle    
                      &sw_thread_s[i]               // put thread here           
           );
          
	  // resume threads
          cyg_thread_resume(sw_thread_s_handle[i]);   
     }
}



/**
 terminates and deletes all HW threads for Sampling
*/
void sample_hw_delete(void){
  
  
  int i;

  // terminate all hw threads
  for (i=0; i<hw_number_of_threads_s;i++){

      while (!cyg_thread_delete(hw_thread_s_handle[i]))
                cyg_thread_release(hw_thread_s_handle[i]);
  }
 
}


/**
   creates sample HW threads (and deletes 'old' hw threads)

   @param number_of_threads: number of threads for sampling step
   @param reconos_slots: pointer to array including the slot numbers, where the sampling hw threads are connected with 
   @param parameter: pointer to a array filled with parameter (size <= 128 byte)
   @param number_of_parameter: number of parameter in parameter array
*/
void set_sample_hw (unsigned int number_of_threads, unsigned int * reconos_slots, int * parameter, unsigned int number_of_parameter){

     
     int i;

     // terminate old sw threads if needed
     if (hw_number_of_threads_s > 0) {

          sample_hw_delete();
                
          for (i=0; i<hw_number_of_threads_s;i++){
  
               free(hw_thread_s_stack[i]);
          }

          free(hw_thread_s);
          free(hw_thread_s_stack);
          free(hw_thread_s_handle);
          free(res_s);
          free(hw_thread_s_attr);
          free(information_s);
       
     }

     // set number of hw threads
     hw_number_of_threads_s = number_of_threads;

     if (number_of_threads < 1) return;

     // set information
     information_s = (information_struct_s *) malloc (sizeof(information_struct_s));
         

     // set information
     information_s[0].particles = particles;
     information_s[0].number_of_particles = N;
     information_s[0].particle_size = sizeof(particle);
     information_s[0].max_number_of_particles = 8096 / sizeof(particle);
     information_s[0].block_size = block_size;

     // parameter
     information_s[0].parameter = parameter;
     information_s[0].number_of_parameter = number_of_parameter;
     
     // create hw threads variables
     hw_thread_s = (cyg_thread *) malloc (number_of_threads * sizeof(cyg_thread));

     // create hw thread stacks 
     hw_thread_s_stack = (char **) malloc (number_of_threads * sizeof (char *));
     for (i=0; i<number_of_threads; i++){
          
          hw_thread_s_stack[i] = (char *) malloc (STACK_SIZE * sizeof(char));     
     }
 
     // create hw handles
     hw_thread_s_handle = (cyg_handle_t *) malloc (number_of_threads * sizeof(cyg_handle_t));

     // set ressources
     res_s = (reconos_res_t *) malloc (3 * sizeof(reconos_res_t));
           
     res_s[0].ptr  =  mb_sampling_handle;
     res_s[0].type =  CYG_MBOX_HANDLE_T ;
     res_s[1].ptr  =  mb_sampling_done_handle;
     res_s[1].type =  CYG_MBOX_HANDLE_T ;
     res_s[2].ptr  =  hw_mb_sampling_measurement_handle;
     res_s[2].type =  CYG_MBOX_HANDLE_T ;

     // attributes for hw threads
     hw_thread_s_attr = malloc (number_of_threads * sizeof(rthread_attr_t));
    
     
     // create and resume hw sampling threads in eCos
     for (i = 0; i < number_of_threads; i++){
     
          // set attributes
          rthread_attr_init(&hw_thread_s_attr[i]);
          // set slot number
          rthread_attr_setslotnum(&hw_thread_s_attr[i], reconos_slots[i]);
          // add ressources
          rthread_attr_setresources(&hw_thread_s_attr[i], res_s, 3); 

          //diag_printf("\n--> hw sampling (%d, slot %d) dcr address: %d", i, reconos_slots[i], hw_thread_s_attr[i].dcr_base_addr);

          // create hw sampling thread
          reconos_hwthread_create(
	      (cyg_addrword_t) PRIO_HW,  // priority
              &hw_thread_s_attr[i], // attributes
              (cyg_addrword_t) &information_s[0], // entry data
              "HW_SAMPLING",           // thread name 
               hw_thread_s_stack[i],   // stack
               STACK_SIZE,             // stack size 
               &hw_thread_s_handle[i], // thread handle
               &hw_thread_s[i]         // thread object
          );
          
	  // resume threads
          cyg_thread_resume(hw_thread_s_handle[i]);   
     }
	
     
}
#endif

