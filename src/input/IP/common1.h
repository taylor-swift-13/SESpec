

#ifndef AUTO_GENERATED_COMMON_H
#define AUTO_GENERATED_COMMON_H



#    define CS_MEM_MAINTAIN_CUR_MAX_LEN32         (128)


#    define CS_MEM_MAINTAIN_DOWN_MAX_LEN32        (512)


#    define CS_MEM_MAINTAIN_UPLOAD_MAX_LEN32      (512)


#    define EVENT_INJ_ADDR_ERR              (0x1D)


#    define EVENT_INJ_ID_ERR                (0x1C)


#    define EVENT_MEM_ADDR_ERR              (0x23)


#    define EVENT_MEM_DST_ADDR_ERR          (0x22)


#    define EVENT_MEM_SRC_ADDR_ERR          (0x21)


#    define EVENT_OS_Operation_Err_ModeErr                     \
        (0x36)


#    define EVENT_OS_Operation_Err_NotAlign (0x33)


#    define EVENT_OS_Operation_Err_NotInEeprom \
        (0x34)


#    define EVENT_OS_Operation_Err_NotInSram \
        (0x35)


#    define EVENT_OS_Operation_OK           (0x30)


#    define EVENT_OS_Operation_Reading      (0x31)


#    define EVENT_OS_Operation_Writing      (0x32)


#    define EVENT_TCEXE_ADDR_ERR            (0x11)


#    define EVENT_TCEXE_ALIGN_ERR           (0x12)


#    define EVENT_TCEXE_CODE_ERR            (0x14)


#    define EVENT_TCEXE_DWLEN_ERR           (0x1B)


#    define EVENT_TCEXE_LEN_ERR             (0x13)


#    define EVENT_TCEXE_OPING_ERR           (0x1A)


#    define EVENT_TCEXE_OPLEN_ERR           (0x15)


#    define EVENT_TCEXE_TYPE_ERR            (0x19)


#    define EVENT_TCEXE_WRITE_SUCC          (0x10)


#    define EVENT_TC_SUCC                   (0)


#    define EVENT_USR_BLOCKTYPE_ERR         (0x17)


#    define EVENT_USR_CHECKSUM_ERR          (0x16)


#    define EVENT_USR_SERVICE_ID_ERR        (0x18)


#    define MemRangeValidAll(addr, len08)                                     \
        (MemRangeValidRam((addr), (len08)) & MemRangeValidE2((addr), (len08)) \
          & MemRangeValidNorFlash((addr), (len08)))


#    define MemRangeValidE2(addr, len08) \
        (MemRangeValidE2A((addr), (len08)) & MemRangeValidE2B((addr), (len08)))


#    define MemRangeValidE2A(addr, len08) \
        (!!MemRangeValid((addr), (len08), E2PROM_A_BASEADDR, E2PROM_SIZE08))


#    define MemRangeValidE2B(addr, len08) \
        (!!MemRangeValid((addr), (len08), E2PROM_B_BASEADDR, E2PROM_SIZE08))


#    define MemRangeValidNorFlash(addr, len08) \
        (!!MemRangeValid((addr), (len08), FLASH_BASEADDR, FLASH_SIZE08))


#    define MemRangeValidRam(addr, len08) \
        (!!MemRangeValid((addr), (len08), RAM_BASEADDR, RAM_SIZE08))


#    define MemRangeValid_EEPROM_NorFlash(addr, len08) \
        (MemRangeValidE2((addr), (len08)) & MemRangeValidNorFlash((addr), (len08)))


#    define READ_U16(buf08) (UI16_MAKE(((unint08 *)(buf08))[0], ((unint08 *)(buf08))[1]))


#    define READ_U24(buf08) \
        (UI32_MAKE16(((unint08 *)(buf08))[0], READ_U16(((unint08 *)(buf08) + 1))))


#    define READ_U32(buf08) \
        (UI32_MAKE16(READ_U16(((unint08 *)(buf08))), READ_U16(((unint08 *)(buf08) + 2))))


#    define READ_U48(buf08) \
        (UI64_MAKE32(READ_U16((unint08 *)(buf08)), READ_U32((unint08 *)(buf08) + 2)))


#    define READ_U64(buf08) \
        (UI64_MAKE32(READ_U32((unint08 *)(buf08)), READ_U32((unint08 *)(buf08) + 4)))


#    define READ_U8(buf08)  (((unint08 *)(buf08))[0])


#    define SYS_E2_Last_Operation_Err_DoubleError (7)


#    define SYS_E2_Last_Operation_OK              (0)


#    define SYS_E2_Operation_Err_ModeErr          (6)


#    define SYS_E2_Operation_Err_NotAlign         (3)


#    define SYS_E2_Operation_Err_NotInEeprom      (4)


#    define SYS_E2_Operation_Err_NotInSram        (5)


#    define SYS_E2_Operation_Err_Reading          (1)


#    define SYS_E2_Operation_Err_Writing          (2)


#    define SYS_E2_Operation_Is_Working           (8)


#    define SYS_E2_Operation_Read                 (0)


#    define SYS_E2_Operation_Status               (2)


#    define SYS_E2_Operation_Write                (1)


#    define SYS_NORF_ASK                          (0x02)


#    define SYS_NORF_DOUBLE_ERR                   (0x08)


#    define SYS_NORF_MODE_ERR      (0x0C)


#    define SYS_NORF_NOTALIGN_ERR                 (0x09)


#    define SYS_NORF_NOTINNORF_ERR \
        (0x0A)


#    define SYS_NORF_NOTINSRAM_ERR (0x0B)


#    define SYS_NORF_OK                           (0x07)


#    define SYS_NORF_OPTNULL                      (0x06)


#    define SYS_NORF_OPT_ERR \
        (0x0D)


#    define SYS_NORF_READ                         (0x00)


#    define SYS_NORF_REFRESH                      (0x04)


#    define SYS_NORF_REPAIR                       (0x05)


#    define SYS_NORF_SUM                          (0x03)


#    define SYS_NORF_WRITE                        (0x01)


#    define TC_COMPARE_FAIL                 (0x2)


#    define TC_COMPARE_NULL                 (0x0)


#    define TC_COMPARE_OK                   (0x1)


#define	ANSY_BRDY 				DISABLE


#define	APPOKMINCOUNT						(80)


#define	APPTRI32_A_BASEADDR					(SYS_TRI32_BASEADDR)


#define	APPTRI32_B_BASEADDR					(SYSTRI32_A_BASEADDR+SYSTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	APPTRI32_C_BASEADDR					(SYSTRI32_B_BASEADDR+SYSTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	APPTRI32_EACHSIZE						(4*1024)


#define	BACKKEY				(0x14)


#define	BEXCN							ENABLE


#define	BRDY							DISABLE


#define	BRDYN							ENABLE


#define	BSPCCR_INIT					((CACHE_RFT << 29)|			\
														(CACHE_SNOOP << 23)|		\
														(CACHE_D_REFRESH << 22)|	\
														(CACHE_I_REFRESH << 21)|	\
														((CACHE_FT & 0x3) << 19)|	\
														((CACHE_I_CATCH) << 16)|	\
														(CACHE_D_INT << 5)|			\
														(CACHE_I_INT << 4)|			\
														((CACHE_D_STATUS & 0x3) << 2)|		\
														(CACHE_I_STATUS & 0x3))


#define	BSPCLEARCPUDOG				*((V_U32*)(BSPMECBASE+BSP_AMBA_WDT_BASEADDR + 0)) = BSPWDT_INIT


#define	BSPCPU_PSR_CWP_MASK			(0x0007)


#define	BSPCPU_PSR_EF_MASK			(0x1000)


#define	BSPCPU_PSR_ET_MASK			(0x0020)


#define	BSPCPU_PSR_PIL_MASK			(0x0f00)


#define	BSPCPU_PSR_PS_MASK			(0x0040)


#define	BSPCPU_PSR_S_MASK			(0x0080)


#define	BSPCPU_TBR_TT_MASK			(0x0ff0)


#define	BSPDISABLECPUDOG			*((V_U32*)(BSPMECBASE+BSP_AMBA_WDT_BASEADDR + 8)) = *((V_U32*)(BSPMECBASE+BSP_AMBA_WDT_BASEADDR + 8)) &(0xfffffffe)


#define	BSPENABLECPUDOG				*((V_U32*)(BSPMECBASE+BSP_AMBA_WDT_BASEADDR + 8)) = BSPWDTCTRL_INIT


#define	BSPFSR_INIT					((NVM << 27)|	\
				 											(OFM << 26)|	\
				 											(UFM << 25)|	\
				 											(DZM << 24)|	\
				 											(NXM << 23))


#define	BSPGPIDATR_INIT				((GPI0_DATA << 0)|	\
								 								(GPI1_DATA << 1)|	\
								 								(GPI2_DATA << 2)|	\
								 								(GPI3_DATA << 3)|	\
								 								(GPI4_DATA << 4)|	\
								 								(GPI5_DATA << 5)|	\
								 								(GPI6_DATA << 6)|	\
								 								(GPI7_DATA << 7)|	\
								 								(GPI8_DATA << 8)|	\
								 								(GPI9_DATA << 9)|	\
								 								(GPI10_DATA << 10)|	\
								 								(GPI11_DATA << 11)|	\
								 								(GPI12_DATA << 12)|	\
								 								(GPI13_DATA << 13)|	\
								 								(GPI14_DATA << 14)|	\
								 								(GPI15_DATA << 15)|	\
								 								(GPI16_DATA << 16)|	\
								 								(GPI17_DATA << 17)|	\
								 								(GPI18_DATA << 18)|	\
								 								(GPI19_DATA << 19)|	\
								 								(GPI20_DATA << 20)|	\
								 								(GPI21_DATA << 21)|	\
								 								(GPI22_DATA << 22)|	\
								 								(GPI23_DATA << 23)|	\
								 								(GPI24_DATA << 24)|	\
								 								(GPI25_DATA << 25)|	\
								 								(GPI26_DATA << 26)|	\
								 								(GPI27_DATA << 27)|	\
								 								(GPI28_DATA << 28)|	\
								 								(GPI29_DATA << 29)|	\
								 								(GPI30_DATA << 30)|	\
								 								(GPI31_DATA << 31))


#define	BSPGPTSR_INIT				(BSPSCALERCOUNT_INIT)


#define	BSPIOBASE					(0x20000000)


#define	BSPMCFG1_INIT				(((PROM_BRDY & 0x01) << 30)|		\
														((ANSY_BRDY & 0x01) << 29)|		\
														((IO_WIDTH & 0x3) << 27)|	\
														((BRDYN & 0x01) << 26)|		\
														((BEXCN & 0x01) << 25)|		\
														((IO_WS & 0xf) << 20)|	\
														(IO_SEL << 19)|	\
														((PROM_BANK_SIZE & 0xf) << 14)|		\
														((PROM_WRITE & 0x01) << 11)|		\
														((PROM_WIDTH & 0x3) << 8)|		\
														((PROM_W_WS & 0xf) << 4)|		\
														(PROM_R_WS & 0xf))


#define	BSPMCFG2_INIT				((SDRAM_FRESH  << 31)|	\
														(SDRAM_TRP  << 30)|	\
														((SDRAM_FRFC & 0x7) << 27)|	\
														(SDRAM_CAS << 26)|	\
														((SDRAM_SIZE & 0x7) << 23)|	\
														((SDRAM_COLUMN & 0x3) << 21)|	\
														((SDRAM_COMMAND & 0x3) << 19)|	\
														((SDRAM_GROUPREAD & 0x1) << 17)|	\
														((SDRAM_EN & 0x01) << 14)|	\
														(((~SRAM_EN) & 0x01)  << 13)|		\
														((SRAM_BANK_SIZE & 0xf) << 9)|	\
													 	(BRDY << 7)|		\
													 	(RMW << 6)|		\
													 	((SRAM_WIDTH & 0x3) << 4) |\
														((SRAM_W_WS & 0x3) << 2)|		\
													 	(SRAM_R_WS & 0x3))


#define	BSPMCFG3_INIT				((MEMORY_EDAC << 27)|		\
														(SRAM_EDAC << 9)|	\
														(PROM_EDAC << 8))


#define	BSPMECBASE				(0x80000000)


#define	BSPMINSTACKSIZE			(0x60)


#define	BSPRAMBASE				(0x40000000)


#define	BSPRAMSIZE					(0x400000) //(0x800000)


#define	BSPRAMTEXTBASE		(0x40018000)


#define	BSPRAM_OFFSET			(0x0)


#define	BSPROMBASE				(0x0)


#define	BSPROMSIZE						(0x8000)


#define	BSPRTCSR_INIT				(BSPSCALERCOUNT_INIT)


#define	BSPSCALERCOUNT_INIT			(((TIMER_SCALER*CPU_FREQ)/1000000) - 1)


#define	BSPSCALERLOAD_INIT			(BSPSCALERCOUNT_INIT)


#define	BSPSETCPUDOG				*((V_U32*)(BSPMECBASE+BSP_AMBA_WDT_BASEADDR + 4)) = BSPWDT_INIT


#define	BSPSOFTRESET				*((V_U32*)0x80000804) = (*((V_U32*)0x80000804)) & 0xfffff7ff


#define	BSPSREEN					(0x1 << 9)


#define	BSPSTACK					OS_SYSSTK_BASE


#define	BSPTEXTSIZE				(0x100000)


#define	BSPTIMER1COUNT_INIT			(TIMER1_INIT)


#define	BSPTIMER1CTRL_INIT			((TIMER1_CH<<5)|		\
																(TIMER1_IE<<3)|		\
																(TIMER1_LD<<2)|		\
																(TIMER1_RS<<1)|		\
																(TIMER1_EN))


#define	BSPTIMER1LOAD_INIT			(TIMER1_INIT)


#define	BSPTIMER3COUNT_INIT			(TIMER3_INIT)


#define	BSPTIMER3CTRL_INIT			((TIMER3_CH<<5)|		\
																(TIMER3_IE<<3)|		\
																(TIMER3_LD<<2)|		\
																(TIMER3_RS<<1)|		\
																(TIMER3_EN))


#define	BSPTIMER4COUNT_INIT			(TIMER4_INIT)


#define	BSPTIMER4CTRL_INIT			((TIMER4_CH<<5)|		\
																(TIMER4_IE<<3)|		\
																(TIMER4_LD<<2)|		\
																(TIMER4_RS<<1)|		\
																(TIMER4_EN))


#define	BSPUART1BAUD					(115200)


#define	BSPUART1CTRl_INIT			((COM1_FIFODEBUG_ENABLE<<11)|		\
																(COM1_RFIFOINT_ENABLE<<10)|\
																(COM1_WFIFOINT_ENABLE<<9)|	\
																(COM1_EC << 8)|				\
																(COM1_LB<<7)|				\
																(COM1_FL<<6)|				\
																((COM1_PARITY_ENABLE)<<5)|	\
																(COM1_PARITY_SELECT<<4)|	\
																(COM1_WINT_ENABLE<<3)|		\
																(COM1_RINT_ENABLE<<2)|		\
																(COM1_W_ENABLE<<1)|		\
																(COM1_R_ENABLE))


#define	BSPUART1SCALER_INIT			((((CPU_FREQ*10)/(BSPUART1BAUD*8))-5)/10)


#define	BSPUART2BAUD					(115200)


#define	BSPUART2SCALER_INIT			((((CPU_FREQ*10)/(BSPUART2BAUD*8))-5)/10)


#define	BSPWDTCTRL_INIT				((ENABLE<<3)|		\
																(ENABLE<<2)|		\
																(ENABLE))


#define	BSPWDT_INIT					(((WDT_RESET_TIME * 1000)/TIMER_SCALER)&0xFFFFFFFF)


#define	BSP_AHB_STATUS_REG				(0xf00)


#define	BSP_AMBA_AHB_BASEADDR			(0xf00)


#define	BSP_AMBA_GPIO_BASEADDR			(0x800)

#define	BSP_AMBA_GPIO_BASEADDR			(0x800)


#define	BSP_AMBA_INTR_BASEADDR			(0x200)


#define	BSP_AMBA_MEMORY_BASEADDR		(0x0)


#define	BSP_AMBA_TIMER_BASEADDR			(0x300)


#define	BSP_AMBA_UART1_BASEADDR			(0x100)


#define	BSP_AMBA_UART2_BASEADDR			(0x900)

#define	BSP_AMBA_UART2_BASEADDR			(0x900)


#define	BSP_AMBA_WDT_BASEADDR			(BSP_AMBA_TIMER_BASEADDR+0x50)


#define	BSP_CACHE_CTRL_REG		(0x80000014)


#define	BSP_CPU_NUMBER		4


#define	BSP_CTRLP_FLAG_ADDR							(0x80000804)


#define	BSP_CTRLP_FLAG_BIT							(10)


#define	BSP_CTRLP_OPT_VALUE							(0x1<<BSP_CTRLP_FLAG_BIT)


#define	BSP_E2PROM_USE_FLAG_ADDR				(0x80000800)


#define	BSP_E2PROM_USE_FLAG_BIT					(31)


#define	BSP_E2PROM_USE_NO_VALUE					(0x1)


#define	BSP_E2PROM_USE_YES_VALUE				(0x0)


#define	BSP_EDAC_CFGR			(BSP_AMBA_MEMORY_BASEADDR+0x08)


#define	BSP_EEPROM_A								(0xE0000001)


#define	BSP_EEPROM_B								(0xE0000002)


#define	BSP_EEPROM_CONTROL_ADDR					(0x80000804)


#define	BSP_EEPROM_CONTROL_BIT					(12)


#define	BSP_EEPROM_ENABLE_VALUE					(0x1)


#define	BSP_EEPROM_STATUS_ADDR					(0x80000804)


#define	BSP_EEPROM_STATUS_BIT						(12)


#define	BSP_FREQ_25M								(0x0<<18)


#define	BSP_FREQ_40M								(0x1<<18)


#define	BSP_FREQ_45M								(0x2<<18)


#define	BSP_FREQ_75M								(0x3<<18)


#define	BSP_FREQ_FLAG_ADDR					(0x80000800)


#define	BSP_FREQ_FLAG_BITS_MASK			(0x3<<18)


#define	BSP_GPT_CR				(BSP_GPT_REG)

#define	BSP_GPT_CR				(BSP_GPT_REG)


#define	BSP_GPT_REG				(BSP_AMBA_TIMER_BASEADDR+0x10)

#define	BSP_GPT_REG				(BSP_AMBA_TIMER_BASEADDR+0x10)


#define	BSP_INTID_EXINT0			(0x4)

#define	BSP_INTID_EXINT0			(0x4)


#define	BSP_INTID_EXINT1			(0x5)

#define	BSP_INTID_EXINT1			(0x5)


#define	BSP_INTID_EXINT2			(0x6)

#define	BSP_INTID_EXINT2			(0x6)


#define	BSP_INTID_EXINT3			(0x7)

#define	BSP_INTID_EXINT3			(0x7)


#define	BSP_INTID_GPT					(0x8)

#define	BSP_INTID_GPT					(0x8)


#define	BSP_INTID_RTCT				(0x9)




#define	BSP_INTID_SEU					(0x1)

#define	BSP_INTID_SEU					(0x1)


#define	BSP_INTID_UART1				(0x2)

#define	BSP_INTID_UART1				(0x2)


#define	BSP_INTID_UART2				(0x3)

#define	BSP_INTID_UART2				(0x3)


#define	BSP_INTMKR					((INT15_EN << 15)|\
															(INT14_EN << 14)|\
															(INT13_EN << 13)|\
															(INT12_EN << 12)|\
															(INT11_EN << 11)|\
															(INT10_EN << 10)|\
															(INT9_EN << 9)|\
															(INT8_EN << 8)|\
															(INT7_EN << 7)|\
															(INT6_EN << 6)|\
															(INT5_EN << 5)|\
															(INT4_EN << 4)|\
															(INT3_EN << 3)|\
															(INT2_EN << 2)|\
															(INT1_EN << 1))


#define	BSP_INTMKR1					(0x0040)


#define	BSP_INTMKR2					(0x0000)


#define	BSP_INTMKR3					(0x0000)


#define	BSP_INTR_BROD			(BSP_AMBA_INTR_BASEADDR+0x14) //多核中断广播寄存器


#define	BSP_INTR_CLR			(BSP_AMBA_INTR_BASEADDR+0x0C)

#define	BSP_INTR_CLR			(BSP_AMBA_INTR_BASEADDR+0x0C)


#define	BSP_INTR_MKR			(BSP_AMBA_INTR_BASEADDR+0x40)


#define	BSP_INTR_MKR0			(BSP_AMBA_INTR_BASEADDR+0x40)


#define	BSP_INTR_MKR1			(BSP_AMBA_INTR_BASEADDR+0x44)


#define	BSP_INTR_MKR2			(BSP_AMBA_INTR_BASEADDR+0x48)


#define	BSP_INTR_MKR3			(BSP_AMBA_INTR_BASEADDR+0x4C)


#define	BSP_INTR_PEND			(BSP_AMBA_INTR_BASEADDR+0x04)


#define	BSP_INTR_SIGTGR			(BSP_AMBA_INTR_BASEADDR+0x08)


#define	BSP_INTR_TGR			(BSP_AMBA_INTR_BASEADDR+0x08)	//SOC2008是0x8，多核是0x80,0x84,0x88,0x8C


#define	BSP_INTR_TGR			(BSP_AMBA_INTR_BASEADDR+0x80)	//SOC2008是0x8，多核是0x80,0x84,0x88,0x8C

#define	BSP_INTR_TGR			(BSP_AMBA_INTR_BASEADDR+0x80)	//SOC2008是0x8，多核是0x80,0x84,0x88,0x8C


#define	BSP_INTR_TGR0			(BSP_AMBA_INTR_BASEADDR+0x80)


#define	BSP_INTR_TGR1			(BSP_AMBA_INTR_BASEADDR+0x84)


#define	BSP_INTR_TGR2			(BSP_AMBA_INTR_BASEADDR+0x88)


#define	BSP_INTR_TGR3			(BSP_AMBA_INTR_BASEADDR+0x8C)


#define	BSP_INT_GPT_CLEAR			(0x1 << BSP_INTID_GPT)


#define	BSP_INT_GPT_ENABLE			(0x1 << BSP_INTID_GPT)


#define	BSP_INT_RTCT_CLEAR			(0x1 << BSP_INTID_RTCT)


#define	BSP_INT_RTCT_ENABLE			(0x1 << BSP_INTID_RTCT)


#define	BSP_INT_SEU_ENABLE			(0x1 << BSP_INTID_SEU)


#define	BSP_MON_FLAG_ADDR				(0x80000800)


#define	BSP_MON_FLAG_BIT				(16)


#define	BSP_MON_NO_VALUE				(0x1)


#define	BSP_MON_YES_VALUE				(0x0)


#define	BSP_NANDFLASH_CONTROL_ADDR				(0x80000804)


#define	BSP_NANDFLASH_CONTROL_BIT					(13)


#define	BSP_NANDFLASH_STATUS_ADDR					(0x80000804)


#define	BSP_NANDFLASH_STATUS_BIT					(13)


#define	BSP_POWER_ON_FLAG_ADDR				(0x80000800)


#define	BSP_POWER_ON_FLAG_BIT					(17)


#define	BSP_POWER_ON_NO_VALUE					(0x0)


#define	BSP_POWER_ON_YES_VALUE				(0x1)


#define	BSP_PROM_A_Base_Addr				(0x0)


#define	BSP_PROM_A_Size							(0x3000)


#define	BSP_PROM_B_Base_Addr				(0x3000)


#define	BSP_PROM_B_Size							(0x5000)


#define	BSP_PROM_SIZE								(32*1024)


#define	BSP_Prog_Storge1_BASE				(0x10000000)


#define	BSP_Prog_Storge1_Flag				(0x0)


#define	BSP_Prog_Storge2_BASE				(0x10180000)


#define	BSP_Prog_Storge2_BASE				(0x10200000)


#define	BSP_Prog_Storge2_Flag				(0x1)


#define	BSP_Prog_Storge3_BASE				(0x10400000)


#define	BSP_Prog_Storge3_Flag				(0x2)


#define	BSP_ROM_Storge1_BASE				(0x10000000)


#define	BSP_ROM_Storge1_END					(0x10180000)


#define	BSP_ROM_Storge1_END					(0x10200000)


#define	BSP_ROM_Storge2_BASE				(0x10180000)


#define	BSP_ROM_Storge2_BASE				(0x10200000)


#define	BSP_ROM_Storge2_END					(0x10300000)


#define	BSP_ROM_Storge2_END					(0x10400000)


#define	BSP_ROM_Storge3_BASE				(0x10400000)


#define	BSP_ROM_Storge3_END					(0x1047ffff)


#define	BSP_RTCT_REG			(BSP_AMBA_TIMER_BASEADDR+0x20)

#define	BSP_RTCT_REG			(BSP_AMBA_TIMER_BASEADDR+0x20)


#define	BSP_TIMER_SR			(BSP_AMBA_TIMER_BASEADDR+0x00)

#define	BSP_TIMER_SR			(BSP_AMBA_TIMER_BASEADDR+0x00)


#define	BSP_WDT_FLAG_ADDR							(0x80000804)


#define	BSP_WDT_FLAG_BIT							(8)


#define	BSP_WDT_IN_FLAG_ADDR					(0x80000804)


#define	BSP_WDT_YES_VALUE							(0x3)


#define	CACHE_DISABLE						0x00


#define	CACHE_D_INT					DISABLE


#define	CACHE_D_REFRESH				DISABLE


#define	CACHE_D_REFRESH				ENABLE


#define	CACHE_D_STATUS				CACHE_DISABLE


#define	CACHE_D_STATUS				CACHE_ENABLE


#define	CACHE_ENABLE						0x03


#define	CACHE_FROZEN						0x01


#define	CACHE_FT					CACHE_FT_DISABLE


#define	CACHE_FT_DISABLE					0x00


#define	CACHE_FT_ENABLE						0x01


#define	CACHE_I_CATCH				DISABLE


#define	CACHE_I_INT					DISABLE


#define	CACHE_I_REFRESH				DISABLE


#define	CACHE_I_REFRESH				ENABLE


#define	CACHE_I_STATUS				CACHE_DISABLE


#define	CACHE_I_STATUS				CACHE_ENABLE


#define	CACHE_RFT					DISABLE


#define	CACHE_SNOOP					DISABLE


#define	CACHE_SNOOP					ENABLE


#define	COM1_EC							DISABLE


#define	COM1_FIFODEBUG_ENABLE			DISABLE


#define	COM1_FL							DISABLE


#define	COM1_LB							DISABLE


#define	COM1_PARITY_ENABLE		DISABLE


#define	COM1_PARITY_SELECT		COM_EVEN


#define	COM1_RFIFOINT_ENABLE			DISABLE


#define	COM1_RINT_ENABLE			DISABLE


#define	COM1_R_ENABLE					ENABLE


#define	COM1_WFIFOINT_ENABLE			DISABLE


#define	COM1_WINT_ENABLE			DISABLE


#define	COM1_W_ENABLE					ENABLE


#define	COM2_EC							DISABLE


#define	COM2_FIFODEBUG_ENABLE			DISABLE


#define	COM2_FL							DISABLE


#define	COM2_LB							DISABLE


#define	COM2_PARITY_ENABLE		DISABLE


#define	COM2_PARITY_SELECT		COM_EVEN


#define	COM2_RFIFOINT_ENABLE			DISABLE


#define	COM2_RINT_ENABLE			DISABLE


#define	COM2_R_ENABLE					ENABLE


#define	COM2_WFIFOINT_ENABLE			DISABLE


#define	COM2_WINT_ENABLE			DISABLE


#define	COM2_W_ENABLE					ENABLE


#define	COM_EVEN						0x0


#define	COM_ODD							0x1


#define	CONTROL_UART				(1)


#define	CONTROL_UARTDR		(BSPMECBASE+BSP_AMBA_UART1_BASEADDR)


#define	CONTROL_UARTDR		(BSPMECBASE+BSP_AMBA_UART2_BASEADDR)


#define	CONTROL_UARTRDATA			(0x00000001)


#define	CONTROL_UARTSR		(BSPMECBASE+BSP_AMBA_UART1_BASEADDR+4)


#define	CONTROL_UARTSR		(BSPMECBASE+BSP_AMBA_UART2_BASEADDR+4)


#define	CONTROL_UART_INT_ENABLE			(0x1 << BSP_INTID_UART1)


#define	CONTROL_UART_INT_ENABLE			(0x1 << BSP_INTID_UART2)


#define	CONTROL_UART_INT_TT				(0x10|BSP_INTID_UART1)


#define	CONTROL_UART_INT_TT				(0x10|BSP_INTID_UART2)


#define	CORE0_SYSTASKNUM				(4)


#define	CORE1_SYSTASKNUM				(2)


#define	CORE2_SYSTASKNUM				(0)


#define	CORE3_SYSTASKNUM				(0)


#define	CPU_FREQ						(80000000)


#define	DISABLE								0x0


#define	DZM								FLOAT_DISABLE


#define	DZM								FLOAT_ENABLE


#define	ENABLE								0x1


#define	FLOAT_DISABLE					0x0


#define	FLOAT_ENABLE					0x1

#define	FLOAT_ENABLE					0x1


#define	GCS_EXTPERIOD_BASETIME_MS					(4)


#define	GCS_EXTPERIOD_INT_MASK					(1<<BSP_INTID_EXINT2)


#define	GFS_AB_MACHINE_SWITCH_FLAG			(1)


#define	GFS_CLOCK_AUTO_DETECTED					(0)


#define	GFS_CLR_APP_EXINT0_PEND		(0)


#define	GFS_CLR_APP_EXINT1_PEND		(1)


#define	GFS_CLR_APP_EXINT2_PEND		(0)


#define	GFS_CLR_APP_EXINT3_PEND		(0)


#define	GFS_CRT0_FORBID									(1)


#define	GFS_DATA_CACHE_AVAILABLE				(1)


#define	GFS_EEPROM_AVAILABLE						(0)


#define	GFS_EXT_PERIOD_ENABLE						(1)


#define	GFS_INTR_CACHE_AVAILABLE				(1)


#define	GFS_MEMOPTEXECUTE_POSITION				(1)


#define	GFS_NAND_FLASH_AVAILABLE				(0)


#define	GFS_NOR_FLASH_AVAILABLE					(1)


#define	GFS_NOR_FLASH_WIDTH						(8) //(40)


#define	GFS_OBC_AUTOCMD_REFRESH					(0)


#define	GFS_SYS_HOOK_BYRET				(1)


#define	GPI0								0x0


#define	GPI0_CFG					GPI_IN


#define	GPI0_DATA					GPI_LOW


#define	GPI1								0x1


#define	GPI10								0xA


#define	GPI10_CFG					GPI_OUT


#define	GPI10_DATA				GPI_LOW


#define	GPI11								0xB


#define	GPI11_CFG					GPI_OUT


#define	GPI11_DATA				GPI_HIGH


#define	GPI12								0xC


#define	GPI12_CFG					GPI_OUT


#define	GPI12_DATA				GPI_HIGH


#define	GPI13								0xD


#define	GPI13_CFG					GPI_OUT


#define	GPI13_DATA				GPI_LOW


#define	GPI14								0xE


#define	GPI14_CFG					GPI_IN


#define	GPI14_DATA				GPI_LOW


#define	GPI15								0xF


#define	GPI15_CFG					GPI_OUT


#define	GPI15_DATA				GPI_LOW


#define	GPI16								0x10


#define	GPI16_CFG					GPI_IN


#define	GPI16_DATA				GPI_LOW


#define	GPI17								0x11


#define	GPI17_CFG					GPI_IN


#define	GPI17_DATA				GPI_LOW


#define	GPI18								0x12


#define	GPI18_CFG					GPI_IN


#define	GPI18_DATA				GPI_LOW


#define	GPI19								0x13


#define	GPI19_CFG					GPI_IN


#define	GPI19_DATA				GPI_LOW


#define	GPI1_CFG					GPI_IN


#define	GPI1_DATA					GPI_LOW


#define	GPI2								0x2


#define	GPI20								0x14


#define	GPI20_CFG					GPI_IN


#define	GPI20_DATA				GPI_LOW


#define	GPI21								0x15


#define	GPI21_CFG					GPI_IN


#define	GPI21_DATA				GPI_LOW


#define	GPI22								0x16


#define	GPI22_CFG					GPI_IN


#define	GPI22_DATA				GPI_LOW


#define	GPI23								0x17


#define	GPI23_CFG					GPI_IN


#define	GPI23_DATA				GPI_LOW


#define	GPI24								0x18


#define	GPI24_CFG					GPI_OUT


#define	GPI24_DATA				GPI_LOW


#define	GPI25								0x19


#define	GPI25_CFG					GPI_OUT


#define	GPI25_DATA				GPI_LOW


#define	GPI26								0x1A


#define	GPI26_CFG					GPI_OUT


#define	GPI26_DATA				GPI_LOW


#define	GPI27								0x1B


#define	GPI27_CFG					GPI_OUT


#define	GPI27_DATA				GPI_LOW


#define	GPI28								0x1C


#define	GPI28_CFG					GPI_IN


#define	GPI28_DATA				GPI_LOW


#define	GPI29								0x1D


#define	GPI29_CFG					GPI_IN


#define	GPI29_DATA				GPI_LOW


#define	GPI2_CFG					GPI_IN


#define	GPI2_DATA					GPI_LOW


#define	GPI3								0x3


#define	GPI30								0x1E


#define	GPI30_CFG					GPI_IN


#define	GPI30_DATA				GPI_LOW


#define	GPI31								0x1F


#define	GPI31_CFG					GPI_IN


#define	GPI31_DATA				GPI_LOW


#define	GPI3_CFG					GPI_IN


#define	GPI3_DATA					GPI_LOW


#define	GPI4								0x4


#define	GPI4_CFG					GPI_IN


#define	GPI4_DATA					GPI_LOW


#define	GPI5								0x5


#define	GPI5_CFG					GPI_IN


#define	GPI5_DATA					GPI_LOW


#define	GPI6								0x6


#define	GPI6_CFG					GPI_IN


#define	GPI6_DATA					GPI_LOW


#define	GPI7								0x7


#define	GPI7_CFG					GPI_IN


#define	GPI7_DATA					GPI_LOW


#define	GPI8								0x8


#define	GPI8_CFG					GPI_OUT


#define	GPI8_DATA					GPI_LOW


#define	GPI9								0x9


#define	GPI9_CFG					GPI_OUT


#define	GPI9_DATA					GPI_LOW


#define	GPI_HIGH							0x1

#define	GPI_HIGH							0x1


#define	GPI_IN								0x0

#define	GPI_IN								0x0


#define	GPI_LOW								0x0


#define	GPI_OUT								0x1


#define	GPT_COUNTER				(TIMER1_INIT)


#define	GPT_COUNTER_MAX				(0xffffffff)


#define	INT10_EN			INT_TIMER3_EN


#define	INT11_EN			INT_TIMER4_EN


#define	INT12_EN			INT_WDT_EN


#define	INT13_EN			INT_1553B_EN


#define	INT14_EN			INT_14_UNSED_EN


#define	INT15_EN			INT_15_UNSED_EN


#define	INT1_EN				INT_AHB_ERR_EN


#define	INT2_EN				INT_UART1_EN


#define	INT3_EN				INT_UART2_EN


#define	INT4_EN				INT_EXINT0_EN


#define	INT5_EN				INT_EXINT1_EN


#define	INT6_EN				INT_EXINT2_EN


#define	INT7_EN				INT_EXINT3_EN


#define	INT8_EN				INT_TIMER1_EN


#define	INT9_EN				INT_TIMER2_EN


#define	INTERVAL										(SYSTRI32_B_BASEADDR - SYSTRI32_A_BASEADDR)//一区的大小


#define	INT_14_UNSED_EN				INT_DISABLE


#define	INT_1553B_EN					INT_DISABLE


#define	INT_15_UNSED_EN				INT_DISABLE


#define	INT_AHB_ERR_EN				INT_ENABLE


#define	INT_DISABLE							0x0


#define	INT_EDGE_TRIG						0x00


#define	INT_ENABLE							0x1


#define	INT_EXINT0_EN					INT_DISABLE


#define	INT_EXINT0_GPI				ENABLE


#define	INT_EXINT0_SOURCE			GPI4


#define	INT_EXINT0_TRIG_MODE			INT_PULSE_TRIG


#define	INT_EXINT0_TRIG_POLARITY		INT_HIGH_TRIG


#define	INT_EXINT1_EN					INT_DISABLE


#define	INT_EXINT1_GPI				ENABLE


#define	INT_EXINT1_SOURCE			GPI5


#define	INT_EXINT1_TRIG_MODE			INT_PULSE_TRIG


#define	INT_EXINT1_TRIG_POLARITY		INT_HIGH_TRIG


#define	INT_EXINT2_EN					INT_ENABLE


#define	INT_EXINT2_GPI				ENABLE


#define	INT_EXINT2_SOURCE			GPI6


#define	INT_EXINT2_TRIG_MODE			INT_PULSE_TRIG


#define	INT_EXINT2_TRIG_POLARITY		INT_HIGH_TRIG


#define	INT_EXINT3_EN					INT_DISABLE


#define	INT_EXINT3_GPI				ENABLE


#define	INT_EXINT3_SOURCE			GPI7


