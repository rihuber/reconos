
 PARAMETER VERSION = 2.2.0


BEGIN OS
 PARAMETER OS_NAME = standalone
 PARAMETER OS_VER = 1.00.a
 PARAMETER PROC_INSTANCE = ppc405_1
END

BEGIN OS
 PARAMETER OS_NAME = device-tree
 PARAMETER PROC_INSTANCE = ppc405_0
 PARAMETER console device = RS232_Uart_1
END


BEGIN PROCESSOR
 PARAMETER DRIVER_NAME = cpu_ppc405
 PARAMETER DRIVER_VER = 1.10.a
 PARAMETER HW_INSTANCE = ppc405_0
 PARAMETER COMPILER = powerpc-eabi-gcc
 PARAMETER ARCHIVER = powerpc-eabi-ar
 PARAMETER CORE_CLOCK_FREQ_HZ = 300000000
 PARAMETER EXTRA_COMPILER_FLAGS = -g -O0
END

BEGIN PROCESSOR
 PARAMETER DRIVER_NAME = cpu_ppc405
 PARAMETER DRIVER_VER = 1.10.a
 PARAMETER HW_INSTANCE = ppc405_1
 PARAMETER COMPILER = powerpc-eabi-gcc
 PARAMETER ARCHIVER = powerpc-eabi-ar
END


BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = jtagppc_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = plbarb
 PARAMETER DRIVER_VER = 1.01.a
 PARAMETER HW_INSTANCE = plb
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = opbarb
 PARAMETER DRIVER_VER = 1.02.a
 PARAMETER HW_INSTANCE = opb
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = opb_onewire
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = onewire_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = uartns550
 PARAMETER DRIVER_VER = 1.11.a
 PARAMETER HW_INSTANCE = RS232_Uart_1
 PARAMETER CLOCK_HZ = 100000000
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = emac
 PARAMETER DRIVER_VER = 1.00.e
 PARAMETER HW_INSTANCE = Ethernet_MAC
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = sysace
 PARAMETER DRIVER_VER = 1.11.a
 PARAMETER HW_INSTANCE = SysACE_CompactFlash
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 2.11.a
 PARAMETER HW_INSTANCE = LEDs_4Bit
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 2.11.a
 PARAMETER HW_INSTANCE = DIPSWs_4Bit
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 2.11.a
 PARAMETER HW_INSTANCE = PushButtons_5Bit
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = ddr
 PARAMETER DRIVER_VER = 1.10.b
 PARAMETER HW_INSTANCE = DDR_512MB_64Mx64_rank2_row13_col10_cl2_5
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = ps2_ref
 PARAMETER DRIVER_VER = 1.01.a
 PARAMETER HW_INSTANCE = PS2_Ports
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = bram
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = plb_bram_if_cntlr_1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = intc
 PARAMETER DRIVER_VER = 1.10.c
 PARAMETER HW_INSTANCE = opb_intc_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = plb2opb
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = plb2opb_bridge_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = tft_ref
 PARAMETER DRIVER_VER = 1.00.b
 PARAMETER HW_INSTANCE = VGA_FrameBuffer
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = hwicap
 PARAMETER DRIVER_VER = 1.01.a
 PARAMETER HW_INSTANCE = opb_hwicap_0
END


