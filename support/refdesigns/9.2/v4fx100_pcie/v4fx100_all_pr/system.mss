
 PARAMETER VERSION = 2.2.0


BEGIN OS
 PARAMETER OS_NAME = standalone
 PARAMETER OS_VER = 1.00.a
 PARAMETER PROC_INSTANCE = ppc405_0
 PARAMETER STDIN = RS232_UART_1
 PARAMETER STDOUT = RS232_UART_1
END

BEGIN OS
 PARAMETER OS_NAME = standalone
 PARAMETER OS_VER = 1.00.a
 PARAMETER PROC_INSTANCE = ppc405_1
END


BEGIN PROCESSOR
 PARAMETER DRIVER_NAME = cpu_ppc405
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ppc405_0
 PARAMETER COMPILER = powerpc-eabi-gcc
 PARAMETER ARCHIVER = powerpc-eabi-ar
 PARAMETER CORE_CLOCK_FREQ_HZ = 300000000
END

BEGIN PROCESSOR
 PARAMETER DRIVER_NAME = cpu_ppc405
 PARAMETER DRIVER_VER = 1.00.a
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
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = reset_block
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = plb2opb
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = plb2opb
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = uartns550
 PARAMETER DRIVER_VER = 1.01.a
 PARAMETER HW_INSTANCE = RS232_UART_1
 PARAMETER CLOCK_HZ = 100000000
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 2.01.a
 PARAMETER HW_INSTANCE = LEDs_8Bit
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 2.01.a
 PARAMETER HW_INSTANCE = DIP_Switches_8Bit
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = gpio
 PARAMETER DRIVER_VER = 2.01.a
 PARAMETER HW_INSTANCE = Push_Buttons_3Bit
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = emac
 PARAMETER DRIVER_VER = 1.00.e
 PARAMETER HW_INSTANCE = Ethernet_MAC
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = emc
 PARAMETER DRIVER_VER = 2.00.a
 PARAMETER HW_INSTANCE = FLASH_8Mx16
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = ddr
 PARAMETER DRIVER_VER = 1.00.b
 PARAMETER HW_INSTANCE = DDR_SDRAM_1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = sysace
 PARAMETER DRIVER_VER = 1.01.a
 PARAMETER HW_INSTANCE = SysACE_CompactFlash
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = bram
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = plb_bram_if_cntlr_1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = plb_bram_if_cntlr_1_bram
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = intc
 PARAMETER DRIVER_VER = 1.00.c
 PARAMETER HW_INSTANCE = opb_intc_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = FLASH_8Mx16_util_bus_split_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = DDR_SDRAM_1_util_bus_split_1
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = sysclk_inv
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = clk90_inv
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = ddr_clk90_inv
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = dcm_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = generic
 PARAMETER DRIVER_VER = 1.00.a
 PARAMETER HW_INSTANCE = dcm_1
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
 PARAMETER DRIVER_NAME = wdttb
 PARAMETER DRIVER_VER = 1.00.b
 PARAMETER HW_INSTANCE = opb_timebase_wdt_0
END