#define	INT_EXINT3_TRIG_MODE			INT_PULSE_TRIG


#define	INT_EXINT3_TRIG_POLARITY		INT_HIGH_TRIG


#define	INT_HIGH_TRIG						0x01


#define	INT_LOW_TRIG						0x00


#define	INT_PULSE_TRIG						0x01


#define	INT_TIMER1_EN				INT_DISABLE


#define	INT_TIMER2_EN				INT_DISABLE

#define	INT_TIMER2_EN				INT_DISABLE


#define	INT_TIMER3_EN					INT_DISABLE


#define	INT_TIMER4_EN					INT_DISABLE

#define	INT_TIMER4_EN					INT_DISABLE


#define	INT_UART1_EN					INT_DISABLE


#define	INT_UART2_EN					INT_DISABLE


#define	INT_WDT_EN					INT_DISABLE


#define	IO_SEL						ENABLE


#define	IO_SIZE_16							0x01


#define	IO_SIZE_32							0x02


#define	IO_SIZE_8							0x00


#define	IO_WIDTH					IO_SIZE_32


#define	IO_WS							(0xF)


#define	LEVEL_CRITICAL						(0x555)


#define	LEVEL_NORMAL							(0xAAA)


#define	LOADERR				(0xaa)


#define	LOADOK				(0x55)


#define	MEMORY_EDAC					ENABLE


#define	NVM								FLOAT_DISABLE


#define	NVM								FLOAT_ENABLE


#define	NXM								FLOAT_DISABLE


#define	OFM								FLOAT_DISABLE


#define	OFM								FLOAT_ENABLE


#define	OS_ERR_INTCONNECT_TT_INVALID	(OS_ERR_INT_LIB  | ( 0x1<<8) | 0x1)


#define	OS_ERR_INTERNAL_LIB					( 0xf << 16)


#define	OS_ERR_INT_LIB						( 0x6 << 16)


#define	OS_ERR_INVALID					(0xffffffff)


#define	OS_ERR_KERSTART_NO_TASK			(OS_ERR_KER_LIB  | ( 0x1<<8) | 0x1)


#define	OS_ERR_KER_LIB						( 0x1 << 16)


#define	OS_ERR_MEMALLOC_NO_FREE_BLOCK	(OS_ERR_MEM_LIB  | ( 0x1<<8) | 0x1)


#define	OS_ERR_MEMFREE_ID_INVALID		(OS_ERR_MEM_LIB  | ( 0x2<<8) | 0x1)


#define	OS_ERR_MEMFREE_ID_NULL			(OS_ERR_MEM_LIB  | ( 0x2<<8) | 0x2)


#define	OS_ERR_MEM_LIB						( 0x5 << 16)


#define	OS_ERR_MQDELETE_ID_INVALID		(OS_ERR_MQ_LIB   | ( 0x3<<8) | 0x1)


#define	OS_ERR_MQQUERY_ID_INVALID		(OS_ERR_MQ_LIB   | ( 0x4<<8) | 0x1)


#define	OS_ERR_MQQUERY_ID_NULL			(OS_ERR_MQ_LIB   | ( 0x4<<8) | 0x2)


#define	OS_ERR_MQREC_CALL_IN_INT		(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x2)


#define	OS_ERR_MQREC_CALL_IN_LOCK		(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x5)


#define	OS_ERR_MQREC_ID_INVALID			(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x1)


#define	OS_ERR_MQREC_MSGSIZE_OVER		(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x3)


#define	OS_ERR_MQREC_TIMEOUT			(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x4)


#define	OS_ERR_MQSEND_ID_INVALID		(OS_ERR_MQ_LIB   | ( 0x1<<8) | 0x1)


#define	OS_ERR_MQSEND_MSGSIZE_OVER		(OS_ERR_MQ_LIB   | ( 0x1<<8) | 0x2)


#define	OS_ERR_MQSEND_QUEUE_FULL		(OS_ERR_MQ_LIB   | ( 0x1<<8) | 0x3)


#define	OS_ERR_MQ_LIB						( 0x4 << 16)


#define	OS_ERR_OK						(0x0)


#define	OS_ERR_OTHER_LIB					( 0x8 << 16)


#define	OS_ERR_SEMDELETE_ID_INVALID		(OS_ERR_SEM_LIB  | ( 0x3<<8) | 0x1)


#define	OS_ERR_SEMDELETE_ID_NULL			(OS_ERR_SEM_LIB  | ( 0x3<<8) | 0x2)


#define	OS_ERR_SEMDELETE_SEMOWNER_ID_NULL			(OS_ERR_SEM_LIB  | ( 0x3<<8) | 0x3)


#define	OS_ERR_SEMFLUSH_ID_INVALID		(OS_ERR_SEM_LIB  | ( 0x4<<8) | 0x1)


#define	OS_ERR_SEMFLUSH_ID_NULL			(OS_ERR_SEM_LIB  | ( 0x4<<8) | 0x2)


#define	OS_ERR_SEMGIVE_ID_INVALID		(OS_ERR_SEM_LIB  | ( 0x2<<8) | 0x1)


#define	OS_ERR_SEMGIVE_ID_NULL			(OS_ERR_SEM_LIB  | ( 0x2<<8) | 0x4)


#define	OS_ERR_SEMGIVE_MUTEX_GIVE_INT	(OS_ERR_SEM_LIB  | ( 0x2<<8) | 0x2)


#define	OS_ERR_SEMGIVE_MUTEX_GIVE_LOCK	(OS_ERR_SEM_LIB  | ( 0x2<<8) | 0x3)


#define	OS_ERR_SEMTAKE_CALL_IN_INT		(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x2)


#define	OS_ERR_SEMTAKE_CALL_IN_LOCK		(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x3)


#define	OS_ERR_SEMTAKE_ID_INVALID		(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x1)


#define	OS_ERR_SEMTAKE_ID_NULL			(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x5)


#define	OS_ERR_SEMTAKE_TIMEOUT			(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x4)


#define	OS_ERR_SEM_LIB						( 0x3 << 16)


#define	OS_ERR_SET_ERRNO(errno)			do {OSErrNo = (errno);  print2("\r\nOSErrNo: 0x%x",OSErrNo); } while(0)


#define	OS_ERR_SET_ERRNO(errno)			do {OSErrNo = (errno);}while(0)


#define	OS_ERR_STKREC_ALLOC_OVERFLOW	(OS_ERR_OTHER_LIB| ( 0x1<<8) | 0x1)


#define	OS_ERR_TASKDELAY_CALL_IN_INT	(OS_ERR_TASK_LIB | ( 0x4<<8) | 0x1)


#define	OS_ERR_TASKDELAY_CALL_IN_LOCK	(OS_ERR_TASK_LIB | ( 0x4<<8) | 0x2)


#define	OS_ERR_TASKDELETE_CALL_IN_INT	(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x3)


#define	OS_ERR_TASKDELETE_ID_INVALID	(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x1)


#define	OS_ERR_TASKDELETE_ID_NULL		(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x4)


#define	OS_ERR_TASKDELETE_SYS_TASK		(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x2)


#define	OS_ERR_TASKPRIOSET_SYS_TASK		(OS_ERR_TASK_LIB | ( 0x6<<8) | 0x1)


#define	OS_ERR_TASKRESTART_ID_INVALID	(OS_ERR_TASK_LIB | ( 0x5<<8) | 0x1)


#define	OS_ERR_TASKRESTART_ID_NULL		(OS_ERR_TASK_LIB | ( 0x5<<8) | 0x2)


#define	OS_ERR_TASKRESUME_ID_INVALID	(OS_ERR_TASK_LIB | ( 0x3<<8) | 0x1)


#define	OS_ERR_TASKRESUME_ID_NULL		(OS_ERR_TASK_LIB | ( 0x3<<8) | 0x2)


#define	OS_ERR_TASKSTACK_REC_ALLOC_FAIL 		(OS_ERR_TASK_LIB | ( 0x7<<8) | 0x1)


#define	OS_ERR_TASKSUSPEND_CALL_IN_INT	(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x2)


#define	OS_ERR_TASKSUSPEND_CALL_IN_LOCK	(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x3)


#define	OS_ERR_TASKSUSPEND_ID_INVALID	(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x1)


#define	OS_ERR_TASKSUSPEND_ID_NULL		(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x5)


#define	OS_ERR_TASKSUSPEND_SYS_TASK		(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x4)


#define	OS_ERR_TASK_LIB						( 0x2 << 16)


#define	OS_ERR_TIMEEVENTSET_TIME_INVALID (OS_ERR_TIME_LIB| ( 0x1<<8) | 0x1)


#define	OS_ERR_TIME_LIB						( 0x7 << 16)


#define	OS_STKBASE_OFFSET


#define	OS_TASKNAME_OFFSET		(0x4)


#define	OS_TASK_DELAY_OUT			(0xFFFFFFFD)


#define	OS_TASK_PEND_OUT			(0xFFFFFFFB)


#define	OS_TASK_READY_OUT			(0xFFFFFFFE)


#define	OS_TASK_RUN_OUT				(0xFFFFFFEF)


#define	OS_TASK_SUSPEND_OUT			(0xFFFFFFF7)


#define	PROM_128K							0x04


#define	PROM_128M							0x0e


#define	PROM_16K							0x01


#define	PROM_16M							0x0b


#define	PROM_1M								0x07


#define	PROM_256K							0x05


#define	PROM_256M							0x0f


#define	PROM_2M								0x08


#define	PROM_32K							0x02


#define	PROM_32M							0x0c


#define	PROM_4M								0x09


#define	PROM_512K							0x06


#define	PROM_512M							0x10


#define	PROM_64K							0x03


#define	PROM_64M							0x0d


#define	PROM_8K								0x00


#define	PROM_8M								0x0a


#define	PROM_BANK_SIZE				PROM_256M


#define	PROM_BRDY						DISABLE


#define	PROM_EDAC						ENABLE


#define	PROM_R_WS						(0xC)


#define	PROM_SIZE_16						0x01


#define	PROM_SIZE_32						0x02


#define	PROM_SIZE_8							0x00


#define	PROM_WIDTH						PROM_SIZE_8 //PROM_SIZE_32


#define	PROM_WRITE						ENABLE


#define	PROM_W_WS						(0xC)


#define	RMW								ENABLE


#define	SDRAM_128M							0x05


#define	SDRAM_16M							0x02


#define	SDRAM_256M							0x06


#define	SDRAM_32M							0x03


#define	SDRAM_4M							0x00


#define	SDRAM_512M							0x07


#define	SDRAM_64M							0x04


#define	SDRAM_8M							0x01


#define	SDRAM_AUTO_REFRESH					0x02


#define	SDRAM_CAS						SDRAM_CAS2


#define	SDRAM_CAS2							0x0


#define	SDRAM_CAS3							0x1


#define	SDRAM_COLUMN				SDRAM_COLUMN_256


#define	SDRAM_COLUMN_1024					0x02


#define	SDRAM_COLUMN_256					0x00


#define	SDRAM_COLUMN_512					0x01


#define	SDRAM_COMMAND				SDRAM_NOCMD


#define	SDRAM_EN						DISABLE


#define	SDRAM_FRESH					DISABLE


#define	SDRAM_FRESH_CYC			(0x0)


#define	SDRAM_FRFC					(0x0)


#define	SDRAM_GROUPREAD			DISABLE


#define	SDRAM_LOAD_COMMAND_REGISTER			0x03


#define	SDRAM_NOCMD							0x00


#define	SDRAM_PRECHAREGE					0x01


#define	SDRAM_SIZE					SDRAM_4M


#define	SDRAM_TRP						SDRAM_TRP2


#define	SDRAM_TRP2							0x0


#define	SDRAM_TRP3							0x1


#define	SMP_Load_BSP_InitFlag_ADDR				(SYS_RUN_INFO_BASEADDR+0x004C)


#define	SMP_Load_SYS_InitFlag_ADDR				(SYS_RUN_INFO_BASEADDR+0x0048)


#define	SRAM_1024M							0x11


#define	SRAM_128K							0x04


#define	SRAM_128M							0x0e


#define	SRAM_16K							0x01


#define	SRAM_16M							0x0b


#define	SRAM_1M								0x07


#define	SRAM_256K							0x05


#define	SRAM_256M							0x0f


#define	SRAM_2M								0x08


#define	SRAM_32K							0x02


#define	SRAM_32M							0x0c


#define	SRAM_4M								0x09


#define	SRAM_512K							0x06


#define	SRAM_512M							0x10


#define	SRAM_64K							0x03


#define	SRAM_64M							0x0d


#define	SRAM_8K								0x00


#define	SRAM_8M								0x0a


#define	SRAM_BANK_SIZE			SRAM_2M


#define	SRAM_EDAC						ENABLE


#define	SRAM_EN							ENABLE


#define	SRAM_R_WS						(0x3)


#define	SRAM_SIZE_16						0x01


#define	SRAM_SIZE_32						0x02


#define	SRAM_SIZE_8							0x00


#define	SRAM_WIDTH					SRAM_SIZE_32


#define	SRAM_W_WS						(0x3)


#define	SUMERR				(0xbb)


#define	SYSHOOKJUMPPROGBYRET


#define	SYSHOOKMAXNUM						16


#define	SYSTASKNUM							(CORE0_SYSTASKNUM+CORE1_SYSTASKNUM+CORE2_SYSTASKNUM+CORE3_SYSTASKNUM)


#define	SYSTASK_ID							TASK4_ID


#define	SYSTRI32_A_BASEADDR					( XWTRI32_A_BASEADDR+ XWTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	SYSTRI32_B_BASEADDR					( XWTRI32_B_BASEADDR+ XWTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	SYSTRI32_C_BASEADDR					( XWTRI32_C_BASEADDR+ XWTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	SYSTRI32_EACHSIZE						(4*1024)


#define	SYS_AutoSwitchCmdEnable_ADDR				(SYSTRI32_A_BASEADDR+0x0170)


#define	SYS_CntTimeforRefresh_H_ADDR	(SYSTRI32_A_BASEADDR+0x0188)


#define	SYS_CntTimeforRefresh_L_ADDR	(SYSTRI32_A_BASEADDR+0x018C)


#define	SYS_CtrlPeriod_Time_MS_ADDR				(SYSTRI32_A_BASEADDR+0x0184)


#define	SYS_E2_ASK							(0x02)//   Y                   查询操作


#define	SYS_E2_DOUBLE_ERR				(0x08)//        Y           Y  在E2读写过程表示单份出现双错


#define	SYS_E2_MAINTAIN					(0x05)//        Y    Y      Y  维护E2


#define	SYS_E2_MODE_ERR					(0x0C)//        Y              本次操作失败，mode参数错误


#define	SYS_E2_NOTALIGN_ERR			(0x09)//        Y              本次操作失败，E2或SRAM地址不对齐


#define	SYS_E2_NOTINEEPROM_ERR	(0x0A)//        Y              本次操作失败，不在E2有效地址空间


#define	SYS_E2_NOTINSRAM_ERR		(0x0B)//        Y              本次操作失败，不在SRAM有效地址空间


#define	SYS_E2_OK								(0x07)//        Y           Y  可以进行新操作


#define	SYS_E2_OPTNULL					(0x06)//             Y         空操作


#define	SYS_E2_OPT_ERR					(0x0D)//        Y              当前操作指令不被执行，EEPROM正响应其他操作指令


#define	SYS_E2_READ							(0x00)//   Y    Y    Y      Y  读操作


#define	SYS_E2_REFRESH					(0x04)//        Y    Y      Y  刷新E2


#define	SYS_E2_STATINFO_BASE				(SYS_TRAP_INFO_RECORD_BASE+SYS_TRAP_INFO_RECORD_SIZE-64)		//EEPROM信息记录区起始地址,64字节


#define	SYS_E2_SUM							(0x03)//   Y    Y    Y      Y  计算程序累加和并写入


#define	SYS_E2_WRITE						(0x01)//   Y    Y    Y      Y  写操作


#define	SYS_EEPROM_1_StartAddr					(0x10400000)//主份EEPROM起始地址，用于参数判断使用


#define	SYS_EEPROM_2_StartAddr					(0x10400000)//备份EEPROM起始地址，用于参数判断使用


#define	SYS_EEPROM_2_StartAddr					(0x10400000|0x80000000)//695主备份基址一样,为区分主备份,特或上0x80000000


#define	SYS_EEPROM_A								(BSP_EEPROM_A)


#define	SYS_EEPROM_B								(BSP_EEPROM_B)


#define	SYS_EEPROM_CONTROL_ADDR					BSP_EEPROM_CONTROL_ADDR


#define	SYS_EEPROM_CONTROL_BIT					BSP_EEPROM_CONTROL_BIT


#define	SYS_EEPROM_DATA1_BASE					SYS_EEPROM_1_StartAddr


#define	SYS_EEPROM_DATA1_SIZE					(0)	//EEPROM数据区大小


#define	SYS_EEPROM_DATA2_BASE					SYS_EEPROM_1_StartAddr


#define	SYS_EEPROM_DATA2_SIZE					(0)	//EEPROM数据区大小


#define	SYS_EEPROM_DATA_SIZE					(0)	//EEPROM数据区大小


#define	SYS_EEPROM_DoubleError_ADDR			(SYSTRI32_A_BASEADDR+0x0168)


#define	SYS_EEPROM_PAGE_SIZE						(0x200)			//页大小为512字节


#define	SYS_EEPROM_PAGE_SIZE_BIT				(0x1FF)		//页大小，用于地址与操作，地址右移9位相当于除以512


#define	SYS_EEPROM_PAGE_SIZE_BITNUM			(0x9)				//页大小，用于位移，地址右移9位相当于除以512


#define	SYS_EEPROM_PROG1_BASE					BSP_Prog_Storge3_BASE


#define	SYS_EEPROM_PROG1_ROM_AREA			BSP_Prog_Storge3_Flag


#define	SYS_EEPROM_PROG1_SIZE					BSPTEXTSIZE	//EEPROM程序区大小


#define	SYS_EEPROM_PROG2_BASE					BSP_Prog_Storge3_BASE


#define	SYS_EEPROM_PROG2_ROM_AREA			BSP_Prog_Storge3_Flag


#define	SYS_EEPROM_PROG2_SIZE					(0)	//EEPROM程序区大小


#define	SYS_EEPROM_PROG_SIZE					BSPTEXTSIZE	//EEPROM程序区大小


#define	SYS_EEPROM_SIZE									(0x80000)


#define	SYS_EEPROM_STATUS_ADDR					BSP_EEPROM_STATUS_ADDR


#define	SYS_EEPROM_STATUS_BIT						BSP_EEPROM_STATUS_BIT


#define	SYS_ExcutingTaskName_ADDR			(SYSTRI32_A_BASEADDR+0x0074)


#define	SYS_FaultType_ADDR					(SYSTRI32_A_BASEADDR+0x0250)


#define	SYS_Flash_BadBlockTable_ADDR			(0x40126600)


#define	SYS_GPT_DATR							(*(V_U32 *)(BSPMECBASE+BSP_GPT_CR))


#define	SYS_Get(addr)						(*(V_U32 *)((U32)(addr)))


#define	SYS_INIT_FINISH_ADDR				(SYSTRI32_A_BASEADDR+0x0000)


#define	SYS_IOASIC_20M	(0x20)


#define	SYS_ISOLATION_SIZE					(512)


#define	SYS_IdleTaskReboot_ADDR				(SYSTRI32_A_BASEADDR+0x0164)


#define	SYS_IdleTaskResetSum_ADDR			(SYSTRI32_A_BASEADDR+0x0154)


#define	SYS_Load_AutoSwitchCmd_ADDR				(SYS_RUN_INFO_BASEADDR+0x0038)


#define	SYS_Load_EEPROM_SEU_Sum_ADDR 		(SYS_RUN_INFO_BASEADDR+0x0024)


#define	SYS_Load_EEPROM_TBE_Sum_ADDR 		(SYS_RUN_INFO_BASEADDR+0x0028)


#define	SYS_Load_FLASH_SEU_Sum_ADDR 			(SYS_RUN_INFO_BASEADDR+0x0060)


#define	SYS_Load_FLASH_TBE_Sum_ADDR 			(SYS_RUN_INFO_BASEADDR+0x0064)


#define	SYS_Load_FaultType_ADDR				(SYS_RUN_INFO_BASEADDR+0x0018)


#define	SYS_Load_InitFinish1_ADDR 				(SYS_RUN_INFO_BASEADDR+0x003C)


#define	SYS_Load_InitFinish2_ADDR 				(SYS_RUN_INFO_BASEADDR+0x0040)


#define	SYS_Load_InitFinish3_ADDR 				(SYS_RUN_INFO_BASEADDR+0x0044)


#define	SYS_Load_Load_Prog_Size_ADDR			(SYS_RUN_INFO_BASEADDR+0x0054)


#define	SYS_Load_Prog_EEPROM_Status_ADDR		(SYS_RUN_INFO_BASEADDR+0x0068)


#define	SYS_Load_Prog_Is_Loaded_ADDR 			(SYS_RUN_INFO_BASEADDR+0x005C)


#define	SYS_Load_Prog_Load_Flag_ADDR			(SYS_RUN_INFO_BASEADDR+0x0030)


#define	SYS_Load_Prog_Load_Status_ADDR			(SYS_RUN_INFO_BASEADDR+0x0034)


#define	SYS_Load_RAM_SIZE						(96*1024)


#define	SYS_Load_RebootTimes_ADDR			(SYS_RUN_INFO_BASEADDR+0x0008)


#define	SYS_Load_ResetFlag_ADDR				(SYS_RUN_INFO_BASEADDR+0x0000)


#define	SYS_Load_Reset_Sum_ADDR				(SYS_RUN_INFO_BASEADDR+0x0004)


#define	SYS_Load_SRAM_SEU_Sum_ADDR			(SYS_RUN_INFO_BASEADDR+0x001C)


#define	SYS_Load_SRAM_TBE_Sum_ADDR			(SYS_RUN_INFO_BASEADDR+0x0020)


#define	SYS_Load_TrapInstr_Adress_ADDR		(SYS_RUN_INFO_BASEADDR+0x0010)


#define	SYS_Load_TrapMem_Adress_ADDR		(SYS_RUN_INFO_BASEADDR+0x0014)


#define	SYS_Load_Trap_FSR_Status_ADDR			(SYS_RUN_INFO_BASEADDR+0x002c)


#define	SYS_Load_Trap_Record_ADDR				(SYS_RUN_INFO_BASEADDR+0x0058)


#define	SYS_Load_Trap_Type_ADDR				(SYS_RUN_INFO_BASEADDR+0x000C)


#define	SYS_MAX_CAUSERELOAD_REBOOTCNT		(3)


#define	SYS_MAX_CAUSESWITCH_REBOOTCNT		(5)


#define	SYS_MAX_EEPROM_Read_Size				(0x80)	//每周期允许读出E2的最大数量


#define	SYS_MAX_EEPROM_Write_Size				(0x10)	//每周期允许写入E2的最大数量


#define	SYS_MAX_FLASH_Read_Size				(0x80)


#define	SYS_MAX_FLASH_Write_Size			(0x08)


#define	SYS_MEM_TWO_SECTION_BASE		(BSPRAMBASE+0x122400)


#define	SYS_MEM_TWO_SECTION_SIZE		(273*1024)


#define	SYS_MgtTaskReboot_ADDR				(SYSTRI32_A_BASEADDR+0x0150)


#define	SYS_MgtTask_Degrade_ADDR			(SYSTRI32_A_BASEADDR+0x0158)


#define	SYS_NORF_ASK							(0x02)//   Y                   查询操作


#define	SYS_NORF_DOUBLE_ERR				(0x08)//        Y           Y  在norflash读写过程表示单份出现双错


#define	SYS_NORF_MODE_ERR					(0x0C)//        Y              本次操作失败，mode参数错误


#define	SYS_NORF_NOTALIGN_ERR			(0x09)//        Y              本次操作失败，NORF或SRAM地址不对齐


#define	SYS_NORF_NOTINNORF_ERR		(0x0A)//        Y              本次操作失败，不在Norflash有效地址空间


#define	SYS_NORF_NOTINSRAM_ERR		(0x0B)//        Y              本次操作失败，不在SRAM有效地址空间


#define	SYS_NORF_OK								(0x07)//        Y           Y  可以进行新操作


#define	SYS_NORF_OPTNULL					(0x06)//             Y         空操作


#define	SYS_NORF_OPT_ERR					(0x0D)//        Y              当前操作指令不被执行，flash正响应其他操作指令


#define	SYS_NORF_READ							(0x00)//   Y    Y    Y      Y  读操作


#define	SYS_NORF_REFRESH					(0x04)//        Y    Y      Y  刷新norflash


#define	SYS_NORF_REPAIR						(0x05)//        Y    Y      Y  修复norflash


#define	SYS_NORF_SUM							(0x03)//   Y    Y    Y      Y  计算程序累加和并写入


#define	SYS_NORF_WRITE						(0x01)//   Y    Y    Y      Y  写操作


#define	SYS_NandFlash_Is_OK							(0x00cc)


#define	SYS_NandFlash_Is_Reading					(0x00aa)


#define	SYS_NandFlash_Is_Writing					(0x00bb)


#define	SYS_NandFlash_MaxBlockMum	0x4000


#define	SYS_NandFlash_MaxPageMum	64


#define	SYS_NandFlash_OPT_NULL						(0x0000)


#define	SYS_NandFlash_OPT_QUERYS					(0x3333)


#define	SYS_NandFlash_OPT_READ						(0x1111)


#define	SYS_NandFlash_OPT_WRITE						(0x2222)


#define	SYS_NandFlash_Operation_Err_ModeErr				(7)


#define	SYS_NandFlash_Operation_Err_NotAlign  			(3)


#define	SYS_NandFlash_Operation_Err_NotInBlock			(5)


#define	SYS_NandFlash_Operation_Err_NotInSram			(4)


#define	SYS_NandFlash_Operation_Err_OnWorking  			(6)


#define	SYS_NandFlash_Operation_Is_Reading				(1)


#define	SYS_NandFlash_Operation_Is_Writing   			(2)


#define	SYS_NandFlash_Operation_OK						(0)


#define	SYS_NandFlash_Operation_QueryStatusMode			(2)


#define	SYS_NandFlash_Operation_ReadMode				(0)


#define	SYS_NandFlash_Operation_WriteMode				(1)


#define	SYS_PERIOD_TIME_MS					(64)


#define	SYS_PROM_SEU_Sum_ADDR				(SYSTRI32_A_BASEADDR+0x0038)


#define	SYS_PROM_State_ADDR					(SYSTRI32_A_BASEADDR+0x0024)


#define	SYS_PROM_TBE_Sum_ADDR				(SYSTRI32_A_BASEADDR+0x003C)


#define	SYS_PROM_WIDTH_32						(32)


#define	SYS_PROM_WIDTH_8						(8)


#define	SYS_Prog_Storge1_LastWord_ADDR		(SYSTRI32_A_BASEADDR+0x0068)


#define	SYS_Prog_Storge1_SEU_Sum_ADDR		(SYSTRI32_A_BASEADDR+0x0048)


#define	SYS_Prog_Storge1_State_ADDR			(SYSTRI32_A_BASEADDR+0x002C)


#define	SYS_Prog_Storge1_TBE_Sum_ADDR		(SYSTRI32_A_BASEADDR+0x004C)


#define	SYS_Prog_Storge2_LastWord_ADDR		(SYSTRI32_A_BASEADDR+0x006C)


#define	SYS_Prog_Storge2_SEU_Sum_ADDR		(SYSTRI32_A_BASEADDR+0x0050)


#define	SYS_Prog_Storge2_State_ADDR			(SYSTRI32_A_BASEADDR+0x0030)


#define	SYS_Prog_Storge2_TBE_Sum_ADDR		(SYSTRI32_A_BASEADDR+0x0054)


#define	SYS_Prog_Storge3_LastWord_ADDR		(SYSTRI32_A_BASEADDR+0x0070)


#define	SYS_Prog_Storge3_SEU_Sum_ADDR		(SYSTRI32_A_BASEADDR+0x0058)


#define	SYS_Prog_Storge3_State_ADDR			(SYSTRI32_A_BASEADDR+0x0034)


#define	SYS_Prog_Storge3_TBE_Sum_ADDR		(SYSTRI32_A_BASEADDR+0x005C)


#define	SYS_RESET_IN_WHICH_TASK_ADDR		(SYSTRI32_A_BASEADDR+0x0078)


#define	SYS_RUN_INFO_BASEADDR				(BSPRAMBASE+0xA200)


#define	SYS_RUN_INFO_SIZE					(1*1024)


#define	SYS_RamRefresh_ADDR					(SYSTRI32_A_BASEADDR+0x0160)


#define	SYS_ResetFlag_ADDR					(SYSTRI32_A_BASEADDR+0x0004)


#define	SYS_SRAMEDAC_ADDR					(SYSTRI32_A_BASEADDR+0x015C)


#define	SYS_SRAM_SEU_Sum_ADDR				(SYSTRI32_A_BASEADDR+0x0040)


#define	SYS_SRAM_State_ADDR					(SYSTRI32_A_BASEADDR+0x0028)


#define	SYS_SRAM_TBE_Sum_ADDR				(SYSTRI32_A_BASEADDR+0x0044)


#define	SYS_Set(addr,value)   				(*(V_U32 *)((U32)(addr))=(value))


#define	SYS_Soft_Reset_Flag_ADDR			(SYSTRI32_A_BASEADDR+0x0178)


#define	SYS_SwitchCmd_ADDR					(SYSTRI32_A_BASEADDR+0x0174)


#define	SYS_TASK10_Allocated_TIME_MS		(0)


#define	SYS_TASK10_LEVEL					LEVEL_NORMAL


#define	SYS_TASK10_STACK_SIZE				(16*1024)


#define	SYS_TASK10_START_TIME_MS			(0xFFFFFFFF)


#define	SYS_TASK11_Allocated_TIME_MS		(0)


#define	SYS_TASK11_LEVEL					LEVEL_NORMAL


#define	SYS_TASK11_STACK_SIZE				(16*1024)


#define	SYS_TASK11_START_TIME_MS			(0xFFFFFFFF)


#define	SYS_TASK12_Allocated_TIME_MS		(0)


#define	SYS_TASK12_LEVEL					LEVEL_NORMAL


#define	SYS_TASK12_STACK_SIZE				(16*1024)


#define	SYS_TASK12_START_TIME_MS			(0xFFFFFFFF)


#define	SYS_TASK13_Allocated_TIME_MS		(0)


#define	SYS_TASK13_LEVEL					LEVEL_NORMAL


#define	SYS_TASK13_STACK_SIZE				(16*1024)


#define	SYS_TASK13_START_TIME_MS			(0xFFFFFFFF)


#define	SYS_TASK14_Allocated_TIME_MS		(0)


#define	SYS_TASK14_LEVEL					LEVEL_NORMAL


#define	SYS_TASK14_STACK_SIZE				(16*1024)


#define	SYS_TASK14_START_TIME_MS			(0xFFFFFFFF)


#define	SYS_TASK15_Allocated_TIME_MS		(0)


#define	SYS_TASK15_LEVEL					LEVEL_NORMAL


#define	SYS_TASK15_STACK_SIZE				(16*1024)


#define	SYS_TASK15_START_TIME_MS			(0xFFFFFFFF)


#define	SYS_TASK16_Allocated_TIME_MS		(0)


#define	SYS_TASK16_LEVEL					LEVEL_NORMAL


#define	SYS_TASK16_STACK_SIZE				(16*1024)


#define	SYS_TASK16_START_TIME_MS			(0xFFFFFFFF)


#define	SYS_TASK1_Allocated_TIME_MS			(12)


#define	SYS_TASK1_LEVEL						LEVEL_CRITICAL


#define	SYS_TASK1_STACK_SIZE				(48*1024)


#define	SYS_TASK1_START_TIME_MS				(0)


#define	SYS_TASK2_Allocated_TIME_MS			(12)


#define	SYS_TASK2_LEVEL						LEVEL_CRITICAL


#define	SYS_TASK2_STACK_SIZE				(48*1024)


#define	SYS_TASK2_START_TIME_MS				(12)


#define	SYS_TASK3_Allocated_TIME_MS			(34)


#define	SYS_TASK3_LEVEL						LEVEL_CRITICAL


#define	SYS_TASK3_STACK_SIZE				(48*1024)


#define	SYS_TASK3_START_TIME_MS				(24)


#define	SYS_TASK4_Allocated_TIME_MS			(6)


#define	SYS_TASK4_LEVEL						LEVEL_NORMAL


#define	SYS_TASK4_STACK_SIZE				(16*1024)


#define	SYS_TASK4_START_TIME_MS				(58)


#define	SYS_TASK5_Allocated_TIME_MS			(58)


#define	SYS_TASK5_LEVEL						LEVEL_NORMAL


#define	SYS_TASK5_STACK_SIZE				(48*1024)


#define	SYS_TASK5_START_TIME_MS				(0)


#define	SYS_TASK6_Allocated_TIME_MS			(6)


#define	SYS_TASK6_LEVEL						LEVEL_NORMAL


#define	SYS_TASK6_STACK_SIZE				(16*1024)


#define	SYS_TASK6_START_TIME_MS				(58)


#define	SYS_TASK7_Allocated_TIME_MS			(0)


#define	SYS_TASK7_LEVEL						LEVEL_NORMAL


#define	SYS_TASK7_STACK_SIZE				(16*1024)


#define	SYS_TASK7_START_TIME_MS				(0xFFFFFFFF)


#define	SYS_TASK8_Allocated_TIME_MS			(0)


#define	SYS_TASK8_LEVEL						LEVEL_NORMAL


#define	SYS_TASK8_STACK_SIZE				(16*1024)


#define	SYS_TASK8_START_TIME_MS				(0xFFFFFFFF)


#define	SYS_TASK9_Allocated_TIME_MS			(0)


#define	SYS_TASK9_LEVEL						LEVEL_NORMAL


#define	SYS_TASK9_STACK_SIZE				(16*1024)


#define	SYS_TASK9_START_TIME_MS				(0xFFFFFFFF)


#define	SYS_TRAP_INFO_BASEADDR				(BSPRAMBASE+0x9400)


#define	SYS_TRAP_INFO_RECORD_BASE		(SYS_MEM_TWO_SECTION_BASE)


#define	SYS_TRAP_INFO_SIZE					(3*1024)


#define	SYS_Task10ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00F4)


#define	SYS_Task10RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0134)


#define	SYS_Task10TimoutSum_ADDR			(SYSTRI32_A_BASEADDR+0x00A0)


#define	SYS_Task11ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00F8)


#define	SYS_Task11RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0138)


#define	SYS_Task11TimoutSum_ADDR			(SYSTRI32_A_BASEADDR+0x00A4)


#define	SYS_Task12ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00FC)


#define	SYS_Task12RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x013C)


#define	SYS_Task12TimoutSum_ADDR			(SYSTRI32_A_BASEADDR+0x00A8)


#define	SYS_Task13ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x0100)


#define	SYS_Task13RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0140)


#define	SYS_Task13TimoutSum_ADDR			(SYSTRI32_A_BASEADDR+0x00AC)


#define	SYS_Task14ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x0104)


#define	SYS_Task14RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0144)


#define	SYS_Task14TimoutSum_ADDR			(SYSTRI32_A_BASEADDR+0x00B0)


#define	SYS_Task15ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x0108)


#define	SYS_Task15RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0148)


#define	SYS_Task15TimoutSum_ADDR			(SYSTRI32_A_BASEADDR+0x00B4)


#define	SYS_Task16ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x010C)


#define	SYS_Task16RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x014C)


#define	SYS_Task16TimoutSum_ADDR			(SYSTRI32_A_BASEADDR+0x00B8)


#define	SYS_Task1ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00D0)


#define	SYS_Task1RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0110)


#define	SYS_Task1TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x007C)


#define	SYS_Task2ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00D4)


#define	SYS_Task2RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0114)


#define	SYS_Task2TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x0080)


#define	SYS_Task3ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00D8)


#define	SYS_Task3RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0118)


#define	SYS_Task3TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x0084)


#define	SYS_Task4ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00DC)


#define	SYS_Task4RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x011C)


#define	SYS_Task4TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x0088)


#define	SYS_Task5ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00E0)


#define	SYS_Task5RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0120)


#define	SYS_Task5TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x008C)


#define	SYS_Task6ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00E4)


#define	SYS_Task6RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0124)


#define	SYS_Task6TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x0090)


#define	SYS_Task7ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00E8)


#define	SYS_Task7RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0128)


#define	SYS_Task7TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x0094)


#define	SYS_Task8ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00EC)


#define	SYS_Task8RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x012C)


#define	SYS_Task8TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x0098)


#define	SYS_Task9ResetSum_ADDR				(SYSTRI32_A_BASEADDR+0x00F0)


#define	SYS_Task9RunMode_ADDR				(SYSTRI32_A_BASEADDR+0x0130)


#define	SYS_Task9TimoutSum_ADDR				(SYSTRI32_A_BASEADDR+0x009C)


#define	SYS_Tr32_Get(addr)   				(UTIL_Tr32_Get((V_U32 *)((U32)(addr)) ,(V_U32 *)(((U32)(addr))+INTERVAL), (V_U32 *)(((U32)(addr))+2*INTERVAL)))


#define	SYS_Tr32_One_Region_Size		(APPTRI32_B_BASEADDR - APPTRI32_A_BASEADDR)


