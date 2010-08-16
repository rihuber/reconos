#ifndef __XPARAMETERS_RECONOS_H__
#define __XPARAMETERS_RECONOS_H__


#if defined( XPAR_OSIF_7_DCR_BASEADDR )
#define UPBHWR_NUM_OSIFS 8
#elif defined( XPAR_OSIF_6_DCR_BASEADDR )
#define UPBHWR_NUM_OSIFS 7
#elif defined( XPAR_OSIF_5_DCR_BASEADDR )
#define UPBHWR_NUM_OSIFS 6
#elif defined( XPAR_OSIF_4_DCR_BASEADDR )
#define UPBHWR_NUM_OSIFS 5
#elif defined( XPAR_OSIF_3_DCR_BASEADDR )
#define UPBHWR_NUM_OSIFS 4
#elif defined( XPAR_OSIF_2_DCR_BASEADDR )
#define UPBHWR_NUM_OSIFS 3
#elif defined( XPAR_OSIF_1_DCR_BASEADDR )
#define UPBHWR_NUM_OSIFS 2
#elif defined( XPAR_OSIF_0_DCR_BASEADDR )
#define UPBHWR_NUM_OSIFS 1
#endif

//#define UPBHWR_OSIF_0_INTR                XPAR_OPB_INTC_0_OSIF_0_INTERRUPT_INTR
#define UPBHWR_OSIF_0_INTR_MASK           XPAR_OSIF_0_INTERRUPT_MASK
#define UPBHWR_OSIF_0_BASEADDR            XPAR_OSIF_0_DCR_BASEADDR

//#define UPBHWR_OSIF_1_INTR                XPAR_OPB_INTC_0_OSIF_1_INTERRUPT_INTR
#define UPBHWR_OSIF_1_INTR_MASK           XPAR_OSIF_1_INTERRUPT_MASK
#define UPBHWR_OSIF_1_BASEADDR            XPAR_OSIF_1_DCR_BASEADDR

//#define UPBHWR_OSIF_2_INTR                XPAR_OPB_INTC_0_OSIF_2_INTERRUPT_INTR
#define UPBHWR_OSIF_2_INTR_MASK           XPAR_OSIF_2_INTERRUPT_MASK
#define UPBHWR_OSIF_2_BASEADDR            XPAR_OSIF_2_DCR_BASEADDR

//#define UPBHWR_OSIF_3_INTR                XPAR_OPB_INTC_0_OSIF_3_INTERRUPT_INTR
#define UPBHWR_OSIF_3_INTR_MASK           XPAR_OSIF_3_INTERRUPT_MASK
#define UPBHWR_OSIF_3_BASEADDR            XPAR_OSIF_3_DCR_BASEADDR

//#define UPBHWR_OSIF_4_INTR                XPAR_OPB_INTC_0_OSIF_4_INTERRUPT_INTR
#define UPBHWR_OSIF_4_INTR_MASK           XPAR_OSIF_4_INTERRUPT_MASK
#define UPBHWR_OSIF_4_BASEADDR            XPAR_OSIF_4_DCR_BASEADDR

//#define UPBHWR_OSIF_5_INTR                XPAR_OPB_INTC_0_OSIF_5_INTERRUPT_INTR
#define UPBHWR_OSIF_5_INTR_MASK           XPAR_OSIF_5_INTERRUPT_MASK
#define UPBHWR_OSIF_5_BASEADDR            XPAR_OSIF_5_DCR_BASEADDR

//#define UPBHWR_OSIF_6_INTR                XPAR_OPB_INTC_0_OSIF_6_INTERRUPT_INTR
#define UPBHWR_OSIF_6_INTR_MASK           XPAR_OSIF_6_INTERRUPT_MASK
#define UPBHWR_OSIF_6_BASEADDR            XPAR_OSIF_6_DCR_BASEADDR

//#define UPBHWR_OSIF_7_INTR                XPAR_OPB_INTC_0_OSIF_7_INTERRUPT_INTR
#define UPBHWR_OSIF_7_INTR_MASK           XPAR_OSIF_7_INTERRUPT_MASK
#define UPBHWR_OSIF_7_BASEADDR            XPAR_OSIF_7_DCR_BASEADDR

#endif // __XPARAMETERS_RECONOS_H__
