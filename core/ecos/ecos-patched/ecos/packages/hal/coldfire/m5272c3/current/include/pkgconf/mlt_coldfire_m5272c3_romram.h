#ifndef CYGONCE_MLT_COLDFIRE_ROMRAM_H
#define CYGONCE_MLT_COLDFIRE_ROMRAM_H

//=============================================================================
//
//      mlt_coldfire_m5272c3_romram.h
//
//      Platform specific memory section definitions for ROMRAM startup
//
//==========================================================================
//####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.
// Copyright (C) 2006 eCosCentric Ltd.
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with eCos; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or inline functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. However the source code for this file must still be made available
// in accordance with section (3) of the GNU General Public License.
//
// This exception does not invalidate any other reasons why a work based on
// this file might be covered by the GNU General Public License.
// -------------------------------------------
//####ECOSGPLCOPYRIGHTEND####
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):     Enrico Piria
// Contributors:
// Date:          2005-25-06
// Purpose:       Memory section definitions specific to the M5272C3 board,
//                used for ROMRAM startup configuration.
//
//####DESCRIPTIONEND####
//========================================================================

// eCos memory layout

#include <cyg/hal/hal_memmap.h>

#define CYGMEM_REGION_sdram (0x00000000)
#define CYGMEM_REGION_sdram_SIZE (0x01000000)

#define CYGMEM_REGION_devs (0x10000000)
#define CYGMEM_REGION_devs_SIZE (0x00001800)

#define CYGMEM_REGION_sram (0x20000000)
#define CYGMEM_REGION_sram_SIZE (0x00001000)

#define CYGMEM_REGION_ext_sram (0x30000000)
#define CYGMEM_REGION_ext_sram_SIZE (0x00080000)

#define CYGMEM_REGION_flash (0xFFE00000)
#define CYGMEM_REGION_flash_SIZE (0x00200000)

#define CYGMEM_SECTION_heap1 (CYG_LABEL_NAME (__heap1))
#define CYGMEM_SECTION_heap1_SIZE (0x01000000 - (size_t) CYG_LABEL_NAME (__heap1))
externC unsigned char CYG_LABEL_NAME (__heap1) [];

// These symbols are required by the test cases. Normally the memory tool would generate them,
// but this file was been generated by hand and so is a little
// different to normal.
#define CYGMEM_REGION_ram       CYGMEM_REGION_sdram
#define CYGMEM_REGION_ram_SIZE  CYGMEM_REGION_sdram_SIZE

// ---------------------------------------------------------------------------
// End of mlt_coldfire_m5272c3_romram.h
#endif // CYGONCE_MLT_COLDFIRE_ROMRAM_H