#define	SYS_Tr32_Set(addr,value)			(UTIL_Tr32_Set((V_U32 *)((U32)(addr)) ,(V_U32 *)(((U32)(addr))+INTERVAL), (V_U32 *)(((U32)(addr))+2*INTERVAL),(U32)(value)))


#define	SYS_TrapInstr_Adress_ADDR			(SYSTRI32_A_BASEADDR+0x0230)


#define	SYS_TrapMem_Adress_ADDR				(SYSTRI32_A_BASEADDR+0x0240)


#define	SYS_Trap_FSR_STATUS_ADDR			(SYSTRI32_A_BASEADDR+0x0260)


#define	SYS_Trap_FlashRecordFull_ADDR			(SYSTRI32_A_BASEADDR+0x0180)


#define	SYS_Trap_FlashRecord_ADDR			(SYSTRI32_A_BASEADDR+0x017C)


#define	SYS_Trap_Record1_ADDR				(SYSTRI32_A_BASEADDR+0x0204)


#define	SYS_Trap_Record2_ADDR				(SYSTRI32_A_BASEADDR+0x0208)


#define	SYS_Trap_Record3_ADDR				(SYSTRI32_A_BASEADDR+0x020C)


#define	SYS_Trap_Record_ADDR				(SYSTRI32_A_BASEADDR+0x0200)


#define	SYS_Trap_Type_ADDR					(SYSTRI32_A_BASEADDR+0x0220)


#define	SYS_WDT_Timeout_Count_ADDR			(SYSTRI32_A_BASEADDR+0x0060)


#define	SYS_WriteProtect_ADDR				(SYSTRI32_A_BASEADDR+0x016c)


#define	TASK10_ID (9)


#define	TASK11_ID (10)


#define	TASK12_ID (11)


#define	TASK13_ID (12)


#define	TASK14_ID (13)


#define	TASK15_ID (14)


#define	TASK16_ID (15)


#define	TASK1_ID (0)


#define	TASK2_ID (1)


#define	TASK3_ID (2)


#define	TASK4_ID (3)


#define	TASK5_ID (4)


#define	TASK6_ID (5)


#define	TASK7_ID (6)


#define	TASK8_ID (7)


#define	TASK9_ID (8)


#define	TIMER1_CH					DISABLE


#define	TIMER1_EN					TIMER_ENABLE


#define	TIMER1_IE					DISABLE


#define	TIMER1_INIT				0xffffffff


#define	TIMER1_LD					ENABLE


#define	TIMER1_RS					TIMER_RELOAD


#define	TIMER3_CH					DISABLE


#define	TIMER3_EN					TIMER_DISABLE


#define	TIMER3_IE					DISABLE


#define	TIMER3_INIT				0xffffffff


#define	TIMER3_LD					DISABLE


#define	TIMER3_RS					TIMER_ONESHOT


#define	TIMER4_CH					DISABLE


#define	TIMER4_EN					TIMER_DISABLE


#define	TIMER4_IE					DISABLE


#define	TIMER4_INIT				(0xffffffff)


#define	TIMER4_LD					DISABLE


#define	TIMER4_RS					TIMER_ONESHOT


#define	TIMER_DISABLE						0x00


#define	TIMER_ENABLE						0x01


#define	TIMER_ONESHOT						0x00


#define	TIMER_RELOAD						0x01

#define	TIMER_RELOAD						0x01


#define	TIMER_SCALER					(1)




#define	UARTDR		( *((V_U32 * )(BSPMECBASE+BSP_AMBA_UART1_BASEADDR)) )


#define	UARTDR		( *((V_U32 * )(BSPMECBASE+BSP_AMBA_UART2_BASEADDR)) )


#define	UARTPORT						(1)


#define	UARTSR		( *((V_U32 * )(BSPMECBASE+BSP_AMBA_UART1_BASEADDR+4)) )


#define	UARTSR		( *((V_U32 * )(BSPMECBASE+BSP_AMBA_UART2_BASEADDR+4)) )


#define	UARTSRDATA					(0x00000004)


#define	UFM								FLOAT_DISABLE


#define	USR_MAXCNT_SEU						10


#define	WANTEDKEY			(0x6f)


#define	WDT_RESET_TIME				(4000)


#define	XWTRI32_EACHSIZE						(4*1024)


#define	__ADD_NORFLASH__


#define	__INT0_FUNC__					SYS_ISR_Default_Hook


#define	__INT1_FUNC__					SYS_ISR_Default_Hook


#define	__INT2_FUNC__					SYS_ControlPeriodInt


#define	__INT3_FUNC__					SYS_ISR_Default_Hook


#define	__INT4_FUNC__					SYS_ISR_Default_Hook


#define     DBL_PI          6.283185307179586


#define     DEG2RAD         0.0174532925199433


#define     FLT32_ZERO      1.0e-7f


#define     FLT64_ZERO      1.0e-14


#define     HALF_PI         1.570796326794897


#define     MASK_08BIT          0x000000FFu


#define     MASK_16BIT          0x0000FFFFu


#define     MASK_24BIT          0x00FFFFFFu


#define     MASK_32BIT          0xFFFFFFFFu


#define     MASK_40BIT          0x000000FFFFFFFFFFu


#define     MASK_48BIT          0x0000FFFFFFFFFFFFu


#define     MASK_56BIT          0x00FFFFFFFFFFFFFFu


#define     MASK_64BIT          0xFFFFFFFFFFFFFFFFu


#define     PI              3.141592653589793


#define     POW_2E_N10      9.765625e-4


#define     POW_2E_N11      4.8828125e-4


#define     POW_2E_N14      6.103515625e-5


#define     POW_2E_N15      3.0517578125e-5


#define     POW_2E_N22      2.384185791015625e-7


#define     POW_2E_N24      5.960464477539063e-8


#define     POW_2E_N30      9.313225746154785e-10


#define     POW_2E_N6       1.5625e-2


#define     RAD2DEG         57.29577951308232


#define   BREAK_REV     0x8


#define   CMG_CTRL         0


#define   CMG_DELTA0_NUM   22


#define   DATA_RD       0x1


#define   DSS13            0


#define   DSS43            1


#define   DSS_ANGLE_DATA_FRAME_LEN          10


#define   DSS_CODE_DATA_FRAME_LEN           32


#define   DSS_XY_NUM       2


#define   DSS_Z_NUM        1


#define   ES_NUM           1


#define   FLIGHT_PHASE    3


#define   FLOW_CTR       0x40


#define   FOG_2_4_D_FRAME_LEN          13


#define   FRAME_ER      0x40


#define   GYRO_NUM         9


#define   HAVE_ACC         0


#define   HAVE_AUTONAVI    1


#define   HAVE_DSSZ        0


#define   HAVE_ECLIPSE     0


#define   HAVE_ES          0


#define   HAVE_ETTHR       0


#define   HAVE_GPRS        1


#define   LOOP_BCK       0x80


#define   NAVI_ASTRO    1


#define   NAVI_GNSS    1


#define   NAVI_SELF_AL    1


#define   NCmg             1


#define   NCmg             6


#define   OVERRUN       0x10


#define   PAR_EN		 0x20


#define   PAR_ER        0x20


#define   PAR_SEL        0x10


#define   REV_EN         0x1


#define   REV_INT_EN     0x4


#define   RW_CTRL          1


#define   STS_NUM          3


#define   TF_FULL       0x200


#define   THR_NUM         16


#define   TRANS_EN       0x2


#define   TRANS_INT_EN   0x8


#define   TS_EMPTY      0x2


#define   WHEEL_NUM        7


#define   _INCLUDE_CSCRIDATASR_


#define   _INCLUDE_CSIOCOMDIAG_H_


#define   _INCLUDE_CS_MEMMAINTAIN_H_


#define   __ORBIT_EX_HEAD__


#define   __ORBIT_NAVI_HEAD__


#define  BSP_NORFLASH_CONTROL_ADDR		(0x80000804)


#define  BSP_NORFLASH_CONTROL_BIT			(15)


#define  BSP_NORFLASH_DISABLE_VALUE		(0x0)


#define  BSP_NORFLASH_ENABLE_VALUE		(0x1)


#define  BSP_NORFLASH_STATUS_ADDR			(0x80000804)


#define  BSP_NORFLASH_STATUS_BIT			(15)


#define  DECLARE   extern


#define  DECLARE   extern  "C" __declspec(dllexport)


#define  DRVCPUBASE					(0x80000800)//CPU GPIO基地址


#define  DRVDISABLE  (0)


#define  DRVENABLE  (1)


#define  DRVFALSE  (0)


#define  DRVHIGH (1)


#define  DRVINVARAANT  (0)//固定脉冲


#define  DRVIOBASE1					(0x20000000)//A6017-1基地址，位于PM板


#define  DRVIOBASE2					(0x20300000)//A6017-2基地址，位于IO1板


#define  DRVIOBASE3					(0x20400000)//A6017-3基地址，位于IO2板


#define  DRVIOBASE4					(0x20500000)//IO4板基地址//不适用


#define  DRVLOW (0)


#define  DRVREV  (1)


#define  DRVTRUE  (1)


#define  DRVUNREV  (0)


#define  DRVUNUSED  (0)


#define  DRVUSED  (1)


#define  DRVVARAANT  (1)//可变脉冲


#define  DRV_BITIN_IO_GPIO  (1) //位口采集标志 IO板GPIO口状态


#define  DRV_BITIN_IO_PULSE  (0) //位口采集标志:IO板脉冲有效性标志


#define  DRV_BITIN_IO_PULSE_WidthAdd (200000)//位口输入的DRV_BITIN_IO_PULSE模式时的余量，单位us，当前配置200ms


#define  DRV_BITIN_PM_GPIO  (2)//位口采集标志 PM 板GPIO口状态


#define  DRV_CLK_100M (100000000)//频率为100M


#define  DRV_CLK_100M_PERIOD (10)//频率为100M时，周期为10ns


#define  DRV_CLK_16M (16000000)//频率为16M


#define  DRV_CLK_20M (20000000)//频率为20M


#define  DRV_CLK_20M_PERIOD (50)//频率为20M时，周期为50ns


#define  DRV_COUNT_CTRL_MODE  (1)


#define  DRV_COUNT_HIGH_MODE  (1)//1为上升沿


#define  DRV_COUNT_LOW_MODE  (0)//0为下降沿


#define  DRV_COUNT_OTHER_MODE  (2)//其他为软件锁存


#define  DRV_COUNT_SOFT_MODE  (0)


#define  DRV_GPS_OUTPUT_ADDR  (0x10C8)//GPS选择输出地址


#define  DRV_Get(addr)                              (*(V_U32 *)((U32)(addr)))


#define  DRV_INT_EDGE_TRIG  (0)//电平触发


#define  DRV_INT_HIGH_TRIG  (1)//高电平或上升沿触发


#define  DRV_INT_LOW_TRIG (2)//低电平或下降沿触发


#define  DRV_INT_PULSE_TRIG (3)//边沿触发


#define  DRV_NO_ERROR  (0xffffffff)//接口驱动中传参no不合法时返回值，除星时


#define  DRV_PULSE_PERIOD  (1)


#define  DRV_PULSE_SINGLE  (0)


#define  DRV_PULSE_SOURCE_ADDR   (0x100C) //同步信号基准源控制周期选择


#define  DRV_STRUCT_MEMBER_ERROR  (0xeeeeeeee)//接口驱动中结构体参数不合法时返回值


#define  DRV_SYN_SOURCE_EQU_ADDR  (0x1040)//当量设置地址


#define  DRV_SYN_SOURCE_OUTPUT_ADDR  (0x10C4)//输出地址


#define  DRV_SYN_SOURCE_PERIOD_ADDR  (0x10B0)//周期设置地址


#define  DRV_SYN_SOURCE_PHASE_ADDR  (0x1070)//相位差设置地址


#define  DRV_SYN_SOURCE_PULSE_ADDR  (0x10C0)//脉冲正负设置地址


#define  DRV_SYN_SOURCE_SELECT_ADDR  (0x1044)//基准源设置地址


#define  DRV_SYN_SOURCE_SOURCE_ADDR   (0x100C) //同步信号基准源控制周期选择地址


#define  DRV_SYN_SOURCE_VALID_ADDR  (0x1140)//基准信号边沿设置地址


#define  DRV_SYN_SOURCE_WIDTH_ADDR  (0x1090)//宽度设置地址


#define  DRV_Set(addr,value)                    (*(V_U32 *)((U32)(addr))=(value))


#define  DRV_Set_High(addr,bit)                (*(V_U32 *)((U32)(addr)) |= (0x1<<((U32)(bit)))) //置bit位为1，其他位不变


#define  DRV_Set_Low(addr,bit)                 (*(V_U32 *)((U32)(addr)) &= (~(0x1<<((U32)(bit)))))//置bit位为0，其他位不变


#define  DRV_TIME_NO_ERROR  (0xffffffffffffffff)//星时接口驱动中传参no不合法时返回值


#define  DRV_Tr32(data1,data2,data3)      ((((U32)(data1)) & ((U32)(data2)))|(((U32)(data1)) & ((U32)(data3)))|(((U32)(data2)) & ((U32)(data3))))


#define  FALSE32          0x00000000u


#define  MERGE_SORT_SIZE           100


#define  SORT_ATTRIBUTE_TYPE       unint32


#define  SYS_NORFLASH_CONTROL_ADDR		BSP_NORFLASH_CONTROL_ADDR


#define  SYS_NORFLASH_CONTROL_BIT			BSP_NORFLASH_CONTROL_BIT


#define  SYS_NORFLASH_DISABLE_VALUE		BSP_NORFLASH_DISABLE_VALUE


#define  SYS_NORFLASH_ENABLE_VALUE		BSP_NORFLASH_ENABLE_VALUE


#define  SYS_NORFLASH_STATUS_ADDR			BSP_NORFLASH_STATUS_ADDR


#define  SYS_NORFLASH_STATUS_BIT			BSP_NORFLASH_STATUS_BIT


#define  TRUE32           0xEB90146Fu


#define  _UPDATE_TIME_    0x20201225u


#define  _VER_INFO_       0x00000106u


#define  __CONFIG_HEAD__


#define ABSUI_TO_ADDR(ui)           ((unint32 *)(ui))


#define ABSUI_TO_ADDR08(ui)         ((volatile unint08 *)(ui))


#define ABSUI_TO_VADDR(ui)          ((volatile unint32 *)(ui))


#define ABSUI_TO_VADDR32(ui)        ((volatile unint32 *)(ui))


#define ACC_NUM     3


#define ADDR_B1553_BC_MEM_BASE		0x20510000


#define ADDR_B1553_BC_REG_BASE		0x20500000


#define ADDR_B1553_RT_MEM_BASE		0x20204000


#define ADDR_B1553_RT_REG_BASE		0x20200000


#define ADDR_IS_ALIGN(addr)         (((addr) & 0x3) == 0)


#define ADDR_RANGE_VALIDATE(addr, head, tail)   (((head) <= (addr)) && ((addr) <= (tail)))


#define ADDR_READ(addr)             (*((volatile unint32 *)(addr)))


#define ADDR_READ08(addr)           (ADDR_READ((addr)) & 0xFF)


#define ADDR_READ16(addr)           (ADDR_READ((addr)) & 0xFFFF)


#define ADDR_REG_GPI_DAT        0x2A000000


#define ADDR_TO_ABSUI(ptr)          ((unint32)(ptr))


#define ADDR_WRITE(addr, value)     {(*((volatile unint32 *)(addr))) = (value);}


#define ADDR_WRITE16(addr, val16)   {(*((volatile unint16 *)(addr))) = (val16);}


#define AFM                             0x3


#define ARRAY_SIZE(x)                   (sizeof(x) / sizeof(x[0]))


#define ASY_UART_DSSA    12


#define ASY_UART_DSSB    11


#define ASY_UART_FTA 0


#define ASY_UART_FTB 1


#define ATTITUDE_H


#define ATTI_ACC_H


#define ATTI_DSS_H


#define ATTI_ESDSSGYRO_H


#define ATTI_ES_H


#define ATTI_GYRO_H


#define ATTI_STS_H


#define ATT_MANEUVER_H


#define AUTOGEN_DECL_H


#define AUTO_GENERATED_COMMON_H


#define Atan2x(x, y)    (atan2((float64)(x), (float64)(y)))


#define Atanx(x)        (atan((float64)(x))               )


#define B1553_CHIP_61580            0x2222


#define B1553_CHIP_63825            0x3333


#define B1553_CHIP_65170            0x1111


#define B1553_CHNL_A                    BC_CTW_D07_CHNL_AB


#define B1553_CHNL_B                    0x0000


#define B1553_CMDSTACK_AREA_A       0x0000


#define B1553_CMDSTACK_AREA_B       0x2000


#define B1553_CMDWORD_ADDR(cmdw)            (((cmdw) >> 11u) & 0x1Fu)


#define B1553_CMDWORD_ADDR_SET(cmdw, addr)  ((cmdw) = ((cmdw) & (~(0x1Fu << 11u))) | (((addr) & 0x1Fu) << 11u))


#define B1553_CMDWORD_CNTD(cmdw)            ((cmdw)          & 0x1Fu)


#define B1553_CMDWORD_CNTD_SET(cmdw, cntd)  ((cmdw) = ((cmdw) & (~(0x1Fu       ))) | (((cntd) & 0x1Fu)       ))


#define B1553_CMDWORD_SAMC(cmdw)            (((cmdw) >>  5u) & 0x1Fu)


#define B1553_CMDWORD_SAMC_SET(cmdw, samc)  ((cmdw) = ((cmdw) & (~(0x1Fu <<  5u))) | (((samc) & 0x1Fu) <<  5u))


#define B1553_CMDWORD_TRCV(cmdw)            (((cmdw) >> 10u) & 0x01u)


#define B1553_CMDWORD_TRCV_SET(cmdw, trcv)  ((cmdw) = ((cmdw) & (~(0x01u << 10u))) | (((trcv) & 0x01u) << 10u))


#define B1553_MEM_CONF_A                    0x0000


#define B1553_MEM_CONF_B                    0x2000


#define B1553_MEM_INIT_ALL          0x2222


#define B1553_MEM_INIT_LESS         0x3333


#define B1553_MEM_INIT_NULL         0x1111


#define B1553_MODE_BC_ENHANCED              0xD2


#define B1553_MODE_BC_NORMAL                0xE1


#define B1553_MODE_IDLE                     0x00


#define B1553_MODE_MSG_MONI                 0xA5


#define B1553_MODE_RT_ENHANCED              0x87


#define B1553_MODE_RT_MT                    0x78


#define B1553_MODE_RT_NORMAL                0x96


#define B1553_MODE_WORD1_MONI               0xC3


#define B1553_MODE_WORD2_MONI               0xB4


#define B1553_MSGBLK_1_CMD(msgPtr)      ((msgPtr) + 1u)


#define B1553_MSGBLK_1_CTRLWD(msgPtr)   ((msgPtr) + 0u)


#define B1553_MSGBLK_1_DATA(msgPtr)     ((msgPtr) + 2u)


#define B1553_MSGBLK_2_CMD(msgPtr)      ((msgPtr) + 1u)


#define B1553_MSGBLK_2_CTRLWD(msgPtr)   ((msgPtr) + 0u)


#define B1553_MSGBLK_2_DATA(msgPtr)     ((msgPtr) + 4u)


#define B1553_MSGBLK_2_LOOPBK(msgPtr)   ((msgPtr) + 2u)


#define B1553_MSGBLK_2_STATUS(msgPtr)   ((msgPtr) + 3u)


#define B1553_MSGBLK_3_CMD(msgPtr)      ((msgPtr) + 1u)


#define B1553_MSGBLK_3_CTRLWD(msgPtr)   ((msgPtr) + 0u)


#define B1553_MSGBLK_3_LOOPBK(msgPtr)   ((msgPtr) + 2u)


#define B1553_MSGBLK_3_STATUS(msgPtr)   ((msgPtr) + 3u)


#define B1553_MSGBLK_4_CMD(msgPtr)      ((msgPtr) + 1u)


#define B1553_MSGBLK_4_CTRLWD(msgPtr)   ((msgPtr) + 0u)


#define B1553_MSGBLK_4_DATA(msgPtr)     ((msgPtr) + 4u)


#define B1553_MSGBLK_4_LOOPBK(msgPtr)   ((msgPtr) + 2u)


#define B1553_MSGBLK_4_STATUS(msgPtr)   ((msgPtr) + 3u)


#define B1553_MSGBLK_5_CMD(msgPtr)      ((msgPtr) + 1u)


#define B1553_MSGBLK_5_CTRLWD(msgPtr)   ((msgPtr) + 0u)


#define B1553_MSGBLK_5_DATA(msgPtr)     ((msgPtr) + 2u)


#define B1553_MSGBLK_5_LOOPBK(msgPtr)   ((msgPtr) + 3u)


#define B1553_MSGBLK_5_STATUS(msgPtr)   ((msgPtr) + 4u)


#define B1553_MSGBLK_6_CMD(msgPtr)      ((msgPtr) + 1u)


#define B1553_MSGBLK_6_CTRLWD(msgPtr)   ((msgPtr) + 0u)


#define B1553_MSGBLK_6_DATA(msgPtr)     ((msgPtr) + 2u)


#define B1553_MSGBLK_7_CMD(msgPtr)      ((msgPtr) + 1u)


#define B1553_MSGBLK_7_CTRLWD(msgPtr)   ((msgPtr) + 0u)


#define B1553_MSGBLK_7_DATA(msgPtr)     ((msgPtr) + 2u)


#define B1553_MSGBLK_8_CMD(msgPtr)      ((msgPtr) + 1u)


#define B1553_MSGBLK_8_CTRLWD(msgPtr)   ((msgPtr) + 0u)


#define B1553_MSGBLK_8_LOOPBK(msgPtr)   ((msgPtr) + 2u)


#define B1553_MSG_POLL_COUNT        500u


#define B1553_MSG_TRANS_TIME        800u


#define B1553_READ(offno, addrbase)         \
            ADDR_READ16((addrbase) + ((offno) << 2u))


#define B1553_REG_BASE                      0x0000u


#define B1553_REG_BC_CTRW                   0x0004u


#define B1553_REG_BC_FRM_TIME_REM           0x000Bu


#define B1553_REG_BC_FTIME                  0x000Du


#define B1553_REG_BC_TIME_REM_NMSG          0x000Cu


#define B1553_REG_CMD_STACK_PTR             0x0003u


#define B1553_REG_CONF1                     0x0001u


#define B1553_REG_CONF2                     0x0002u


#define B1553_REG_CONF3                     0x0007u


#define B1553_REG_CONF4                     0x0008u


#define B1553_REG_CONF5                     0x0009u


#define B1553_REG_INT_MASK                  0x0000u


#define B1553_REG_INT_ST                    0x0006u


#define B1553_REG_MT_DAT_STK_PTR            0x000Au


#define B1553_REG_MT_TRIGGER_WORD           0x000Du


#define B1553_REG_RT_BITW                   0x000Fu


#define B1553_REG_RT_DAT_STK_PTR            0x000Au


#define B1553_REG_RT_LAST_CMD               0x000Du


#define B1553_REG_RT_SA_CTRW                0x0004u


#define B1553_REG_RT_STW                    0x000Eu


#define B1553_REG_START_RST                 0x0003u


#define B1553_REG_TIME_TAG                  0x0005u


#define B1553_RESP_TIMEOUT_1300         3u


#define B1553_RESP_TIMEOUT_185          0u


#define B1553_RESP_TIMEOUT_225          1u


#define B1553_RESP_TIMEOUT_505          2u


#define B1553_RT_BROAD                      2u


#define B1553_RT_DBLBUF                     3u


#define B1553_RT_RECV                       0u


#define B1553_RT_TRAN                       1u


#define B1553_TIMETAG_02us          0x5u


#define B1553_TIMETAG_04us          0x4u


#define B1553_TIMETAG_08us          0x3u


#define B1553_TIMETAG_16us          0x2u


#define B1553_TIMETAG_32us          0x1u


#define B1553_TIMETAG_64us          0x0u


#define B1553_WRITE(offno, val32, addrbase) \
            ADDR_WRITE(((addrbase) + ((offno) << 2u)), ((val32) & 0xFFFF))


#define BALANCE_ERROR        0x22222222


#define BALANCE_NO           0x00000000


#define BALANCE_RIGHT        0x11111111


#define BC_BLKSTW_D00_INV_WORD          0x0001


#define BC_BLKSTW_D01_INC_SYNC_TYPE     0x0002


#define BC_BLKSTW_D02_WORD_CNT_ERR      0x0004


#define BC_BLKSTW_D03_WRONG_ST_ADDR     0x0008


#define BC_BLKSTW_D04_GOOD_DATA_TRANS   0x0010


#define BC_BLKSTW_D05_RETRY_CNT0        0x0020


#define BC_BLKSTW_D06_RETRY_CNT1        0x0040


#define BC_BLKSTW_D07_MASKED_ST_SET     0x0080


#define BC_BLKSTW_D08_LOOP_FAIL         0x0100


#define BC_BLKSTW_D09_NO_RESP           0x0200


#define BC_BLKSTW_D10_FORMAT_ERROR      0x0400


#define BC_BLKSTW_D11_ST_SET            0x0800


#define BC_BLKSTW_D12_ERR_FLAG          0x1000


#define BC_BLKSTW_D13_CHNEL_B1_A0       0x2000


#define BC_BLKSTW_D14_SOM               0x4000


#define BC_BLKSTW_D15_EOM               0x8000


#define BC_CTW_D00_RT2RT_FORMAT         0x0001


#define BC_CTW_D01_BRD_FORMAT           0x0002


#define BC_CTW_D02_MODE_FORMAT          0x0004


#define BC_CTW_D03_1553AB_SELE          0x0008


#define BC_CTW_D04_EOMINT_EN            0x0010


#define BC_CTW_D05_BRDCAST_MASK         0x0020


#define BC_CTW_D06_OFF_TEST             0x0040


#define BC_CTW_D07_CHNL_AB              0x0080


#define BC_CTW_D08_RETRY_EN             0x0100


#define BC_CTW_D09_REVDFLG_MASK         0x0200


#define BC_CTW_D10_TERFLG_MASK          0x0400


#define BC_CTW_D11_SUBFLG_MASK          0x0800


#define BC_CTW_D12_SUBBUSY_MASK         0x1000


#define BC_CTW_D13_SERACQ_MASK          0x2000


#define BC_CTW_D14_MSGERR_MASK          0x4000


#define BC_CTW_D15_RESERVED             0x8000


#define BC_MEM_CMDSTACK_PTR_A           0x0100


#define BC_MEM_CMDSTACK_PTR_A_INI       0x0102


#define BC_MEM_CMDSTACK_PTR_B           0x0104


#define BC_MEM_CMDSTACK_PTR_B_INI       0x0106


#define BC_MEM_MSGCNT_PTR_A             0x0101


#define BC_MEM_MSGCNT_PTR_A_INI         0x0103


#define BC_MEM_MSGCNT_PTR_B             0x0105


#define BC_MEM_MSGCNT_PTR_B_INI         0x0107


#define BC_STACK_MSG_MAX                64u


#define BHDR_OVERHEAD	(0x10 - MIN_BLOCK_SIZE)


#define BIT_CLR(uv, bp, mask)           ((uv) = (uv) & ((0x01u << (bp)) ^ (mask)))


#define BIT_GET(uv, bp)                 (((uv) >> (bp)) & 0x01u)


#define BIT_SET(uv, bp, mask)           ((uv) = (uv) | ((0x01u << (bp)) & (mask)))


#define BLOCK_ALIGN		(0x8)


#define BLOCK_SIZE		(0xFFFFFFFF - PTR_MASK)


#define BLOCK_STATE	(0x1)


#define BSPGPICNFR_INIT				((GPI0_CFG << 0)|	\
								 								(GPI1_CFG << 1)|	\
								 								(GPI2_CFG << 2)|	\
								 								(GPI3_CFG << 3)|	\
								 								(GPI4_CFG << 4)|	\
								 								(GPI5_CFG << 5)|	\
								 								(GPI6_CFG << 6)|	\
								 								(GPI7_CFG << 7)|	\
								 								(GPI8_CFG << 8)|	\
								 								(GPI9_CFG << 9)|	\
								 								(GPI10_CFG << 10)|	\
								 								(GPI11_CFG << 11)|	\
								 								(GPI12_CFG << 12)|	\
								 								(GPI13_CFG << 13)|	\
								 								(GPI14_CFG << 14)|	\
								 								(GPI15_CFG << 15)|	\
								 								(GPI16_CFG << 16)|	\
								 								(GPI17_CFG << 17)|	\
								 								(GPI18_CFG << 18)|	\
								 								(GPI19_CFG << 19)|	\
								 								(GPI20_CFG << 20)|	\
								 								(GPI21_CFG << 21)|	\
								 								(GPI22_CFG << 22)|	\
								 								(GPI23_CFG << 23)|	\
								 								(GPI24_CFG << 24)|	\
								 								(GPI25_CFG << 25)|	\
								 								(GPI26_CFG << 26)|	\
								 								(GPI27_CFG << 27)|	\
								 								(GPI28_CFG << 28)|	\
								 								(GPI29_CFG << 29)|	\
								 								(GPI30_CFG << 30)|	\
								 								(GPI31_CFG << 31))


#define BSPGPIINT_EN_INIT			((INT_EXINT3_GPI << INT_EXINT3_SOURCE)|	\
								 								(INT_EXINT2_GPI << INT_EXINT2_SOURCE)|	\
								 								(INT_EXINT1_GPI << INT_EXINT1_SOURCE)|	\
								 								(INT_EXINT0_GPI << INT_EXINT0_SOURCE))


#define BSPGPIINT_POLA_INIT			((INT_EXINT3_TRIG_POLARITY << INT_EXINT3_SOURCE)|	\
								 								(INT_EXINT2_TRIG_POLARITY << INT_EXINT2_SOURCE)|	\
								 								(INT_EXINT1_TRIG_POLARITY << INT_EXINT1_SOURCE)|	\
								 								(INT_EXINT0_TRIG_POLARITY << INT_EXINT0_SOURCE))


#define BSPGPIINT_TRIG_INIT			((INT_EXINT3_TRIG_MODE << INT_EXINT3_SOURCE)|	\
								 								(INT_EXINT2_TRIG_MODE << INT_EXINT2_SOURCE)|	\
								 								(INT_EXINT1_TRIG_MODE << INT_EXINT1_SOURCE)|	\
								 								(INT_EXINT0_TRIG_MODE << INT_EXINT0_SOURCE))


#define BSPINTCLR_INIT				(0xFFFE)


#define BSPINTMKR_INIT				(0x0000)


#define BSPUART2CTRl_INIT			((COM2_FIFODEBUG_ENABLE<<11)|		\
																(COM2_RFIFOINT_ENABLE<<10)|\
																(COM2_WFIFOINT_ENABLE<<9)|	\
																(COM2_EC << 8)|				\
																(COM2_LB<<7)|				\
																(COM2_FL<<6)|				\
																((COM2_PARITY_ENABLE)<<5)|	\
																(COM2_PARITY_SELECT<<4)|	\
																(COM2_WINT_ENABLE<<3)|		\
																(COM2_RINT_ENABLE<<2)|		\
																(COM2_W_ENABLE<<1)|		\
																(COM2_R_ENABLE))


#define BSP_EEPROM_NULL							(0xE0000000)


#define BSP_FAIL_ADDR_REG					(0xf04)


#define BSP_INTBROD					(0x0240)


#define BSP_NORFLASH		(BSP_NORFLASH_ENABLE_VALUE | 0xF0000000)


#define BSP_Prog1_ROMType						(BSP_NORFLASH)


#define BSP_Prog2_ROMType						(BSP_NORFLASH)


#define BSP_Prog3_ROMType						(BSP_EEPROM_A)


#define BSP_Prog_SRAM_Flag					(0x3)


#define BSP_ROM_ProgNum							(0x2)


#define CHECK_MORE_TICK (2)  //作为余量，用来计算关闭单脉冲的时间，可自行设置


#define CMD_BUF_LEN  513


#define CMGE_SG42_2_2_H


#define CNT_PLACES_CRI_DATA_SAVE   2


#define CORE0_PERIOD_N							(1)


#define CORE1_PERIOD_N							(1)


#define CORE2_PERIOD_N							(1)


#define CORE3_PERIOD_N							(1)


#define COUNTER_DN(pre, cur, mask, zero)        ( ((pre) >= (cur)) ? ((pre) - (cur)) : ((mask) - ((cur) - (pre)) + (zero)) )


#define COUNTER_UP(pre, cur, mask, zero)        ( ((cur) >= (pre)) ? ((cur) - (pre)) : ((mask) - ((pre) - (cur)) + (zero)) )


#define CRI_DATA_RECV_FAIL         0xAAAAAAAA


#define CRI_DATA_RECV_FAULT        0xFFFFFFFF


#define CRI_DATA_RECV_ING          0x00000000


#define CRI_DATA_RECV_SUB_FAIL   0xAAAAAAAA


#define CRI_DATA_RECV_SUB_ING    0x00000000


#define CRI_DATA_RECV_SUB_SUCC   0x55555555


#define CRI_DATA_RECV_SUCC         0x55555555


#define CRI_DATA_RECV_TYPE1        0x00000000


#define CRI_DATA_RECV_TYPE2        0x55555555


#define CS_Bit 								(12)


#define CS_MEMMAINTAINH_H


#define CS_MEMMAINTAIN_H


#define CS_MEM_MAINTAIN_CUR_MAX_LEN32         (128)


#define CS_MEM_MAINTAIN_DOWN_MAX_LEN32        (512)


#define CS_MEM_MAINTAIN_INJ_MAX_LEN32  (512)


#define CS_MEM_MAINTAIN_UPLOAD_MAX_LEN32      (512)


#define CTRL_BASE_H


#define CTRL_H


#define CTRL_SADA_H


#define CTRL_THRUSTER_H


#define CTRL_WHEEL_H


#define CTU_ADDR_BM4802         0x20100000


#define CTU_ADDR_BM4802_CH1            (CTU_ADDR_BM4802 + (0x10<<2))


#define CTU_ADDR_BM4802_CH2            (CTU_ADDR_BM4802 + (0x30<<2))


#define CTU_ADDR_BM4802_CH3            (CTU_ADDR_BM4802 + (0x50<<2))


#define CTU_RX_START_ADDR1		0x20602000


#define CTU_RX_START_ADDR2		0x20702000


#define CTU_TX_START_ADDR1		0x20600000


#define CTU_TX_START_ADDR2		0x20700000


#define C_PARTS_OPR_H


#define Ceilx(x)        (ceil((float64)(x))               )


#define Cosx(x)         (cos((float64)(x))                )


#define DBL_TO_SI16(x)                  ((unint16)(siint32)(x))


#define DBL_TO_SI32(x)                  ((unint32)(siint32)(x))


#define DBL_TO_SI64(x)                  ((ulong64)((llong64)(x)))


#define DBL_TO_UN08(x)                  ((unint08)(llong64)(x))


#define DBL_TO_UN16(x)                  ((unint16)(llong64)(x))


#define DBL_TO_UN32(x)                  ((unint32)(llong64)(x))


#define DBL_TO_UN64(x)                  ((ulong64)(llong64)(x))


#define DEV_HEALTH              0x00


#define DEV_INVALID             0x00


#define DEV_NO_HEALTH           0xFF


#define DEV_ONDUTY              0xFF


#define DEV_POWERON             0xFF


#define DRVNANDFLASH_H


#define DRV_AD0_CIRCLE  (DRVUSED)


#define DRV_AD0_IOBASE  (DRVIOBASE1)


#define DRV_AD0_MASK   (0xfff) //12位AD


#define DRV_AD0_MAX   (5.0f) //最大值5V


#define DRV_AD0_MIN   (0.0f) //最小值0V


#define DRV_AD0_MODE   (DRV_AD_SPI_MODE)


#define DRV_AD0_NUMBER   (96) //采集路数


#define DRV_AD1_CIRCLE  (DRVUNUSED)


#define DRV_AD1_IOBASE  (DRVIOBASE2)


#define DRV_AD1_MASK   (0xfff)


#define DRV_AD1_MAX   (5.0f)


#define DRV_AD1_MIN   (0.0f)


#define DRV_AD1_MODE   (DRV_AD_SPI_MODE)


#define DRV_AD1_NUMBER   (32)


#define DRV_AD2_CIRCLE  (DRVUNUSED)


#define DRV_AD2_IOBASE  (DRVIOBASE1)


#define DRV_AD2_MASK   (0xfff)


#define DRV_AD2_MAX   (5.0f)


#define DRV_AD2_MIN   (0.0f)


#define DRV_AD2_MODE   (0)


#define DRV_AD2_NUMBER   (32)


#define DRV_AD3_CIRCLE  (DRVUNUSED)


#define DRV_AD3_IOBASE  (DRVIOBASE1)


#define DRV_AD3_MASK   (0xfff)


#define DRV_AD3_MAX   (5.0f)


#define DRV_AD3_MIN   (0.0f)


#define DRV_AD3_MODE   (0)


#define DRV_AD3_NUMBER   (32)


#define DRV_AD_CIRCLE_AGR  (0x100)  //256us


#define DRV_AD_CIRCLE_AGR_ADDR     0x1C


#define DRV_AD_ENSTART_ADDR     0x14


#define DRV_AD_FRE_ADDR         0x0


#define DRV_AD_GRADE   (0xfff)


#define DRV_AD_NUM					(1)//使用AD采集功能的A6017数量//PM


#define DRV_AD_NUM_LIMIT (4)


#define DRV_AD_READ_ADDR   0x200


#define DRV_AD_SINGLENUM_ADDR   0x20


#define DRV_AD_SINGLE_ADNUM   (16) //16


#define DRV_AD_SPI_ADDR   0x9000


#define DRV_AD_SPI_FRE  (0x5)


#define DRV_AD_SPI_MODE (1)  //SPI采集


#define DRV_AD_SSI_MODE (0) //同步串口控制


#define DRV_AD_SSI_NO1  (62)


#define DRV_AD_SSI_NO2  (63)


#define DRV_AD_SSI_NO3  (0)


#define DRV_AD_SSI_NO4  (0)


#define DRV_AD_SSI_WIDTH (100)


#define DRV_AD_SUMNUM_ADDR      0x24


#define DRV_AD_SWITCH_TIME (0x100) //256us


#define DRV_AD_SWITCH_TIME_ADDR 0x18


#define DRV_AD_TYPE					DRVUSED//AD功能


#define DRV_AD_WRIDATA_ADDR0   0x28


#define DRV_AD_WRIDATA_ADDR1   0x2c


#define DRV_BIT_DIR_ADDR            (0x00) //D(15:0)对应GPIO(15:0)


#define DRV_BIT_FILWID_ADDR          (0x1c)  //滤波长度GPIO(7:0)


#define DRV_BIT_FILWID_ADDR_GPIO16   (0x24)  //滤波长度GPIO(23:16)


#define DRV_BIT_FILWID_ADDR_GPIO24   (0x28)  //滤波长度GPIO(31:24)


#define DRV_BIT_FILWID_ADDR_GPIO32   (0x2C)  //滤波长度GPIO(39:32)


#define DRV_BIT_FILWID_ADDR_GPIO40   (0x30)  //滤波长度GPIO(47:40)


#define DRV_BIT_FILWID_ADDR_GPIO48   (0x34)  //滤波长度GPIO(55:48)


#define DRV_BIT_FIL_0_ADDR          (0x14)  //D(1:0):GPIO(7:0)滤波当量选择，D(3:2):GPIO(15:8)滤波当量选择，以此类推


#define DRV_BIT_FIL_1_ADDR          (0x18)  //D(1:0):GPIO(71:64)滤波当量选择，D(3:2):GPIO(79:72)滤波当量选择


#define DRV_BIT_IN0_GATHER   DRV_BITIN_IO_GPIO


#define DRV_BIT_IN0_IOBASE   DRVIOBASE2


#define DRV_BIT_IN0_NUMGPIO   (0)


#define DRV_BIT_IN0_REV   DRVUNREV


#define DRV_BIT_IN10_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN10_IOBASE   DRVIOBASE2


#define DRV_BIT_IN10_NUMGPIO   (10)


#define DRV_BIT_IN10_REV   DRVUNREV


#define DRV_BIT_IN11_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN11_IOBASE   DRVIOBASE2


#define DRV_BIT_IN11_NUMGPIO   (11)


#define DRV_BIT_IN11_REV   DRVUNREV


#define DRV_BIT_IN12_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN12_IOBASE   DRVIOBASE2


#define DRV_BIT_IN12_NUMGPIO   (12)


#define DRV_BIT_IN12_REV   DRVUNREV


#define DRV_BIT_IN13_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN13_IOBASE   DRVIOBASE2


#define DRV_BIT_IN13_NUMGPIO   (13)


#define DRV_BIT_IN13_REV   DRVUNREV


#define DRV_BIT_IN14_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN14_IOBASE   DRVIOBASE2


#define DRV_BIT_IN14_NUMGPIO   (14)


#define DRV_BIT_IN14_REV   DRVUNREV


#define DRV_BIT_IN15_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN15_IOBASE   DRVIOBASE2


#define DRV_BIT_IN15_NUMGPIO   (15)


#define DRV_BIT_IN15_REV   DRVUNREV


#define DRV_BIT_IN16_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN16_IOBASE   DRVIOBASE2


#define DRV_BIT_IN16_NUMGPIO   (24)


#define DRV_BIT_IN16_REV   DRVUNREV


#define DRV_BIT_IN17_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN17_IOBASE   DRVIOBASE2


#define DRV_BIT_IN17_NUMGPIO   (25)


#define DRV_BIT_IN17_REV   DRVUNREV


#define DRV_BIT_IN18_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN18_IOBASE   DRVIOBASE2


#define DRV_BIT_IN18_NUMGPIO   (26)


#define DRV_BIT_IN18_REV   DRVUNREV


#define DRV_BIT_IN19_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN19_IOBASE   DRVIOBASE3


#define DRV_BIT_IN19_NUMGPIO   (0)


#define DRV_BIT_IN19_REV   DRVUNREV


#define DRV_BIT_IN1_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN1_IOBASE   DRVIOBASE2


#define DRV_BIT_IN1_NUMGPIO   (1)


#define DRV_BIT_IN1_REV   DRVUNREV


#define DRV_BIT_IN20_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN20_IOBASE   DRVIOBASE3


#define DRV_BIT_IN20_NUMGPIO   (1)


#define DRV_BIT_IN20_REV   DRVUNREV


#define DRV_BIT_IN21_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN21_IOBASE   DRVIOBASE3


#define DRV_BIT_IN21_NUMGPIO   (2)


#define DRV_BIT_IN21_REV   DRVUNREV


#define DRV_BIT_IN22_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN22_IOBASE   DRVIOBASE3


#define DRV_BIT_IN22_NUMGPIO   (3)


#define DRV_BIT_IN22_REV   DRVUNREV


#define DRV_BIT_IN23_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN23_IOBASE   DRVIOBASE3


#define DRV_BIT_IN23_NUMGPIO   (4)


#define DRV_BIT_IN23_REV   DRVUNREV


#define DRV_BIT_IN24_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN24_IOBASE   DRVIOBASE3


#define DRV_BIT_IN24_NUMGPIO   (5)


#define DRV_BIT_IN24_REV   DRVUNREV


#define DRV_BIT_IN25_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN25_IOBASE   DRVIOBASE3


#define DRV_BIT_IN25_NUMGPIO   (6)


#define DRV_BIT_IN25_REV   DRVUNREV


#define DRV_BIT_IN26_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN26_IOBASE   DRVIOBASE3


#define DRV_BIT_IN26_NUMGPIO   (7)


#define DRV_BIT_IN26_REV   DRVUNREV


#define DRV_BIT_IN27_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN27_IOBASE   DRVIOBASE3


#define DRV_BIT_IN27_NUMGPIO   (8)


#define DRV_BIT_IN27_REV   DRVUNREV


#define DRV_BIT_IN28_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN28_IOBASE   DRVIOBASE3


#define DRV_BIT_IN28_NUMGPIO   (9)


#define DRV_BIT_IN28_REV   DRVUNREV


#define DRV_BIT_IN29_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN29_IOBASE   DRVIOBASE3


#define DRV_BIT_IN29_NUMGPIO   (10)


#define DRV_BIT_IN29_REV   DRVUNREV


#define DRV_BIT_IN2_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN2_IOBASE   DRVIOBASE2


#define DRV_BIT_IN2_NUMGPIO   (2)


#define DRV_BIT_IN2_REV   DRVUNREV


#define DRV_BIT_IN30_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN30_IOBASE   DRVIOBASE3


#define DRV_BIT_IN30_NUMGPIO   (11)


#define DRV_BIT_IN30_REV   DRVUNREV


#define DRV_BIT_IN31_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN31_IOBASE   DRVIOBASE3


#define DRV_BIT_IN31_NUMGPIO   (12)


#define DRV_BIT_IN31_REV   DRVUNREV


#define DRV_BIT_IN32_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN32_IOBASE   DRVIOBASE3


#define DRV_BIT_IN32_NUMGPIO   (13)


#define DRV_BIT_IN32_REV   DRVUNREV


#define DRV_BIT_IN33_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN33_IOBASE   DRVIOBASE3


#define DRV_BIT_IN33_NUMGPIO   (14)


#define DRV_BIT_IN33_REV   DRVUNREV


#define DRV_BIT_IN34_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN34_IOBASE   DRVIOBASE3


#define DRV_BIT_IN34_NUMGPIO   (15)


#define DRV_BIT_IN34_REV   DRVUNREV


#define DRV_BIT_IN35_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN35_IOBASE   DRVIOBASE3


#define DRV_BIT_IN35_NUMGPIO   (38)


#define DRV_BIT_IN35_REV   DRVUNREV


#define DRV_BIT_IN36_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN36_IOBASE   DRVIOBASE3


#define DRV_BIT_IN36_NUMGPIO   (39)


#define DRV_BIT_IN36_REV   DRVUNREV


#define DRV_BIT_IN37_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN37_IOBASE   DRVIOBASE3


#define DRV_BIT_IN37_NUMGPIO   (40)


#define DRV_BIT_IN37_REV   DRVUNREV


#define DRV_BIT_IN38_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN38_IOBASE   DRVIOBASE3


#define DRV_BIT_IN38_NUMGPIO   (41)


#define DRV_BIT_IN38_REV   DRVUNREV


#define DRV_BIT_IN39_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN39_IOBASE   DRVIOBASE3


#define DRV_BIT_IN39_NUMGPIO   (42)


#define DRV_BIT_IN39_REV   DRVUNREV


#define DRV_BIT_IN3_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN3_IOBASE   DRVIOBASE2


#define DRV_BIT_IN3_NUMGPIO   (3)


#define DRV_BIT_IN3_REV   DRVUNREV


#define DRV_BIT_IN40_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN40_IOBASE   DRVIOBASE3


#define DRV_BIT_IN40_NUMGPIO   (43)


#define DRV_BIT_IN40_REV   DRVUNREV


#define DRV_BIT_IN41_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN41_IOBASE   DRVIOBASE3


#define DRV_BIT_IN41_NUMGPIO   (44)


#define DRV_BIT_IN41_REV   DRVUNREV


#define DRV_BIT_IN42_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN42_IOBASE   DRVIOBASE3


#define DRV_BIT_IN42_NUMGPIO   (45)


#define DRV_BIT_IN42_REV   DRVUNREV


#define DRV_BIT_IN43_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN43_IOBASE   DRVIOBASE3


#define DRV_BIT_IN43_NUMGPIO   (46)


#define DRV_BIT_IN43_REV   DRVUNREV


#define DRV_BIT_IN44_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN44_IOBASE   DRVIOBASE3


#define DRV_BIT_IN44_NUMGPIO   (47)


#define DRV_BIT_IN44_REV   DRVUNREV


#define DRV_BIT_IN45_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN45_IOBASE   DRVIOBASE3


#define DRV_BIT_IN45_NUMGPIO   (56)


#define DRV_BIT_IN45_REV   DRVUNREV


#define DRV_BIT_IN46_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN46_IOBASE   DRVIOBASE3


#define DRV_BIT_IN46_NUMGPIO   (57)


#define DRV_BIT_IN46_REV   DRVUNREV


#define DRV_BIT_IN47_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN47_IOBASE   DRVIOBASE3


#define DRV_BIT_IN47_NUMGPIO   (58)


#define DRV_BIT_IN47_REV   DRVUNREV


#define DRV_BIT_IN48_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN48_IOBASE   DRVIOBASE3


#define DRV_BIT_IN48_NUMGPIO   (59)


#define DRV_BIT_IN48_REV   DRVUNREV


#define DRV_BIT_IN49_GATHER    DRV_BITIN_IO_PULSE


#define DRV_BIT_IN49_IOBASE   DRVIOBASE1


#define DRV_BIT_IN49_NUMGPIO   (0)


#define DRV_BIT_IN49_REV   DRVUNREV


#define DRV_BIT_IN4_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN4_IOBASE   DRVIOBASE2


#define DRV_BIT_IN4_NUMGPIO   (4)


#define DRV_BIT_IN4_REV   DRVUNREV


#define DRV_BIT_IN50_GATHER    DRV_BITIN_IO_PULSE


#define DRV_BIT_IN50_IOBASE   DRVIOBASE1


#define DRV_BIT_IN50_NUMGPIO   (1)


#define DRV_BIT_IN50_REV   DRVUNREV


#define DRV_BIT_IN51_GATHER    DRV_BITIN_IO_PULSE


#define DRV_BIT_IN51_IOBASE   DRVIOBASE1


#define DRV_BIT_IN51_NUMGPIO   (2)


#define DRV_BIT_IN51_REV   DRVUNREV


#define DRV_BIT_IN52_GATHER    DRV_BITIN_IO_PULSE


#define DRV_BIT_IN52_IOBASE   DRVIOBASE1


#define DRV_BIT_IN52_NUMGPIO   (3)


#define DRV_BIT_IN52_REV   DRVUNREV


#define DRV_BIT_IN53_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN53_IOBASE   DRVIOBASE1


#define DRV_BIT_IN53_NUMGPIO   (0)


#define DRV_BIT_IN53_REV   DRVUNREV


#define DRV_BIT_IN54_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN54_IOBASE   DRVIOBASE1


#define DRV_BIT_IN54_NUMGPIO   (1)


#define DRV_BIT_IN54_REV   DRVUNREV


#define DRV_BIT_IN55_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN55_IOBASE   DRVIOBASE1


#define DRV_BIT_IN55_NUMGPIO   (3)


#define DRV_BIT_IN55_REV   DRVUNREV


#define DRV_BIT_IN56_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN56_IOBASE   DRVIOBASE1


#define DRV_BIT_IN56_NUMGPIO   (5)


#define DRV_BIT_IN56_REV   DRVUNREV


#define DRV_BIT_IN57_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN57_IOBASE   DRVIOBASE1


#define DRV_BIT_IN57_NUMGPIO   (7)


#define DRV_BIT_IN57_REV   DRVUNREV


#define DRV_BIT_IN5_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN5_IOBASE   DRVIOBASE2


#define DRV_BIT_IN5_NUMGPIO   (5)


#define DRV_BIT_IN5_REV   DRVUNREV


#define DRV_BIT_IN6_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN6_IOBASE   DRVIOBASE2


#define DRV_BIT_IN6_NUMGPIO   (6)


#define DRV_BIT_IN6_REV   DRVUNREV


#define DRV_BIT_IN7_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN7_IOBASE   DRVIOBASE2


#define DRV_BIT_IN7_NUMGPIO   (7)


#define DRV_BIT_IN7_REV   DRVUNREV


#define DRV_BIT_IN8_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN8_IOBASE   DRVIOBASE2


#define DRV_BIT_IN8_NUMGPIO   (8)


#define DRV_BIT_IN8_REV   DRVUNREV


#define DRV_BIT_IN9_GATHER    DRV_BITIN_IO_GPIO


#define DRV_BIT_IN9_IOBASE   DRVIOBASE2


#define DRV_BIT_IN9_NUMGPIO   (9)


#define DRV_BIT_IN9_REV   DRVUNREV


#define DRV_BIT_IN_ADDR            (0x44) //位口采集GPIO(15:0)


#define DRV_BIT_IN_FILTER_WIDTH  (1000)//位口采集滤波宽度1000us


#define DRV_BIT_IN_GPS_WIDTH  (1000000)//gps秒脉冲周期1s//在Drv_Bit_In_Struct_Init设置有效时间时对该值加200000


#define DRV_BIT_IN_NUM				(53)//位口输入路数		//IO1:19、IO2:30、PM:4


#define DRV_BIT_IN_NUM_LIMIT    (58)//位输入58路


#define DRV_BIT_IN_SYN_SOURCE_WIDTH  (1000000)//所有同步信号的周期最大值


#define DRV_BIT_IN_TYPE				DRVUSED//位口采集


#define DRV_BIT_OUT0_INIT   DRVHIGH


#define DRV_BIT_OUT0_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT0_NUMGPIO   (72)


#define DRV_BIT_OUT0_REV   DRVUNREV


#define DRV_BIT_OUT10_INIT   DRVHIGH


#define DRV_BIT_OUT10_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT10_NUMGPIO   (42)


#define DRV_BIT_OUT10_REV   DRVUNREV


#define DRV_BIT_OUT11_INIT   DRVHIGH


#define DRV_BIT_OUT11_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT11_NUMGPIO   (43)


#define DRV_BIT_OUT11_REV   DRVUNREV


#define DRV_BIT_OUT12_INIT   DRVHIGH


#define DRV_BIT_OUT12_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT12_NUMGPIO   (44)


#define DRV_BIT_OUT12_REV   DRVUNREV


#define DRV_BIT_OUT13_INIT   DRVHIGH


#define DRV_BIT_OUT13_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT13_NUMGPIO   (45)


#define DRV_BIT_OUT13_REV   DRVUNREV


#define DRV_BIT_OUT14_INIT   DRVHIGH


#define DRV_BIT_OUT14_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT14_NUMGPIO   (46)


#define DRV_BIT_OUT14_REV   DRVUNREV


#define DRV_BIT_OUT15_INIT   DRVHIGH


#define DRV_BIT_OUT15_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT15_NUMGPIO   (47)


#define DRV_BIT_OUT15_REV   DRVUNREV


#define DRV_BIT_OUT16_INIT   DRVHIGH


#define DRV_BIT_OUT16_IOBASE  DRVIOBASE2


#define DRV_BIT_OUT16_NUMGPIO   (33)


#define DRV_BIT_OUT16_REV   DRVUNREV


#define DRV_BIT_OUT17_INIT   DRVHIGH


#define DRV_BIT_OUT17_IOBASE  DRVIOBASE2


#define DRV_BIT_OUT17_NUMGPIO   (34)


#define DRV_BIT_OUT17_REV   DRVUNREV


#define DRV_BIT_OUT18_INIT   DRVHIGH


#define DRV_BIT_OUT18_IOBASE  DRVIOBASE2


#define DRV_BIT_OUT18_NUMGPIO   (35)


#define DRV_BIT_OUT18_REV   DRVUNREV


#define DRV_BIT_OUT19_INIT   DRVHIGH


#define DRV_BIT_OUT19_IOBASE  DRVIOBASE2


#define DRV_BIT_OUT19_NUMGPIO   (36)


#define DRV_BIT_OUT19_REV   DRVUNREV


#define DRV_BIT_OUT1_INIT   DRVHIGH


#define DRV_BIT_OUT1_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT1_NUMGPIO   (73)


#define DRV_BIT_OUT1_REV   DRVUNREV


#define DRV_BIT_OUT20_INIT   DRVHIGH


#define DRV_BIT_OUT20_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT20_NUMGPIO   (72)


#define DRV_BIT_OUT20_REV   DRVUNREV


#define DRV_BIT_OUT2_INIT   DRVHIGH


#define DRV_BIT_OUT2_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT2_NUMGPIO   (34)


#define DRV_BIT_OUT2_REV   DRVUNREV


#define DRV_BIT_OUT3_INIT   DRVHIGH


#define DRV_BIT_OUT3_IOBASE   DRVIOBASE1


#define DRV_BIT_OUT3_NUMGPIO   (35)


#define DRV_BIT_OUT3_REV   DRVUNREV


#define DRV_BIT_OUT4_INIT   DRVHIGH


#define DRV_BIT_OUT4_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT4_NUMGPIO   (36)


#define DRV_BIT_OUT4_REV   DRVUNREV


#define DRV_BIT_OUT5_INIT   DRVHIGH


#define DRV_BIT_OUT5_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT5_NUMGPIO   (37)


#define DRV_BIT_OUT5_REV   DRVUNREV


#define DRV_BIT_OUT6_INIT   DRVHIGH


#define DRV_BIT_OUT6_IOBASE   DRVIOBASE1


#define DRV_BIT_OUT6_NUMGPIO   (38)


#define DRV_BIT_OUT6_REV   DRVUNREV


#define DRV_BIT_OUT7_INIT   DRVHIGH


#define DRV_BIT_OUT7_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT7_NUMGPIO   (39)


#define DRV_BIT_OUT7_REV   DRVUNREV


#define DRV_BIT_OUT8_INIT   DRVHIGH


#define DRV_BIT_OUT8_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT8_NUMGPIO   (40)


#define DRV_BIT_OUT8_REV   DRVUNREV


#define DRV_BIT_OUT9_INIT   DRVHIGH


#define DRV_BIT_OUT9_IOBASE  DRVIOBASE1


#define DRV_BIT_OUT9_NUMGPIO   (41)


#define DRV_BIT_OUT9_REV   DRVUNREV


#define DRV_BIT_OUT_ADDR            (0x188) //位口状态GPIO(15:0)


#define DRV_BIT_OUT_NUM				(2)//位口输出路数	//2路位口输出都只适用于电性件	//PM:2，模样冒脉冲改，第2路仅在初始化时使用


#define DRV_BIT_OUT_NUM_LIMIT     (21)//位输出21路


#define DRV_BIT_OUT_TYPE			DRVUNUSED//位口输出


#define DRV_BIT_OUT_TYPE			DRVUSED//位口输出


#define DRV_BIT_SELOUT_ADDR          (0x180) //D(15:0)对应GPIO(63:48)


#define DRV_BUS_BUSRDY_ADDR(i)    (0x600+0x4*(i))


#define DRV_BUS_IOBASE  DRVIOBASE1


#define DRV_BUS_IO_ADDR    0x400


#define DRV_BUS_NCS0_ADDR(i)    (0x20000+0x4*(i))


#define DRV_BUS_NCS1_ADDR(i)    (0x28000+0x4*(i))


#define DRV_BUS_NCS2_ADDR(i)    (0x30000+0x4*(i))


#define DRV_BUS_NCS3_ADDR(i)    (0x38000+0x4*(i))


#define DRV_BUS_READY (6)


#define DRV_BUS_TIME (2)


#define DRV_BUS_TYPE				DRVUSED//总线桥接功能


#define DRV_CAN1_BASEADDRA               (0x1400)


#define DRV_CAN1_BASEADDRB               (0x1800)


#define DRV_CAN1_BASE_ADDR                (0x1C00)


#define DRV_CAN1_USED   DRVUSED


#define DRV_CAN2_BASEADDRA               (0x4000)


#define DRV_CAN2_BASEADDRB               (0x4400)


#define DRV_CAN2_BASE_ADDR                (0x4800)


#define DRV_CAN2_USED   DRVUNUSED


#define DRV_CAN_INT1_NO   (1)


#define DRV_CAN_INT2_NO   (0)


#define DRV_CAN_INT_MODE   DRV_INT_EDGE_TRIG


#define DRV_CAN_IOBASE   DRVIOBASE1


#define DRV_CAN_RESET_TIME   (10)


#define DRV_CAN_TYPE				DRVUNUSED//CAN总线


#define DRV_CLK_FRE					(DRV_CLK_20M)


#define DRV_CLK_FRE_IO1				(DRV_CLK_FRE)//(DRVFALSE)//IO1板频率为20M，不能用DRVFALSE，静态分析报除零


#define DRV_CLK_FRE_M				(20)//20或100,要和DRV_CLK_FRE的配置一致。用于配置八通道频率采集看门狗时间


#define DRV_COUNT0_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT0_IOBASE   DRVIOBASE2


#define DRV_COUNT0_MODE   (48)//GPIO<48>锁存//DRV_COUNT_SOFT_MODE软件锁存，DRV_COUNT_CTRL_MODE控制周期锁存，其他 GPIO锁存(数值为GPIO号)


#define DRV_COUNT0_NUMGPIO   (16)


#define DRV_COUNT10_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT10_IOBASE   DRVIOBASE3


#define DRV_COUNT10_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT10_NUMGPIO   (20)


#define DRV_COUNT11_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT11_IOBASE   DRVIOBASE3


#define DRV_COUNT11_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT11_NUMGPIO   (21)


#define DRV_COUNT12_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT12_IOBASE   DRVIOBASE3


#define DRV_COUNT12_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT12_NUMGPIO   (22)


#define DRV_COUNT13_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT13_IOBASE   DRVIOBASE3


#define DRV_COUNT13_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT13_NUMGPIO   (23)


#define DRV_COUNT14_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT14_IOBASE   DRVIOBASE3


#define DRV_COUNT14_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT14_NUMGPIO   (24)


#define DRV_COUNT15_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT15_IOBASE   DRVIOBASE3


#define DRV_COUNT15_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT15_NUMGPIO   (25)


#define DRV_COUNT16_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT16_IOBASE   DRVIOBASE3


#define DRV_COUNT16_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT16_NUMGPIO   (26)


#define DRV_COUNT17_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT17_IOBASE   DRVIOBASE3


#define DRV_COUNT17_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT17_NUMGPIO   (27)


#define DRV_COUNT18_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT18_IOBASE   DRVIOBASE3


#define DRV_COUNT18_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT18_NUMGPIO   (28)


#define DRV_COUNT19_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT19_IOBASE   DRVIOBASE3


#define DRV_COUNT19_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT19_NUMGPIO   (29)


#define DRV_COUNT1_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT1_IOBASE   DRVIOBASE2


#define DRV_COUNT1_MODE   (48)//GPIO<48>锁存


#define DRV_COUNT1_NUMGPIO   (17)


#define DRV_COUNT20_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT20_IOBASE   DRVIOBASE3


#define DRV_COUNT20_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT20_NUMGPIO   (30)


#define DRV_COUNT21_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT21_IOBASE   DRVIOBASE3


#define DRV_COUNT21_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT21_NUMGPIO   (31)


#define DRV_COUNT22_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT22_IOBASE   DRVIOBASE3


#define DRV_COUNT22_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT22_NUMGPIO   (32)


#define DRV_COUNT23_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT23_IOBASE   DRVIOBASE3


#define DRV_COUNT23_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT23_NUMGPIO   (33)


#define DRV_COUNT24_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT24_IOBASE   DRVIOBASE3


#define DRV_COUNT24_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT24_NUMGPIO   (34)


#define DRV_COUNT25_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT25_IOBASE   DRVIOBASE3


#define DRV_COUNT25_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT25_NUMGPIO   (35)


#define DRV_COUNT26_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT26_IOBASE   DRVIOBASE3


#define DRV_COUNT26_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT26_NUMGPIO   (36)


#define DRV_COUNT27_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT27_IOBASE   DRVIOBASE3


#define DRV_COUNT27_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT27_NUMGPIO   (37)


#define DRV_COUNT2_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT2_IOBASE   DRVIOBASE2


#define DRV_COUNT2_MODE   (48)//GPIO<48>锁存


#define DRV_COUNT2_NUMGPIO   (18)


#define DRV_COUNT3_EDGE DRV_COUNT_HIGH_MODE


#define DRV_COUNT3_IOBASE   DRVIOBASE2


#define DRV_COUNT3_MODE   (48)//GPIO<48>锁存


#define DRV_COUNT3_NUMGPIO   (19)


#define DRV_COUNT4_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT4_IOBASE   DRVIOBASE2


#define DRV_COUNT4_MODE   (48)//GPIO<48>锁存


#define DRV_COUNT4_NUMGPIO   (20)


#define DRV_COUNT5_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT5_IOBASE   DRVIOBASE2


#define DRV_COUNT5_MODE   (48)//GPIO<48>锁存


#define DRV_COUNT5_NUMGPIO   (21)


#define DRV_COUNT6_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT6_IOBASE   DRVIOBASE3


#define DRV_COUNT6_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT6_NUMGPIO   (16)


#define DRV_COUNT7_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT7_IOBASE   DRVIOBASE3


#define DRV_COUNT7_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT7_NUMGPIO   (17)


#define DRV_COUNT8_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT8_IOBASE   DRVIOBASE3


#define DRV_COUNT8_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT8_NUMGPIO   (18)


#define DRV_COUNT9_EDGE  DRV_COUNT_HIGH_MODE


#define DRV_COUNT9_IOBASE   DRVIOBASE3


#define DRV_COUNT9_MODE   DRV_COUNT_CTRL_MODE


#define DRV_COUNT9_NUMGPIO   (19)


#define DRV_COUNT_NUM				(28)//脉冲计数路数		//不使用


#define DRV_COUNT_NUM_LIMIT (28)


#define DRV_COUNT_TYPE				DRVUNUSED//脉冲采集


#define DRV_CSB_BAUD   (0xC)


#define DRV_CSB_CTRL   (0x0)


#define DRV_CSB_DATA   (0x4)


#define DRV_CSB_IOBASE   DRVIOBASE1


#define DRV_CSB_IOBASEA   (0x9400)


#define DRV_CSB_IOBASEB   (0x9600)


#define DRV_CSB_REV_FAIL    (0x3)//接收字节数不够一包(4字节)


#define DRV_CSB_REV_NULL    (0x1)   //发送参数无效


#define DRV_CSB_SEND_FAIL   (0x3)//发送fifo剩余字节数小于要发送的字节数


#define DRV_CSB_SEND_NULL    (0x1)   //发送参数无效


#define DRV_CSB_TMFIFO   (0x8)


#define DRV_CSB_TYPE				DRVUNUSED//CSB总线


#define DRV_DA0_IOBASE  (DRVIOBASE1)


#define DRV_DA0_NUMCHIP   (1)


#define DRV_DA0_NUMGPIO   (0)


#define DRV_DA10_IOBASE  (DRVIOBASE1)


#define DRV_DA10_NUMCHIP   (1)


#define DRV_DA10_NUMGPIO   (0)


#define DRV_DA11_IOBASE  (DRVIOBASE1)


#define DRV_DA11_NUMCHIP   (1)


#define DRV_DA11_NUMGPIO   (0)


#define DRV_DA12_IOBASE  (DRVIOBASE1)


#define DRV_DA12_NUMCHIP   (1)


#define DRV_DA12_NUMGPIO   (0)


#define DRV_DA13_IOBASE  (DRVIOBASE1)


#define DRV_DA13_NUMCHIP   (1)


#define DRV_DA13_NUMGPIO   (0)


#define DRV_DA1_IOBASE  (DRVIOBASE1)


#define DRV_DA1_NUMCHIP   (1)


#define DRV_DA1_NUMGPIO   (1)


#define DRV_DA2_IOBASE  (DRVIOBASE1)


#define DRV_DA2_NUMCHIP   (1)


#define DRV_DA2_NUMGPIO   (2)


#define DRV_DA3_IOBASE  (DRVIOBASE1)


#define DRV_DA3_NUMCHIP   (1)


#define DRV_DA3_NUMGPIO   (3)


#define DRV_DA4_IOBASE  (DRVIOBASE1)


#define DRV_DA4_NUMCHIP   (1)


#define DRV_DA4_NUMGPIO   (4)


#define DRV_DA5_IOBASE  (DRVIOBASE1)


#define DRV_DA5_NUMCHIP   (1)


#define DRV_DA5_NUMGPIO   (5)


#define DRV_DA6_IOBASE  (DRVIOBASE1)


#define DRV_DA6_NUMCHIP   (1)


#define DRV_DA6_NUMGPIO   (6)


#define DRV_DA7_IOBASE  (DRVIOBASE1)


#define DRV_DA7_NUMCHIP   (1)


#define DRV_DA7_NUMGPIO   (7)


#define DRV_DA8_IOBASE  (DRVIOBASE1)


#define DRV_DA8_NUMCHIP   (1)


#define DRV_DA8_NUMGPIO   (0)


#define DRV_DA9_IOBASE  (DRVIOBASE1)


#define DRV_DA9_NUMCHIP   (1)


#define DRV_DA9_NUMGPIO   (0)


#define DRV_DA_BUS_ADDRNUM   (0)


#define DRV_DA_BUS_MODE (2)


#define DRV_DA_CHIP_BITOUT_GPIO1 (0)


#define DRV_DA_CHIP_BITOUT_GPIO2 (1)


#define DRV_DA_CHIP_BITOUT_NO1 (8)


#define DRV_DA_CHIP_BITOUT_NO2 (9)


#define DRV_DA_CHIP_BITOUT_SUM (0)


#define DRV_DA_CHIP_RESETTIME  (50)


#define DRV_DA_DATA_REV DRVUNREV


#define DRV_DA_GPIO_CS  3


#define DRV_DA_GPIO_DATA  16


#define DRV_DA_GPIO_GPIO0  8


#define DRV_DA_GPIO_GPIO1  9


#define DRV_DA_GPIO_LS  10


#define DRV_DA_GPIO_MODE (1)


#define DRV_DA_LSCS_DELAY_TIME    1


#define DRV_DA_MASK (0xfff)


#define DRV_DA_MODE DRV_DA_SSI_MODE


#define DRV_DA_NUM					(8)//DA输出路数		//预留。同步串口模式


#define DRV_DA_NUM_LIMIT (14)


#define DRV_DA_SSI_BAUD (100000) //100Kbps


#define DRV_DA_SSI_CTRL_GPIO	(35)


#define DRV_DA_SSI_DELAY_TIME    200  //保证数据能发完，所以有个延迟，延迟的时间根据型号而定


#define DRV_DA_SSI_MODE (0)


#define DRV_DA_SSI_NO (9)


#define DRV_DA_TYPE					DRVUNUSED//DA功能(预留，未用)


#define DRV_DEFEND					DRVUSED//翻转防护措施


#define DRV_EIGHT_FRE_CLEARDOG     (20000)//清狗宽度20ms


#define DRV_EIGHT_FRE_CLEARDOG_ADDR         (0x3DC)//频率采集看门狗时间寄存器


#define DRV_EIGHT_FRE_COUNT_ADDR(i)         (0x3A0+0x4*(i))//频率采集数量寄存器


#define DRV_EIGHT_FRE_DATA_ADDR(i)          (0x380+0x4*(i))//频率采集计数寄存器


#define DRV_EIGHT_FRE_DELAY          (20000)//延时20ms


#define DRV_EIGHT_FRE_DELAY_ADDR            (0x3C4)//频率采集延时寄存器


#define DRV_EIGHT_FRE_EQU_ADDR                   (0x3CC)//频率采集当量寄存器


#define DRV_EIGHT_FRE_FIL_EQU_ADDR           (0x3D0)//频率采集滤波当量寄存器


#define DRV_EIGHT_FRE_FIL_WIDTH  (10000)//滤波宽度10us


#define DRV_EIGHT_FRE_FIL_WIDTH_ADDR         (0x3D4)//频率采集滤波宽度寄存器


#define DRV_EIGHT_FRE_INT_MODE   DRV_INT_EDGE_TRIG


#define DRV_EIGHT_FRE_INT_NO   (0)


#define DRV_EIGHT_FRE_IOBASE  DRVIOBASE3//IO2板


#define DRV_EIGHT_FRE_NUM                (8)//使用通道数


#define DRV_EIGHT_FRE_PERIOD         (150000) //周期150ms


#define DRV_EIGHT_FRE_PERIOD_ADDR           (0x3C0)//频率采集周期寄存器


#define DRV_EIGHT_FRE_RANGE          (120000)//宽度120ms


#define DRV_EIGHT_FRE_RANGE_ADDR            (0x3C8)//频率采集区间寄存器


#define DRV_EIGHT_FRE_START_ADDR                 (0x3D8)//频率采集启动寄存器


#define DRV_EIGHT_FRE_TYPE			DRVUSED//八通道频率采集功能


#define DRV_ERR_AD                            (0xF << 8)


#define DRV_ERR_AD_PASS_PARAMETER_NO                              (DRV_ERR_AD  | 0x1)


#define DRV_ERR_AD_STRUCT_MEMBER_MODE                          (DRV_ERR_AD  | 0x2)


#define DRV_ERR_BIT_IN                   (0x1 << 8)


#define DRV_ERR_BIT_IN_PASS_PARAMETER_NO                    (DRV_ERR_BIT_IN |  0x1)


#define DRV_ERR_BIT_IN_STRUCT_MEMBER_GATHER             (DRV_ERR_BIT_IN  | 0x2)


#define DRV_ERR_BIT_OUT                (0x2 << 8)


#define DRV_ERR_BIT_OUT_PASS_PARAMETER_NO                 (DRV_ERR_BIT_OUT |  0x1)


#define DRV_ERR_BIT_OUT_PASS_PARAMETER_VALUE             (DRV_ERR_BIT_OUT |  0x2)


#define DRV_ERR_BUS                            (0x12<< 8)


#define DRV_ERR_BUS_PASS_PARAMETER_ADDR                        (DRV_ERR_BUS  | 0x1)


#define DRV_ERR_CAN                       (0x4 << 8)


#define DRV_ERR_CAN_PASS_PARAMETER_BAUD                     (DRV_ERR_CAN |  0x2)


#define DRV_ERR_CAN_PASS_PARAMETER_NO                       (DRV_ERR_CAN |  0x1)


#define DRV_ERR_COUNT                      (0xB << 8)


#define DRV_ERR_COUNT_PASS_PARAMETER_NO                    (DRV_ERR_COUNT |  0x1)


#define DRV_ERR_CSB                        (0x8 << 8)


#define DRV_ERR_CSB_PASS_PARAMETER_NO                         (DRV_ERR_CSB |  0x1)


#define DRV_ERR_DA                            (0x10<< 8)


#define DRV_ERR_DA_DEFINE_MODE                                           (DRV_ERR_DA  | 0x2)


#define DRV_ERR_DA_PASS_PARAMETER_NO                              (DRV_ERR_DA  | 0x1)


#define DRV_ERR_INT                            (0x11<< 8)


#define DRV_ERR_INT_PASS_PARAMETER_ASICNO                         (DRV_ERR_INT  | 0x2)


#define DRV_ERR_INT_PASS_PARAMETER_INTNO                         (DRV_ERR_INT  | 0x1)


#define DRV_ERR_INT_PASS_PARAMETER_MODE                         (DRV_ERR_INT  | 0x3)


#define DRV_ERR_LATCH                      (0xC << 8)


#define DRV_ERR_LATCH_PASS_PARAMETER_NO                    (DRV_ERR_LATCH |  0x1)


#define DRV_ERR_POWER                   (0x5 << 8)


#define DRV_ERR_POWER_PASS_PARAMETER_ACTION              (DRV_ERR_POWER |  0x2)


#define DRV_ERR_POWER_PASS_PARAMETER_NO                    (DRV_ERR_POWER |  0x1)


#define DRV_ERR_PULSE                     (0xA << 8)


#define DRV_ERR_PULSE_PASS_PARAMETER_NO                    (DRV_ERR_PULSE |  0x1)


#define DRV_ERR_PULSE_PERIOD_WIDTH                     (0x13 << 8) // add by lcl


#define DRV_ERR_SET_ERRNO(errno)         do {DRVErrNo = (errno);  print2("\r\nDRVErrNo: 0x%x",DRVErrNo); } while(0)


#define DRV_ERR_SET_ERRNO(errno)         do {DRVErrNo = (errno);}while(0)


#define DRV_ERR_SPI                          (0xD << 8)


#define DRV_ERR_SPI_PASS_PARAMETER_NO                    (DRV_ERR_SPI |  0x1)


#define DRV_ERR_SSI                           (0xE << 8)


#define DRV_ERR_SSI_PASS_PARAMETER_MODE                    (DRV_ERR_SSI |  0x2)


#define DRV_ERR_SSI_PASS_PARAMETER_NO                    (DRV_ERR_SSI |  0x1)


#define DRV_ERR_SYN_SOURCE          (0x3 << 8)


#define DRV_ERR_SYN_SOURCE_PASS_PARAMETER_NO            (DRV_ERR_SYN_SOURCE |  0x1)


#define DRV_ERR_SYN_SOURCE_PASS_PARAMETER_PERIOD    (DRV_ERR_SYN_SOURCE |  0x2)


#define DRV_ERR_SYN_SOURCE_PASS_PARAMETER_PHASE    (DRV_ERR_SYN_SOURCE |  0x4)


#define DRV_ERR_SYN_SOURCE_PASS_PARAMETER_SELECT    (DRV_ERR_SYN_SOURCE |  0x3)


#define DRV_ERR_SYN_SOURCE_PASS_PARAMETER_WIDTH    (DRV_ERR_SYN_SOURCE |  0x5)


#define DRV_ERR_TIME                      (0x6 << 8)


#define DRV_ERR_TIME_PASS_PARAMETER_GPS                      (DRV_ERR_TIME |  0x3)


#define DRV_ERR_TIME_PASS_PARAMETER_NO                       (DRV_ERR_TIME |  0x1)


#define DRV_ERR_TIME_PASS_PARAMETER_TIME                     (DRV_ERR_TIME |  0x2)


#define DRV_ERR_TM                          (0x9 << 8)


#define DRV_ERR_TM_PASS_PARAMETER_BAUD                        (DRV_ERR_TM |  0x2)


#define DRV_ERR_TM_PASS_PARAMETER_NO                             (DRV_ERR_TM |  0x1)


#define DRV_ERR_UART                      (0x7 << 8)


#define DRV_ERR_UART_PASS_PARAMETER_NO                        (DRV_ERR_UART |  0x1)


#define DRV_GPS0_FLAG_TIME_ADDR            (0x1104) //GPS0


#define DRV_GPS1_FLAG_TIME_ADDR            (0x1108) //GPS1


#define DRV_GPS2_FLAG_TIME_ADDR           (0x110c) //GPS2


#define DRV_GPS3_FLAG_TIME_ADDR            (0x1110) //GPS3


#define DRV_HARD_TYPE				_DRV_5M_//5米


#define DRV_INT_ASIC0         (0)


#define DRV_INT_ASIC1         (1)


#define DRV_INT_ASIC2         (2)


#define DRV_INT_DISABLE       (0x91D0200A)


#define DRV_INT_EIGHT_FRE_TYPE		DRVUNUSED//位口中断输出  //八通道频率采集中断相关


#define DRV_INT_ENABLE         (0xEB90146F)


#define DRV_INT_ENABLE_ADDR           (0xC40) //中断使能寄存器


#define DRV_INT_GPI0_IOBASE   DRVIOBASE1


#define DRV_INT_GPI0_MODE   DRV_INT_HIGH_TRIG


#define DRV_INT_GPI0_NUMASIC   (0)


#define DRV_INT_GPI0_NUMGPI   (0)


#define DRV_INT_GPI1_IOBASE   DRVIOBASE1


#define DRV_INT_GPI1_MODE   DRV_INT_HIGH_TRIG


#define DRV_INT_GPI1_NUMASIC   (0)


#define DRV_INT_GPI1_NUMGPI   (0)


#define DRV_INT_GPI2_IOBASE   DRVIOBASE1


#define DRV_INT_GPI2_MODE   DRV_INT_HIGH_TRIG


#define DRV_INT_GPI2_NUMASIC   (0)


#define DRV_INT_GPI2_NUMGPI   (0)


#define DRV_INT_GPI3_IOBASE   DRVIOBASE1


#define DRV_INT_GPI3_MODE   DRV_INT_HIGH_TRIG


#define DRV_INT_GPI3_NUMASIC   (0)


#define DRV_INT_GPI3_NUMGPI   (0)


#define DRV_INT_GPI_NUM				(1)//GPI中断路数		//不使用


#define DRV_INT_GPI_NUM_LIMIT   (4)//GPI中断4路


#define DRV_INT_GPI_TYPE			DRVUNUSED//位口中断输出  //GPI中断相关


#define DRV_INT_MODE_ADDR            (0xD80) //中断模式寄存器


#define DRV_INT_SEL_ADDR(i)              (0xD40+0xC*(i)) //中断选择寄存器


#define DRV_INT_SSI_RECV_ADDR              (0xCC0) //同步串口中断接收个数寄存器


#define DRV_INT_STATE_ADDR               (0xC00) //中断状态寄存器


#define DRV_INT_TM_SEND_ADDR              (0xD00) //TM遥测串口中断剩余发送个数寄存器


#define DRV_INT_UART_RECV_ADDR           (0xC80) //异步串口中断接收个数寄存器


#define DRV_LATCH0_EDGE  DRV_COUNT_HIGH_MODE//0为下降沿，1为上升沿


#define DRV_LATCH0_IOBASE   DRVIOBASE1


#define DRV_LATCH0_NUMGPIO   (0)


#define DRV_LATCH1_EDGE  DRV_COUNT_HIGH_MODE//0为下降沿，1为上升沿


#define DRV_LATCH1_IOBASE   DRVIOBASE1


#define DRV_LATCH1_NUMGPIO   (0)


#define DRV_LATCH2_EDGE  DRV_COUNT_HIGH_MODE//0为下降沿，1为上升沿


#define DRV_LATCH2_IOBASE   DRVIOBASE1


#define DRV_LATCH2_NUMGPIO   (0)


#define DRV_LATCH3_EDGE  DRV_COUNT_HIGH_MODE//0为下降沿，1为上升沿


#define DRV_LATCH3_IOBASE   DRVIOBASE1


#define DRV_LATCH3_NUMGPIO   (0)


#define DRV_LATCH_FILTER_WIDTH  (100)


#define DRV_LATCH_NUM				(4) //单脉冲状态锁存路数//不使用


#define DRV_LATCH_NUM_LIMIT (4)


#define DRV_LATCH_TYPE				DRVUNUSED//单脉冲锁存


#define DRV_PLUSE_MEANWHILE_IOBASE	DRVIOBASE1


#define DRV_POWER0_IOBASE   DRVIOBASE2


#define DRV_POWER0_NUMGPIOOFF   (57)


#define DRV_POWER0_NUMGPIOON   (56)


#define DRV_POWER0_NUMPOWEROFF   (56)//控制端A 位号


#define DRV_POWER0_NUMPOWEROFF1   (65)//控制端B位号


#define DRV_POWER0_NUMPOWERON   (56)//控制端A 位号


#define DRV_POWER0_NUMPOWERON1   (64)//控制端B位号


#define DRV_POWER10_IOBASE   DRVIOBASE2


#define DRV_POWER10_NUMGPIOOFF   (57)


#define DRV_POWER10_NUMGPIOON   (56)


#define DRV_POWER10_NUMPOWEROFF   (58)


#define DRV_POWER10_NUMPOWEROFF1   (69)


#define DRV_POWER10_NUMPOWERON   (58)


#define DRV_POWER10_NUMPOWERON1   (68)


#define DRV_POWER11_IOBASE   DRVIOBASE2


#define DRV_POWER11_NUMGPIOOFF   (57)


#define DRV_POWER11_NUMGPIOON   (56)


#define DRV_POWER11_NUMPOWEROFF   (58)


#define DRV_POWER11_NUMPOWEROFF1   (71)


#define DRV_POWER11_NUMPOWERON   (58)


#define DRV_POWER11_NUMPOWERON1   (70)


#define DRV_POWER12_IOBASE   DRVIOBASE2


#define DRV_POWER12_NUMGPIOOFF   (57)


#define DRV_POWER12_NUMGPIOON   (56)


#define DRV_POWER12_NUMPOWEROFF   (59)


#define DRV_POWER12_NUMPOWEROFF1   (65)


#define DRV_POWER12_NUMPOWERON   (59)


#define DRV_POWER12_NUMPOWERON1   (64)


#define DRV_POWER13_IOBASE   DRVIOBASE2


#define DRV_POWER13_NUMGPIOOFF   (57)


#define DRV_POWER13_NUMGPIOON   (56)


#define DRV_POWER13_NUMPOWEROFF   (59)


#define DRV_POWER13_NUMPOWEROFF1   (67)


#define DRV_POWER13_NUMPOWERON   (59)


#define DRV_POWER13_NUMPOWERON1   (66)


#define DRV_POWER14_IOBASE   DRVIOBASE2


#define DRV_POWER14_NUMGPIOOFF   (57)


#define DRV_POWER14_NUMGPIOON   (56)


#define DRV_POWER14_NUMPOWEROFF   (59)


#define DRV_POWER14_NUMPOWEROFF1   (69)


#define DRV_POWER14_NUMPOWERON   (59)


#define DRV_POWER14_NUMPOWERON1   (68)


#define DRV_POWER15_IOBASE   DRVIOBASE2


#define DRV_POWER15_NUMGPIOOFF   (57)


#define DRV_POWER15_NUMGPIOON   (56)


#define DRV_POWER15_NUMPOWEROFF   (59)


#define DRV_POWER15_NUMPOWEROFF1   (71)


#define DRV_POWER15_NUMPOWERON   (59)


#define DRV_POWER15_NUMPOWERON1   (70)


#define DRV_POWER16_IOBASE   DRVIOBASE2


#define DRV_POWER16_NUMGPIOOFF   (57)


#define DRV_POWER16_NUMGPIOON   (56)


#define DRV_POWER16_NUMPOWEROFF   (60)


#define DRV_POWER16_NUMPOWEROFF1   (65)


#define DRV_POWER16_NUMPOWERON   (60)


#define DRV_POWER16_NUMPOWERON1   (64)


#define DRV_POWER17_IOBASE   DRVIOBASE2


#define DRV_POWER17_NUMGPIOOFF   (57)


#define DRV_POWER17_NUMGPIOON   (56)


#define DRV_POWER17_NUMPOWEROFF   (60)


#define DRV_POWER17_NUMPOWEROFF1   (67)


#define DRV_POWER17_NUMPOWERON   (60)


#define DRV_POWER17_NUMPOWERON1   (66)


#define DRV_POWER18_IOBASE   DRVIOBASE2


#define DRV_POWER18_NUMGPIOOFF   (57)


#define DRV_POWER18_NUMGPIOON   (56)


#define DRV_POWER18_NUMPOWEROFF   (60)


#define DRV_POWER18_NUMPOWEROFF1   (69)


#define DRV_POWER18_NUMPOWERON   (60)


#define DRV_POWER18_NUMPOWERON1   (68)


#define DRV_POWER19_IOBASE   DRVIOBASE2


#define DRV_POWER19_NUMGPIOOFF   (57)


#define DRV_POWER19_NUMGPIOON   (56)


#define DRV_POWER19_NUMPOWEROFF   (60)


#define DRV_POWER19_NUMPOWEROFF1   (71)


#define DRV_POWER19_NUMPOWERON   (60)


#define DRV_POWER19_NUMPOWERON1   (70)


#define DRV_POWER1_IOBASE   DRVIOBASE2


#define DRV_POWER1_NUMGPIOOFF   (57)


#define DRV_POWER1_NUMGPIOON   (56)


#define DRV_POWER1_NUMPOWEROFF   (56)


#define DRV_POWER1_NUMPOWEROFF1   (67)


#define DRV_POWER1_NUMPOWERON   (56)


#define DRV_POWER1_NUMPOWERON1   (66)


#define DRV_POWER20_IOBASE   DRVIOBASE2


#define DRV_POWER20_NUMGPIOOFF   (57)


#define DRV_POWER20_NUMGPIOON   (56)


#define DRV_POWER20_NUMPOWEROFF   (61)


#define DRV_POWER20_NUMPOWEROFF1   (65)


#define DRV_POWER20_NUMPOWERON   (61)


#define DRV_POWER20_NUMPOWERON1   (64)


#define DRV_POWER21_IOBASE   DRVIOBASE2


#define DRV_POWER21_NUMGPIOOFF   (57)


#define DRV_POWER21_NUMGPIOON   (56)


#define DRV_POWER21_NUMPOWEROFF   (61)


#define DRV_POWER21_NUMPOWEROFF1   (67)


#define DRV_POWER21_NUMPOWERON   (61)


#define DRV_POWER21_NUMPOWERON1   (66)


#define DRV_POWER22_IOBASE   DRVIOBASE2


#define DRV_POWER22_NUMGPIOOFF   (57)


#define DRV_POWER22_NUMGPIOON   (56)


#define DRV_POWER22_NUMPOWEROFF   (61)


#define DRV_POWER22_NUMPOWEROFF1   (69)


#define DRV_POWER22_NUMPOWERON   (61)


#define DRV_POWER22_NUMPOWERON1   (68)


#define DRV_POWER23_IOBASE   DRVIOBASE2


#define DRV_POWER23_NUMGPIOOFF   (57)


#define DRV_POWER23_NUMGPIOON   (56)


#define DRV_POWER23_NUMPOWEROFF   (61)


#define DRV_POWER23_NUMPOWEROFF1   (71)


#define DRV_POWER23_NUMPOWERON   (61)


#define DRV_POWER23_NUMPOWERON1   (70)


#define DRV_POWER24_IOBASE   DRVIOBASE2


#define DRV_POWER24_NUMGPIOOFF   (57)


#define DRV_POWER24_NUMGPIOON   (56)


#define DRV_POWER24_NUMPOWEROFF   (62)


#define DRV_POWER24_NUMPOWEROFF1   (65)


#define DRV_POWER24_NUMPOWERON   (62)


#define DRV_POWER24_NUMPOWERON1   (64)


#define DRV_POWER25_IOBASE   DRVIOBASE2


#define DRV_POWER25_NUMGPIOOFF   (57)


#define DRV_POWER25_NUMGPIOON   (56)


#define DRV_POWER25_NUMPOWEROFF   (62)


#define DRV_POWER25_NUMPOWEROFF1   (67)


#define DRV_POWER25_NUMPOWERON   (62)


#define DRV_POWER25_NUMPOWERON1   (66)


#define DRV_POWER26_IOBASE   DRVIOBASE2


#define DRV_POWER26_NUMGPIOOFF   (57)


#define DRV_POWER26_NUMGPIOON   (56)


#define DRV_POWER26_NUMPOWEROFF   (62)


#define DRV_POWER26_NUMPOWEROFF1   (69)


#define DRV_POWER26_NUMPOWERON   (62)


#define DRV_POWER26_NUMPOWERON1   (68)


#define DRV_POWER27_IOBASE   DRVIOBASE2


#define DRV_POWER27_NUMGPIOOFF   (57)


#define DRV_POWER27_NUMGPIOON   (56)


#define DRV_POWER27_NUMPOWEROFF   (62)


#define DRV_POWER27_NUMPOWEROFF1   (71)


#define DRV_POWER27_NUMPOWERON   (62)


#define DRV_POWER27_NUMPOWERON1   (70)


#define DRV_POWER28_IOBASE   DRVIOBASE2


#define DRV_POWER28_NUMGPIOOFF   (57)


#define DRV_POWER28_NUMGPIOON   (56)


#define DRV_POWER28_NUMPOWEROFF   (63)


#define DRV_POWER28_NUMPOWEROFF1   (65)


#define DRV_POWER28_NUMPOWERON   (63)


#define DRV_POWER28_NUMPOWERON1   (64)


#define DRV_POWER29_IOBASE   DRVIOBASE2


#define DRV_POWER29_NUMGPIOOFF   (57)


#define DRV_POWER29_NUMGPIOON   (56)


#define DRV_POWER29_NUMPOWEROFF   (63)


#define DRV_POWER29_NUMPOWEROFF1   (67)


#define DRV_POWER29_NUMPOWERON   (63)


#define DRV_POWER29_NUMPOWERON1   (66)


#define DRV_POWER2_IOBASE   DRVIOBASE2


#define DRV_POWER2_NUMGPIOOFF   (57)


#define DRV_POWER2_NUMGPIOON   (56)


#define DRV_POWER2_NUMPOWEROFF   (56)


#define DRV_POWER2_NUMPOWEROFF1   (69)


#define DRV_POWER2_NUMPOWERON   (56)


#define DRV_POWER2_NUMPOWERON1   (68)


#define DRV_POWER30_IOBASE   DRVIOBASE2


#define DRV_POWER30_NUMGPIOOFF   (57)


#define DRV_POWER30_NUMGPIOON   (56)


#define DRV_POWER30_NUMPOWEROFF   (63)


#define DRV_POWER30_NUMPOWEROFF1   (69)


#define DRV_POWER30_NUMPOWERON   (63)


#define DRV_POWER30_NUMPOWERON1   (68)


#define DRV_POWER31_IOBASE   DRVIOBASE2


#define DRV_POWER31_NUMGPIOOFF   (57)


#define DRV_POWER31_NUMGPIOON   (56)


#define DRV_POWER31_NUMPOWEROFF   (63)


#define DRV_POWER31_NUMPOWEROFF1   (71)


#define DRV_POWER31_NUMPOWERON   (63)


#define DRV_POWER31_NUMPOWERON1   (70)


#define DRV_POWER32_IOBASE   DRVIOBASE3


#define DRV_POWER32_NUMGPIOOFF   (57)


#define DRV_POWER32_NUMGPIOON   (56)


#define DRV_POWER32_NUMPOWEROFF   (70)


#define DRV_POWER32_NUMPOWEROFF1   (76)


#define DRV_POWER32_NUMPOWERON   (69)


#define DRV_POWER32_NUMPOWERON1   (79)


#define DRV_POWER33_IOBASE   DRVIOBASE3


#define DRV_POWER33_NUMGPIOOFF   (57)


#define DRV_POWER33_NUMGPIOON   (56)


#define DRV_POWER33_NUMPOWEROFF   (62)


#define DRV_POWER33_NUMPOWEROFF1   (64)


#define DRV_POWER33_NUMPOWERON   (61)


#define DRV_POWER33_NUMPOWERON1   (67)


#define DRV_POWER34_IOBASE   DRVIOBASE3


#define DRV_POWER34_NUMGPIOOFF   (57)


#define DRV_POWER34_NUMGPIOON   (56)


#define DRV_POWER34_NUMPOWEROFF   (68)


#define DRV_POWER34_NUMPOWEROFF1   (64)


#define DRV_POWER34_NUMPOWERON   (68)


#define DRV_POWER34_NUMPOWERON1   (65)


#define DRV_POWER35_IOBASE   DRVIOBASE3


#define DRV_POWER35_NUMGPIOOFF   (57)


#define DRV_POWER35_NUMGPIOON   (56)


#define DRV_POWER35_NUMPOWEROFF   (72)


#define DRV_POWER35_NUMPOWEROFF1   (76)


#define DRV_POWER35_NUMPOWERON   (72)


#define DRV_POWER35_NUMPOWERON1   (77)


#define DRV_POWER36_IOBASE   DRVIOBASE3


#define DRV_POWER36_NUMGPIOOFF   (57)


#define DRV_POWER36_NUMGPIOON   (56)


#define DRV_POWER36_NUMPOWEROFF   (69)//VIPPCU复位


#define DRV_POWER36_NUMPOWEROFF1   (67)


#define DRV_POWER36_NUMPOWERON   (71)//预留


#define DRV_POWER36_NUMPOWERON1   (67)


#define DRV_POWER37_IOBASE   DRVIOBASE3


#define DRV_POWER37_NUMGPIOOFF   (57)


#define DRV_POWER37_NUMGPIOON   (56)


#define DRV_POWER37_NUMPOWEROFF   (74)


#define DRV_POWER37_NUMPOWEROFF1   (76)


#define DRV_POWER37_NUMPOWERON   (73)


#define DRV_POWER37_NUMPOWERON1   (79)


#define DRV_POWER38_IOBASE   DRVIOBASE3


#define DRV_POWER38_NUMGPIOOFF   (57)


#define DRV_POWER38_NUMGPIOON   (56)


#define DRV_POWER38_NUMPOWEROFF   (74)


#define DRV_POWER38_NUMPOWEROFF1   (61)


#define DRV_POWER38_NUMPOWERON   (74)


#define DRV_POWER38_NUMPOWERON1   (60)


#define DRV_POWER39_IOBASE   DRVIOBASE3


#define DRV_POWER39_NUMGPIOOFF   (57)


#define DRV_POWER39_NUMGPIOON   (56)


#define DRV_POWER39_NUMPOWEROFF   (62)


#define DRV_POWER39_NUMPOWEROFF1   (66)


#define DRV_POWER39_NUMPOWERON   (62)


#define DRV_POWER39_NUMPOWERON1   (65)


#define DRV_POWER3_IOBASE   DRVIOBASE2


#define DRV_POWER3_NUMGPIOOFF   (57)


#define DRV_POWER3_NUMGPIOON   (56)


#define DRV_POWER3_NUMPOWEROFF   (56)


#define DRV_POWER3_NUMPOWEROFF1   (71)


#define DRV_POWER3_NUMPOWERON   (56)


#define DRV_POWER3_NUMPOWERON1   (70)


#define DRV_POWER40_IOBASE   DRVIOBASE3


#define DRV_POWER40_NUMGPIOOFF   (57)


#define DRV_POWER40_NUMGPIOON   (56)


#define DRV_POWER40_NUMPOWEROFF   (70)


#define DRV_POWER40_NUMPOWEROFF1   (67)


#define DRV_POWER40_NUMPOWERON   (70)


#define DRV_POWER40_NUMPOWERON1   (66)


#define DRV_POWER41_IOBASE   DRVIOBASE3


#define DRV_POWER41_NUMGPIOOFF   (57)


#define DRV_POWER41_NUMGPIOON   (56)


#define DRV_POWER41_NUMPOWEROFF   (71)


#define DRV_POWER41_NUMPOWEROFF1   (76)


#define DRV_POWER41_NUMPOWERON   (70)


#define DRV_POWER41_NUMPOWERON1   (79)


#define DRV_POWER42_IOBASE   DRVIOBASE3


#define DRV_POWER42_NUMGPIOOFF   (57)


#define DRV_POWER42_NUMGPIOON   (56)


#define DRV_POWER42_NUMPOWEROFF   (63)


#define DRV_POWER42_NUMPOWEROFF1   (64)


#define DRV_POWER42_NUMPOWERON   (62)


#define DRV_POWER42_NUMPOWERON1   (67)


#define DRV_POWER43_IOBASE   DRVIOBASE3


#define DRV_POWER43_NUMGPIOOFF   (57)


#define DRV_POWER43_NUMGPIOON   (56)


#define DRV_POWER43_NUMPOWEROFF   (71)


#define DRV_POWER43_NUMPOWEROFF1   (65)


#define DRV_POWER43_NUMPOWERON   (71)


#define DRV_POWER43_NUMPOWERON1   (64)


#define DRV_POWER44_IOBASE   DRVIOBASE3


#define DRV_POWER44_NUMGPIOOFF   (57)


#define DRV_POWER44_NUMGPIOON   (56)


#define DRV_POWER44_NUMPOWEROFF   (75)


#define DRV_POWER44_NUMPOWEROFF1   (78)


#define DRV_POWER44_NUMPOWERON   (75)


#define DRV_POWER44_NUMPOWERON1   (77)


#define DRV_POWER45_IOBASE   DRVIOBASE3


#define DRV_POWER45_NUMGPIOOFF   (57)


#define DRV_POWER45_NUMGPIOON   (56)


#define DRV_POWER45_NUMPOWEROFF   (74)


#define DRV_POWER45_NUMPOWEROFF1   (63)


#define DRV_POWER45_NUMPOWERON   (74)


#define DRV_POWER45_NUMPOWERON1   (62)


#define DRV_POWER46_IOBASE   DRVIOBASE3


#define DRV_POWER46_NUMGPIOOFF   (57)


#define DRV_POWER46_NUMGPIOON   (56)


#define DRV_POWER46_NUMPOWEROFF   (70)


#define DRV_POWER46_NUMPOWEROFF1   (78)


#define DRV_POWER46_NUMPOWERON   (70)


#define DRV_POWER46_NUMPOWERON1   (77)


#define DRV_POWER47_IOBASE   DRVIOBASE3


#define DRV_POWER47_NUMGPIOOFF   (57)


#define DRV_POWER47_NUMGPIOON   (56)


#define DRV_POWER47_NUMPOWEROFF   (75)


#define DRV_POWER47_NUMPOWEROFF1   (76)


#define DRV_POWER47_NUMPOWERON   (74)


#define DRV_POWER47_NUMPOWERON1   (79)


#define DRV_POWER48_IOBASE   DRVIOBASE3


#define DRV_POWER48_NUMGPIOOFF   (57)


#define DRV_POWER48_NUMGPIOON   (56)


#define DRV_POWER48_NUMPOWEROFF   (75)


#define DRV_POWER48_NUMPOWEROFF1   (61)


#define DRV_POWER48_NUMPOWERON   (75)


#define DRV_POWER48_NUMPOWERON1   (60)


#define DRV_POWER49_IOBASE   DRVIOBASE3


#define DRV_POWER49_NUMGPIOOFF   (57)


#define DRV_POWER49_NUMGPIOON   (56)


#define DRV_POWER49_NUMPOWEROFF   (72)


#define DRV_POWER49_NUMPOWEROFF1   (60)


#define DRV_POWER49_NUMPOWERON   (72)


#define DRV_POWER49_NUMPOWERON1   (61)


#define DRV_POWER4_IOBASE   DRVIOBASE2


#define DRV_POWER4_NUMGPIOOFF   (57)


#define DRV_POWER4_NUMGPIOON   (56)


#define DRV_POWER4_NUMPOWEROFF   (57)


#define DRV_POWER4_NUMPOWEROFF1   (65)


#define DRV_POWER4_NUMPOWERON   (57)


#define DRV_POWER4_NUMPOWERON1   (64)


#define DRV_POWER50_IOBASE   DRVIOBASE3


#define DRV_POWER50_NUMGPIOOFF   (57)


#define DRV_POWER50_NUMGPIOON   (56)


#define DRV_POWER50_NUMPOWEROFF   (68)


#define DRV_POWER50_NUMPOWEROFF1   (76)


#define DRV_POWER50_NUMPOWERON   (68)


#define DRV_POWER50_NUMPOWERON1   (77)


#define DRV_POWER51_IOBASE   DRVIOBASE3


#define DRV_POWER51_NUMGPIOOFF   (57)


#define DRV_POWER51_NUMGPIOON   (56)


#define DRV_POWER51_NUMPOWEROFF   (60)


#define DRV_POWER51_NUMPOWEROFF1   (64)


#define DRV_POWER51_NUMPOWERON   (60)


#define DRV_POWER51_NUMPOWERON1   (65)


#define DRV_POWER52_IOBASE   DRVIOBASE3


#define DRV_POWER52_NUMGPIOOFF   (57)


#define DRV_POWER52_NUMGPIOON   (56)


#define DRV_POWER52_NUMPOWEROFF   (68)


#define DRV_POWER52_NUMPOWEROFF1   (66)


#define DRV_POWER52_NUMPOWERON   (68)


#define DRV_POWER52_NUMPOWERON1   (67)


#define DRV_POWER53_IOBASE   DRVIOBASE3


#define DRV_POWER53_NUMGPIOOFF   (57)


#define DRV_POWER53_NUMGPIOON   (56)


#define DRV_POWER53_NUMPOWEROFF   (72)


#define DRV_POWER53_NUMPOWEROFF1   (78)


#define DRV_POWER53_NUMPOWERON   (72)


#define DRV_POWER53_NUMPOWERON1   (79)


#define DRV_POWER54_IOBASE   DRVIOBASE3


#define DRV_POWER54_NUMGPIOOFF   (57)


#define DRV_POWER54_NUMGPIOON   (56)


#define DRV_POWER54_NUMPOWEROFF   (72)


#define DRV_POWER54_NUMPOWEROFF1   (63)


#define DRV_POWER54_NUMPOWERON   (73)


#define DRV_POWER54_NUMPOWERON1   (60)


#define DRV_POWER55_IOBASE   DRVIOBASE3


#define DRV_POWER55_NUMGPIOOFF   (57)


#define DRV_POWER55_NUMGPIOON   (56)


#define DRV_POWER55_NUMPOWEROFF   (72)


#define DRV_POWER55_NUMPOWEROFF1   (62)


#define DRV_POWER55_NUMPOWERON   (72)


#define DRV_POWER55_NUMPOWERON1   (62)


#define DRV_POWER56_IOBASE   DRVIOBASE3


#define DRV_POWER56_NUMGPIOOFF   (57)


#define DRV_POWER56_NUMGPIOON   (56)


#define DRV_POWER56_NUMPOWEROFF   (68)


#define DRV_POWER56_NUMPOWEROFF1   (78)


#define DRV_POWER56_NUMPOWERON   (68)


#define DRV_POWER56_NUMPOWERON1   (78)


#define DRV_POWER57_IOBASE   DRVIOBASE3


#define DRV_POWER57_NUMGPIOOFF   (57)


#define DRV_POWER57_NUMGPIOON   (56)


#define DRV_POWER57_NUMPOWEROFF   (60)


#define DRV_POWER57_NUMPOWEROFF1   (66)


#define DRV_POWER57_NUMPOWERON   (60)


#define DRV_POWER57_NUMPOWERON1   (66)


#define DRV_POWER58_IOBASE   DRVIOBASE3


#define DRV_POWER58_NUMGPIOOFF   (57)


#define DRV_POWER58_NUMGPIOON   (56)


#define DRV_POWER58_NUMPOWEROFF   (69)


#define DRV_POWER58_NUMPOWEROFF1   (64)


#define DRV_POWER58_NUMPOWERON   (69)


#define DRV_POWER58_NUMPOWERON1   (64)


#define DRV_POWER59_IOBASE   DRVIOBASE3


#define DRV_POWER59_NUMGPIOOFF   (57)


#define DRV_POWER59_NUMGPIOON   (56)


#define DRV_POWER59_NUMPOWEROFF   (73)


#define DRV_POWER59_NUMPOWEROFF1   (76)


#define DRV_POWER59_NUMPOWERON   (73)


#define DRV_POWER59_NUMPOWERON1   (76)


#define DRV_POWER5_IOBASE   DRVIOBASE2


#define DRV_POWER5_NUMGPIOOFF   (57)


#define DRV_POWER5_NUMGPIOON   (56)


#define DRV_POWER5_NUMPOWEROFF   (57)


#define DRV_POWER5_NUMPOWEROFF1   (67)


#define DRV_POWER5_NUMPOWERON   (57)


#define DRV_POWER5_NUMPOWERON1   (66)


#define DRV_POWER60_IOBASE   DRVIOBASE3


#define DRV_POWER60_NUMGPIOOFF   (57)


#define DRV_POWER60_NUMGPIOON   (56)


#define DRV_POWER60_NUMPOWEROFF   (73)


#define DRV_POWER60_NUMPOWEROFF1   (61)


#define DRV_POWER60_NUMPOWERON   (73)


#define DRV_POWER60_NUMPOWERON1   (61)


#define DRV_POWER61_IOBASE   DRVIOBASE3


#define DRV_POWER61_NUMGPIOOFF   (57)


#define DRV_POWER61_NUMGPIOON   (56)


#define DRV_POWER61_NUMPOWEROFF   (68)


#define DRV_POWER61_NUMPOWEROFF1   (79)


#define DRV_POWER61_NUMPOWERON   (69)


#define DRV_POWER61_NUMPOWERON1   (76)


#define DRV_POWER62_IOBASE   DRVIOBASE3


#define DRV_POWER62_NUMGPIOOFF   (57)


#define DRV_POWER62_NUMGPIOON   (56)


#define DRV_POWER62_NUMPOWEROFF   (60)


#define DRV_POWER62_NUMPOWEROFF1   (67)


#define DRV_POWER62_NUMPOWERON   (61)


#define DRV_POWER62_NUMPOWERON1   (64)


#define DRV_POWER63_IOBASE   DRVIOBASE3


#define DRV_POWER63_NUMGPIOOFF   (57)


#define DRV_POWER63_NUMGPIOON   (56)


#define DRV_POWER63_NUMPOWEROFF   (69)


#define DRV_POWER63_NUMPOWEROFF1   (65)


#define DRV_POWER63_NUMPOWERON   (69)


#define DRV_POWER63_NUMPOWERON1   (66)


#define DRV_POWER64_IOBASE   DRVIOBASE3


#define DRV_POWER64_NUMGPIOOFF   (57)


#define DRV_POWER64_NUMGPIOON   (56)


#define DRV_POWER64_NUMPOWEROFF   (73)


#define DRV_POWER64_NUMPOWEROFF1   (77)


#define DRV_POWER64_NUMPOWERON   (73)


#define DRV_POWER64_NUMPOWERON1   (78)


#define DRV_POWER65_IOBASE   DRVIOBASE3


#define DRV_POWER65_NUMGPIOOFF   (57)


#define DRV_POWER65_NUMGPIOON   (56)


#define DRV_POWER65_NUMPOWEROFF   (70)


#define DRV_POWER65_NUMPOWEROFF1   (65)


#define DRV_POWER65_NUMPOWERON   (70)


#define DRV_POWER65_NUMPOWERON1   (64)


#define DRV_POWER66_IOBASE   DRVIOBASE3


#define DRV_POWER66_NUMGPIOOFF   (57)


#define DRV_POWER66_NUMGPIOON   (56)


#define DRV_POWER66_NUMPOWEROFF   (74)


#define DRV_POWER66_NUMPOWEROFF1   (78)


#define DRV_POWER66_NUMPOWERON   (74)


#define DRV_POWER66_NUMPOWERON1   (77)


#define DRV_POWER67_IOBASE   DRVIOBASE3


#define DRV_POWER67_NUMGPIOOFF   (57)


#define DRV_POWER67_NUMGPIOON   (56)


#define DRV_POWER67_NUMPOWEROFF   (73)


#define DRV_POWER67_NUMPOWEROFF1   (62)


#define DRV_POWER67_NUMPOWERON   (73)


#define DRV_POWER67_NUMPOWERON1   (63)


#define DRV_POWER68_IOBASE   DRVIOBASE3


#define DRV_POWER68_NUMGPIOOFF   (57)


#define DRV_POWER68_NUMGPIOON   (56)


#define DRV_POWER68_NUMPOWEROFF   (69)


#define DRV_POWER68_NUMPOWEROFF1   (77)


#define DRV_POWER68_NUMPOWERON   (69)


#define DRV_POWER68_NUMPOWERON1   (78)


#define DRV_POWER69_IOBASE   DRVIOBASE3


#define DRV_POWER69_NUMGPIOOFF   (57)


#define DRV_POWER69_NUMGPIOON   (56)


#define DRV_POWER69_NUMPOWEROFF   (61)


#define DRV_POWER69_NUMPOWEROFF1   (65)


#define DRV_POWER69_NUMPOWERON   (61)


#define DRV_POWER69_NUMPOWERON1   (66)


#define DRV_POWER6_IOBASE   DRVIOBASE2


#define DRV_POWER6_NUMGPIOOFF   (57)


#define DRV_POWER6_NUMGPIOON   (56)


#define DRV_POWER6_NUMPOWEROFF   (57)


#define DRV_POWER6_NUMPOWEROFF1   (69)


#define DRV_POWER6_NUMPOWERON   (57)


#define DRV_POWER6_NUMPOWERON1   (68)


#define DRV_POWER70_IOBASE   DRVIOBASE3


#define DRV_POWER70_NUMGPIOOFF   (57)


#define DRV_POWER70_NUMGPIOON   (56)


#define DRV_POWER70_NUMPOWEROFF   (71)


#define DRV_POWER70_NUMPOWEROFF1   (77)


#define DRV_POWER70_NUMPOWERON   (75)


#define DRV_POWER70_NUMPOWERON1   (79)


#define DRV_POWER71_IOBASE   DRVIOBASE3


#define DRV_POWER71_NUMGPIOOFF   (57)


#define DRV_POWER71_NUMGPIOON   (56)


#define DRV_POWER71_NUMPOWEROFF   (71)


#define DRV_POWER71_NUMPOWEROFF1   (79)


#define DRV_POWER71_NUMPOWERON   (71)


#define DRV_POWER71_NUMPOWERON1   (78)


#define DRV_POWER72_IOBASE   DRVIOBASE3


#define DRV_POWER72_NUMGPIOOFF   (57)


#define DRV_POWER72_NUMGPIOON   (56)


#define DRV_POWER72_NUMPOWEROFF   (63)


#define DRV_POWER72_NUMPOWEROFF1   (66)


#define DRV_POWER72_NUMPOWERON   (63)


#define DRV_POWER72_NUMPOWERON1   (65)


#define DRV_POWER73_IOBASE   DRVIOBASE3


#define DRV_POWER73_NUMGPIOOFF   (57)


#define DRV_POWER73_NUMGPIOON   (56)


#define DRV_POWER73_NUMPOWEROFF   (75)


#define DRV_POWER73_NUMPOWEROFF1   (62)


#define DRV_POWER73_NUMPOWERON   (63)


#define DRV_POWER73_NUMPOWERON1   (67)


#define DRV_POWER74_IOBASE   DRVIOBASE3


#define DRV_POWER74_NUMGPIOOFF   (57)


#define DRV_POWER74_NUMGPIOON   (56)


#define DRV_POWER74_NUMPOWEROFF   (71)


#define DRV_POWER74_NUMPOWEROFF1   (66)


#define DRV_POWER74_NUMPOWERON   (75)


#define DRV_POWER74_NUMPOWERON1   (63)


#define DRV_POWER7_IOBASE   DRVIOBASE2


#define DRV_POWER7_NUMGPIOOFF   (57)


#define DRV_POWER7_NUMGPIOON   (56)


#define DRV_POWER7_NUMPOWEROFF   (57)


#define DRV_POWER7_NUMPOWEROFF1   (71)


#define DRV_POWER7_NUMPOWERON   (57)


#define DRV_POWER7_NUMPOWERON1   (70)


#define DRV_POWER8_IOBASE   DRVIOBASE2


#define DRV_POWER8_NUMGPIOOFF   (57)


#define DRV_POWER8_NUMGPIOON   (56)


#define DRV_POWER8_NUMPOWEROFF   (58)


#define DRV_POWER8_NUMPOWEROFF1   (65)


#define DRV_POWER8_NUMPOWERON   (58)


#define DRV_POWER8_NUMPOWERON1   (64)


#define DRV_POWER9_IOBASE   DRVIOBASE2


#define DRV_POWER9_NUMGPIOOFF   (57)


#define DRV_POWER9_NUMGPIOON   (56)


#define DRV_POWER9_NUMPOWEROFF   (58)


#define DRV_POWER9_NUMPOWEROFF1   (67)


#define DRV_POWER9_NUMPOWERON   (58)


#define DRV_POWER9_NUMPOWERON1   (66)


#define DRV_POWER_MODE        DRV_POWER_MODE_4


#define DRV_POWER_MODE_1  (1)//方式1： 无输出使能位，单个脉冲直接控制开关


#define DRV_POWER_MODE_2  (2)//方式2：1位输出使能位，单个脉冲和1位使能位控制开关


#define DRV_POWER_MODE_3  (3)//方式3：多位输出使能位(且连续)。单个脉冲和多位使能位控制开关


#define DRV_POWER_MODE_4  (4)//方式4：2个脉冲控制开关


#define DRV_POWER_MODE_5  (5)//方式5：多个脉冲控制开关


#define DRV_POWER_NUM				(75)//开关模块路数		//IO1:32、IO2:43


#define DRV_POWER_NUM_LIMIT (75)


#define DRV_POWER_TYPE				DRVUSED//开关模块加断电


#define DRV_POWER_USED_GPIO_NUM  (6)


#define DRV_POWER_USED_GPIO_START  (32)  //多路信号对应的gpio


#define DRV_PULSE0_IOBASE   DRVIOBASE1


#define DRV_PULSE0_NUMPULSE   (48)


#define DRV_PULSE0_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE10_IOBASE   DRVIOBASE1


#define DRV_PULSE10_NUMPULSE   (58)


#define DRV_PULSE10_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE11_IOBASE   DRVIOBASE1


#define DRV_PULSE11_NUMPULSE   (59)


#define DRV_PULSE11_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE12_IOBASE   DRVIOBASE1


#define DRV_PULSE12_NUMPULSE   (60)


#define DRV_PULSE12_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE13_IOBASE   DRVIOBASE1


#define DRV_PULSE13_NUMPULSE   (61)


#define DRV_PULSE13_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE14_IOBASE   DRVIOBASE1


#define DRV_PULSE14_NUMPULSE   (62)


#define DRV_PULSE14_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE15_IOBASE   DRVIOBASE1


#define DRV_PULSE15_NUMPULSE   (63)


#define DRV_PULSE15_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE16_IOBASE   DRVIOBASE1


#define DRV_PULSE16_NUMPULSE   (64)


#define DRV_PULSE16_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE17_IOBASE   DRVIOBASE1


#define DRV_PULSE17_NUMPULSE   (65)


#define DRV_PULSE17_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE18_IOBASE   DRVIOBASE1


#define DRV_PULSE18_NUMPULSE   (66)


#define DRV_PULSE18_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE19_IOBASE   DRVIOBASE1


#define DRV_PULSE19_NUMPULSE   (67)


#define DRV_PULSE19_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE1_IOBASE   DRVIOBASE1


#define DRV_PULSE1_NUMPULSE   (49)


#define DRV_PULSE1_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE20_IOBASE   DRVIOBASE1


#define DRV_PULSE20_NUMPULSE   (68)


#define DRV_PULSE20_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE21_IOBASE   DRVIOBASE1


#define DRV_PULSE21_NUMPULSE   (69)


#define DRV_PULSE21_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE22_IOBASE   DRVIOBASE1


#define DRV_PULSE22_NUMPULSE   (70)


#define DRV_PULSE22_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE23_IOBASE   DRVIOBASE1


#define DRV_PULSE23_NUMPULSE   (71)


#define DRV_PULSE23_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE24_IOBASE   DRVIOBASE1


#define DRV_PULSE24_IOBASE   DRVIOBASE3


#define DRV_PULSE24_NUMPULSE   (52)


#define DRV_PULSE24_NUMPULSE   (72)


#define DRV_PULSE24_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE25_IOBASE   DRVIOBASE3


#define DRV_PULSE25_NUMPULSE   (48)


#define DRV_PULSE25_PERIODICITY   DRV_PULSE_PERIOD


#define DRV_PULSE26_IOBASE   DRVIOBASE3


#define DRV_PULSE26_NUMPULSE   (49)


#define DRV_PULSE26_PERIODICITY   DRV_PULSE_PERIOD


#define DRV_PULSE27_IOBASE   DRVIOBASE3


#define DRV_PULSE27_NUMPULSE   (50)


#define DRV_PULSE27_PERIODICITY   DRV_PULSE_PERIOD


#define DRV_PULSE28_IOBASE   DRVIOBASE3


#define DRV_PULSE28_NUMPULSE   (51)


#define DRV_PULSE28_PERIODICITY   DRV_PULSE_PERIOD


#define DRV_PULSE29_IOBASE   DRVIOBASE3


#define DRV_PULSE29_NUMPULSE   (52)


#define DRV_PULSE29_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE2_IOBASE   DRVIOBASE1


#define DRV_PULSE2_NUMPULSE   (50)


#define DRV_PULSE2_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE30_IOBASE   DRVIOBASE3


#define DRV_PULSE30_NUMPULSE   (53)


#define DRV_PULSE30_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE31_IOBASE   DRVIOBASE3


#define DRV_PULSE31_NUMPULSE   (54)


#define DRV_PULSE31_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE32_IOBASE   DRVIOBASE3


#define DRV_PULSE32_NUMPULSE   (55)


#define DRV_PULSE32_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE3_IOBASE   DRVIOBASE1


#define DRV_PULSE3_NUMPULSE   (51)


#define DRV_PULSE3_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE4_IOBASE   DRVIOBASE1


#define DRV_PULSE4_NUMPULSE   (52)


#define DRV_PULSE4_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE5_IOBASE   DRVIOBASE1


#define DRV_PULSE5_NUMPULSE   (53)


#define DRV_PULSE5_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE6_IOBASE   DRVIOBASE1


#define DRV_PULSE6_NUMPULSE   (54)


#define DRV_PULSE6_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE7_IOBASE   DRVIOBASE1


#define DRV_PULSE7_NUMPULSE   (55)


#define DRV_PULSE7_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE8_IOBASE   DRVIOBASE1


#define DRV_PULSE8_NUMPULSE   (56)


#define DRV_PULSE8_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE9_IOBASE   DRVIOBASE1


#define DRV_PULSE9_NUMPULSE   (57)


#define DRV_PULSE9_PERIODICITY   DRV_PULSE_SINGLE


#define DRV_PULSE_ACT_0          (0x364) //脉冲启动GPIO48-63


#define DRV_PULSE_ACT_1          (0x368) //脉冲启动GPIO64-79


#define DRV_PULSE_CIR_0         0x1c4 //脉冲是否循环GPIO(63:48)


#define DRV_PULSE_CIR_1         0x1c8//脉冲是否循环GPIO(79:64)


#define DRV_PULSE_COUNT_EDGE         0x80//脉冲计数锁存信号边沿选择寄存器


#define DRV_PULSE_COUNT_NUM0 (6)//第一种类型路数


#define DRV_PULSE_COUNT_NUM1 (8)//第二种类型路数


#define DRV_PULSE_COUNT_NUM2 (8)//第三种类型路数


#define DRV_PULSE_COUNT_NUM3 (6)//第四种类型路数


#define DRV_PULSE_COUNT_SEL          0x60//脉冲计数锁存信号选择寄存器


#define DRV_PULSE_COUNT_SOFT         0x68//脉冲计数软件写锁存寄存器


#define DRV_PULSE_COUNT_TYPE       (4)


#define DRV_PULSE_COUNT_VALUE        0x84//脉冲计数器寄存器0


#define DRV_PULSE_DIS         (0x294) //GPIO(48)


#define DRV_PULSE_EN_0          (0x35c) //脉冲使能GPIO48-63


#define DRV_PULSE_EN_1          (0x360) //脉冲使能GPIO64-79


#define DRV_PULSE_EQU         (0x1c0) //脉冲当量D2-0 对应GPIO(55:48);D5-3 对应GPIO(63:56);D8-6 对应GPIO(71:64);D11-9对应GPIO(79:72)


#define DRV_PULSE_FILTER_WIDTH0  (10)//第一种类型滤波宽度10us//滤波当量50ns、滤波宽度50ns，当前能设置的滤波宽度最小值为10us


#define DRV_PULSE_FILTER_WIDTH1  (10)//第二种类型滤波宽度10us//要求滤波当量50ns、滤波宽度5us，当前能设置的滤波宽度最小值为10us


#define DRV_PULSE_FILTER_WIDTH2  (1000)//第三种类型滤波宽度1000us//要求滤波当量10us，滤波宽度1ms，没问题


#define DRV_PULSE_FILTER_WIDTH3  (10)//第四种类型滤波宽度10us//滤波当量50ns、滤波宽度50ns，当前能设置的滤波宽度最小值为10us


#define DRV_PULSE_LATCH_EDGE         0x58


#define DRV_PULSE_LATCH_STATUS         0x5c


#define DRV_PULSE_NO1  (23)


#define DRV_PULSE_NO2  (24)


#define DRV_PULSE_NO3  (0)


#define DRV_PULSE_NO4  (0)


#define DRV_PULSE_NUM				(33)//可变脉冲输出路数	//PM:25、IO2:8


#define DRV_PULSE_NUM_LIMIT (33)


#define DRV_PULSE_POWER_WIDTH     			(128000) //128ms


#define DRV_PULSE_POWER_WIDTH_TYPE   DRVINVARAANT //固定脉宽


#define DRV_PULSE_TYPE				DRVUSED//可变脉冲输出


#define DRV_PULSE_WID         (0x1cc) //GPIO(48)


#define DRV_PeliCAN_ACC_CODE0     (0x00000040)


#define DRV_PeliCAN_ACC_CODE1     (0x00000044)


#define DRV_PeliCAN_ACC_CODE2     (0x00000048)


#define DRV_PeliCAN_ACC_CODE3     (0x0000004C)


#define DRV_PeliCAN_ACC_MASK0     (0x00000050)


#define DRV_PeliCAN_ACC_MASK1     (0x00000054)


#define DRV_PeliCAN_ACC_MASK2     (0x00000058)


#define DRV_PeliCAN_ACC_MASK3     (0x0000005C)


#define DRV_PeliCAN_BTR0          (0x00000018)


#define DRV_PeliCAN_BTR1          (0x0000001C)


#define DRV_PeliCAN_COMMAND       (0x00000004)


#define DRV_PeliCAN_INTR          (0x0000000C)


#define DRV_PeliCAN_INTR_ENABLE   (0x00000010)


#define DRV_PeliCAN_MODE          (0x00000000)


#define DRV_PeliCAN_OCR           (0x00000020)


#define DRV_PeliCAN_RXBUF(i)      (0x00000040 + (i) * 4)


#define DRV_PeliCAN_RXBUFBASE     (0x00000078)


#define DRV_PeliCAN_RXMSGCOUNT    (0x00000074)


#define DRV_PeliCAN_RX_ERR        (0x00000038)


#define DRV_PeliCAN_STATUS        (0x00000008)


#define DRV_PeliCAN_TIME          (0x0000007C)


#define DRV_PeliCAN_TXBUF(i)      (0x00000040 + (i) * 4)


#define DRV_PeliCAN_TX_ERR        (0x0000003C)


#define DRV_REGS_NUM (40)


#define DRV_SPI0_INTFLAG  DRV_INT_DISABLE


#define DRV_SPI0_IOBASE   DRVIOBASE1


#define DRV_SPI0_NUMSPI   (0)


#define DRV_SPI1_INTFLAG  DRV_INT_DISABLE


#define DRV_SPI1_IOBASE   DRVIOBASE1


#define DRV_SPI1_NUMSPI   (1)


#define DRV_SPI2_INTFLAG  DRV_INT_DISABLE


#define DRV_SPI2_IOBASE   DRVIOBASE1


#define DRV_SPI2_NUMSPI   (2)


#define DRV_SPI3_INTFLAG  DRV_INT_DISABLE


#define DRV_SPI3_IOBASE   DRVIOBASE1


#define DRV_SPI3_NUMSPI   (3)


#define DRV_SPI4_INTFLAG  DRV_INT_DISABLE


#define DRV_SPI4_IOBASE   DRVIOBASE1


#define DRV_SPI4_NUMSPI   (4)


#define DRV_SPI_BASE 0x7400


#define DRV_SPI_CFR          (0x1C)


#define DRV_SPI_DATA          (0x00)


#define DRV_SPI_FRE_TIME  (3)//系统时钟的1/2(n+1)


#define DRV_SPI_ICR         (0x04)


#define DRV_SPI_INT_MODE DRV_INT_EDGE_TRIG


#define DRV_SPI_ISR         (0x08)


#define DRV_SPI_ISR_TIME  (2)//n*0.5*SPI时钟周期


#define DRV_SPI_NUM					(4)//SPI模块路数		//不使用


#define DRV_SPI_NUM_LIMIT  (5)


#define DRV_SPI_RBN        (0x0C)


#define DRV_SPI_RBN_TIME  (2)//n*0.5*SPI时钟周期


#define DRV_SPI_RIC          (0x14)


#define DRV_SPI_STR         (0x18)


#define DRV_SPI_TBN        (0x10)


#define DRV_SPI_TBN_TIME  (2)//n*0.5*SPI时钟周期


#define DRV_SPI_TYPE				DRVUNUSED//SPI功能


#define DRV_SSI_BASE_ADDR        0x800//同步串口模块基地址


#define DRV_SSI_BAUD_ADDR(i)         (0x50+0x40*(i))//同步串口波特率寄存器


#define DRV_SSI_CTRL_ADDR         0x8//同步串口发送控制寄存器USCR,只写


#define DRV_SSI_IN0_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_IN0_IOBASE   DRVIOBASE2


#define DRV_SSI_IN0_MODE   DRV_SSI_IN_MODE1


#define DRV_SSI_IN0_NUMSSI   (0)


#define DRV_SSI_IN0_USFR   (512)


#define DRV_SSI_IN1_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_IN1_IOBASE   DRVIOBASE2


#define DRV_SSI_IN1_MODE   DRV_SSI_IN_MODE1


#define DRV_SSI_IN1_NUMSSI   (1)


#define DRV_SSI_IN1_USFR   (512)


#define DRV_SSI_IN2_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_IN2_IOBASE   DRVIOBASE1


#define DRV_SSI_IN2_MODE   DRV_SSI_IN_MODE1


#define DRV_SSI_IN2_NUMSSI   (4)


#define DRV_SSI_IN2_USFR   (5)


#define DRV_SSI_IN3_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_IN3_IOBASE   DRVIOBASE1


#define DRV_SSI_IN3_MODE   DRV_SSI_IN_MODE1


#define DRV_SSI_IN3_NUMSSI   (5)


#define DRV_SSI_IN3_USFR   (5)


#define DRV_SSI_IN4_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_IN4_IOBASE   DRVIOBASE1


#define DRV_SSI_IN4_MODE   0


#define DRV_SSI_IN4_NUMSSI   0


#define DRV_SSI_IN4_USFR   0


#define DRV_SSI_IN_INT_MODE DRV_INT_EDGE_TRIG


#define DRV_SSI_IN_MODE1 (0)//ML,被动


#define DRV_SSI_IN_MODE2 (3)//DS,主动


#define DRV_SSI_IN_NUM				(2)//同步串口接收路数	//不使用


#define DRV_SSI_IN_NUM_LIMIT  (5)


#define DRV_SSI_IN_TYPE				DRVUNUSED//同步串口遥测功能


#define DRV_SSI_OUT0_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_OUT0_IOBASE   DRVIOBASE1


#define DRV_SSI_OUT0_MODE   DRV_SSI_OUT_MODE1


#define DRV_SSI_OUT0_NUMSSI   (5)


#define DRV_SSI_OUT0_USFR   (4)


#define DRV_SSI_OUT1_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_OUT1_IOBASE   DRVIOBASE1


#define DRV_SSI_OUT1_MODE   DRV_SSI_OUT_MODE1


#define DRV_SSI_OUT1_NUMSSI   (6)


#define DRV_SSI_OUT1_USFR   (4)


#define DRV_SSI_OUT2_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_OUT2_IOBASE   DRVIOBASE1


#define DRV_SSI_OUT2_MODE   DRV_SSI_OUT_MODE1


#define DRV_SSI_OUT2_NUMSSI   (7)


#define DRV_SSI_OUT2_USFR   (4)


#define DRV_SSI_OUT3_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_OUT3_IOBASE   DRVIOBASE2


#define DRV_SSI_OUT3_MODE   DRV_SSI_OUT_MODE1


#define DRV_SSI_OUT3_NUMSSI   (6)


#define DRV_SSI_OUT3_USFR   (8)


#define DRV_SSI_OUT4_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_OUT4_IOBASE   DRVIOBASE2


#define DRV_SSI_OUT4_MODE   DRV_SSI_OUT_MODE2


#define DRV_SSI_OUT4_NUMSSI   (5)


#define DRV_SSI_OUT4_USFR   (256)


#define DRV_SSI_OUT5_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_OUT5_IOBASE   DRVIOBASE2


#define DRV_SSI_OUT5_MODE   DRV_SSI_OUT_MODE2


#define DRV_SSI_OUT5_NUMSSI   (7)


#define DRV_SSI_OUT5_USFR   (256)


#define DRV_SSI_OUT6_INTFLAG  DRV_INT_DISABLE


#define DRV_SSI_OUT6_IOBASE   DRVIOBASE2


#define DRV_SSI_OUT6_MODE   DRV_SSI_OUT_MODE2


#define DRV_SSI_OUT6_NUMSSI   (9)


#define DRV_SSI_OUT6_USFR   (256)


#define DRV_SSI_OUT_INT_MODE DRV_INT_EDGE_TRIG


#define DRV_SSI_OUT_MODE1 (1)//ML,主动


#define DRV_SSI_OUT_MODE2 (2)//DS,被动


#define DRV_SSI_OUT_NUM				(3)//同步串口发送路数	//PM:3


#define DRV_SSI_OUT_NUM_LIMIT  (7)


#define DRV_SSI_OUT_TYPE			DRVUSED//同步串口遥控功能


#define DRV_SSI_USCFR_ADDR         0xC//同步串口FIFO复位寄存器,只写


#define DRV_SSI_USCNTR_ADDR(i)          (0x48+0x40*(i))//同步串口FIFO计数器,D[8:0]:FIFO中字节个数,为0时或为空或为满;D[9]:FIFO满标志,'1'为满;D[10]:FIFO空标志,'1'为空


#define DRV_SSI_USDR_ADDR(i)          (0x4c+0x40*(i))//同步串口数据寄存器


#define DRV_SSI_USFR_ADDR(i)          (0x44+0x40*(i))//同步串口帧长寄存器


#define DRV_SSI_USMR_ADDR(i)          (0x40+0x40*(i))//同步串口模式寄存器


#define DRV_STAR_TIME0_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME0_NUMTIME   (0)


#define DRV_STAR_TIME10_IOBACE     DRVIOBASE3


#define DRV_STAR_TIME10_NUMTIME   (6)


#define DRV_STAR_TIME11_IOBACE     DRVIOBASE3


#define DRV_STAR_TIME11_NUMTIME   (8)


#define DRV_STAR_TIME1_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME1_NUMTIME   (1)


#define DRV_STAR_TIME2_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME2_NUMTIME   (2)


#define DRV_STAR_TIME3_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME3_NUMTIME   (3)


#define DRV_STAR_TIME4_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME4_NUMTIME   (4)


#define DRV_STAR_TIME5_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME5_NUMTIME   (5)


#define DRV_STAR_TIME6_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME6_NUMTIME   (6)


#define DRV_STAR_TIME7_IOBACE     DRVIOBASE2


#define DRV_STAR_TIME7_NUMTIME   (3)


#define DRV_STAR_TIME8_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME8_NUMTIME   (6)


#define DRV_STAR_TIME9_IOBACE     DRVIOBASE1


#define DRV_STAR_TIME9_NUMTIME   (6)


#define DRV_STAR_TIME_NUM			(7) //星时锁存路数		//PM:7


#define DRV_STAR_TIME_NUM_LIMIT   (12)//支持12路星时采集


#define DRV_STAR_TIME_TYPE			DRVUSED//星时锁存功能


#define DRV_SYN_SOURCE0_FLAG_TIME_ADDR            (0x1114)//SYN_SOURCE0


#define DRV_SYN_SOURCE0_IOBASE   DRVIOBASE1


#define DRV_SYN_SOURCE0_NUMSYN   (0)//第0路周期信号


#define DRV_SYN_SOURCE1_FLAG_TIME_ADDR            (0x1118) //SYN_SOURCE1


#define DRV_SYN_SOURCE1_IOBASE   DRVIOBASE3


#define DRV_SYN_SOURCE1_NUMSYN   (0)//第0路周期信号


#define DRV_SYN_SOURCE2_FLAG_TIME_ADDR           (0x111c) //SYN_SOURCE2


#define DRV_SYN_SOURCE2_IOBASE   DRVIOBASE3


#define DRV_SYN_SOURCE2_NUMSYN   (1)//第1路周期信号


#define DRV_SYN_SOURCE3_FLAG_TIME_ADDR            (0x1120) //SYN_SOURCE3


#define DRV_SYN_SOURCE3_IOBASE   DRVIOBASE3


#define DRV_SYN_SOURCE3_NUMSYN   (2)//第2路周期信号


#define DRV_SYN_SOURCE_FLAG_ADDR                 (0x1100)


#define DRV_SYN_SOURCE_NUM			(4) //同步信号类型路数	//PM:1、IO2:3


#define DRV_SYN_SOURCE_NUM_LIMIT  (4)//同步信号4路


#define DRV_SYN_SOURCE_TYPE			DRVUSED//同步信号输出


#define DRV_TIMER_SCALER   (1)


#define DRV_TIME_0         (0x1004) //内部分频产生控制周期寄存器0  D[15:0]


#define DRV_TIME_1         (0x1008)//内部分频产生控制周期寄存器1  D[19:16]


#define DRV_TIME_CTRLEQU   (0x100C) //控制周期计时当量和来源选择


#define DRV_TIME_EDGE         (0x1140)//基准信号源选择寄存器


#define DRV_TIME_EQU         (0x1000)//星时计时当量寄存器


#define DRV_TIME_READ         (0x1148)//星时读取寄存器


#define DRV_TIME_SEL         (0x1144)//星时锁存控制寄存器,只写


#define DRV_TM_BAUD0   (0x20)


#define DRV_TM_BAUD1   (0x24)


#define DRV_TM_CODE   (0x0)


#define DRV_TM_DATA   (0x0)


#define DRV_TM_INIT0   (0x28)


#define DRV_TM_INIT1   (0x2c)


#define DRV_TM_INT0_NO   (0)


#define DRV_TM_INT1_NO   (0)


#define DRV_TM_INT_MODE   DRV_INT_EDGE_TRIG


#define DRV_TM_IOBASE   DRVIOBASE1


#define DRV_TM_IOBASEA   (0x6C00)


#define DRV_TM_IOBASEB   (0x7000)


#define DRV_TM_MCODE   (0x1)


#define DRV_TM_OUTPUT_CODE  DRV_TM_CODE


#define DRV_TM_PCM   (0xC)


#define DRV_TM_RESET   (0x4)


#define DRV_TM_SCODE   (0x2)


#define DRV_TM_TYPE					DRVUNUSED//TM功能


#define DRV_UART0_INTFLAG  DRV_INT_DISABLE


#define DRV_UART0_IOBASE   DRVIOBASE1


#define DRV_UART0_MUX   (0xF)


#define DRV_UART0_NUMUART   (0)


#define DRV_UART10_INTFLAG  DRV_INT_DISABLE


#define DRV_UART10_IOBASE   DRVIOBASE2


#define DRV_UART10_MUX   (0xF)


#define DRV_UART10_NUMUART   (13)


#define DRV_UART10_NUMUART   (6)


#define DRV_UART11_INTFLAG  DRV_INT_DISABLE


#define DRV_UART11_IOBASE   DRVIOBASE2


#define DRV_UART11_MUX   (0xF)


#define DRV_UART11_NUMUART   (7)


#define DRV_UART12_INTFLAG  DRV_INT_DISABLE


#define DRV_UART12_IOBASE   DRVIOBASE2


#define DRV_UART12_MUX   (0xF)


#define DRV_UART12_NUMUART   (6)


#define DRV_UART12_NUMUART   (8)


#define DRV_UART13_INTFLAG  DRV_INT_DISABLE


#define DRV_UART13_IOBASE   DRVIOBASE2


#define DRV_UART13_MUX   (0xF)


#define DRV_UART13_NUMUART   (9)


#define DRV_UART14_INTFLAG  DRV_INT_DISABLE


#define DRV_UART14_IOBASE   DRVIOBASE2


#define DRV_UART14_MUX   (0xF)


#define DRV_UART14_NUMUART   (10)


#define DRV_UART15_INTFLAG  DRV_INT_DISABLE


#define DRV_UART15_IOBASE   DRVIOBASE2


#define DRV_UART15_MUX   (0xF)


#define DRV_UART15_NUMUART   (11)


#define DRV_UART16_INTFLAG  DRV_INT_DISABLE


#define DRV_UART16_IOBASE   DRVIOBASE2


#define DRV_UART16_MUX   (0xF)


#define DRV_UART16_NUMUART   (0)


#define DRV_UART16_NUMUART   (12)


#define DRV_UART17_INTFLAG  DRV_INT_DISABLE


#define DRV_UART17_IOBASE   DRVIOBASE2


#define DRV_UART17_MUX   (0xF)


#define DRV_UART17_NUMUART   (1)


#define DRV_UART17_NUMUART   (13)


#define DRV_UART18_INTFLAG  DRV_INT_DISABLE


#define DRV_UART18_IOBASE   DRVIOBASE2


#define DRV_UART18_MUX   (0xF)


#define DRV_UART18_NUMUART   (14)


#define DRV_UART19_INTFLAG  DRV_INT_DISABLE


#define DRV_UART19_IOBASE   DRVIOBASE2


#define DRV_UART19_MUX   (0xF)


#define DRV_UART19_NUMUART   (15)


#define DRV_UART1_INTFLAG  DRV_INT_DISABLE


#define DRV_UART1_IOBASE   DRVIOBASE1


#define DRV_UART1_MUX   (0xF)


#define DRV_UART1_NUMUART   (1)


#define DRV_UART20_INTFLAG  DRV_INT_DISABLE


#define DRV_UART20_IOBASE   DRVIOBASE1


#define DRV_UART20_MUX   (0xF)


#define DRV_UART20_NUMUART   (2)


#define DRV_UART21_INTFLAG  DRV_INT_DISABLE


#define DRV_UART21_IOBASE   DRVIOBASE1


#define DRV_UART21_MUX   (0xF)


#define DRV_UART21_NUMUART   (3)


#define DRV_UART22_INTFLAG  DRV_INT_DISABLE


#define DRV_UART22_IOBASE   DRVIOBASE1


#define DRV_UART22_MUX   (0xF)


#define DRV_UART22_NUMUART   (4)


#define DRV_UART23_INTFLAG  DRV_INT_DISABLE


#define DRV_UART23_IOBASE   DRVIOBASE1


#define DRV_UART23_MUX   (0xF)


#define DRV_UART23_NUMUART   (5)


#define DRV_UART24_INTFLAG  DRV_INT_DISABLE


#define DRV_UART24_IOBASE   DRVIOBASE1


#define DRV_UART24_MUX   (0xF)


#define DRV_UART24_NUMUART   (6)


#define DRV_UART25_INTFLAG  DRV_INT_DISABLE


#define DRV_UART25_IOBASE   DRVIOBASE1


#define DRV_UART25_MUX   (0xF)


#define DRV_UART25_NUMUART   (7)


#define DRV_UART26_INTFLAG  DRV_INT_DISABLE


#define DRV_UART26_IOBASE   DRVIOBASE1


#define DRV_UART26_MUX   (0xF)


#define DRV_UART26_NUMUART   (8)


#define DRV_UART27_INTFLAG  DRV_INT_DISABLE


#define DRV_UART27_IOBASE   DRVIOBASE1


#define DRV_UART27_MUX   (0xF)


#define DRV_UART27_NUMUART   (9)


#define DRV_UART28_INTFLAG  DRV_INT_DISABLE


#define DRV_UART28_IOBASE   DRVIOBASE1


#define DRV_UART28_MUX   (0xF)


#define DRV_UART28_NUMUART   (10)


#define DRV_UART29_INTFLAG  DRV_INT_DISABLE


#define DRV_UART29_IOBASE   DRVIOBASE1


#define DRV_UART29_MUX   (0xF)


#define DRV_UART29_NUMUART   (11)


#define DRV_UART2_INTFLAG  DRV_INT_DISABLE


#define DRV_UART2_IOBASE   DRVIOBASE1


#define DRV_UART2_MUX   (0xF)


#define DRV_UART2_NUMUART   (2)


#define DRV_UART30_INTFLAG  DRV_INT_DISABLE


#define DRV_UART30_IOBASE   DRVIOBASE1


#define DRV_UART30_MUX   (0xF)


#define DRV_UART30_NUMUART   (10)


#define DRV_UART31_INTFLAG  DRV_INT_DISABLE


#define DRV_UART31_IOBASE   DRVIOBASE1


#define DRV_UART31_MUX   (0xF)


#define DRV_UART31_NUMUART   (11)


#define DRV_UART3_INTFLAG  DRV_INT_DISABLE


#define DRV_UART3_IOBASE   DRVIOBASE1


#define DRV_UART3_MUX   (0xF)


#define DRV_UART3_NUMUART   (3)


#define DRV_UART4_INTFLAG  DRV_INT_DISABLE


#define DRV_UART4_IOBASE   DRVIOBASE2


#define DRV_UART4_MUX   (0xF)


#define DRV_UART4_NUMUART   (0)


#define DRV_UART4_NUMUART   (12)


#define DRV_UART5_INTFLAG  DRV_INT_DISABLE


#define DRV_UART5_IOBASE   DRVIOBASE2


#define DRV_UART5_MUX   (0xF)


#define DRV_UART5_NUMUART   (1)


#define DRV_UART5_NUMUART   (8)


#define DRV_UART6_INTFLAG  DRV_INT_DISABLE


#define DRV_UART6_IOBASE   DRVIOBASE2


#define DRV_UART6_MUX   (0xF)


#define DRV_UART6_NUMUART   (2)


#define DRV_UART7_INTFLAG  DRV_INT_DISABLE


#define DRV_UART7_IOBASE   DRVIOBASE2


#define DRV_UART7_MUX   (0xF)


#define DRV_UART7_NUMUART   (3)


#define DRV_UART8_INTFLAG  DRV_INT_DISABLE


#define DRV_UART8_IOBASE   DRVIOBASE2


#define DRV_UART8_MUX   (0xF)


#define DRV_UART8_NUMUART   (4)


#define DRV_UART9_INTFLAG  DRV_INT_DISABLE


#define DRV_UART9_IOBASE   DRVIOBASE2


#define DRV_UART9_MUX   (0xF)


#define DRV_UART9_NUMUART   (5)


#define DRV_UART_BASE          (0x2000)


#define DRV_UART_BAUDH         (0x08)


#define DRV_UART_BAUDL         (0x04)


#define DRV_UART_CTRL          (0x1C)


#define DRV_UART_DATA          (0x00)


#define DRV_UART_FIFO_0         (1024)


#define DRV_UART_FIFO_1         (256)


#define DRV_UART_INTR          (0x14)


#define DRV_UART_INT_MODE   DRV_INT_EDGE_TRIG


#define DRV_UART_NUM				(20)//异步串口路数		//PM:4、IO1:16


#define DRV_UART_NUM_LIMIT        (32)//此基线支持32路异步串口


#define DRV_UART_REV_DATAERR (0x7)    //数据错误


#define DRV_UART_REV_NULL    (0x1)    //接收参数无效


#define DRV_UART_REV_STATEERR (0x5)   //状态错误


#define DRV_UART_REV_TIMEOUT (0x3)   //接收超时


#define DRV_UART_RXFIFO        (0x0C)


#define DRV_UART_SEND_NULL    (0x1)   //发送参数无效


#define DRV_UART_SEND_RUNOVER (0x5)   //发送溢出，要发送数据大于FIFO深度


#define DRV_UART_SEND_TIMEOUT (0x3)   //发送超时，DRV16C850时发送数据时间大于timeout


#define DRV_UART_STAT         (0x18)


#define DRV_UART_TXFIFO        (0x10)


#define DRV_UART_TYPE				DRVUSED//异步串口


#define E2PROM_A_BASEADDR  0x0


#define E2PROM_B_BASEADDR  0x0


#define E2PROM_SIZE08      0x0


#define ELETHRUST_H


#define ERROR				(-1)


#define ET_NUM             4


#define Expx(x)         (exp((float64)(x))                )


#define FALSE32             0x00000000u


#define FALSE32     0x00u


#define FAST	register


#define FDIR_CMD_QUE_BUF_LEN   300


#define FLASH_BASEADDR     0x10000000


#define FLASH_SIZE08       0x300000


#define FLI_OFFSET		(6)


#define FLT32_TO_MEM(fptr)          (*((volatile unint32 *)(fptr)))


#define FLT64_TO_MEM(fptr)          (*((volatile ulong64 *)(fptr)))


#define FLT_TO_SI08(x)                  ((unint08)((unint32)((siint32)(x)))


#define FLT_TO_SI16(x)                  ((unint16)((unint32)((siint32)(x)))


#define FLT_TO_SI32(x)                  ((unint32)((siint32)(x)))


#define FLT_TO_UN08(x)                  ((unint08)(llong64)(x))


#define FLT_TO_UN16(x)                  ((unint16)(llong64)(x))


#define FLT_TO_UN32(x)                  ((unint32)(llong64)(x))


#define FREE_BLOCK	(0x1)


#define FT_ADDR_A_CRU_DATA		0x00000


#define FT_ADDR_B_CRU_DATA		0x01000


#define FT_DIRECT               0x00000000


#define FT_LEN_BLACK_DATA		245u


#define FT_LEN_CRU_DATA			192u


#define FT_LEN_DATA_FRAME	    245u


#define FT_MAXLEN_BLACK_DATA    1024u


#define FT_RANK_ONE             0x55555555


#define FT_RANK_TWO             0xaaaaaaaa


#define Fabsx(x)        (fabs((float64)(x))               )


#define Floorx(x)       (floor((float64)(x))              )


#define GET_NEXT_BLOCK(_addr, _r)	((BHDR *) ((I8 *) (_addr) + (_r)))


#define GFH_3SGCMGRATECALC_H


#define GFH_ACCTRACK_H


#define GFH_CALSTATION_H


#define GFH_PSIPCALC_H


#define GFH_SADACONTROL_H


#define GFH_SGCMFRAMEHOLD_H


#define GFH_SGCMGRATECALC_H


#define GFH_THROUTPUTFILTER_H


#define GFH_ZEROMOMENTUMCALC_H


#define GFS_A6017DEFEND_AVAILABLE 				(1)


#define GFS_AUTO_EN_SEUINT_ENABLE 	(0)


#define GFS_CLR_APPINT_PEND_ENABLE 	(0)


#define GFS_CNT_RUNCORE				(2)


#define GFS_MULTI_EXTPERIOD_JOINT_ENABLE 	(0)


#define GFS_REBOOT_PROGLOAD_ENABLE 			(0)


#define GFS_REFRESHPERIOD_DAY						(365)


#define GFS_SPECIAL_INIT_ENABLE 	(0)


#define GPIO_NUM   (32) //GPIO 路数80-48, 无需修改


#define GPRS_NUM           7


#define GPS_SEC_CHNL_NUM        0x2


#define GYRO_GROUP_ABNORM_NUM		9


#define GYRO_GROUP_XYZ_NUM          1


#define HAVE_BROAD_TIME  1


#define HAVE_GNSS_TIME   1


#define ID_COMDIAG_DSSXYA     2


#define ID_COMDIAG_DSSXYB     3


#define ID_COMDIAG_GYRO1      4


#define ID_COMDIAG_GYRO2      5


#define ID_COMDIAG_GYRO3      6


#define ID_COMDIAG_GYRO4      7


#define ID_COMDIAG_GYRO5      8


#define ID_COMDIAG_GYRO6      9


#define ID_COMDIAG_GYRO7     10


#define ID_COMDIAG_GYRO8     11


#define ID_COMDIAG_GYRO9     12


#define ID_COMDIAG_SADEA     13


#define ID_COMDIAG_SADEB     14


#define ID_COMDIAG_STEA       0


#define ID_COMDIAG_STEB       1


#define ID_COMDIAG_STESYSA   15


#define ID_COMDIAG_STESYSB   16


#define IMPORT	extern


#define INPUT_HEAD


#define IN_RANGE_CLOSE(val, lo, up)     (((lo) <= (val)) && ((val) <= (up)))


#define IN_RANGE_LCUO(val, lo, up)      (((lo) <= (val)) && ((val) < (up)))


#define IN_RANGE_LOUC(val, lo, up)      (((lo) < (val)) && ((val) <= (up)))


#define IN_RANGE_OPEN(val, lo, up)      (((lo) < (val)) && ((val) < (up)))


#define IO_6017_EN_NUM (2) //6017使能寄存器的个数，无需修改


#define IO_6017_NUM					(3)//6017个数


#define IPM                             0x2


#define IPM_DAMP                0


#define IPM_MANUVERING          1


#define IPM_ORBIT               1


#define IPM_STABILIZING         2


#define IPM_SUNPOINT            0


#define IPM_USER_DEFINE         2


#define J1                              0


#define J2                              1


#define J3                              2


#define J4                              3


#define J5                              4


#define J6                              5


#define J7                              6


#define J8                              7


#define LIST_HEAD(name)     struct list_head name = LIST_HEAD_INIT(name)


#define LIST_HEAD_INIT(name) { &(name), &(name) }


#define LOCAL	static


#define Log10x(x)       (log10((float64)(x))              )


#define Logx(x)         (log((float64)(x))                )


#define MASK_ALL8F                      0xFFFFFFFFu


#define MASK_HI08                       0xFF000000u


#define MASK_HI16                       0xFFFF0000u


#define MASK_HL08                       0x00FF0000u


#define MASK_LH08                       0x0000FF00u


#define MASK_LO04                       0x0000000Fu


#define MASK_LO08                       0x000000FFu


#define MASK_LO16                       0x0000FFFFu


#define MAX_FLI			(30)


#define MAX_LOG2_SLI	(5)


#define MAX_PERIOD_N								CORE0_PERIOD_N


#define MAX_SLI			(1 << MAX_LOG2_SLI)


#define MEM_ALIGN					((BLOCK_ALIGN) - 1)


#define MEM_OP_CHECK                        (2)


#define MEM_OP_COPY							(1)


#define MEM_OP_DOWN                         (3)


#define MEM_OP_NULL							(0)


#define MEM_TO_FLT32(uptr)          (*((volatile float32 *)(uptr)))


#define MEM_TO_FLT64(ulptr)         (*((volatile float64 *)(ulptr)))


#define MIN(a, b)                       ((a) < (b) ? (a) : (b))


#define MIN_BLOCK_SIZE	(0x8)


#define MNV_Q_AA      0x33333333


#define MNV_Q_LINEAR  0x11111111


#define MNV_Q_MIX     0x22222222


#define MODE_CTRL_H


#define MODE_NUM                        0x6


#define MemRangeValidAll(addr, len08) \
	(MemRangeValidRam((addr), (len08)) & MemRangeValidE2((addr), (len08)) \
	& MemRangeValidNorFlash((addr), (len08)))


#define MemRangeValidE2(addr, len08) \
	(MemRangeValidE2A((addr), (len08)) & MemRangeValidE2B((addr), (len08)))


#define MemRangeValidE2A(addr, len08) \
	(!!MemRangeValid((addr), (len08), E2PROM_A_BASEADDR, E2PROM_SIZE08))


#define MemRangeValidE2B(addr, len08) \
	(!!MemRangeValid((addr), (len08), E2PROM_B_BASEADDR, E2PROM_SIZE08))


#define MemRangeValidNorFlash(addr, len08) \
	(!!MemRangeValid((addr), (len08), FLASH_BASEADDR, FLASH_SIZE08))


#define MemRangeValidRam(addr, len08) \
	(!!MemRangeValid((addr), (len08), RAM_BASEADDR, RAM_SIZE08))


#define MemRangeValid_EEPROM_NorFlash(addr, len08) \
	(MemRangeValidE2((addr), (len08)) & MemRangeValidNorFlash((addr), (len08)))


#define NAVI_NUM   NAVI_GNSS+NAVI_SELF_AL+NAVI_ASTRO


#define NELEMENTS(array)  (sizeof (array) / sizeof ((array) [0]))


#define NFLASH_CS_ADDRINTER		(0x1<<CS_Bit) //NANDFLASH片选地址间隔


#define NFTYPE	0x3D //0x0B //0x3D //进口3D器件则设置为: 0x3D, 否则设置为国产欧比特器件: 0x0B


#define NM                              0x5


#define NO_WAIT				(0)


#define NPRIO						(64)


#define NULL 				(0)


#define NULL_STATEMENT()    {_nullStatement = 0;}


#define NUM_FACTION	8


#define NUM_OBT_INJECT 10


#define OBT_IN                  0x11111111


#define OBT_INVALID             0x22222222


#define OBT_IN_FROM_INIT		0x00000000


#define OBT_IN_FROM_OTHER		0x22222222


#define OBT_IN_FROM_TCMD		0x11111111


#define OBT_NOIN                0x00000000


#define OBT_RESTORE             0x33333333


#define OK					(0)


#define OSFALSE				(0)


#define OSTICK_TT  		(0x10|BSP_INTID_RTCT)


#define OSTRUE				(1)


#define OS_CONTEXT_OFFSET		(0x54)


#define OS_CONTEXT_STK_SIZE		(0x68)		//(0x64)


#define OS_CPU_0_ENTICK					(1)


#define OS_CPU_1_ENTICK					(1)


#define OS_CPU_2_ENTICK					(0)


#define OS_CPU_3_ENTICK					(0)


#define OS_CPU_INT_CNT			(0x100)


#define OS_CPU_INT_CNT_POWER			(0x8)


#define OS_CPU_NUMBER						(BSP_CPU_NUMBER)


#define OS_CPU_PSR_CWP_MASK		(0x0007)


#define OS_CPU_PSR_EF_MASK		(0x1000)


#define OS_CPU_PSR_ET_MASK		(0x0020)


#define OS_CPU_PSR_PIL_MASK		(0x0f00)


#define OS_CPU_PSR_PS_MASK		(0x0040)


#define OS_CPU_PSR_S_MASK		(0x0080)


#define OS_CPU_STACK_FRAME_I0_OFFSET		(0x20)


#define OS_CPU_STACK_FRAME_I1_OFFSET		(0x24)


#define OS_CPU_STACK_FRAME_I2_OFFSET		(0x28)


#define OS_CPU_STACK_FRAME_I3_OFFSET		(0x2c)


#define OS_CPU_STACK_FRAME_I4_OFFSET		(0x30)


#define OS_CPU_STACK_FRAME_I5_OFFSET		(0x34)


#define OS_CPU_STACK_FRAME_I6_FP_OFFSET		(0x38)


#define OS_CPU_STACK_FRAME_I7_OFFSET		(0x3c)


#define OS_CPU_STACK_FRAME_L0_OFFSET  		(0x00)


#define OS_CPU_STACK_FRAME_L1_OFFSET		(0x04)


#define OS_CPU_STACK_FRAME_L2_OFFSET		(0x08)


#define OS_CPU_STACK_FRAME_L3_OFFSET		(0x0c)


#define OS_CPU_STACK_FRAME_L4_OFFSET		(0x10)


#define OS_CPU_STACK_FRAME_L5_OFFSET		(0x14)


#define OS_CPU_STACK_FRAME_L6_OFFSET		(0x18)


#define OS_CPU_STACK_FRAME_L7_OFFSET		(0x1c)


#define OS_CPU_SYSFSR_ASFV_MASK			0x0100			//mask the bit of ASFV field in system fault status register


#define OS_CPU_SYSFSR_SRFT_MASK			0x0078			//mask the bits of SRFT field in system fault status register


#define OS_CPU_SYSFSR_SRFV_MASK			0x0004			//mask the bit of SRFV field in system fault status register


#define OS_CPU_TBR_TT_MASK		(0x0ff0)  	//mask the bits of TT field in trap base register


#define OS_DATA_OFFSET					(0x1D0E00)


#define OS_DATA_SIZE						(1024*1024)


#define OS_ERR_PRIOSET_ID_NULL		(OS_ERR_INTERNAL_LIB  | ( 0x2<<8) | 0x1)


#define OS_ERR_RDYSTAT_YET			(OS_ERR_INTERNAL_LIB  | ( 0x1<<8) | 0x4)


#define OS_ERR_TASKDELETE_CALL_IN_LOCK	(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x5)


#define OS_F0_OFFSET			(0x00)


#define OS_F10_OFFSET			(0x28)


#define OS_F11_OFFSET			(0x2c)


#define OS_F12_OFFSET			(0x30)


#define OS_F13_OFFSET			(0x34)


#define OS_F14_OFFSET			(0x38)


#define OS_F15_OFFSET			(0x3c)


#define OS_F16_OFFSET			(0x40)


#define OS_F17_OFFSET			(0x44)


#define OS_F18_OFFSET			(0x48)


#define OS_F19_OFFSET			(0x4c)


#define OS_F1_OFFSET			(0x04)


#define OS_F20_OFFSET			(0x50)


#define OS_F21_OFFSET			(0x54)


#define OS_F22_OFFSET			(0x58)


#define OS_F23_OFFSET			(0x5c)


#define OS_F24_OFFSET			(0x60)


#define OS_F25_OFFSET			(0x64)


#define OS_F26_OFFSET			(0x68)


#define OS_F27_OFFSET			(0x6c)


#define OS_F28_OFFSET			(0x70)


#define OS_F29_OFFSET			(0x74)


#define OS_F2_OFFSET			(0x08)


#define OS_F30_OFFSET			(0x78)


#define OS_F31_OFFSET			(0x7c)


#define OS_F3_OFFSET			(0x0c)


#define OS_F4_OFFSET			(0x10)


#define OS_F5_OFFSET			(0x14)


#define OS_F6_OFFSET			(0x18)


#define OS_F7_OFFSET			(0x1c)


#define OS_F8_OFFSET			(0x20)


#define OS_F9_OFFSET			(0x24)


#define OS_FCONTEXT_SIZE		(0x88)		//(0x84)


#define OS_FREGCONTEXT_OFFSET	(0xa8)


#define OS_FSR_OFFSET			(0x80)


#define OS_G0_OFFSET			(0x30)


#define OS_G1_OFFSET			(0x34)


#define OS_G2_OFFSET			(0x38)


#define OS_G3_OFFSET			(0x3c)


#define OS_G4_OFFSET			(0x40)


#define OS_G5_OFFSET			(0x44)


#define OS_G6_OFFSET			(0x48)


#define OS_G7_OFFSET			(0x4c)


#define OS_I0_OFFSET			(0x10)


#define OS_I1_OFFSET			(0x14)


#define OS_I2_OFFSET			(0x18)


#define OS_I3_OFFSET			(0x1c)


#define OS_I4_OFFSET			(0x20)


#define OS_I5_OFFSET			(0x24)


#define OS_I6_OFFSET			(0x28)


#define OS_I7_OFFSET			(0x2c)


#define OS_IDLE_PRIO					(63)


#define OS_IDLE_TASK_STACKSIZE	(0x4000)


#define OS_INTSTK_SIZE					(32*1024)


#define OS_INT_STK_HIGHBASE						(((OS_INT_STK_LOWBASE+OS_INTSTK_SIZE)&0xFFFFFFF8)-8)


#define OS_INT_STK_LOWBASE						(OS_SYSSTK_LOWBASE+OS_SYSSTK_SIZE+OS_ISOLATION_SIZE)


#define OS_INVALID_ID		(0)


#define OS_ISOLATION_SIZE				(512)


#define OS_ISRMAP_ARG_OFFSET	(0x8)


#define OS_ISRMAP_HANDLE_OFFSET	(0x4)


#define OS_ISRMAP_SIZEPOWER		(4)//(3)


#define OS_ISRMAP_TYPE_OFFSET  	(0)


#define OS_L0_OFFSET			(0x00)


#define OS_L1_OFFSET			(0x04)


#define OS_L2_OFFSET			(0x08)


#define OS_L3_OFFSET			(0x0c)


#define OS_MEM_CHK_ID		(4)


#define OS_MEM_POOL_ADDR						(OS_INT_STK_LOWBASE+OS_INTSTK_SIZE+OS_ISOLATION_SIZE)


#define OS_MEM_POOL_SIZE				(384*1024)//(256*1024)


#define OS_MQ_CHK_ID		(3)


#define OS_NWINDOWS				(8)


#define OS_PERIODIC_INT		(-1)


#define OS_SEM_CHK_ID		(2)


#define OS_SINGLE_INT		(0)


#define OS_SYSIDLETASK_NAME		(0x1001)


#define OS_SYSSTK_BASE							(((OS_SYSSTK_LOWBASE+OS_SYSSTK_SIZE)&0xFFFFFFF8)-8)


#define OS_SYSSTK_LOWBASE						(0x166800)


#define OS_SYSSTK_SIZE					(8*1024)


#define OS_TASKINFOREC_SIZE			(0)


#define OS_TASK_CHK_ID		(1)


#define OS_TASK_DEFAULT_OPTION		(0x0)


#define OS_TASK_DEFAULT_STACKSIZE		(0x400)


#define OS_TASK_DELAY				(0x02)


#define OS_TASK_DELETED				(0x0f)


#define OS_TASK_INFO_REC_HIGHBASE				(OS_TASK_INFO_REC_LOWBASE+OS_TASKINFOREC_SIZE-16)//改为减16，会任务调动信息记录函数有关,xj,2013.3.30


#define OS_TASK_INFO_REC_LOWBASE				(OS_DATA_OFFSET+OS_DATA_SIZE+OS_SYSSTK_SIZE+OS_INTSTK_SIZE+OS_MEM_POOL_SIZE)


#define OS_TASK_PEND				(0x04)


#define OS_TASK_READY				(0x01)


#define OS_TASK_RR_TICKS				(1)


#define OS_TASK_RUN					(0x10)


#define OS_TASK_STACK_FILL_DATA			(0x0)


#define OS_TASK_STACK_FILL_DATA_SIZE	(400)


#define OS_TASK_STACK_INIT_ALL


#define OS_TASK_SUSPEND				(0x08)


#define OS_TEXT_OFFSET				(0x18000)


#define OS_TEXT_SIZE					(1024*1024)


#define OS_TIME_TICKS_PER_SEC		(500)


#define OS_TRAP_ADDR_OFFSET		(0x2)


#define OS_Y_OFFSET				(0x50)


#define PACKED


#define PACKED                    __attribute__ ((aligned(1), packed))


#define PREV_FREE	(0x2)


#define PREV_STATE	(0x2)


#define PREV_USED	(0x0)


#define PTH_BASAL_HEAD


#define PTH_DECL_HEAD


#define PTR_MASK		(3)


#define Powx(x, y)      (pow((float64)(x), (float64)(y))  )


#define QFirstNode(qhead)		((qhead)->Head)


#define QInsertHead(qhead, qnode)	do	 			\
			{											\
				QInsert((qhead), (Q_NODE *)NULL, (qnode));	\
			}while(0)


#define QInsertTail(qhead, qnode)	do				\
	 		{											\
				QInsert((qhead), (qhead)->Tail, (qnode));	\
			}while(0)


#define QLastNode(qhead)		((qhead)->Tail)


#define QNextNode(qnode)		((qnode)->Next)


#define QPrevNode(qnode)		((qnode)->Prev)


#define RAM_BASEADDR  0x40000000


#define RAM_SIZE08    0x400000


#define REAL(i)      (U32)(*((V_U32*)(&i)))


#define REAL64(i)      (U64)(*((V_U64*)(&i)))


#define REAL_FLI		(MAX_FLI - FLI_OFFSET)


#define REF_DN                  0x00000000


#define REF_INERTPOINT          0x33333333


#define REF_ORBIT               0x11111111


#define REF_QRI                 0x44444444


#define REF_SUNPOINT            0x22222222


#define REG_BC_CTW_D00_RT2RT_FORMAT         0x0001u


#define REG_BC_CTW_D01_BRD_FORMAT           0x0002u


#define REG_BC_CTW_D02_MODE_FORMAT          0x0004u


#define REG_BC_CTW_D03_1553AB_SELE          0x0008u


#define REG_BC_CTW_D04_EOMINT_EN            0x0010u


#define REG_BC_CTW_D05_BRDCAST_MASK         0x0020u


#define REG_BC_CTW_D06_OFF_TEST             0x0040u


#define REG_BC_CTW_D07_CHNL_AB              0x0080u


#define REG_BC_CTW_D08_RETRY_EN             0x0100u


#define REG_BC_CTW_D09_REVDFLG_MASK         0x0200u


#define REG_BC_CTW_D10_TERFLG_MASK          0x0400u


#define REG_BC_CTW_D11_SUBFLG_MASK          0x0800u


#define REG_BC_CTW_D12_SUBBUSY_MASK         0x1000u


#define REG_BC_CTW_D13_SERACQ_MASK          0x2000u


#define REG_BC_CTW_D14_MSGERR_MASK          0x4000u


#define REG_BC_CTW_D15_RESERVED             0x8000u


#define REG_CFG1_D00_BC_MSG_IN_PROG         0x0001u


#define REG_CFG1_D00_MT_MSG_IN_PRO          0x0001u


#define REG_CFG1_D00_RT_MSG_IN_PRO          0x0001u


#define REG_CFG1_D01_BC_FRAME_IN_PROG       0x0002u


#define REG_CFG1_D01_MT_MONI_TRIG           0x0002u


#define REG_CFG1_D01_RT_NOT_USED            0x0002u


#define REG_CFG1_D02_BC_ENABLED             0x0004u


#define REG_CFG1_D02_MT_MONI_EN_R           0x0004u


#define REG_CFG1_D02_RT_NOT_USED            0x0004u


#define REG_CFG1_D03_BC_DBL_RETRY           0x0008u


#define REG_CFG1_D03_MT_NOT_USED            0x0008u


#define REG_CFG1_D03_RT_NOT_USED            0x0008u


#define REG_CFG1_D04_BC_RETRY_EN            0x0010u


#define REG_CFG1_D04_MT_NOT_USED            0x0010u


#define REG_CFG1_D04_RT_NOT_USED            0x0010u


#define REG_CFG1_D05_BC_MSG_GAPTIMER        0x0020u


#define REG_CFG1_D05_MT_NOT_USED            0x0020u


#define REG_CFG1_D05_RT_MSG_GAPTIMER        0x0020u


#define REG_CFG1_D06_BC_INTL_TRIGGER        0x0040u


#define REG_CFG1_D06_MT_NOT_USED            0x0040u


#define REG_CFG1_D06_RT_INTL_TRIGGER        0x0040u


#define REG_CFG1_D07_BC_EXTL_TRIGGER        0x0080u


#define REG_CFG1_D07_MT_EX_TRIG_EN          0x0080u


#define REG_CFG1_D07_RT_NOT_RTFLAG          0x0080u


#define REG_CFG1_D08_BC_FRAME_AUTO          0x0100u


#define REG_CFG1_D08_MT_NOT_USED            0x0100u


#define REG_CFG1_D08_RT_NOT_SUBSYS_FLAG     0x0100u


#define REG_CFG1_D09_BC_ST_SET_STOF         0x0200u


#define REG_CFG1_D09_MT_STOP_ON_TRIG        0x0200u


#define REG_CFG1_D09_RT_NOT_SERVICE_REQ     0x0200u


#define REG_CFG1_D10_BC_ST_SET_STOM         0x0400u


#define REG_CFG1_D10_MT_START_ON_TRIG       0x0400u


#define REG_CFG1_D10_RT_NOT_BUSY            0x0400u


#define REG_CFG1_D11_BC_FRAME_STOP_ERR      0x0800u


#define REG_CFG1_D11_MT_TRIG_EN             0x0800u


#define REG_CFG1_D11_RT_NOT_DYN_BUS         0x0800u


#define REG_CFG1_D12_BC_MSG_STOP_ERR        0x1000u


#define REG_CFG1_D12_MT_MSG_MONI_EN         0x1000u


#define REG_CFG1_D12_RT_MSG_MONI_EN         0x1000u


#define REG_CFG1_D13_BC_AREA_B_SELECT       0x2000u


#define REG_CFG1_D13_MT_AREA_B_SELECT       0x2000u


#define REG_CFG1_D13_RT_AREA_B_SELECT       0x2000u


#define REG_CFG1_D14_BC_MT_SELECT           0x4000u


#define REG_CFG1_D14_MT_MT_SELECT           0x4000u


#define REG_CFG1_D14_RT_MT_SELECT           0x4000u


#define REG_CFG1_D15_BC_RT_SELECT           0x8000u


#define REG_CFG1_D15_MT_RT_SELECT           0x8000u


#define REG_CFG1_D15_RT_RT_SELECT           0x8000u


#define REG_CFG2_D00_SEP_BCST_DATA          0x0001u


#define REG_CFG2_D01_EHD_RT_MEMM            0x0002u


#define REG_CFG2_D02_CLEAR_SR               0x0004u


#define REG_CFG2_D03_LEVEL_INT              0x0008u


#define REG_CFG2_D04_INT_AUTO_CLEAR         0x0010u


#define REG_CFG2_D05_LOAD_TTAG_SYN          0x0020u


#define REG_CFG2_D06_CLEAR_TTAG_SYN         0x0040u


#define REG_CFG2_D07_TTAG_R0                0x0080u


#define REG_CFG2_D08_TTAG_R1                0x0100u


#define REG_CFG2_D09_TTAG_R2                0x0200u


#define REG_CFG2_D10_256_DISBL              0x0400u


#define REG_CFG2_D11_INVALID_DATA           0x0800u


#define REG_CFG2_D12_DBL_BUF_EN             0x1000u


#define REG_CFG2_D13_BUSY_LUT_EN            0x2000u


#define REG_CFG2_D14_RAM_PTY_EN             0x4000u


#define REG_CFG2_D15_EHD_INT                0x8000u


#define REG_CFG3_D00_RT_EHD_HDL             0x0001u


#define REG_CFG3_D01_1553A_EN               0x0002u


#define REG_CFG3_D02_RT_FFW_EN              0x0004u


#define REG_CFG3_D03_BUSY_TRAN_EN           0x0008u


#define REG_CFG3_D04_ILL_TRAN_DIS           0x0010u


#define REG_CFG3_D05_RT_ALT_ST_EN           0x0020u


#define REG_CFG3_D06_RT_OVERRIDE_T_ERR      0x0040u


#define REG_CFG3_D07_RT_ILL_DIS             0x0080u


#define REG_CFG3_D08_MT_DATSTK_SIZE_0       0x0100u


#define REG_CFG3_D09_MT_DATSTK_SIZE_1       0x0200u


#define REG_CFG3_D10_MT_DATSTK_SIZE_2       0x0400u


#define REG_CFG3_D11_MT_CMDSTK_SIZE_0       0x0800u


#define REG_CFG3_D12_MT_CMDSTK_SIZE_1       0x1000u


#define REG_CFG3_D13_BCRT_CMDSTK_SIZE0      0x2000u


#define REG_CFG3_D14_BCRT_CMDSTK_SIZE1      0x4000u


#define REG_CFG3_D15_ENHANCED_EN            0x8000u


#define REG_CFG4_D00_TM0                    0x0001u


#define REG_CFG4_D01_TM1                    0x0002u


#define REG_CFG4_D02_TM2                    0x0004u


#define REG_CFG4_D03_RTADDR_CFG5            0x0008u


#define REG_CFG4_D04_MT_TAG_OPTION          0x0010u


#define REG_CFG4_D05_VALID_BUSY_BIT         0x0020u


#define REG_CFG4_D06_VALID_MSG_ERR          0x0040u


#define REG_CFG4_D07_SEC_RETRY_ALT          0x0080u


#define REG_CFG4_D08_FST_RETRY_ALT          0x0100u


#define REG_CFG4_D09_RETRY_ST_SET           0x0200u


#define REG_CFG4_D10_RETRY_MSG_ERR          0x0400u


#define REG_CFG4_D11_BC_BCST_MK_EN          0x0800u


#define REG_CFG4_D12_BC_EXPD_CW_EN          0x1000u


#define REG_CFG4_D13_RT_MODE_OV_BUSY        0x2000u


#define REG_CFG4_D14_RT_INBW_BUSY           0x4000u


#define REG_CFG4_D15_RT_EXBW_EN             0x8000u


#define REG_CFG5_D00_RT_ADDRPTY_R           0x0001u


#define REG_CFG5_D01_RT_A0_R                0x0002u


#define REG_CFG5_D02_RT_A1_R                0x0004u


#define REG_CFG5_D03_RT_A2_R                0x0008u


#define REG_CFG5_D04_RT_A3_R                0x0010u


#define REG_CFG5_D05_RT_A4_R                0x0020u


#define REG_CFG5_D06_RT_A_LATCH             0x0040u


#define REG_CFG5_D07_BCST_DIS               0x0080u


#define REG_CFG5_D08_GAP_CHK_EN             0x0100u


#define REG_CFG5_D09_RTIME_SELE0            0x0200u


#define REG_CFG5_D10_RTIME_SELE1            0x0400u


#define REG_CFG5_D11_EXPD_CROSS_EN          0x0800u


#define REG_CFG5_D12_EXT_TX_B               0x1000u


#define REG_CFG5_D13_EXT_TX_A               0x2000u


#define REG_CFG5_D14_SNGL_SELT              0x4000u


#define REG_CFG5_D15_12M_SELT               0x8000u


#define REG_INTMK_D00_EOM                   0x0001u


#define REG_INTMK_D01_BC_ST_SET             0x0002u


#define REG_INTMK_D01_MT_TRIGGER            0x0002u


#define REG_INTMK_D01_RT_MD_CODE            0x0002u


#define REG_INTMK_D02_FORMAT_ERR            0x0004u


#define REG_INTMK_D03_BC_EOF                0x0008u


#define REG_INTMK_D04_BC_MSG_EOM            0x0010u


#define REG_INTMK_D04_RT_CTRL_EOM           0x0010u


#define REG_INTMK_D05_RT_CIRC_ROLL          0x0020u


#define REG_INTMK_D06_TIME_TAG_ERR          0x0040u


#define REG_INTMK_D07_RT_ADDR_PERR          0x0080u


#define REG_INTMK_D08_BC_RETRY              0x0100u


#define REG_INTMK_D09_HDSHAKE_FAIL          0x0200u


#define REG_INTMK_D10_MT_DATA_ROLL          0x0400u


#define REG_INTMK_D11_MT_CMD_ROLL           0x0800u


#define REG_INTMK_D12_CMD_ROLL              0x1000u


#define REG_INTMK_D13_TX_TOUT               0x2000u


#define REG_INTMK_D14_RAM_PERR              0x4000u


#define REG_INTMK_D15_RSERVED               0x8000u


#define REG_INT_ST_D00_EOM                  0x0001u


#define REG_INT_ST_D01_BC_STATUS            0x0002u


#define REG_INT_ST_D01_MT_TRIGGER           0x0002u


#define REG_INT_ST_D01_RT_MODE              0x0002u


#define REG_INT_ST_D02_FMAT_ERR             0x0004u


#define REG_INT_ST_D03_BC_EOF               0x0008u


#define REG_INT_ST_D04_RT_CTRL_EOM          0x0010u


#define REG_INT_ST_D05_RT_BUF_ROLL          0x0020u


#define REG_INT_ST_D06_TIME_TAG_ERR         0x0040u


#define REG_INT_ST_D07_RT_ADDR_ERR          0x0080u


#define REG_INT_ST_D08_BC_RETRY             0x0100u


#define REG_INT_ST_D09_HDSHAKE              0x0200u


#define REG_INT_ST_D10_MT_DATA_ROLL         0x0400u


#define REG_INT_ST_D11_MTCMD_ROLL           0x0800u


#define REG_INT_ST_D12_CMD_ROLL             0x1000u


#define REG_INT_ST_D13_TRAN_TOUT            0x2000u


#define REG_INT_ST_D14_RAM_ERR              0x4000u


#define REG_INT_ST_D15_MASTER               0x8000u


#define REG_RT_SACW_D00_BCST_MM0            0x0001u


#define REG_RT_SACW_D01_BCST_MM1            0x0002u


#define REG_RT_SACW_D02_BCST_MM2            0x0004u


#define REG_RT_SACW_D03_BCST_CIRC_BUF_INT   0x0008u


#define REG_RT_SACW_D04_BCST_EOM_INT        0x0010u


#define REG_RT_SACW_D05_RX_MM0              0x0020u


#define REG_RT_SACW_D06_RX_MM1              0x0040u


#define REG_RT_SACW_D07_RX_MM2              0x0080u


#define REG_RT_SACW_D08_RX_CIRC_BUF_INT     0x0100u


#define REG_RT_SACW_D09_RX_EOM_INT          0x0200u


#define REG_RT_SACW_D10_TX_MM0              0x0400u


#define REG_RT_SACW_D11_TX_MM1              0x0800u


#define REG_RT_SACW_D12_TX_MM2              0x1000u


#define REG_RT_SACW_D13_TX_CIRC_BUF_INT     0x2000u


#define REG_RT_SACW_D14_TX_EOM_INT          0x4000u


#define REG_RT_SACW_D15_RX_DBUF_EN          0x8000u


#define REG_START_D00_RESET                 0x0001u


#define REG_START_D01_BC_START              0x0002u


#define REG_START_D01_MT_START              0x0002u


#define REG_START_D02_INT_RESET             0x0004u


#define REG_START_D03_TTAG_RESET            0x0008u


#define REG_START_D04_TTAG_CLOCK            0x0010u


#define REG_START_D05_BC_STOF               0x0020u


#define REG_START_D06_BC_STOM               0x0040u


#define REG_START_D06_MT_STOM               0x0040u


#define REG_START_D15_D07_RESERVED          0x0000u


#define REQ_CMG_GIM          0x2


#define REQ_CMG_NONE         0x0


#define REQ_CMG_ROT          0x1


#define REQ_DSS_RECONFIG_SAM 0x4


#define REQ_ELETHR_CLOSE		 0x2


#define REQ_ELETHR_NONE			 0x0


#define REQ_ELETHR_OPEN			 0x1


#define REQ_NONE             0x0


#define REQ_POWEROFF         0x3


#define REQ_POWERON          0x2


#define REQ_RECONFIG         0x1


#define REQ_THR_CLOSELV          0x5


#define REQ_THR_NONE             0x0


#define REQ_THR_POWERON_490NBUS  0x4


#define REQ_THR_REAG             0x6


#define REQ_THR_REAG_Other		 0x9


#define REQ_THR_REAK             0x7


#define REQ_THR_RECONFIG         0x8


#define REQ_THR_SAFE             0x1


#define REQ_THR_WAL              0x3


#define REQ_THR_WTF              0x2


#define REQ_TPAC_START			 0x3


#define RET_CMG_GIM_READY    0x2


#define RET_CMG_NO           0x3


#define RET_CMG_NONE         0x0


#define RET_CMG_ROT_READY    0x1


#define RET_NONE             0x0


#define RET_POWEROFF_READY   0x5


#define RET_POWERON_NO       0x4


#define RET_POWERON_READY    0x3


#define RET_RECONFIG_NO      0x1


#define RET_RECONFIG_READY   0x2


#define RNG_DLE_H


#define RNG_POINTER_N_DEC(rngId, p, n)  RngPointerDec((rngId), (p), (n))


#define RNG_POINTER_N_INC(rngId, p, n)  RngPointerInc((rngId), (p), (n))


#define RNG_SKIP_N(rngId, n)            RngPointerInc((rngId), &((rngId)->pFromBuf), (n))


#define ROUNDDOWN_SIZE(_r)			((_r) & ~MEM_ALIGN)


#define ROUNDUP(_x, _v)				((((~(_x)) + 1) & ((_v)-1)) + (_x))


#define ROUNDUP_SIZE(_r)			(((_r) + MEM_ALIGN) & ~MEM_ALIGN)


#define ROUND_DOWN(x, align)	((U32)(x) & ~((align) - 1))


#define ROUND_UP(x, align)		(((U32) (x) + ((align) - 1)) & ~((align) - 1))


#define RT_BSTW_D00_CMDERR              0x0001


#define RT_BSTW_D01_RT2RT_2CMDERR       0x0002


#define RT_BSTW_D02_RT2RT_ERR           0x0004


#define RT_BSTW_D03_INVALIDWORD         0x0008


#define RT_BSTW_D04_NODATASYNC          0x0010


#define RT_BSTW_D05_WDCNTERR            0x0020


#define RT_BSTW_D06_ILLCMD              0x0040


#define RT_BSTW_D07_DATASTACKRL         0x0080


#define RT_BSTW_D08_LTSTFAIL            0x0100


#define RT_BSTW_D09_NORSP               0x0200


#define RT_BSTW_D10_FMTERR              0x0400


#define RT_BSTW_D11_RT2RT               0x0800


#define RT_BSTW_D12_ERRFLG              0x1000


#define RT_BSTW_D13_CHNL                0x2000


#define RT_BSTW_D14_SOM                 0x4000


#define RT_BSTW_D15_EOM                 0x8000


#define RT_MEM_A_BRCT_TBL(i)            (RT_MEM_A_LOOKUP_TBL + 0x40 + (i))


#define RT_MEM_A_CTRL_TBL(i)            (RT_MEM_A_LOOKUP_TBL + 0x60 + (i))


#define RT_MEM_A_LOOKUP_TBL             0x0140


#define RT_MEM_A_RECV_TBL(i)            (RT_MEM_A_LOOKUP_TBL + 0x00 + (i))


#define RT_MEM_A_STK                    0x0100


#define RT_MEM_A_TRAN_TBL(i)            (RT_MEM_A_LOOKUP_TBL + 0x20 + (i))


#define RT_MEM_BUSY_LOOKUP_TBL          0x0240


#define RT_MEM_B_BRCT_TBL(i)            (RT_MEM_B_LOOKUP_TBL + 0x40 + (i))


#define RT_MEM_B_CTRL_TBL(i)            (RT_MEM_B_LOOKUP_TBL + 0x60 + (i))


#define RT_MEM_B_LOOKUP_TBL             0x01C0


#define RT_MEM_B_RECV_TBL(i)            (RT_MEM_B_LOOKUP_TBL + 0x00 + (i))


#define RT_MEM_B_STK                    0x0104


#define RT_MEM_B_TRAN_TBL(i)            (RT_MEM_B_LOOKUP_TBL + 0x20 + (i))


#define RT_MEM_CMDILL_TBL(i)            (0x0300 + (i))


#define RT_MEM_CMD_ILL_TBL              0x0300


#define RT_MEM_CONF_STK_A 0x0E00


#define RT_MEM_CONF_STK_B 0x0F00


#define RT_MEM_MODE CODE DATA           0x0110


#define RT_MEM_MODE_CODE_TBL            0x0108


#define RT_SA00                     0u


#define RT_SA01                     1u


#define RT_SA02                     2u


#define RT_SA03                     3u


#define RT_SA04                     4u


#define RT_SA05                     5u


#define RT_SA06                     6u


#define RT_SA07                     7u


#define RT_SA08                     8u


#define RT_SA09                     9u


#define RT_SA10                     10u


#define RT_SA11                     11u


#define RT_SA12                     12u


#define RT_SA13                     13u


#define RT_SA14                     14u


#define RT_SA15                     15u


#define RT_SA16                     16u


#define RT_SA17                     17u


#define RT_SA18                     18u


#define RT_SA19                     19u


#define RT_SA20                     20u


#define RT_SA21                     21u


#define RT_SA22                     22u


#define RT_SA23                     23u


#define RT_SA24                     24u


#define RT_SA25                     25u


#define RT_SA26                     26u


#define RT_SA27                     27u


#define RT_SA28                     28u


#define RT_SA29                     29u


#define RT_SA30                     30u


#define RT_SA31                     31u


#define RT_STACK_MASK      	(RT_STACK_SIZE-0x4)


#define RT_STACK_SIZE      	0x0200


#define RT_STW_D00_TERMINAL_FLG         0x0001


#define RT_STW_D01_DYN_BUS_ACP          0x0002


#define RT_STW_D02_SUB_SYS_FLG          0x0004


#define RT_STW_D03_BUSY                 0x0008


#define RT_STW_D04_BCST_RES             0x0010


#define RT_STW_D05_RES                  0x0020


#define RT_STW_D06_RES                  0x0040


#define RT_STW_D07_RES                  0x0080


#define RT_STW_D08_SER_REQ              0x0100


#define RT_STW_D09_INSTRUMENT           0x0200


#define RT_STW_D10_MSG_ERR              0x0400


#define RT_STW_D11_ZERO                 0x0800


#define RT_STW_D12_ZERO                 0x1000


#define RT_STW_D13_ZERO                 0x2000


#define RT_STW_D14_ZERO                 0x4000


#define RT_STW_D15_ZERO                 0x8000


#define SACTRL_POS_BRCT             	0u


#define SACTRL_POS_RECV             	5u


#define SACTRL_POS_TRAN             	10u


#define SADA_CRUISE		0x2


#define SADA_HOLD		0x0


#define SADA_INCR		0x1


#define SADA_ZERO       0x3


#define SAM                             0x1


#define SAM_CRUISE              3


#define SAM_DAMP                0


#define SAM_PHI                 2


#define SAM_THETA               1


#define SA_BRCT							0


#define SA_NULL							255


#define SA_RECV							1


#define SA_TRAN							2


#define SBM                             0x0


#define SF_GYRO_33Y2B_H


#define SI08_TO_DBL(x)                  ((float64)((siint08)(x)))


#define SI16_TO_DBL(x)                  ((float64)((siint16)(x)))


#define SI16_TO_FLT(x)                  ((float32)((siint16)(x)))


#define SI32_TO_DBL(x)                  ((float64)((siint32)(x)))


#define SI32_TO_FLT(x)                  ((float32)((siint32)(x)))


#define SIZEOF(v)                       ((unint32)sizeof(v))


#define SI_DSS                        0x01


#define SI_ES                         0x05


#define SI_KALMAN                     0x04


#define SI_NO                         0x00


#define SI_QUATERNION                 0x06


#define SI_RIGA                       0x02


#define SI_STS                        0x03


#define SKK_DIR_NONE            0x00000000


#define SKM                             0x4


#define SMALL_BLOCK		(128)


#define SMP_BSPSTACKSIZE		(OS_SYSSTK_SIZE>>2)


#define SS13     2


#define SS43     3


#define SS61     0


#define SS62     1


#define STD_1553_BC_H


#define STD_1553_H


#define STD_1553_REG_H


#define STD_1553_RT_H


#define STD_ADDR_H


#define STD_BASAL_H


#define STD_BIT_OPERATION_H


#define STD_COMMON_H


#define STD_CRI_DATA_SR_EX_HHH


#define STD_CRI_DATA_SR_IN_HHH


#define STD_GFH_H


#define STD_MACRO_FUN_EXP_H


#define STD_STRUCT_H


#define STD_TYPE_CONVERT_H


#define STD_UTILS_H


#define STS_GYRO_H


#define STS_SEL_GROUP	   6


#define ST_HA_APS3_2C_HEAD


#define ST_HA_APS6_1_H


#define ST_VHA5S_3_H


#define SYSFALSE			0x0


#define SYSTRUE				0xeb90146f


#define SYS_BASE_PERIOD_TIME_MS						(SYS_PERIOD_TIME_MS)


#define SYS_BASE_TICKNUM_PER_PERIOD				(SYS_BASE_PERIOD_TIME_MS*OS_TIME_TICKS_PER_SEC/1000)


#define SYS_CtrlPeriod_ScalerAndSrc_Reg		(*(V_U32*)(SYS_IOASIC_BASEADDR+0x100C))


#define SYS_CtrlPeriod_ScalerSelect		(0x0)


#define SYS_CtrlPeriod_Scaler_us					(1)


#define SYS_CtrlPeriod_Scaler_us					(1.25)


#define SYS_CtrlPeriod_Scaler_us					(10)


#define SYS_CtrlPeriod_Scaler_us					(100)


#define SYS_CtrlPeriod_Scaler_us					(12.5)


#define SYS_CtrlPeriod_Scaler_us					(125)


#define SYS_CtrlPeriod_Scaler_us					(50)


#define SYS_CtrlPeriod_Scaler_us					(62.5)


#define SYS_CtrlPeriod_SetHigh4Bit_Reg		(*(V_U32*)(SYS_IOASIC_BASEADDR+0x1008))


#define SYS_CtrlPeriod_SetLow16Bit_Reg		(*(V_U32*)(SYS_IOASIC_BASEADDR+0x1004))


#define SYS_CtrlPeriod_Set_Reg			(*(V_U32*)(SYS_FPGA_BASEADDR+0x1100))


#define SYS_CtrlPeriod_SrcSelect			(0x0)


#define SYS_DCACHE_DATA_ERR_ADDR		(SYSTRI32_A_BASEADDR+0x0290)


#define SYS_DCACHE_TAG_ERR_ADDR			(SYSTRI32_A_BASEADDR+0x02A0)


#define SYS_E2_Last_Operation_Err_DoubleError (7)


#define SYS_E2_Last_Operation_OK              (0)


#define SYS_E2_Operation_Err_ModeErr          (6)


#define SYS_E2_Operation_Err_NotAlign         (3)


#define SYS_E2_Operation_Err_NotInEeprom      (4)


#define SYS_E2_Operation_Err_NotInSram        (5)


#define SYS_E2_Operation_Err_Reading          (1)


#define SYS_E2_Operation_Err_Writing          (2)


#define SYS_E2_Operation_Is_Working           (8)


#define SYS_E2_Operation_Read                 (0)


#define SYS_E2_Operation_Status               (2)


#define SYS_E2_Operation_Write                (1)


#define SYS_E2prom_DataArea				(0x6A)


#define SYS_E2prom_DataArea_A			(0xAA)


#define SYS_E2prom_DataArea_B			(0x5A)


#define SYS_E2prom_IllegalArea		(0xFFFFFFFF)


#define SYS_E2prom_ProgArea				(0x95)


#define SYS_E2prom_ProgArea_A			(0x55)


#define SYS_E2prom_ProgArea_B			(0xA5)


#define SYS_EEPROM_NULL							(BSP_EEPROM_NULL)


#define SYS_EEPROM_ProgNum						(1)


#define SYS_EEPROM_RefreshData_Enable	(0) //0:表示不刷新E2数据区; 1:表示刷新E2数据区


#define SYS_FPGA_BASEADDR				(0x20000000)


#define SYS_ICACHE_DATA_ERR_ADDR 		(SYSTRI32_A_BASEADDR+0x0270)


#define SYS_ICACHE_TAG_ERR_ADDR	 		(SYSTRI32_A_BASEADDR+0x0280)


#define SYS_IOASIC_16M	(0x16)


#define SYS_IOASIC_BASEADDR		(0x20000000)


#define SYS_IOASIC_FREQ		(SYS_IOASIC_20M)


#define SYS_MAX_EEPROM_Auto_Check_Size	(0x80) //一次自检最多检测32*4B,扇区大小必须为该size的整数倍,防止一次刷新过程中跨扇区


#define SYS_MAX_EEPROM_ReWrite_Size  		(0x10) //空闲任务一次回写最多4个字=4*4B


#define SYS_MAX_FLASH_Auto_Check_Size		(0x80)


#define SYS_MAX_FLASH_Repair_Read_Size  	(0x80)


#define SYS_MAX_FLASH_Repair_Write_Size  	(0x08)


#define SYS_MAX_FLASH_SetSum_Read_Size  	(0x80)


#define SYS_MAX_FLASH_SetSum_Write_Size  	(0x08)


#define SYS_MAX_TICKNUM_PER_PERIOD				(SYS_BASE_TICKNUM_PER_PERIOD*MAX_PERIOD_N)


#define SYS_MAX_TICK_INDEXNUM_PER_PERIOD	((SYS_MAX_TICKNUM_PER_PERIOD>>5)+1)


#define SYS_Mem_Operation_EEPROM    SYS_NorFlashOperation


#define SYS_Mem_Operation_NorFlash  SYS_NorFlashOperation


#define SYS_NORF_ASK                          (0x02)


#define SYS_NORF_DOUBLE_ERR                   (0x08)


#define SYS_NORF_MODE_ERR                     (0x0C)


#define SYS_NORF_NOTALIGN_ERR                 (0x09)


#define SYS_NORF_NOTINNORF_ERR                (0x0A)


#define SYS_NORF_NOTINSRAM_ERR                (0x0B)


#define SYS_NORF_OK                           (0x07)


#define SYS_NORF_OPTNULL                      (0x06)


#define SYS_NORF_OPT_ERR                      (0x0D)


#define SYS_NORF_READ                         (0x00)


#define SYS_NORF_REFRESH                      (0x04)


#define SYS_NORF_REPAIR                       (0x05)


#define SYS_NORF_SUM                          (0x03)


#define SYS_NORF_WRITE                        (0x01)


#define SYS_NorFlash1_PhysicSize		(0x00400000)


#define SYS_NorFlash1_Size 				(0x00300000)


#define SYS_NorFlash1_Size 				(0x00400000)


#define SYS_NorFlash1_StartAddr		(0x10000000)


#define SYS_NorFlash2_DieNum			(0x4)


#define SYS_NorFlash2_DieSize			(0x01000000)


#define SYS_NorFlash2_Size 				(0x04000000)


#define SYS_NorFlash2_StartAddr		(0x14000000)


#define SYS_NorFlash_DATA_PhysicSect_Num		(SYS_NorFlash_EDAC_PhysicSect_Num*0x4)


#define SYS_NorFlash_DATA_SA_Limit				(((SYS_NorFlash1_PhysicSize/0x5)*0x4)&SYS_NorFlash_SectorNum_Allbit)


#define SYS_NorFlash_DATA_Size					(SYS_NorFlash_DATA_PhysicSect_Num*SYS_NorFlash_PhysicalSectorSize)


#define SYS_NorFlash_Data1_Base		(0x10100000)


#define SYS_NorFlash_Data1_Size		(0x00080000)


#define SYS_NorFlash_Data1_Size		(0x00100000)


#define SYS_NorFlash_Data2_Base		(0x10280000)


#define SYS_NorFlash_Data2_Base		(0x10300000)


#define SYS_NorFlash_Data2_Size		(0x00080000)


#define SYS_NorFlash_Data2_Size		(0x00100000)


#define SYS_NorFlash_DataArea				(0x6A)


#define SYS_NorFlash_DataArea_A			(0xAA)


#define SYS_NorFlash_DataArea_B			(0x5A)


#define SYS_NorFlash_DataIntervalSectorNum	((SYS_NorFlash_Data2_Base-SYS_NorFlash_Data1_Base)>>SYS_NorFlash_SectorSize_AddrBit_Num)


#define SYS_NorFlash_EDAC_PhysicSect_Num		((SYS_NorFlash_PhysicSect_Num/0x5)&(~0x1))


#define SYS_NorFlash_EDAC_SA_Mixed				((SYS_NorFlash1_PhysicSize-(SYS_NorFlash1_PhysicSize/0x5))&SYS_NorFlash_PhysicSectorNum_Allbit)


#define SYS_NorFlash_EDAC_StartAddr				(SYS_NorFlash1_PhysicSize-0x1)


#define SYS_NorFlash_EDAC_StartSA				(SYS_NorFlash1_PhysicSize-SYS_NorFlash_PhysicalSectorSize)


#define SYS_NorFlash_IllegalArea		(0xFFFFFFFF)


#define SYS_NorFlash_PhysicSect_Num				(SYS_NorFlash1_PhysicSize/SYS_NorFlash_PhysicalSectorSize)


#define SYS_NorFlash_PhysicSectorNum_Allbit		(0xFFFF8000)


#define SYS_NorFlash_PhysicalSectorSize			(0x20000)


#define SYS_NorFlash_PhysicalSectorSize			(0x8000)


#define SYS_NorFlash_Prog1_Base		BSP_Prog_Storge1_BASE


#define SYS_NorFlash_Prog1_Size		BSPTEXTSIZE


#define SYS_NorFlash_Prog2_Base		BSP_Prog_Storge2_BASE


#define SYS_NorFlash_Prog2_Size		BSPTEXTSIZE


#define SYS_NorFlash_ProgArea				(0x95)


#define SYS_NorFlash_ProgArea_A			(0x55)


#define SYS_NorFlash_ProgArea_B			(0xA5)


#define SYS_NorFlash_ProgIntervalSectorNum	((SYS_NorFlash_Prog2_Base-SYS_NorFlash_Prog1_Base)>>SYS_NorFlash_SectorSize_AddrBit_Num)


#define SYS_NorFlash_ProgNum			(2)


#define SYS_NorFlash_Prog_Size		BSPTEXTSIZE


#define SYS_NorFlash_RefreshData_Enable					(0)


#define SYS_NorFlash_Repair_Buff_BaseAddr				(0x40126600)


#define SYS_NorFlash_Repair_Erase			(3)


#define SYS_NorFlash_Repair_EraseErr	(8)


#define SYS_NorFlash_Repair_ErrorInfo_BaseAddr			(0x405AF400)


#define SYS_NorFlash_Repair_ErrorInfo_Size				(0x8000)


#define SYS_NorFlash_Repair_Init			(1)


#define SYS_NorFlash_Repair_OK				(0)


#define SYS_NorFlash_Repair_OtherErr	(9)


#define SYS_NorFlash_Repair_Read			(2)


#define SYS_NorFlash_Repair_ReadErr		(6)


#define SYS_NorFlash_Repair_Record		(5)


#define SYS_NorFlash_Repair_Write			(4)


#define SYS_NorFlash_Repair_WriteErr	(7)


#define SYS_NorFlash_SectorNum_Allbit			(0xFFFC0000)


#define SYS_NorFlash_SectorNum_Allbit			(0xFFFE0000)


#define SYS_NorFlash_SectorSize					(0x20000)


#define SYS_NorFlash_SectorSize					(0x40000)


#define SYS_NorFlash_SectorSize_AddrBit_Num		(17)


#define SYS_NorFlash_SectorSize_AddrBit_Num		(18)


#define SYS_NorFlash_SectorSize_bit				(0x1FFFF)


#define SYS_NorFlash_SectorSize_bit				(0x3FFFF)


#define SYS_NorFlash_SetSum_Erase			(3)


#define SYS_NorFlash_SetSum_EraseErr	(8)


#define SYS_NorFlash_SetSum_Init			(1)


#define SYS_NorFlash_SetSum_OK				(0)


#define SYS_NorFlash_SetSum_OtherErr	(9)


#define SYS_NorFlash_SetSum_Read			(2)


#define SYS_NorFlash_SetSum_ReadErr		(6)


#define SYS_NorFlash_SetSum_Record		(5)


#define SYS_NorFlash_SetSum_Write			(4)


#define SYS_NorFlash_SetSum_WriteErr	(7)


#define SYS_NorFlash_StateInfoPtr_ADDR				SYS_NorFlash_StateInfo_ADDR


#define SYS_NorFlash_StateInfo_ADDR				(SYSTRI32_A_BASEADDR+0x0300)


#define SYS_NorFlash_TrapRecord_BaseAddr				(0x10100000)


#define SYS_NorFlash_TrapRecord_Enable					(0)


#define SYS_NorFlash_TrapRecord_Size					(SYS_NorFlash_SectorSize)


#define SYS_ProgOfNorFlash_SectorNum	((BSPTEXTSIZE)>>SYS_NorFlash_SectorSize_AddrBit_Num)


#define SYS_TRAP_INFO_RECORD_SIZE 	(16*1024)


#define SYS_TRAP_INFO_RECORD_SIZE_PERCORE 	(3*1024)


#define SYS_TRI32_BASEADDR					(BSPRAMBASE+0x118200)


#define SYS_Trap_RollNum1_ADDR				(SYSTRI32_A_BASEADDR+0x0214)


#define SYS_Trap_RollNum2_ADDR				(SYSTRI32_A_BASEADDR+0x0218)


#define SYS_Trap_RollNum3_ADDR				(SYSTRI32_A_BASEADDR+0x021C)


#define SYS_Trap_RollNum_ADDR				(SYSTRI32_A_BASEADDR+0x0210)


#define Sinx(x)         (sin((float64)(x))                )


#define Sqrtx(x)        (sqrt((float64)(x))               )


#define TBS_A                           0x00


#define TBS_AB                          0x02


#define TBS_B                           0x01


#define TBS_NUM           0x03


#define TC_CMD_QUE_BUF_LEN 513


#define TDS_SINKING1            0x11111111


#define TDS_SINKING2            0x22222222


#define TDS_SINKING3            0x33333333


#define TDS_SINKING4            0x44444444


#define TDS_SINKING5            0x55555555


#define TDS_SINKING_NOT         0x00000000


#define THR_GC_END              0x00000000


#define THR_GC_FIRING           0x33333333


#define THR_GC_INJECT           0x11111111


#define THR_GC_START            0x22222222


#define THR_WORKSTATUS_NUM              0x4


#define TIME_COUNTER_INCREMENT(pre, cur)            (COUNTER_UP((pre), (cur), MASK_48BIT, 1))


#define TIME_COUNTER_UNINT                          (1.0e-6)


#define TIME_CTRLPERIOD		1


#define TIME_CTRL_CYCLE_T               0.064


#define TIME_CURRENT		0


#define TIME_DRIVER_6017                1


#define TIME_INT_CLOSE()            NULL_STATEMENT()


#define TIME_INT_CLOSE()            UserDefTimeIntClose()


#define TIME_INT_OPEN()             NULL_STATEMENT()


#define TIME_INT_OPEN()             UserDefTimeIntOpen()


#define TIME_INT_PROTECT				0


#define TIME_PPS_GNSSA		2


#define TIME_PPS_GNSSB		3


#define TIME_PPS_STS        6


#define TIME_PPS_TMUA		4


#define TIME_PPS_TMUB		5


#define TLSF_SIGNATURE	(0x2A59FA59)


#define TRUE32              0xEB90146Fu


#define TRUE32      0xEB90146Fu


#define TS		    0.064


#define TWM_EAST                0x22222222


#define TWM_NORMAL              0x00000000


#define TWM_NORTH               0x55555555


#define TWM_SINKING             0x11111111


#define TWM_SOUTH               0x44444444


#define TWM_WEST                0x33333333


#define Tanx(x)         (tan((float64)(x))                )


#define UI08_BIT_CLR(uv, bp)            ((uv) = (((unint32)(uv)) & ((0x01u << (bp)) ^ MASK_LO08)))


#define UI08_BIT_GET(uv, bp)            ((unint08)((((unint32)(uv)) >> (bp)) & 0x01u))


#define UI08_BIT_SET(uv, bp)            ((uv) = (((unint32)(uv)) | ((0x01u << (bp)) & MASK_LO08)))


#define UI08_MAKE04(h4, l4)             ((((unint32)(h4)) << 4u) | ((unint32)(l4)))


#define UI16_BIT_CLR(uv, bp)            ((uv) = (((unint32)(uv)) & ((0x01u << (bp)) ^ MASK_LO16)))


#define UI16_BIT_GET(uv, bp)            ((unint16)((((unint32)(uv)) >> (bp)) & 0x01u))


#define UI16_BIT_GET1(uv, bp)           ((unint16)((((unint32)(uv)) >> (bp)) & 0x01))


#define UI16_BIT_GET2(uv, bp)           ((unint16)((((unint32)(uv)) >> (bp)) & 0x03))


#define UI16_BIT_GET3(uv, bp)           ((unint16)((((unint32)(uv)) >> (bp)) & 0x07u))


#define UI16_BIT_SET(uv, bp)            ((uv) = (((unint32)(uv)) | ((0x01u << (bp)) & MASK_LO16)))


#define UI16_BIT_SET1(uv, bp, bv)       ((uv) = (unint16)((((unint32)(uv)) & ((0x01 << (bp)) ^ (MASK_LO16))) | ((bv) << (bp))))


#define UI16_BIT_SET2(uv, bp, bv)       ((uv) = (unint16)((((unint32)(uv)) & ((0x03 << (bp)) ^ (MASK_LO16))) | ((bv) << (bp))))


#define UI16_HI8(ui16)                  ((unint08)((((unint32)(ui16)) >> 8u) & MASK_LO08))


#define UI16_LO8(ui16)                  ((unint08)((((unint32)(ui16))      ) & MASK_LO08))


#define UI16_MAKE(hi8, lo8)             ((unint16)((((unint32)(hi8)) <<  8u) | ((unint32)(lo8))))


#define UI16_MAKE_HI12(hi8, lo8)        ((unint16)((((unint32)(hi8)) << 4u) | (((unint32)(lo8)) >> 4u)))


#define UI32_BIT_CLR(uv, bp)            BIT_CLR((uv), (bp), MASK_ALL8F)


#define UI32_BIT_GET(uv, bp)            BIT_GET((uv), (bp))


#define UI32_BIT_GET1(uv, bp)           (((uv) >> (bp)) & 0x001u)


#define UI32_BIT_GET10(uv, bp)          (((uv) >> (bp)) & 0x3FFu)


#define UI32_BIT_GET12(uv, bp)          (((uv) >> (bp)) & 0xFFFu)


#define UI32_BIT_GET2(uv, bp)           (((uv) >> (bp)) & 0x003u)


#define UI32_BIT_GET3(uv, bp)           (((uv) >> (bp)) & 0x007u)


#define UI32_BIT_GET4(uv, bp)           (((uv) >> (bp)) & 0x00Fu)


#define UI32_BIT_GET5(uv, bp)           (((uv) >> (bp)) & 0x01Fu)


#define UI32_BIT_GET6(uv, bp)           (((uv) >> (bp)) & 0x03Fu)


#define UI32_BIT_GET7(uv, bp)           (((uv) >> (bp)) & 0x07Fu)


#define UI32_BIT_GET8(uv, bp)           (((uv) >> (bp)) & 0x0FFu)


#define UI32_BIT_GETN(uv, bp, n)        (((uv) >> (bp)) & UI32_BIT_MASKN((n)))


#define UI32_BIT_MASKN(n)               (MASK_ALL8F >> (32u - (n)))


#define UI32_BIT_SET(uv, bp)            BIT_SET((uv), (bp), MASK_ALL8F)


#define UI32_BIT_SET1(uv, bp, bv)       ((uv) = ((uv) & ((0x01u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET2(uv, bp, bv)       ((uv) = ((uv) & ((0x03u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET3(uv, bp, bv)       ((uv) = ((uv) & ((0x07u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET4(uv, bp, bv)       ((uv) = ((uv) & ((0x0Fu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET5(uv, bp, bv)       ((uv) = ((uv) & ((0x1Fu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BYTE_CLR(uv, hl)           ((uv) = ((uv) & ((0xFFu << ((3u - (hl)) << 3u)) ^ (MASK_ALL8F))))


#define UI32_BYTE_GET(uv, hl)           (((uv) >> ((3u - (hl)) << 3u)) & 0xFFu)


#define UI32_BYTE_SET(uv, hl, byv)      ((uv) = ((uv) & ((0xFFu << ((3u - (hl)) << 3u)) ^ (MASK_ALL8F))) | ((byv) << ((3u - (hl)) << 3u)))


#define UI32_BYTE_SET_HIHI8(ui08, val)  (((ui08) & 0x00FFFFFFu) | ((val) << 24u))


#define UI32_BYTE_SET_HILO8(ui08, val)  (((ui08) & 0xFF00FFFFu) | ((val) << 16u))


#define UI32_BYTE_SET_LOHI8(ui08, val)  (((ui08) & 0xFFFF00FFu) | ((val) <<  8u))


#define UI32_BYTE_SET_LOLO8(ui08, val)  (((ui08) & 0xFFFFFF00u) | ((val)      ))


#define UI32_HI16(ui32)                 ((unint16)(((ui32) >> 16u) & MASK_LO16))


#define UI32_HIHI8(ui32)                ((unint08)(((ui32) >> 24u) & MASK_LO08))


#define UI32_HILO8(ui32)                ((unint08)(((ui32) >> 16u) & MASK_LO08))


#define UI32_LO16(ui32)                 ((unint16)(((ui32)       ) & MASK_LO16))


#define UI32_LOHI8(ui32)                ((unint08)(((ui32) >>  8u) & MASK_LO08))


#define UI32_LOLO8(ui32)                ((unint08)(((ui32)       ) & MASK_LO08))


#define UI32_MAKE(hh8, hl8, lh8, ll8)   ((((unint32)(hh8)) << 24u) | (((unint32)(hl8)) << 16u) | (((unint32)(lh8)) << 8u) | ((unint32)(ll8)))


#define UI32_MAKE16(h16, l16)           ((((unint32)(h16)) << 16u) | ((unint32)(l16)))


#define UI64_MAKE16(hh, hl, lh, ll)     ((((ulong64)(hh)) << 48u) | (((ulong64)(hl)) << 32u) | (((ulong64)(lh)) << 16u) | ((ulong64)(ll)))


#define UI64_MAKE32(hh, ll)             ((((ulong64)(hh)) << 32u) | ((ulong64)(ll)))


#define UI8_HI4(ui8)                    ((unint08)((((unint32)(ui8)) >> 4u) & MASK_LO04))


#define UI8_LO4(ui8)                    ((unint08)((((unint32)(ui8))      ) & MASK_LO04))


#define UN08_TO_DBL(x)                  ((float64)(x))


#define UN16_TO_DBL(x)                  ((float64)(x))


#define UN16_TO_FLT(x)                  ((float32)(x))


#define UN32_TO_DBL(x)                  ((float64)(x))


#define UN32_TO_FLT(x)                  ((float32)(x))


#define USED_BLOCK	(0x0)


#define USR_RAMREFRESHWORDSIZE		0x400


#define WAIT_FOREVER		(-1)


#define WHEEL_CTRL_NO                   0x00000000


#define WHEEL_CTRL_NORM                 0x00000001


#define WHEEL_CTRL_NO_HIGHSPEED_OFF     0x00000004


#define WHEEL_CTRL_SPEED                0x00000002


#define WHEEL_CTRL_SPEED_GRD			0x00000005


#define WHEEL_CTRL_SPEED_OFF            0x00000003


#define XWTRI32_A_BASEADDR					(APPTRI32_A_BASEADDR+APPTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define XWTRI32_B_BASEADDR					(APPTRI32_B_BASEADDR+APPTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define XWTRI32_C_BASEADDR					(APPTRI32_C_BASEADDR+APPTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define _DRV_5M_					(0x2A02)


#define _DRV_CorJZ_					(0xF)


#define _DRV_F4_					(0x2A01)


#define _DRV_WWT_					(0x2A03)


#define __ACC_JZ064S_H__


#define __ADD_DATA_NORFLASH__		(0)


#define __BLOCKCNT__					(2048)


#define __BLOCKCNT__					(4096)


#define __BLOCK_BIT__					(11)


#define __BLOCK_BIT__					(12)


#define __BLOCK_PAGE_NUM__		(128)								//一块有多少页


#define __BLOCK_PAGE_NUM__		(64)								//一块有多少页


#define __BSPDEBUG_H__


#define __BSP_CONFIG_H__


#define __BSP_DEF_H__


#define __BSP_LIB_H__


#define __BSP_MACRO_H__


#define __BSP_MEMADDR_H__


#define __BSP_SET_H__


#define __CFG_AOCC_HEAD__


#define __CHECK__						0			//执行完向EEPROM缓冲区的写操作后，对EEPROM进行回读检查


#define __CMGE_100_A_H__


#define __CMGE_SG100_1_3C_H__


#define __CMG_COMDIAG_H__


#define __CMG_CTRL_H__


#define __CONSOLE_UART_INT_ENABLE__  *(V_U32*)(OSCFGIntMKRAddr) &= OSCFGUartIntEnable


#define __CONSOLE_UART_INT_ENABLE__  *(V_U32*)(OSCFGIntMKRAddr) |= OSCFGUartIntEnable


#define __CSCMD_QUEUE_H__


#define __CSIO_COMDIAGH_CFG__


#define __CS_NUM__						(4)


#define __CS_PC_EXE_H__


#define __C_AINTERFACT_FUNCTION_H__


#define __ComNum__	2


#define __ComNum__	3


#define __DELAY__						(16000)		//3D需要延时16ms


#define __DOUBLE__


#define __DRV_ADDA_H__


#define __DRV_BIT_H__


#define __DRV_CAN_H__


#define __DRV_COM_H__


#define __DRV_CSB_H__


#define __DRV_DEFEND_H__


#define __DRV_EEPROM_H__


#define __DRV_NORFLASH_H__


#define __DRV_PULSE_H__


#define __DRV_SPI_H__


#define __DRV_SSI_H__


#define __DRV_TIME_H__


#define __DRV_UART_H__


#define __DRV_USRDEF_ADDA_H__


#define __DRV_USRDEF_BIT_H__


#define __DRV_USRDEF_CAN_H__


#define __DRV_USRDEF_CSB_H__


#define __DRV_USRDEF_H__


#define __DRV_USRDEF_PULSE_H__


#define __DRV_USRDEF_SPI_H__


#define __DRV_USRDEF_SSI_H__


#define __DRV_USRDEF_TIME_H__


#define __DRV_USRDEF_UART_H__


#define __DSS_SIC_COD_F_2_H__


#define __EEPROM_WIDTH40__						//EEPROM 为40位 带EDAC


#define __EPS_FOG6_2_512_H__


#define __ER_TIME_US__				(1500)


#define __ER_TIME_US__				(700)


#define __FDIR_PARTS_HEAD__


#define __FDIR_SYS_HEAD__


#define __FG_3_3_3SA_H__


#define __FLASHMAXWAITTIME__	(0x2)


#define __FLOAT__


#define __FOG_2_4_D_H__


#define __FOG_33_1A_B_H__


#define __FOG_33_1A_H__


#define __FOG_3_3_4S_H__


#define __FT_FUNCTION_CFG__


#define __FT_FUNCTION__


#define __FUNC_MODULE__


#define __GNC_EXTERN_DECL_H__


#define __GNC_INCLUDE_H__


#define __GNSS_HEAD__


#define __GPRSSENSOR_HEAD_


#define __IO_COM_DIAG__


#define __IRES_AAS_2_H__


#define __NFLASHBASEADDR__ 		(0x20020000)		//NANDFLASH访问基地址


#define __NOCHECK__						0xffffffff	//执行完向EEPROM缓冲区的写操作后，不对EEPROM进行回读检查


#define __NOWAIT__						0xffffffff	//执行完向EEPROM缓冲区的写操作后，不等待EEPROM数据实际写入后就直接返回


#define __NOWAIT__					0xffffffff	//执行完向缓冲区的写操作后，不等待数据实际写入后就直接返回


#define __ORBIT_AUTO_CTRL__


#define __OSCONFIG_H__


#define __OSCONSOLE_H__


#define __OSDEF_H__


#define __OSERRNO_H__


#define __OSINCLUDEALL_H__


#define __OSINFOREC_H__


#define __OSINTA_H__


#define __OSINT_H__


#define __OSKERNEL_H__


#define __OSMEM_H__


#define __OSMQ_H__


#define __OSSEM_H__


#define __OSTASK_H__


#define __OSTIME_H__


#define __OS_CONSOLE_EN__ 				0


#define __OS_MEM_USED_COMPUTE__ 	0


#define __OS_MQ_EN__ 							0


#define __OS_SCHED_REC_EN__ 			0


#define __OS_SEM_EN__ 						0


#define __OS_STACK_REC_EN__ 			0


#define __OS_TIME_EN__ 						0


#define __PAGESIZE__					(4*1024)						//一页NAND FLASH大小


#define __PAGE_BIT__					(6)


#define __PAGE_BIT__					(7)


#define __QLIB_H__


#define __RD_TIME_US__				(25)


#define __RS_422_COM_H__


#define __SADE_2_3A_H__


#define __SET_WRITE_WAIT_TIME__			1000//等待时间是1ms


#define __STD_HASH_H__


#define __STD_LIST_H__


#define __STD_ORBIT_H__


#define __STD_SORT_CONF_H__


#define __STD_SORT_H__


#define __STD_TIME_CFG_H__


#define __STD_TIME_H__


#define __ST_VHA_APS_2_H__


#define __SYS_EEPROM_H__


#define __SYS_HOOK_H__


#define __SYS_INTERFACE_H__


#define __SYS_LIB_H__


#define __SYS_MACRO_H__


#define __SYS_MCONFIG_H__


#define __SYS_NANDFLASH_H__


#define __SYS_NORFLASH_H__


#define __SYS_ROM_H__


#define __SYS_TASK_H__


#define __SYS_TRAP_HANDLER_H__


#define __SYS_TRAP_HOOK_H__


#define __SYS_USR_DEF_H__


#define __SYS_VARIABLES_H__


#define __SYS_WDT_H__


#define __UFM_12_0_5_H__


#define __USE_FUDANWEI_SMALLSECTOR__		(1)


#define __USE_REPAIR_BUFFER__							(1)


#define __USE_REPAIR_ERRORINFO_BUFFER__ 				(0)


#define __UTIL_LIB_H__


#define __UTIL_STD_H__


#define __VIPCU_HEAD__


#define __WAIT__						0			//执行完向EEPROM缓冲区的写操作后，等待EEPROM数据实际写入后才返回


#define __WAIT__						0	//执行完向缓冲区的写操作后，等待数据实际写入后才返回


#define __WR_TIME_US__				(200)


#define __WR_TIME_US__				(230)


#define __XH_HARD_H__


#define __XH_IOPUT_H__


#define _bit32_sector_


#define container_of(address, type, field) \
            ((type *)((char *)(address) - offsetof(type, field)))


#define hash_find(pos, table, userkey, type_of)     \
    do {                                            \
            list_for_each_entry(pos, type_of, &table[hash_key(table, userkey)], list) \
            {                                       \
                if (pos->key == userkey) {break;}   \
            }                                       \
            if ((&pos->list) == (&table[hash_key(table, userkey)])) {pos = 0;}     \
        } while (0)


#define hash_init(node) INIT_LIST_HEAD(&node)


#define hash_insert(table, cell)  list_add_tail(&(cell.list), &(table[hash_key(table, cell.key)]))


#define hash_key(table, userkey)    ((userkey) % ARRAY_SIZE(table))


#define inline _inline


#define list_entry(ptr, type, member) \
                container_of(ptr, type, member)


#define list_for_each(pos, head) \
    for (pos = (head)->next;  pos != (head); pos = pos->next)


#define list_for_each_entry(pos, typeof_pos, head, member) \
    for (pos = list_entry((head)->next, typeof_pos, member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.next, typeof_pos, member))


#define list_for_each_entry_continue(pos, typeof_pos, head, member) \
    for (pos = list_entry(pos->member.next, typeof_pos, member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.next, typeof_pos, member))


#define list_for_each_entry_reverse(pos, typeof_pos, head, member) \
    for (pos = list_entry((head)->prev, typeof_pos, member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.prev, typeof_pos, member))


#define list_for_each_entry_safe(pos, typeof_pos, n, typeof_n, head, member) \
                    for (pos = list_entry((head)->next, typeof_pos, member), \
                         n = list_entry(pos->member.next, typeof_pos, member); \
                         &pos->member != (head); \
                         pos = n, n = list_entry(n->member.next, typeof_n, member))


#define list_for_each_prev(pos, head) \
    for (pos = (head)->prev;  pos != (head); pos = pos->prev)


#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)


#define list_prepare_entry(pos, typeof_pos, head, member) \
        ((pos) ? : list_entry(head, typeof_pos, member))


#define offsetof(type, field)    ((int)&((type *)0)->field)




typedef enum
{
    MEM_NULL,
    MEM_E2PROM,
    MEM_NOR_FLASH,
    MEM_SRAM

} MEM_ID;

typedef enum
{
    MEM_OP_NULL,
    MEM_OP_MODIFY,
    MEM_OP_DOWN,
    MEM_OP_COPY,
    MEM_OP_CHECK,
    MEM_OP_COMPARE,

} MEM_OP;

typedef enum
{
    OP_EEPROM,
    OP_NOR_FLASH,
    OP_TOTAL,

} TYPE_OP;

typedef enum
{
    OP_EEPROM,
    OP_NOR_FLASH,
    OP_TOTAL,
} TYPE_OP;

typedef enum sem_b_state
{
	SEM_EMPTY,
	SEM_FULL
} SEM_B_STATE;

typedef enum sem_type
{
	OS_SEM_BINARY,
	OS_SEM_MUTEX,
	OS_SEM_COUNT
} SEM_TYPE;


#endif // AUTO_GENERATED_COMMON_H
