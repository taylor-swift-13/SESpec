

#ifndef AUTO_GENERATED_COMMON_H
#define AUTO_GENERATED_COMMON_H



#define	ABT_MODE 0x17

#define	AFE						BSP_DISABLE


#define	ALLTIMER_FREQ_DIVIDED_PARAM 			(2)


#define	APBTIMER_FREQ							(CPU_FREQ/4)


#define	APBTIMER_FREQ_DIVIDED_PARAM				(ALLTIMER_FREQ_DIVIDED_PARAM)


#define	APPTRI32_A_BASEADDR					(SYS_TRI32_BASEADDR)

#define	APPTRI32_B_BASEADDR					(SYSTRI32_A_BASEADDR+SYSTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	APPTRI32_C_BASEADDR					(SYSTRI32_B_BASEADDR+SYSTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	APPTRI32_EACHSIZE					(4*1024)


#define	ASEDIS					0


#define	AW						1


#define	BACKKEY				(0x14)


#define	BIG_ENDIAN							0x1


#define	BSPCPACR_INIT				(((ASEDIS & 0x01) << 31)|	\
									((D32DIS & 0x01) << 30)|	\
									((CP & 0x03) << 26)|		\
									((CP & 0x03) << 24)|		\
									((CP & 0x03) << 22)|		\
									((CP & 0x03) << 20)|		\
									((CP & 0x03) << 18)|		\
									((CP & 0x03) << 16)|		\
									((CP & 0x03) << 14)|		\
									((CP & 0x03) << 12)|		\
									((CP & 0x03) << 10)|		\
									((CP & 0x03) << 8)|			\
									((CP & 0x03) << 6)|			\
									((CP & 0x03) << 4)|			\
									((CP & 0x03) << 2)|			\
									((CP & 0x03) << 0))


#define	BSPFPEXC_INIT				(((EX & 0x01) << 31)|		\
									((FEN & 0x01) << 30))


#define	BSPNSACR_INIT				(((RFQ & 0x01) << 19)|		\
									((NSASEDIS & 0x01) << 15)|	\
									((NSD32DIS & 0x01) << 14)|	\
									((nCP & 0x01) << 13)|		\
									((nCP & 0x01) << 12)|		\
									((nCP & 0x01) << 11)|		\
									((nCP & 0x01) << 10)|		\
									((nCP & 0x01) << 9)|		\
									((nCP & 0x01) << 8)|		\
									((nCP & 0x01) << 7)|		\
									((nCP & 0x01) << 6)|		\
									((nCP & 0x01) << 5)|		\
									((nCP & 0x01) << 4)|		\
									((nCP & 0x01) << 3)|		\
									((nCP & 0x01) << 2)|		\
									((nCP & 0x01) << 1)|		\
									((nCP & 0x01) << 0))


#define	BSPSCR_INIT					((((~nET) & 0x01) << 6)|	\
									((AW & 0x01) << 5)|			\
									((FW & 0x01) << 4)|			\
									((EA & 0x01) << 3)|			\
									((FIQ & 0x01) << 2)|		\
									((IQR & 0x01) << 1)|		\
									((NS & 0x01) << 0))


#define	BSPSCTLR_INIT				(((TE & 0x01) << 30)|		\
									((AFE & 0x01) << 29)|		\
									((TRE & 0x01) << 28)|		\
									((EE & 0x01) << 25)|		\
									((VE & 0x01) << 24)|		\
									((FI & 0x01) << 21)|		\
									((HA & 0x01) << 17)|		\
									((RR & 0x01) << 14)|		\
									((V & 0x01) << 13)|			\
									((CACHE_DISABLE & 0x01) << 12)|\
									((Z & 0x01) << 11)|			\
									((SW & 0x01) << 10)|		\
									((CACHE_DISABLE & 0x01) << 2)|\
									((MMU & 0x01) << 0))


#define	BSP_APBTIMERS_COMPVERSION				(0xac)


#define	BSP_APBTIMERS_EOI						(0xa4)


#define	BSP_APBTIMERS_INTS						(0xa0)


#define	BSP_APBTIMERS_RAWINTS				 	(0xa8)


#define	BSP_APBTIMERS_SCALE						(0x100)


#define	BSP_APBTIMER_COUNT						(0x004)


#define	BSP_APBTIMER_CTRL						(0x008)


#define	BSP_APBTIMER_EOI						(0x00c)


#define	BSP_APBTIMER_INTS						(0x010)


#define	BSP_APBTIMER_LOAD						(0x000)


#define	BSP_DISABLE							0x0


#define	BSP_ENABLE							0x1


#define	BSP_ERROR							-1


#define	BSP_GLOBALTIMER_AUTOINCREMENT			(0x018)


#define	BSP_GLOBALTIMER_COMPARATORH				(0x014)


#define	BSP_GLOBALTIMER_COMPARATORL				(0x010)


#define	BSP_GLOBALTIMER_COUNTH					(0x004)


#define	BSP_GLOBALTIMER_COUNTL					(0x000)


#define	BSP_GLOBALTIMER_CTRL					(0x008)


#define	BSP_GLOBALTIMER_INTS					(0x00c)


#define	BSP_GPI_HIGH							(0x1)

#define	BSP_GPI_LOW								(0x0)


#define	BSP_OK								0


#define	BSP_PRIVATETIMER_COUNT					(0x004)


#define	BSP_PRIVATETIMER_CTRL					(0x008)


#define	BSP_PRIVATETIMER_INTS					(0x00c)


#define	BSP_PRIVATETIMER_LOAD					(0x000)


#define	BSP_PreciseDelay_No						(0x0)


#define	BSP_Prog_Storge1_Flag			(0x0)


#define	BSP_Prog_Storge2_Flag			(0x1)


#define	BSP_Prog_Storge3_Flag			(0x2)


#define	BSP_TimeSlice_No						(0x1)

#define	BSP_UART_BaudDivdR					(0x00)


#define	BSP_UART_ContrlR					(0x0c)


#define	BSP_UART_FCR						(0x08)


#define	BSP_UART_FifoR						(0x00)


#define	BSP_UART_IIR						(0x08)


#define	BSP_UART_StatusR					(0x14)


#define	CACHE_DISABLE						0x00


#define	CACHE_ENABLE						0x03


#define	CACHE_FROZEN						0x01


#define	CACHE_FT_DISABLE					0x00


#define	CACHE_FT_ENABLE						0x01


#define	COM_EVEN							0x0


#define	COM_ODD								0x1


#define	CP						3


#define	D32DIS					0


#define	DELAY_TIMER_MAX							(0xffffffff>>ALLTIMER_FREQ_DIVIDED_PARAM)


#define	DISABLE_ALL_INT		((1<<6)|(1<<7)|(1<<8))

#define	EA						0


#define	EE						LITTLE_ENDIAN


#define	EMIF_PROM_WIDTH_16				(16)


#define	EMIF_PROM_WIDTH_32				(32)


#define	EMIF_PROM_WIDTH_8				(8)


#define	ENABLE_ALL_INT		(~DISABLE_ALL_INT)

#define	EX					0


#define	FEN					BSP_ENABLE


#define	FI						BSP_DISABLE


#define	FIQ						0


#define	FIQ_MODE 0x11

#define	FLOAT_DISABLE						0x0


#define	FLOAT_ENABLE						0x1

#define	FW						1


#define	GFS_A6017_INIT_ENABLE					(1)


#define	GFS_A6017_INIT_ENABLE				(1)


#define	GLOBALTIMER_FREQ						(CPU_FREQ)


#define	GLOBALTIMER_FREQ_DIVIDED_PARAM			(ALLTIMER_FREQ_DIVIDED_PARAM)


#define	GPI0								0x0


#define	GPI1								0x1


#define	GPI10								0xA


#define	GPI11								0xB


#define	GPI12								0xC


#define	GPI13								0xD


#define	GPI14								0xE


#define	GPI15								0xF


#define	GPI16								0x10


#define	GPI17								0x11


#define	GPI18								0x12


#define	GPI19								0x13


#define	GPI2								0x2


#define	GPI20								0x14


#define	GPI21								0x15


#define	GPI22								0x16


#define	GPI23								0x17


#define	GPI24								0x18


#define	GPI25								0x19


#define	GPI26								0x1A


#define	GPI27								0x1B


#define	GPI28								0x1C


#define	GPI29								0x1D


#define	GPI3								0x3


#define	GPI30								0x1E


#define	GPI31								0x1F


#define	GPI4								0x4


#define	GPI5								0x5


#define	GPI6								0x6


#define	GPI7								0x7


#define	GPI8								0x8


#define	GPI9								0x9


#define	GPI_HIGH							0x1

#define	GPI_IN								0x0

#define	GPI_LOW								0x0


#define	GPI_OUT								0x1


#define	HA						BSP_ENABLE


#define	INTERVAL							(SYSTRI32_B_BASEADDR - SYSTRI32_A_BASEADDR)


#define	IO_SIZE_16							0x01


#define	IO_SIZE_32							0x02


#define	IO_SIZE_8							0x00


#define	IQR						0


#define	IRQ_MODE 0x12

#define	LEVEL_CRITICAL						(0x555)


#define	LEVEL_NORMAL						(0xAAA)


#define	LITTLE_ENDIAN						0x0


#define	LOADERR				(0xaa)


#define	LOADOK				(0x55)


#define	MMU						BSP_DISABLE


#define	MON_MODE 0x16

#define	NS						0


#define	NSASEDIS				1


#define	NSD32DIS				1


#define	OSEDISABLE			(0)


#define	OSENABLE			(1)


#define	OS_ERR_INTCONNECT_TT_INVALID		(OS_ERR_INT_LIB  | ( 0x1<<8) | 0x1)


#define	OS_ERR_INTERNAL_LIB				( 0xf << 16)

#define	OS_ERR_INT_LIB					( 0x6 << 16)


#define	OS_ERR_INVALID					(0xffffffff)


#define	OS_ERR_KERSTART_NO_TASK				(OS_ERR_KER_LIB  | ( 0x1<<8) | 0x1)


#define	OS_ERR_KER_LIB					( 0x1 << 16)


#define	OS_ERR_MEMALLOC_NO_FREE_BLOCK		(OS_ERR_MEM_LIB  | ( 0x1<<8) | 0x1)


#define	OS_ERR_MEMFREE_ID_INVALID			(OS_ERR_MEM_LIB  | ( 0x2<<8) | 0x1)


#define	OS_ERR_MEMFREE_ID_NULL				(OS_ERR_MEM_LIB  | ( 0x2<<8) | 0x2)


#define	OS_ERR_MEM_LIB					( 0x5 << 16)


#define	OS_ERR_MQDELETE_ID_INVALID			(OS_ERR_MQ_LIB   | ( 0x3<<8) | 0x1)


#define	OS_ERR_MQQUERY_ID_INVALID			(OS_ERR_MQ_LIB   | ( 0x4<<8) | 0x1)


#define	OS_ERR_MQQUERY_ID_NULL				(OS_ERR_MQ_LIB   | ( 0x4<<8) | 0x2)


#define	OS_ERR_MQREC_CALL_IN_INT			(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x2)


#define	OS_ERR_MQREC_CALL_IN_LOCK			(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x5)


#define	OS_ERR_MQREC_ID_INVALID				(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x1)


#define	OS_ERR_MQREC_MSGSIZE_OVER			(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x3)


#define	OS_ERR_MQREC_TIMEOUT				(OS_ERR_MQ_LIB   | ( 0x2<<8) | 0x4)


#define	OS_ERR_MQSEND_ID_INVALID			(OS_ERR_MQ_LIB   | ( 0x1<<8) | 0x1)


#define	OS_ERR_MQSEND_MSGSIZE_OVER			(OS_ERR_MQ_LIB   | ( 0x1<<8) | 0x2)


#define	OS_ERR_MQSEND_PTR_NULL				(OS_ERR_MQ_LIB   | ( 0x1<<8) | 0x4)


#define	OS_ERR_MQSEND_QUEUE_FULL			(OS_ERR_MQ_LIB   | ( 0x1<<8) | 0x3)


#define	OS_ERR_MQ_LIB					( 0x4 << 16)


#define	OS_ERR_OK						(0x0)


#define	OS_ERR_OTHER_LIB				( 0x8 << 16)


#define	OS_ERR_SEMDELETE_ID_INVALID			(OS_ERR_SEM_LIB  | ( 0x3<<8) | 0x1)


#define	OS_ERR_SEMDELETE_ID_NULL			(OS_ERR_SEM_LIB  | ( 0x3<<8) | 0x2)


#define	OS_ERR_SEMDELETE_SEMOWNER_ID_NULL	(OS_ERR_SEM_LIB  | ( 0x3<<8) | 0x3)


#define	OS_ERR_SEMFLUSH_ID_INVALID			(OS_ERR_SEM_LIB  | ( 0x4<<8) | 0x1)


#define	OS_ERR_SEMFLUSH_ID_NULL				(OS_ERR_SEM_LIB  | ( 0x4<<8) | 0x2)


#define	OS_ERR_SEMGIVE_ID_INVALID			(OS_ERR_SEM_LIB  | ( 0x2<<8) | 0x1)


#define	OS_ERR_SEMGIVE_ID_NULL				(OS_ERR_SEM_LIB  | ( 0x2<<8) | 0x4)


#define	OS_ERR_SEMGIVE_MUTEX_GIVE_INT		(OS_ERR_SEM_LIB  | ( 0x2<<8) | 0x2)


#define	OS_ERR_SEMGIVE_MUTEX_GIVE_LOCK		(OS_ERR_SEM_LIB  | ( 0x2<<8) | 0x3)


#define	OS_ERR_SEMTAKE_CALL_IN_INT			(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x2)


#define	OS_ERR_SEMTAKE_CALL_IN_LOCK			(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x3)


#define	OS_ERR_SEMTAKE_ID_INVALID			(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x1)


#define	OS_ERR_SEMTAKE_ID_NULL				(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x5)


#define	OS_ERR_SEMTAKE_TIMEOUT				(OS_ERR_SEM_LIB  | ( 0x1<<8) | 0x4)


#define	OS_ERR_SEM_LIB					( 0x3 << 16)


#define	OS_ERR_SET_ERRNO(errno)			do {OSErrNo = (errno);  print2("\r\nOSErrNo: 0x%x",OSErrNo); } while(0)


#define	OS_ERR_SET_ERRNO(errno)			do {OSErrNo = (errno);}while(0)


#define	OS_ERR_STKREC_ALLOC_OVERFLOW		(OS_ERR_OTHER_LIB| ( 0x1<<8) | 0x1)


#define	OS_ERR_TASKDELAY_CALL_IN_INT		(OS_ERR_TASK_LIB | ( 0x4<<8) | 0x1)


#define	OS_ERR_TASKDELAY_CALL_IN_LOCK		(OS_ERR_TASK_LIB | ( 0x4<<8) | 0x2)


#define	OS_ERR_TASKDELETE_CALL_IN_INT		(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x3)


#define	OS_ERR_TASKDELETE_ID_INVALID		(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x1)


#define	OS_ERR_TASKDELETE_ID_NULL			(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x4)


#define	OS_ERR_TASKDELETE_SYS_TASK			(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x2)


#define	OS_ERR_TASKPRIOSET_SYS_TASK			(OS_ERR_TASK_LIB | ( 0x6<<8) | 0x1)


#define	OS_ERR_TASKRESTART_ID_INVALID		(OS_ERR_TASK_LIB | ( 0x5<<8) | 0x1)


#define	OS_ERR_TASKRESTART_ID_NULL			(OS_ERR_TASK_LIB | ( 0x5<<8) | 0x2)


#define	OS_ERR_TASKRESUME_ID_INVALID		(OS_ERR_TASK_LIB | ( 0x3<<8) | 0x1)


#define	OS_ERR_TASKRESUME_ID_NULL			(OS_ERR_TASK_LIB | ( 0x3<<8) | 0x2)


#define	OS_ERR_TASKSTACK_REC_ALLOC_FAIL		(OS_ERR_TASK_LIB | ( 0x7<<8) | 0x1)


#define	OS_ERR_TASKSUSPEND_CALL_IN_INT		(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x2)


#define	OS_ERR_TASKSUSPEND_CALL_IN_LOCK		(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x3)


#define	OS_ERR_TASKSUSPEND_ID_INVALID		(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x1)


#define	OS_ERR_TASKSUSPEND_ID_NULL			(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x5)


#define	OS_ERR_TASKSUSPEND_SYS_TASK			(OS_ERR_TASK_LIB | ( 0x2<<8) | 0x4)


#define	OS_ERR_TASK_LIB					( 0x2 << 16)


#define	OS_ERR_TIMEEVENTSET_TIME_INVALID	 (OS_ERR_TIME_LIB| ( 0x1<<8) | 0x1)


#define	OS_ERR_TIME_LIB					( 0x7 << 16)


#define	OS_TASK_DELAY_OUT					(0xFFFFFFFD)


#define	OS_TASK_PEND_OUT					(0xFFFFFFFB)


#define	OS_TASK_READY_OUT					(0xFFFFFFFE)


#define	OS_TASK_RUN_OUT						(0xFFFFFFEF)


#define	OS_TASK_SUSPEND_OUT					(0xFFFFFFF7)


#define	PRIVATETIMER_FREQ						(CPU_FREQ)


#define	PRIVATETIMER_FREQ_DIVIDED_PARAM 		(ALLTIMER_FREQ_DIVIDED_PARAM)


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


#define	PROM_SIZE_16						0x01


#define	PROM_SIZE_32						0x02


#define	PROM_SIZE_8							0x00


#define	RFQ						0


#define	RR						0


#define	SDRAM_128M							0x0C


#define	SDRAM_128k							0x02


#define	SDRAM_16M							0x09


#define	SDRAM_1G							0x0F


#define	SDRAM_1M							0x05


#define	SDRAM_256M							0x0D


#define	SDRAM_256k							0x03


#define	SDRAM_2M							0x06


#define	SDRAM_32M							0x0A


#define	SDRAM_4M							0x07


#define	SDRAM_512M							0x0E


#define	SDRAM_512k							0x04


#define	SDRAM_64M							0x0B


#define	SDRAM_64k							0x01


#define	SDRAM_8M							0x08


#define	SDRAM_AUTO_REFRESH					0x02


#define	SDRAM_LOAD_COMMAND_REGISTER			0x03


#define	SDRAM_NOCMD							0x00


#define	SDRAM_PRECHAREGE					0x01


#define	SPW_BASE						(0x300000)		//spacewire基地址


#define	SPW_FIFO_MAX_LEN					(0x38)


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


#define	SRAM_SIZE_16						0x01


#define	SRAM_SIZE_32						0x02


#define	SRAM_SIZE_8							0x00


#define	SUMERR				(0xbb)


#define	SVC_MODE 0x13

#define	SW						BSP_DISABLE


#define	SWITCH_BASE						(0x200000)		//交换机基地址


#define	SYSTASKNUM							(4)


#define	SYSTRI32_A_BASEADDR					( XWTRI32_A_BASEADDR+XWTRI32_EACHSIZE+SYS_ISOLATION_SIZE)

#define	SYSTRI32_B_BASEADDR					( XWTRI32_B_BASEADDR+XWTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	SYSTRI32_C_BASEADDR					( XWTRI32_C_BASEADDR+XWTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define	SYSTRI32_EACHSIZE					(4*1024)


#define	SYS_Get(addr)					(*(V_U32 *)((U32)(addr)))


#define	SYS_ISOLATION_SIZE					(512)


#define	SYS_LESS_COMMON_TRAP_INFO_RECORD_BASE		(SYS_SEU_TRAP_INFO_RECORD_BASE+SYS_SEU_TRAP_INFO_RECORD_SIZE)


#define	SYS_MAX_FLASH_Read_Size				(0x80)


#define	SYS_MAX_FLASH_Write_Size			(0x08)


#define	SYS_MODE 0x1f



#define	SYS_PERIOD_TIME_MS					(64)


#define	SYS_SEU_TRAP_INFO_RECORD_BASE				(MEM_TRAP_INFO_RECORD_BASE)


#define	SYS_Set(addr,value)				(*(V_U32 *)((U32)(addr))=(value))


#define	SYS_TASK1_Allocated_TIME_MS			(10)


#define	SYS_TASK2_Allocated_TIME_MS			(14)


#define	SYS_TASK2_START_TIME_MS				(10)


#define	SYS_TASK3_Allocated_TIME_MS			(34)


#define	SYS_TASK3_LEVEL						LEVEL_CRITICAL


#define	SYS_TASK3_START_TIME_MS				(24)


#define	SYS_TASK4_Allocated_TIME_MS			(6)


#define	SYS_TASK4_START_TIME_MS				(58)


#define	SYS_Tr32_Get(addr) 				(UTIL_Tr32_Get((V_U32 *)((U32)(addr)) ,(V_U32 *)(((U32)(addr))+INTERVAL), (V_U32 *)(((U32)(addr))+2*INTERVAL)))


#define	SYS_Tr32_Set(addr,value)		(UTIL_Tr32_Set((V_U32 *)((U32)(addr)) ,(V_U32 *)(((U32)(addr))+INTERVAL), (V_U32 *)(((U32)(addr))+2*INTERVAL),(U32)(value)))


#define	TASK_SCHED_INTERFACE_SWITCH_FLAG	(0xeb900000)


#define	TASK_SCHED_MODE_FOUR				(0x3)


#define	TASK_SCHED_MODE_ONE					(0x0)


#define	TASK_SCHED_MODE_THREE				(0x2)


#define	TASK_SCHED_MODE_TWO					(0x1)


#define	TE						BSP_DISABLE


#define	TIMER_DISABLE						0x00


#define	TIMER_ENABLE						0x01


#define	TIMER_ONESHOT						0x00


#define	TIMER_RELOAD						0x01

#define	TRE						BSP_DISABLE


#define	TTE_FPGA_CONFIG_DONE_BIT			(11)


#define	TT_send_vl_id_reg				(0x32)


#define	UND_MODE 0x1b


#define	USER6017_FPGA_CONFIG_DONE_BIT		(7)


#define	USER6017_FPGA_CONFIG_DONE_VALID		(0x1)


#define	USER6017_FPGA_RESET_BIT_INDEX		(4)		// Note: 与驱动使用说明一致


#define	USER6017_FPGA_RESET_BIT_VALID		(0x1)


#define	USR_DEVICE_NUM				(0x3)


#define	USR_MODE 0x10

#define	USR_PCFA_PROC_DELAY			USR_PCF_PROC_DELAY


#define	USR_PCFB_PROC_DELAY			USR_PCF_PROC_DELAY


#define	USR_PCFC_PROC_DELAY			USR_PCF_PROC_DELAY


#define	USR_PCF_PROC_DELAY			(0x0)


#define	USR_PCF_PROC_DELAY			(0x33)


#define	USR_UNIT_NUM_IN_DEVICE		(0x1)


#define	UserDefBlock1BeginAddr	(INVALID)	//起始地址


#define	UserDefBlock1CopyAddr1	(INVALID)	//备份地址1


#define	UserDefBlock1CopyAddr2	(INVALID)	//备份地址2


#define	UserDefBlock1Func		(SYS_RamDefault_Handle)	//挂接函数


#define	UserDefBlock1Size		(INVALID)	//连续空间的总大小。例如：如果是空间连续的三取二区，每个三取二区为3K，则总大小应填写9K。


#define	UserDefBlock1Type		(INVALID)	//类型 (0~2)


#define	UserDefBlock2BeginAddr	(INVALID)	//起始地址


#define	UserDefBlock2CopyAddr1	(INVALID)	//备份地址1


#define	UserDefBlock2CopyAddr2	(INVALID)	//备份地址2


#define	UserDefBlock2Func		(SYS_RamDefault_Handle)	//挂接函数


#define	UserDefBlock2Size		(INVALID)	//连续空间的总大小。例如：如果是空间连续的三取二区，每个三取二区为3K，则总大小应填写9K。


#define	UserDefBlock2Type		(INVALID)	//类型 (0~2)


#define	UserDefBlock3BeginAddr	(INVALID)	//起始地址


#define	UserDefBlock3CopyAddr1	(INVALID)	//备份地址1


#define	UserDefBlock3CopyAddr2	(INVALID)	//备份地址2


#define	UserDefBlock3Func		(SYS_RamDefault_Handle)	//挂接函数


#define	UserDefBlock3Size		(INVALID)	//连续空间的总大小。例如：如果是空间连续的三取二区，每个三取二区为3K，则总大小应填写9K。


#define	UserDefBlock3Type		(INVALID)	//类型 (0~2)


#define	UserDefBlock4BeginAddr	(INVALID)	//起始地址


#define	UserDefBlock4CopyAddr1	(INVALID)	//备份地址1


#define	UserDefBlock4CopyAddr2	(INVALID)	//备份地址2


#define	UserDefBlock4Func		(SYS_RamDefault_Handle)	//挂接函数


#define	UserDefBlock4Size		(INVALID)	//连续空间的总大小。例如：如果是空间连续的三取二区，每个三取二区为3K，则总大小应填写9K。


#define	UserDefBlock4Type		(INVALID)	//类型 (0~2)


#define	V						0


#define	VE						0


#define	WANTEDKEY			(0x6f)


#define	WTDTIMER_FREQ						(CPU_FREQ)


#define	WTDTIMER_FREQ_DIVIDED_PARAM			(2)


#define	XWTRI32_EACHSIZE					(4*1024)


#define	Z						BSP_DISABLE


#define	__AppTask3__						AppTask3


#define	__AppTask4__						SYS_ManageTask


#define	__INT_GPIO_6_FUNC__					SYS_ISR_Default_Hook


#define	__INT_GPIO_7_FUNC__					ISR_TTESycPeriod


#define	__ROM_CS0_FUNC__				SYS_RomTBE_Handle_DefaultHandler


#define	__ROM_CS1_FUNC__				SYS_RomTBE_Handle_DefaultHandler


#define	__ROM_CS2_FUNC__				SYS_NorFlashTrapEdacHandlerHook


#define	__ROM_CS3_FUNC__				SYS_RomTBE_Handle_DefaultHandler


#define	__SYS_FUNCTION_HOOK__


#define	nCP						1


#define	nET						BSP_DISABLE


#define      ASSERT(x)      assert((x))


#define     DBL_PI          6.283185307179586


#define     DEG2RAD         0.0174532925199433


#define     EARTH_ALPHA     1.0/298.257


#define     EARTH_Mu        3.986005e14


#define     EARTH_R         6378140.0


#define     EARTH_W         7.292115e-5


#define     FLT32_ZERO      1.0e-7f


#define     FLT64_ZERO      1.0e-14


#define     HALF_PI         1.570796326794897


#define     PI              3.141592653589793


#define     POW_2E_N10      9.765625e-4


#define     POW_2E_N11      4.8828125e-4


#define     POW_2E_N14      6.103515625e-5


#define     POW_2E_N15      3.0517578125e-5


#define     POW_2E_N22      2.384185791015625e-7


#define     POW_2E_N24      5.960464477539063e-8


#define     POW_2E_N30      9.313225746154785e-10


#define     POW_2E_N31      4.6566128730773925e-10


#define     POW_2E_N6       1.5625e-2


#define     RAD2DEG         57.29577951308232


#define  ASSERT(x)      ((void)0)


#define  ASSERT(x)      {if (!(x)) { do{ print2("\r\nAssert failed !!!"); } while(1); } }


#define  BE_PARTITION_STATE				(0x00010002)


#define  BE_RECV_FRAME_STATE			(0x00020003)


#define  BE_RECV_PARTITION_STATE		(0x00020002)


#define  BE_SEND_CONTROL				(0x00010003)


#define  DRVDISABLE  (0)


#define  DRVENABLE  (1)


#define  DRVFALSE  (0)


#define  DRVHIGH (1)


#define  DRVINVARAANT  (0)//固定脉冲


#define  DRVLOW (0)


#define  DRVREV  (1)


#define  DRVTRUE  (1)


#define  DRVUNREV  (0)


#define  DRVUNUSED  (0)


#define  DRVUSED  (1)


#define  DRVVARAANT  (1)//可变脉冲


#define  DRV_A  (0)//第1路can/csb/TM


#define  DRV_B (1)//第2路can/csb/TM


#define  DRV_BITIN_IO_GPIO  (1) //位口采集标志 IO板GPIO口状态


#define  DRV_BITIN_IO_PULSE  (0) //位口采集标志:IO板脉冲有效性标注


#define  DRV_BITIN_PM_GPIO  (2)//位口采集标志 PM 板GPIO口状态


#define  DRV_BITOUT_IO_GPIO  (1) //位口输出标志 6017 GPIO口状态


#define  DRV_BITOUT_PM_GPIO  (2)//位口输出标志 处理器GPIO口状态


#define  DRV_CAN_NO_ERROR  (0xffffeeee) //串口号错误


#define  DRV_CLK_100M (100)//频率为100M


#define  DRV_CLK_100M_PERIOD (10)//频率为100M时，周期为10ns


#define  DRV_CLK_16M (16)//频率为16M


#define  DRV_CLK_20M (20)//频率为20M


#define  DRV_CLK_20M_PERIOD (50)//频率为20M时，周期为50ns


#define  DRV_COUNT_CTRL_MODE  (1)


#define  DRV_COUNT_HIGH_MODE  (1)


#define  DRV_COUNT_LOW_MODE  (0)


#define  DRV_COUNT_OTHER_MODE  (2)


#define  DRV_COUNT_SOFT_MODE  (0)


#define  DRV_FIRST_SAMP  (0)//SPI 在时钟第1个跳变沿采样数据


#define  DRV_GPS_OUTPUT_ADDR  (0x10C8)//GPS选择输出地址


#define  DRV_Get(addr)                              (*(V_U32 *)((U32)(addr)))


#define  DRV_INT_EDGE_TRIG  (0)//电平触发


#define  DRV_INT_HIGH_TRIG  (1)//高电平或上升沿触发


#define  DRV_INT_LOW_TRIG (2)//低电平或下降沿触发


#define  DRV_INT_PULSE_TRIG (3)//边沿触发


#define  DRV_NO_ERROR  (0xffffffff)//接口驱动中传参no不合法时返回值，除星时


#define  DRV_PULSE_PERIOD  (1)


#define  DRV_PULSE_SINGLE  (0)


#define  DRV_SECOND_SAMP (1) //SPI 在时钟第2个跳变沿采样数据


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


#define  MERGE_SORT_SIZE           100


#define  SORT_ATTRIBUTE_TYPE       unint32


#define  TT_PARTITION_STATE				(0x00010000)


#define  TT_RECV_FRAME_STATE			(0x00020001)


#define  TT_RECV_PARTITION_STATE		(0x00020000)


#define  TT_SEND_CONTROL				(0x00010001)


#define  _1553B_UPDATE_TIME_    0x20240308u


#define  _1553B_VER_INFO_       0x00000201u


#define  _UPDATE_TIME_    0x20181219u


#define  _UPDATE_TIME_    0x20231130u


#define  _VER_INFO_       0x00000105u


#define  _VER_INFO_       0x00000200u


#define  __TEST_MAIN_H__


#define  __TEST_NANDFlash_H__


#define  __TEST_NorFlash_H__


#define  __TEST_Task_H__


#define A6017_Param1Add						SYS_NorFlash_ADDAParam1_Base


#define A6017_Param2Add						SYS_NorFlash_ADDAParam2_Base


#define ABSUI_TO_ADDR(ui)           ((unint32 *)(ui))


#define ABSUI_TO_ADDR(ui)           ((unint32 *)(ui))


#define ABSUI_TO_ADDR08(ui)         ((volatile unint08 *)(ui))


#define ABSUI_TO_ADDR08(ui)         ((volatile unint08 *)(ui))


#define ABSUI_TO_VADDR(ui)          ((volatile unint32 *)(ui))


#define ABSUI_TO_VADDR(ui)          ((volatile unint32 *)(ui))


#define ABSUI_TO_VADDR32(ui)        ((volatile unint32 *)(ui))


#define ABSUI_TO_VADDR32(ui)        ((volatile unint32 *)(ui))


#define ABT_MODE_STACK_SIZE				(8*1024)


#define ABT_MODE_STACK_TOP			((UND_MODE_STACK_TOP - UND_MODE_STACK_SIZE) & 0xfffffff0)


#define ACCEPTANCE_WINDOW_reg           (0x0C)


#define ADDA_KB_SIZE						(2048)


#define ADDR_IS_ALIGN(addr)         (((addr) & 0x3) == 0)


#define ADDR_IS_ALIGN(addr)         (((addr) & 0x3) == 0)


#define ADDR_RANGE_VALIDATE(addr, head, tail)   (((head) <= (addr)) && ((addr) <= (tail)))


#define ADDR_RANGE_VALIDATE(addr, head, tail)   (((head) <= (addr)) && ((addr) <= (tail)))


#define ADDR_READ(addr)             (*((volatile unint32 *)(addr)))


#define ADDR_READ(addr)             (*((volatile unint32 *)(addr)))


#define ADDR_READ08(addr)           (*((volatile unint08 *)(addr)))


#define ADDR_READ08(addr)           (ADDR_READ((addr)) & 0xFF)


#define ADDR_READ16(addr)           (*((volatile unint16 *)(addr)))


#define ADDR_READ16(addr)           (ADDR_READ((addr)) & 0xFFFF)


#define ADDR_TO_ABSUI(ptr)          ((unint32)(ptr))


#define ADDR_TO_ABSUI(ptr)          ((unint32)(ptr))


#define ADDR_WRITE(addr, value)     {(*((volatile unint32 *)(addr))) = (value);}


#define ADDR_WRITE(addr, value)     {(*((volatile unint32 *)(addr))) = (value);}


#define ADDR_WRITE16(addr, val16)   {(*((volatile unint16 *)(addr))) = (val16);}


#define ADDR_WRITE16(addr, val16)   {(*((volatile unint16 *)(addr))) = (val16);}


#define ALL_USR_ISR					(0xfffffff0)


#define AM29LV160D			(2)	//AM29LV160,2M大小


#define AOCC_A_LOG_ADDR (0x51u)


#define AOCC_B_LOG_ADDR (0x52u)


#define AOCC_C_LOG_ADDR (0x53u)


#define AOCC_RT_ADDR (0x12u)


#define APB_TIMER_NO_END		(APB_TIMER_NO_START + __APB_TIMER_NUM__ - 1)


#define APB_TIMER_NO_START		(0x2)


#define APPOKMINCOUNT						(80)


#define APP_CP_AOCC_SYNC (0xBBBBu)


#define APP_CP_TIMESLICE (0xAAAAu)


#define APP_CP_TTE_SYNC (0xCCCCu)

#define ARRAY_SIZE(x)                   (sizeof((x)) / sizeof((x[0])))


#define Atan2x(x, y)    (atan2((float64)(x), (float64)(y)))


#define Atan2x(y, x)    (atan2((float64)(y), (float64)(x)))


#define Atanx(x)        (atan((float64)(x))               )


#define Atanx(x)        (atan((float64)(x))               )


#define B1553_0_ERR							(0x1)


#define B1553_0_MEM_BASE		(0x28000000)


#define B1553_0_REG_BASE		(0xA0030000)


#define B1553_1_ERR							(0x2)


#define B1553_1_MEM_BASE		(0x29000000)


#define B1553_1_REG_BASE		(0xA0040000)


#define B1553_ADDR(offno, addrbase)         ((volatile unint32 *)(((offno) << 2u) + (addrbase)))


#define B1553_B0_ERR					(0x2)	//b1553b0_twobits_err


#define B1553_B1_ERR					(0x1)	//b1553b1_twobits_err


#define B1553_CHIP_61580            0x2222


#define B1553_CHIP_63825            0x3333


#define B1553_CHIP_65170            0x1111


#define B1553_CHIP_OTHERS           0x5555


#define B1553_CHIP_SOC2018          0x4444


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


#define B1553_GAP				(0x1000)


#define B1553_MEM_INIT_ALL          0x2222


#define B1553_MEM_INIT_LESS         0x3333


#define B1553_MEM_INIT_NULL         0x1111


#define B1553_MODE_BC_ENHANCED      0xD2


#define B1553_MODE_BC_NORMAL        0xE1


#define B1553_MODE_IDLE             0x00


#define B1553_MODE_MSG_MONI         0xA5


#define B1553_MODE_RT_ENHANCED      0x87


#define B1553_MODE_RT_MT            0x78


#define B1553_MODE_RT_NORMAL        0x96


#define B1553_MODE_WORD1_MONI       0xC3


#define B1553_MODE_WORD2_MONI       0xB4


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


#define B1553_MSG_POLL_COUNT        5000u


#define B1553_MSG_POLL_COUNT        500u


#define B1553_MSG_TRANS_TIME        800u


#define B1553_RAMA				(0x0)


#define B1553_RAMB				(0x1)


#define B1553_READ(offno, addrbase)         (((*(volatile unint32 *)(((offno) << 2u) + (addrbase)))) & 0xFFFFu)


#define B1553_REG_BASE                       0x0000


#define B1553_REG_BC_CTRW                    0x0004


#define B1553_REG_BC_FRM_TIME_REM            0x000B


#define B1553_REG_BC_FTIME                   0x000D


#define B1553_REG_BC_TIME_REM_NMSG           0x000C


#define B1553_REG_CMD_STACK_PTR              0x0003


#define B1553_REG_CONF1                      0x0001


#define B1553_REG_CONF2                      0x0002


#define B1553_REG_CONF3                      0x0007


#define B1553_REG_CONF4                      0x0008


#define B1553_REG_CONF5                      0x0009


#define B1553_REG_INT_MASK                   0x0000


#define B1553_REG_INT_ST                     0x0006


#define B1553_REG_MT_DAT_STK_PTR             0x000A


#define B1553_REG_MT_TRIGGER_WORD            0x000D


#define B1553_REG_RT_BITW                    0x000F


#define B1553_REG_RT_DAT_STK_PTR             0x000A


#define B1553_REG_RT_LAST_CMD                0x000D


#define B1553_REG_RT_SA_CTRW                 0x0004


#define B1553_REG_RT_STW                     0x000E


#define B1553_REG_START_RST                  0x0003


#define B1553_REG_TIME_TAG                   0x0005


#define B1553_RESP_TIMEOUT_1300         3u


#define B1553_RESP_TIMEOUT_185          0u


#define B1553_RESP_TIMEOUT_225          1u


#define B1553_RESP_TIMEOUT_505          2u


#define B1553_RT_BROAD                      0x02


#define B1553_RT_BROAD              0x02


#define B1553_RT_CONGIG_ERR                 0x1100


#define B1553_RT_CONGIG_ERR_CHIP            (B1553_RT_CONGIG_ERR | 0x01u)


#define B1553_RT_CONGIG_ERR_CMD_ILLEGAL     (B1553_RT_CONGIG_ERR | 0x11u)


#define B1553_RT_CONGIG_ERR_DATALEN         (B1553_RT_CONGIG_ERR | 0x0Bu)


#define B1553_RT_CONGIG_ERR_ENHANCED        (B1553_RT_CONGIG_ERR | 0x02u)


#define B1553_RT_CONGIG_ERR_EOM_INT         (B1553_RT_CONGIG_ERR | 0x0Eu)


#define B1553_RT_CONGIG_ERR_MEMSIZE         (B1553_RT_CONGIG_ERR | 0x04u)


#define B1553_RT_CONGIG_ERR_NUM             (B1553_RT_CONGIG_ERR | 0x0Fu)


#define B1553_RT_CONGIG_ERR_RTADDR          (B1553_RT_CONGIG_ERR | 0x03u)


#define B1553_RT_CONGIG_ERR_SA              (B1553_RT_CONGIG_ERR | 0x09u)


#define B1553_RT_CONGIG_ERR_SAME_BLK        (B1553_RT_CONGIG_ERR | 0x0Du)


#define B1553_RT_CONGIG_ERR_SA_DUPLIC       (B1553_RT_CONGIG_ERR | 0x0Cu)


#define B1553_RT_CONGIG_ERR_STKSIZE         (B1553_RT_CONGIG_ERR | 0x05u)


#define B1553_RT_CONGIG_ERR_STK_EXPAND      (B1553_RT_CONGIG_ERR | 0x06u)


#define B1553_RT_CONGIG_ERR_STK_OVERMEM     (B1553_RT_CONGIG_ERR | 0x07u)


#define B1553_RT_CONGIG_ERR_STK_SELECT      (B1553_RT_CONGIG_ERR | 0x08u)


#define B1553_RT_CONGIG_ERR_TIMETAG         (B1553_RT_CONGIG_ERR | 0x10u)


#define B1553_RT_CONGIG_ERR_TRB             (B1553_RT_CONGIG_ERR | 0x0Au)


#define B1553_RT_ERR_NULL                   0x0000


#define B1553_RT_HARDWARE_SET               0xFF


#define B1553_RT_INSTANCE_ERR               0x4400


#define B1553_RT_INSTANCE_ERR_OVER          (B1553_RT_INSTANCE_ERR    | 0x01u)


#define B1553_RT_LOOKUP_DISP_ERR            0x3300


#define B1553_RT_LOOKUP_DISP_ERR_OVER       (B1553_RT_LOOKUP_DISP_ERR | 0x01u)


#define B1553_RT_LOOKUP_MONITOR_ERR         0x5500


#define B1553_RT_LOOKUP_MONITOR_ERR_CTRL    (B1553_RT_LOOKUP_MONITOR_ERR | 0x01u)


#define B1553_RT_LOOKUP_MONITOR_ERR_CYCLE   (B1553_RT_LOOKUP_MONITOR_ERR | 0x03u)


#define B1553_RT_LOOKUP_MONITOR_ERR_SINGLE  (B1553_RT_LOOKUP_MONITOR_ERR | 0x02u)


#define B1553_RT_RECV                       0x00


#define B1553_RT_RECV               0x00


#define B1553_RT_STK_DISP_ERR               0x2200


#define B1553_RT_STK_DISP_ERR_OVER          (B1553_RT_STK_DISP_ERR    | 0x01u)


#define B1553_RT_TRAN                       0x01


#define B1553_RT_TRAN               0x01


#define B1553_TIMETAG_02us          0x5u


#define B1553_TIMETAG_04us          0x4u


#define B1553_TIMETAG_08us          0x3u


#define B1553_TIMETAG_16us          0x2u


#define B1553_TIMETAG_32us          0x1u


#define B1553_TIMETAG_64us          0x0u


#define B1553_TWO_BITS_ERR_INT			(0x3<<9)	//b15531_twobits_err


#define B1553_WRITE(offno, val32, addrbase) ((*((volatile unint32 *)((((offno) << 2u) + (addrbase))))) = ((val32) & 0xFFFFu))


#define BASIC_MODE_reg					(0x3E)


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


#define BC_DEBUG_ENABLE             0


#define BC_INSTANCE_MAX             0


#define BC_MEM_CMDSTACK_PTR_A           0x0100


#define BC_MEM_CMDSTACK_PTR_A_INI       0x0102


#define BC_MEM_CMDSTACK_PTR_B           0x0104


#define BC_MEM_CMDSTACK_PTR_B_INI       0x0106


#define BC_MEM_MSGCNT_PTR_A             0x0101


#define BC_MEM_MSGCNT_PTR_A_INI         0x0103


#define BC_MEM_MSGCNT_PTR_B             0x0105


#define BC_MEM_MSGCNT_PTR_B_INI         0x0107


#define BC_STACK_MSG_MAX                64u		//手册中，最大到消息块93


#define BE_MAC_LABEL_reg_HIGH           (0x2D)


#define BE_MAC_LABEL_reg_LOW            (0x2C)


#define BE_RECV_RAM_START_ADDR			(0x02004000)


#define BE_SEND_RAM_START_ADDR			(0x01004000)


#define BE_SERVICE							(0x0)


#define BE_partition_allocated_num 		(0x4A)


#define BE_partition_valid_num_reg 		(0x36)


#define BE_recv_partition_base_addr 	(0x3D)


#define BE_recv_rd_frame_done_reg 		(0x39)


#define BE_recv_vl_length_reg 			(0x4F)


#define BE_recv_vl_num_reg 				(0x4E)


#define BE_recv_vl_partition_addr 		(0x4F)


#define BE_send_length_reg 				(0x35)


#define BE_send_partition_addr_reg   	(0x36)


#define BE_send_partition_base_addr 	(0x3B)


#define BE_send_wr_done_reg 			(0x37)


#define BHDR_OVERHEAD	(0x10 - MIN_BLOCK_SIZE)


#define BIG_STAR_TIME 4294901760.0


#define BIT(b) ((0x00000001) << (b))


#define BIT_CLR(uv, bp, mask)           ((uv) = (uv) & ((0x01u << (bp)) ^ (mask)))


#define BIT_CLR(uv, bp, mask)           ((uv) = (uv) & ((0x01u << (bp)) ^ (mask)))


#define BIT_GET(uv, bp)                 (((uv) >> (bp)) & 0x01u)


#define BIT_GET(uv, bp)                 (((uv) >> (bp)) & 0x01u)


#define BIT_SET(uv, bp, mask)           ((uv) = (uv) | ((0x01u << (bp)) & (mask)))


#define BIT_SET(uv, bp, mask)           ((uv) = (uv) | ((0x01u << (bp)) & (mask)))


#define BLOCK_ALIGN		(0x8)


#define BLOCK_SIZE		(0xFFFFFFFF - PTR_MASK)


#define BLOCK_STATE	(0x1)


#define BREAK_REV		0x8


#define BSPGPIDATR_INIT 			((GPI0_DATA << 0)|	\
															(GPI1_DATA << 1)|	\
															(GPI2_DATA << 2)|	\
															(GPI3_DATA << 3)|	\
															(GPI4_DATA << 4)|	\
															(GPI5_DATA << 5)|	\
															(GPI6_DATA << 6)|	\
															(GPI7_DATA << 7)|	\
															(GPI8_DATA << 8)|	\
															(GPI9_DATA << 9)|	\
															(GPI10_DATA << 10)| \
															(GPI11_DATA << 11)| \
															(GPI12_DATA << 12)| \
															(GPI13_DATA << 13)| \
															(GPI14_DATA << 14)| \
															(GPI15_DATA << 15))


#define BSPGPIDIRR_INIT 			((GPI0_CFG << 0)|	\
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
															(GPI15_CFG << 15))


#define BSPGPIINTCLR_INIT			(0xFFFF)


#define BSPGPIINTMKR_INIT			(~BSPGPIINT_EN_INIT)


#define BSPGPIINT_EN_INIT 			((GPI0_IntEn << 0)|	\
															(GPI1_IntEn << 1)|	\
															(GPI2_IntEn << 2)|	\
															(GPI3_IntEn << 3)|	\
															(GPI4_IntEn << 4)|	\
															(GPI5_IntEn << 5)|	\
															(GPI6_IntEn << 6)|	\
															(GPI7_IntEn << 7)|	\
															(GPI8_IntEn << 8)|	\
															(GPI9_IntEn << 9)|	\
															(GPI10_IntEn << 10)| \
															(GPI11_IntEn << 11)| \
															(GPI12_IntEn << 12)| \
															(GPI13_IntEn << 13)| \
															(GPI14_IntEn << 14)| \
															(GPI15_IntEn << 15))


#define BSPGPIINT_POLA_INIT 		((GPI0Int_TRIG_POLARITY << 0)|	\
												(GPI1Int_TRIG_POLARITY << 1)|	\
												(GPI2Int_TRIG_POLARITY << 2)|	\
												(GPI3Int_TRIG_POLARITY << 3)|	\
												(GPI4Int_TRIG_POLARITY << 4)|	\
												(GPI5Int_TRIG_POLARITY << 5)|	\
												(GPI6Int_TRIG_POLARITY << 6)|	\
												(GPI7Int_TRIG_POLARITY << 7)|	\
												(GPI8Int_TRIG_POLARITY << 8)|	\
												(GPI9Int_TRIG_POLARITY << 9)|	\
												(GPI10Int_TRIG_POLARITY << 10)| \
												(GPI11Int_TRIG_POLARITY << 11)| \
												(GPI12Int_TRIG_POLARITY << 12)| \
												(GPI13Int_TRIG_POLARITY << 13)| \
												(GPI14Int_TRIG_POLARITY << 14)| \
												(GPI15Int_TRIG_POLARITY << 15))


#define BSPGPIINT_TRIG_INIT 		((GPI0Int_TRIG_MODE << 0)|	\
													(GPI1Int_TRIG_MODE << 1)|	\
													(GPI2Int_TRIG_MODE << 2)|	\
													(GPI3Int_TRIG_MODE << 3)|	\
													(GPI4Int_TRIG_MODE << 4)|	\
													(GPI5Int_TRIG_MODE << 5)|	\
													(GPI6Int_TRIG_MODE << 6)|	\
													(GPI7Int_TRIG_MODE << 7)|	\
													(GPI8Int_TRIG_MODE << 8)|	\
													(GPI9Int_TRIG_MODE << 9)|	\
													(GPI10Int_TRIG_MODE << 10)| \
													(GPI11Int_TRIG_MODE << 11)| \
													(GPI12Int_TRIG_MODE << 12)| \
													(GPI13Int_TRIG_MODE << 13)| \
													(GPI14Int_TRIG_MODE << 14)| \
													(GPI15Int_TRIG_MODE << 15))


#define BSPGPIOPWIDTH_INIT			(0x0000)


#define BSPINTDEBOUNCE_INIT			(0x0000)


#define BSPMODCTRL_INIT				(0x0000)


#define BSPRAMSIZE				(0x00200000)


#define BSPUART1BAUD			115200


#define BSPUART2BAUD			115200


#define BSP_1553B0_SEU_IRQID		(93)


#define BSP_1553B0_TWO_BITS_ERR_INT	(0x1<<9) //b15530_twobits_err


#define BSP_1553B1_SEU_IRQID		(94)


#define BSP_1553B1_TWO_BITS_ERR_INT	(0x1<<10) //b15531_twobits_err


#define BSP_1553B_ERR_CLEAR_REG	(0x40)	//共享RAM错误状态清除


#define BSP_1553B_RAMA_ERR_REG	(0x40)	//共享RAM A端口出错的地址


#define BSP_1553B_RAMB_ERR_REG	(0x44)	//共享RAM B端口出错的地址


#define BSP_1553SIZE			(16*1024)


#define BSP_1553_0_IRQID			(32)


#define BSP_1553_0_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_1553_1_IRQID			(33)


#define BSP_1553_1_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+12)


#define BSP_1553_A_SEU_ERR		(1)


#define BSP_1553_A_TBE_ERR		(1<<1)


#define BSP_1553_B_SEU_ERR		(1<<2)


#define BSP_1553_B_TBE_ERR		(1<<3)


#define BSP_ABC_VARIABLE_BIT			(0x2)


#define BSP_ABC_VARIABLE_GPIONO			(0x2)


#define BSP_AMBA_AHB_BASEADDR		(0xf00)


#define BSP_AMBA_MEMORY_BASEADDR	(0x0)


#define BSP_AMBA_UART0_BASEADDR		(0xA0000000)


#define BSP_AMBA_UART1_BASEADDR		(0xA0000100)


#define BSP_AMBA_WDT_BASEADDR		(0x3FFF0600)


#define BSP_APBTIMER_0_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_APBTIMER_1_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_APBTIMER_2_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_APBTIMER_3_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_APBTIMER_4_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_APBTIMER_5_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_APBTIMER_6_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_APBTIMER_7_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+2)


#define BSP_APBTIMER_BASEADDR		(0xA00B0000)


#define BSP_A_VALUE						(0x00)


#define BSP_All_POWER_ON				(1)


#define BSP_BLOCK_SINGLE				(0x2)


#define BSP_BLOCK_TR32					(0x0)


#define BSP_BLOCK_TRAB					(0x1)


#define BSP_BLOCK_USERDEF				(0x3)


#define BSP_B_VALUE						(0x01)


#define BSP_CLAP_Inc_ADDR_RD_LENGTH    (13)


#define BSP_CLAP_Inc_ADDR_WR_NODATA_LENGTH    (8)


#define BSP_CLAP_MAX_BYTE_LENGTH            (512*4)  //0412 clap协议长度


#define BSP_CLAP_SINGLE_ADDR_RD_LENGTH    (8)


#define BSP_CLAP_SINGLE_ADDR_WR_LENGTH    (12)


#define BSP_CPU_INT_CNT				(160)


#define BSP_C_VALUE						(0x02)


#define BSP_ClearFTWDT_FLAG_BIT			((1<<9) | (1<<8))


#define BSP_ClearFTWDT_NO_VALUE			((0<<9) | (0<<8))


#define BSP_ClearFTWDT_YES_VALUE		((1<<9) | (1<<8))


#define BSP_DMA_SEU_IRQID			(79)


#define BSP_EDAC_CFGR				(BSP_AMBA_MEMORY_BASEADDR + 0x08)


#define BSP_EDGE_TRIGGER			(0x3)


#define BSP_EMIF_DATA16						(0x1)


#define BSP_EMIF_DATA32						(0x3)


#define BSP_EMIF_DATA8						(0x0)


#define BSP_EMIF_DOUBLE_ERR_EN			(BSP_ENABLE)


#define BSP_EMIF_DOUBLE_ERR_INT		(100)


#define BSP_EMIF_INIT_FILL_SIZE				(BSP_EMIF_RAM_SIZE-BSP_EMIF_INIT_LOADER_FILLED_SIZE)


#define BSP_EMIF_INIT_FILL_StartAdd			(BSP_EMIF_RAM_BASE_ADDR+BSP_EMIF_INIT_LOADER_FILLED_SIZE)


#define BSP_EMIF_INIT_LOADER_FILLED_SIZE	(0x00000)


#define BSP_EMIF_IO_IOMEM_WS_H1			(0x8)


#define BSP_EMIF_IO_IOMEM_WS_H2			(0x8)


#define BSP_EMIF_IO_IOMEM_WS_S1			(0x8)


#define BSP_EMIF_IO_IOMEM_WS_S2			(0x8)


#define BSP_EMIF_IO_RDY_BUS_TIMEOUT_ERR_IRQID		(83)


#define BSP_EMIF_IO_Rdy_Timeout_reg		(0x61a8)


#define BSP_EMIF_IO_WS_CFG_REG 			( (BSP_EMIF_IO_IOMEM_WS_S1 << 24)|		\
											(BSP_EMIF_IO_IOMEM_WS_S2 << 16)|	\
											(BSP_EMIF_IO_IOMEM_WS_H2 << 8)|		\
												BSP_EMIF_IO_IOMEM_WS_H1)


#define BSP_EMIF_IO_config_reg			( (BSP_EMIF_IO_rdy << 10)|		\
											(BSP_EMIF_IO_wt << 8)|		\
												BSP_EMIF_IO_ws)


#define BSP_EMIF_IO_rdy					(0)


#define BSP_EMIF_IO_ws					(0x80)


#define BSP_EMIF_IO_wt					(BSP_EMIF_DATA32)


#define BSP_EMIF_RAMEDAC_EN				(BSP_ENABLE)


#define BSP_EMIF_RAM_16M					(0xb)


#define BSP_EMIF_RAM_1M						(0x7)


#define BSP_EMIF_RAM_2M						(0x8)


#define BSP_EMIF_RAM_32M					(0xc)


#define BSP_EMIF_RAM_4M						(0x9)


#define BSP_EMIF_RAM_512K					(0x0)


#define BSP_EMIF_RAM_64M					(0xf)


#define BSP_EMIF_RAM_8M						(0xa)


#define BSP_EMIF_RAM_BASE_ADDR			(0x10000000)


#define BSP_EMIF_RAM_END_ADDR			(BSP_EMIF_RAM_BASE_ADDR + BSP_EMIF_RAM_SIZE)


#define BSP_EMIF_RAM_SIZE               (8*1024*1024)


#define BSP_EMIF_RAM_WRMEM_BS			(BSP_EMIF_RAM_2M)


#define BSP_EMIF_RAM_WRMEM_CONFIG_REG  ( (BSP_EMIF_RAM_WRMEM_WT << 14)|			\
											(BSP_EMIF_RAM_WRMEM_RMW << 12)|		\
											(BSP_EMIF_RAM_WRMEM_BS << 8)|		\
												BSP_EMIF_RAM_WRMEM_WS)


#define BSP_EMIF_RAM_WRMEM_RMW			(BSP_ENABLE)


#define BSP_EMIF_RAM_WRMEM_WS			(0xA)


#define BSP_EMIF_RAM_WRMEM_WS_H1		(0x1)


#define BSP_EMIF_RAM_WRMEM_WS_H2		(0x0)


#define BSP_EMIF_RAM_WRMEM_WS_S1		(0x2)


#define BSP_EMIF_RAM_WRMEM_WS_S2		(0x2)


#define BSP_EMIF_RAM_WRMEM_WT			(BSP_EMIF_DATA32)


#define BSP_EMIF_RAM_WR_WRITE_BACK_EN	(BSP_DISABLE)


#define BSP_EMIF_RAM_WR_WS_CFG_REG		( (BSP_EMIF_RAM_WRMEM_WS_S1 << 24)|		\
										(BSP_EMIF_RAM_WRMEM_WS_S2 << 16)|		\
										(BSP_EMIF_RAM_WRMEM_WS_H2 << 8)|		\
												BSP_EMIF_RAM_WRMEM_WS_H1)


#define BSP_EMIF_REG_BASE_ADDR			(BSP_MEC_BASE_ADDR)


#define BSP_EMIF_ROMEDAC_EN				(BSP_ENABLE)


#define BSP_EMIF_ROM_128K					(0x4)


#define BSP_EMIF_ROM_16K					(0x1)


#define BSP_EMIF_ROM_16M					(0xb)


#define BSP_EMIF_ROM_1M						(0x7)


#define BSP_EMIF_ROM_256K					(0x5)


#define BSP_EMIF_ROM_2M						(0x8)


#define BSP_EMIF_ROM_32K					(0x2)


#define BSP_EMIF_ROM_32M					(0xc)


#define BSP_EMIF_ROM_4M						(0x9)


#define BSP_EMIF_ROM_512K					(0x6)


#define BSP_EMIF_ROM_64K					(0x3)


#define BSP_EMIF_ROM_64M					(0xf)


#define BSP_EMIF_ROM_8K						(0x0)


#define BSP_EMIF_ROM_8M						(0xa)


#define BSP_EMIF_ROM_ORMEM_BS			(BSP_EMIF_ROM_64M)


#define BSP_EMIF_ROM_ORMEM_RMW			(BSP_DISABLE)


#define BSP_EMIF_ROM_ORMEM_WEN			(BSP_ENABLE)


#define BSP_EMIF_ROM_ORMEM_WS			(0x28)


#define BSP_EMIF_ROM_ORMEM_WS_H1		(0x5)


#define BSP_EMIF_ROM_ORMEM_WS_H2		(0xB)


#define BSP_EMIF_ROM_ORMEM_WS_S1		(0x1)


#define BSP_EMIF_ROM_ORMEM_WS_S2		(0x1)


#define BSP_EMIF_ROM_ORMEM_WT			(BSP_EMIF_DATA8)


#define BSP_EMIF_ROM_ORMEM_config_reg  	( (BSP_EMIF_ROM_ORMEM_WEN<<16)|			\
										(BSP_EMIF_ROM_ORMEM_WT << 14)|			\
										(BSP_EMIF_ROM_ORMEM_RMW << 12)|			\
										(BSP_EMIF_ROM_ORMEM_BS << 8)|			\
										BSP_EMIF_ROM_ORMEM_WS)


#define BSP_EMIF_ROM_OR_WRITE_BACK_EN	(BSP_DISABLE)


#define BSP_EMIF_ROM_OR_WS_CFG_REG		( (BSP_EMIF_ROM_ORMEM_WS_S1 << 24)|		\
										(BSP_EMIF_ROM_ORMEM_WS_S2 << 16)|		\
										(BSP_EMIF_ROM_ORMEM_WS_H2 << 8)|		\
										BSP_EMIF_ROM_ORMEM_WS_H1)


#define BSP_EMIF_SEU_IRQID			(81)


#define BSP_EMIF_WRITE_TO_FORBIDEN_AREA_ERR_IRQID	(82)


#define BSP_FORCE_A_WORK_ON				(0)


#define BSP_FORCE_B_WORK_ON				(1)


#define BSP_FORCE_C_WORK_ON				(2)


#define BSP_FORCE_WORK_OFF				(3)


#define BSP_GIC_BASE_ADDR				(0xF8F00000)


#define BSP_GIC_ICC_BASEADDR		(BSP_INTR_GIC_BASE + 0x100)


#define BSP_GIC_ICD_BASEADDR		(BSP_INTR_GIC_BASE + 0x1000)


#define BSP_GLOBAL_TIMER_BASEADDR	(BSP_INTR_GIC_BASE + 0x200)


#define BSP_GPIO_0_IRQID			(34)


#define BSP_GPIO_10_IRQID			(44)


#define BSP_GPIO_11_IRQID			(45)


#define BSP_GPIO_12_IRQID			(46)


#define BSP_GPIO_13_IRQID			(47)


#define BSP_GPIO_14_IRQID			(48)


#define BSP_GPIO_15_IRQID			(49)


#define BSP_GPIO_1_IRQID			(35)


#define BSP_GPIO_2_IRQID			(36)


#define BSP_GPIO_3_IRQID			(37)


#define BSP_GPIO_4_IRQID			(38)


#define BSP_GPIO_4_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+7)


#define BSP_GPIO_5_IRQID			(39)


#define BSP_GPIO_5_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+6)


#define BSP_GPIO_6_IRQID			(40)


#define BSP_GPIO_6_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+5)


#define BSP_GPIO_7_IRQID			(41)


#define BSP_GPIO_7_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+4)


#define BSP_GPIO_8_IRQID			(42)


#define BSP_GPIO_9_IRQID			(43)


#define BSP_GPIO_BASE_ADDR				(0xA00D0000)


#define BSP_GPIO_HARD_MODE						(0x1)


#define BSP_GPIO_IN								(0x0)


#define BSP_GPIO_OUT							(0x1)


#define BSP_GPIO_SOFT_MODE						(0x0)


#define BSP_GPI_FALL_EDGE_TRIGER				(0x1)


#define BSP_GPI_HIGH_LEVEL_TRIGER				(0x2)

#define BSP_GPI_LOW_LEVEL_TRIGER				(0x3)

#define BSP_GPI_RISE_EDGE_TRIGER				(0x0)

#define BSP_Get(addr)			(*(V_U32 *)((U32)(addr)))


#define BSP_HIGHEST_PRIORITY		(0)


#define BSP_HOTFT_POWER_OFF				(0)


#define BSP_HOTFT_POWER_ON				(1)


#define BSP_IDLE_VALUE					(0x1)


#define BSP_IIC0_IRQID				(69)


#define BSP_IIC1_IRQID				(68)


#define BSP_INTR_GIC_BASE			(0x3FFF0000)


#define BSP_INTR_ICCABPR			(0x01c)


#define BSP_INTR_ICCBPR				(0x008)


#define BSP_INTR_ICCEOIR			(0x010)


#define BSP_INTR_ICCHPIR			(0x018)


#define BSP_INTR_ICCIAR				(0x00C)


#define BSP_INTR_ICCICR				(0x000)


#define BSP_INTR_ICCIDR				(0x0fc)


#define BSP_INTR_ICCPMR				(0x004)


#define BSP_INTR_ICCRPR				(0x014)


#define BSP_INTR_ICDABR				(0x300)


#define BSP_INTR_ICDDCR				(0x000)


#define BSP_INTR_ICDICER			(0x180)


#define BSP_INTR_ICDICFR			(0xc00)


#define BSP_INTR_ICDICPR			(0x280)


#define BSP_INTR_ICDICTR			(0x004)


#define BSP_INTR_ICDIIDR			(0x008)


#define BSP_INTR_ICDIPR				(0x400)


#define BSP_INTR_ICDIPTR			(0x800)


#define BSP_INTR_ICDISER			(0x100)


#define BSP_INTR_ICDISPR			(0x200)


#define BSP_INTR_ICDISR				(0x080)


#define BSP_INTR_ICDSGIR			(0xf00)


#define BSP_INT_USED_NUM			(0)


#define BSP_INVALID_MACHINE				(0xff)


#define BSP_INVALID_PRIORITY		(BSP_LOWEST_PRIORITY + 1)


#define BSP_IOASIC_0_IRQID			(50)


#define BSP_IOASIC_0_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+10)


#define BSP_IOASIC_1_IRQID			(51)


#define BSP_IOASIC_1_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+9)


#define BSP_IOASIC_2_IRQID			(52)


#define BSP_IOASIC_2_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+8)


#define BSP_IO_BASE_ADDR				(0x20000000)


#define BSP_IO_END_ADDR					(0x28000000)


#define BSP_JK_OUTPUT_BIT				(10)


#define BSP_JK_OUTPUT_NO_VALUE			(0)


#define BSP_JK_OUTPUT_YES_VALUE			(1)


#define BSP_LEVEL_TRIGGER			(0x1)


#define BSP_LOWEST_PRIORITY			(30)


#define BSP_MACHINE_TYPE				(0x2)


#define BSP_MEC_BASE_ADDR				(0xA00A0000)


#define BSP_MEC_END_ADDR				(0xF8F01FFC)


#define BSP_MON_FLAG_BIT				(12)


#define BSP_MON_NO_VALUE				(0x1)


#define BSP_MON_YES_VALUE				(0x0)


#define BSP_ONLY_SELF_POWER_ON			(0)


#define BSP_OTHER_POWER_ON				(2)


#define BSP_PM_WORK_FLAG_BIT			(0xE)


#define BSP_POWEROFF					(0x1)


#define BSP_POWERON						(0x0)


#define BSP_POWER_ON_BIT				(0x7)


#define BSP_POWER_ON_FLAG_BIT			(0x8)


#define BSP_POWER_ON_GPIONO				(0x9)


#define BSP_POWER_ON_RESET_FLAG_BIT		(0xD)


#define BSP_POWER_ON_VALUE				(0x1)


#define BSP_PRIVATE_TIMER_BASEADDR	(BSP_INTR_GIC_BASE + 0x600)


#define BSP_Prog_SRAM_Flag				(0x3)


#define BSP_RAM_BASE_ADDR				(0x40000000)


#define BSP_RAM_END_ADDR				(BSP_RAM_BASE_ADDR + BSPRAMSIZE)


#define BSP_RESET						(0xeb90146f)


#define BSP_ROMCS0_BASE_ADDR			(0x00000000)


#define BSP_ROMCS0_END_ADDR				(0x04000000)


#define BSP_ROMCS1_BASE_ADDR			(0x04000000)


#define BSP_ROMCS1_END_ADDR				(0x08000000)


#define BSP_ROMCS2_BASE_ADDR			(0x08000000)


#define BSP_ROMCS2_END_ADDR				(0x0C000000)


#define BSP_ROMCS3_BASE_ADDR			(0x0C000000)


#define BSP_ROMCS3_END_ADDR				(0x10000000)


#define BSP_ROM_Storge3_BASE					(0)


#define BSP_ROM_Storge3_END						(0)


#define BSP_SDRAM_DATA_BASE_ADDR		(0xC0000000)


#define BSP_SDRAM_DATA_END_ADDR			(BSP_SDRAM_DATA_BASE_ADDR+SDRAM_SIZE)


#define BSP_SDRAM_EDAC_CTL				( (SDRAM_EDAC_AHBERR_EN << 3)|			\
															SDRAM_EDAC_EN )


#define BSP_SDRAM_REG_BASE_ADDR			(0xB0000000)


#define BSP_SDRAM_SEU_IRQID			(92)


#define BSP_SLCR_BASEADDR			(0xF8000000)


#define BSP_SOFT_RESET_BIT				(11)


#define BSP_SOFT_RESET_NO_VALUE			(1)


#define BSP_SOFT_RESET_YES_VALUE		(0)


#define BSP_SOFT_TRAP				0x00


#define BSP_SPI_M1_IRQID			(63)


#define BSP_SPW0_EMEM_RX_END			(0x102fffff)


#define BSP_SPW0_EMEM_RX_END			(0xC4000000)


#define BSP_SPW0_EMEM_RX_START			(0x10280000)


#define BSP_SPW0_EMEM_RX_START			(0xC3000000)


#define BSP_SPW0_EMEM_TX_CNT			(0xFFFFFFFF)


#define BSP_SPW0_EMEM_TX_START			(0x10200000)


#define BSP_SPW0_EMEM_TX_START			(0xC2000000)


#define BSP_SPW0_IRQID				(67)


#define BSP_SPW1_EMEM_RX_END			(0x103fffff)


#define BSP_SPW1_EMEM_RX_END			(0xC7000000)


#define BSP_SPW1_EMEM_RX_START			(0x10380000)


#define BSP_SPW1_EMEM_RX_START			(0xC6000000)


#define BSP_SPW1_EMEM_TX_CNT			(0xFFFFFFFF)


#define BSP_SPW1_EMEM_TX_START			(0x10300000)


#define BSP_SPW1_EMEM_TX_START			(0xC5000000)


#define BSP_SPW1_IRQID				(66)


#define BSP_SPW2_BULK_RX_END			(0xFFF)						//最大0xFFF，0到4095，共4096个U32地址


#define BSP_SPW2_BULK_RX_START			(0)


#define BSP_SPW2_BULK_TX_CNT			(32)//(0x4000)				//最大长度0x4000bytes


#define BSP_SPW2_BULK_TX_START			(0)


#define BSP_SPW2_IRQID				(65)


#define BSP_SPW2_RxSEU_IRQID		(89)


#define BSP_SPW2_TxSEU_IRQID		(88)


#define BSP_SPW3_BULK_RX_END			(0xFFF)						//最大0xFFF，0到4095，共4096个U32地址


#define BSP_SPW3_BULK_RX_START			(0)


#define BSP_SPW3_BULK_TX_CNT			(32)//(0x4000)				//最大长度0x4000bytes


#define BSP_SPW3_BULK_TX_START			(0)


#define BSP_SPW3_IRQID				(64)


#define BSP_SPW3_RxSEU_IRQID		(91)


#define BSP_SPW3_TxSEU_IRQID		(90)


#define BSP_SPWSIZE						(16*1024)


#define BSP_SPW_0_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+16)


#define BSP_SPW_1_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+15)


#define BSP_SPW_2_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+14)


#define BSP_SPW_3_IRQID_PRIORITY	(BSP_HIGHEST_PRIORITY+13)


#define BSP_SRAM_ADDR_ONE_BIT_COUNT				(0x18)	//单错计数器寄存器


#define BSP_SRAM_ADDR_ONE_BIT_REG				(0x10)	//最近发生单错并纠正的访问双字地址


#define BSP_SRAM_ADDR_TWO_BIT_REG				(0x20)	//最近发生双错的访问双字地址


#define BSP_SRAM_BYTE_ERR_REG					(0x40)	//单双错字节标识寄存器


#define BSP_SRAM_DATA_TWO_BIT_REG				(0x58)	//最近发生双错的读取数据


#define BSP_SRAM_EADC_READ_BYPASS_ADDR			(0x48)	//EDAC读旁路配置地址寄存器


#define BSP_SRAM_EADC_TWO_BIT_REG				(0x60)	//最近发生双错的读取校验码


#define BSP_SRAM_EADC_WRITE_BYPASS_ADDR			(0x50)	//EDAC写旁路配置地址寄存器


#define BSP_SRAM_EDAC_BYPASS_DATAIN				(0x8)	//EDACBYPASS的注入数据寄存器


#define BSP_SRAM_EDAC_READBYPASS_DATA_HIGH		(0x2c)	//EDAC读旁路数据寄存器--高20位校验码


#define BSP_SRAM_EDAC_READBYPASS_DATA_LOW		(0x28)	//EDAC读旁路数据寄存器--低20位校验码


#define BSP_SRAM_MEM_CONFIG						(0x0)	//空间配置寄存器


#define BSP_SRAM_ONE_BIT_CLEAR					(0x30)	//清单错中断寄存器


#define BSP_SRAM_SEU_IRQID			(80)


#define BSP_SRAM_TWO_BIT_CLEAR					(0x38)	//清多位错中断寄存器


#define BSP_SYS_TRAP				(0x08)


#define BSP_Set(addr, value)	(*(V_U32 *)((U32)(addr)) = (value))


#define BSP_TIMER_0_IRQID			(29)


#define BSP_TIMER_1_IRQID			(27)


#define BSP_TIMER_2_IRQID			(53)


#define BSP_TIMER_3_IRQID			(54)


#define BSP_TIMER_4_IRQID			(55)


#define BSP_TIMER_5_IRQID			(56)


#define BSP_TIMER_6_IRQID			(57)


#define BSP_TIMER_7_IRQID			(58)


#define BSP_TIMER_8_IRQID			(59)


#define BSP_TIMER_9_IRQID			(60)


#define BSP_TRAP_DATA_ABORT				(0x4)


#define BSP_TRAP_FIQ_INTERRUPT			(0x7)


#define BSP_TRAP_IRQ_INTERRUPT			(0x5)


#define BSP_TRAP_NOTUSED_INTERRUPT		(0x6)


#define BSP_TRAP_PREFETCH_ABORT			(0x3)


#define BSP_TRAP_SOFTWARE_INTERRUPT		(0x2)


#define BSP_TRAP_UNDEFINED_ISTRUCTION	(0x1)


#define BSP_UART_0_IRQID			(61)


#define BSP_UART_1_IRQID			(62)


#define BSP_UART_FREQ			400000000


#define BSP_UART_IntEnR						(0x04)


#define BSP_Used_Int_No0			(BSP_1553_1_IRQID)


#define BSP_Used_Int_No1			(BSP_1553_0_IRQID)


#define BSP_Used_Int_No2			(BSP_1553_1_IRQID)


#define BSP_Used_Int_No3			(BSP_IOASIC_1_IRQID)


#define BSP_Used_Int_No4			(BSP_SPW0_IRQID)


#define BSP_Used_Int_No5			(BSP_SPW1_IRQID)


#define BSP_WDT_CONTROL_OFFSET_REG			(0x28)


#define BSP_WDT_COUNT_OFFSET_REG			(0x24)


#define BSP_WDT_FORBIDDEN_OFFSET_REG		(0x34)


#define BSP_WDT_INT_STATUS_OFFSET_REG		(0x2C)


#define BSP_WDT_IRQID				(30)


#define BSP_WDT_RELOAD_OFFSET_REG			(0x20)


#define BSP_WDT_RESET_STATUS_OFFSET_REG		(0x30)


#define BSP_WDT_TIMER_FREQ					(CPU_FREQ)


#define BSP_WORK_FLAG_GPIONO			(0xE)


#define BSP_WORK_VALUE					(0x0)


#define BSP_WORK_VARIABLE_BIT			(0x1)


#define BULK_NOT_SUPPORT					(0)


#define Bsp_Delay(tm)							(Bsp_TimerDelay((BSP_PreciseDelay_No),(tm)))


#define CA_ACCEPTANCE_WINDOW_reg        (0x09)


#define CA_OFFSET_reg                   (0x07)


#define CA_ROUND_TRIP_reg               (0x0A)


#define CCU_1553B0_MEM_ADDR_BASE (0x28000000u)


#define CCU_1553B0_REG_ADDR_BASE (0xA0030000u)


#define CCU_1553B1_MEM_ADDR_BASE (0x29000000u)


#define CCU_1553B1_REG_ADDR_BASE (0xA0040000u)


#define CCU_EMIFSRAM_BASE (0x10000000u)


#define CCU_EMIFSRAM_SIZE (0x800000u)


#define CCU_NORFLASH_BASE (0x08000000u)


#define CCU_NORFLASH_SIZE (0x1980000u)


#define CCU_PROM_BASE (0x00000000u)


#define CCU_PROM_SIZE (0x8000u)


#define CCU_RAM_BASE (0x40000000u)


#define CCU_RAM_SIZE (0x200000u)


#define CERR_ADDR_REG					(0x0030)		//最近发生单错的访问字地址


#define CERR_DATA_REG					(0x0034)		//最近发生单错的访问字数据


#define CERR_EDAC_REG					(0x0038)		//最近发生单错的访问字EDAC码


#define CHECK_MORE_TICK (2)  //作为余量，用来计算关闭单脉冲的时间，可自行设置


#define CHECK_MORE_US (2000)  //作为余量，用来计算关闭单脉冲的时间，可自行设置  目前是2ms


#define CLR_BITS(addr, mask)				\
	{										\
		U32 temp_reg_val = BSP_Get((addr));	\
		temp_reg_val &= ~(mask);			\
		BSP_Set((addr), temp_reg_val);		\
	}


#define CLUSTER_CYCLE_DURATION    		(0x10)


#define CMD_STACK_BOUND(instNo, ptr)        ((sRtStatus[(instNo)].stackBase) + \
                                                (((ptr) - (sRtStatus[(instNo)].stackBase)) & ((sRtStatus[(instNo)].stackSize) - 0x4u)))


#define CMD_STACK_BOUND(ptr)            ((sRtStatus.stackBase) + (((ptr) - (sRtStatus.stackBase)) & ((sRtStatus.stackSize) - 0x4u)))


#define CMD_STACK_MSGNUM(instNo, ptrNew)    ((((ptrNew) + sRtStatus[(instNo)].stackSize - sRtStatus[(instNo)].stackPtrOld) % sRtStatus[(instNo)].stackSize) >> 2u)


#define CMG_CONTROL_ANGLE_LOCK (0xEDu)


#define CMG_CONTROL_ANGLE_SPEED (0xECu)


#define CMG_CONTROL_FRAME_MODE_SET (0xE0u)


#define CMG_CONTROL_HIGH_ROTOR_START (0xE8u)


#define CMG_CONTROL_POSITION_LOCK (0xEAu)


#define CMG_CONTROL_ROTOR_SLIDE (0xE1u)


#define CMG_CONTROL_ROTOR_SPEED (0xE2u)


#define CMG_CONTROL_SOFT_RESET (0xE6u)


#define CMG_FRAME_CLOSE_LOOP (0xAAu)


#define CMG_FRAME_HUNT_CIRCLE (0xF0u)


#define CMG_FRAME_OPEN_LOOP (0x55u)


#define CMG_FRAME_SAFE (0x0Fu)


#define CNT_PLACES_CRI_DATA_SAVE   2


#define COM1_DATABIT_Len		data_8_bit


#define COM1_FIFO_ENABLE		BSP_DISABLE


#define COM1_PARITY_SELECT		no_check


#define COM1_RFIFOINT_LEN		rcvr_1_int


#define COM1_RINT_ENABLE		BSP_DISABLE


#define COM1_STOPBIT_SELECT		stop_1_bit


#define COM1_TFIFOINT_LEN		tet_empty_int


#define COM1_TINT_ENABLE		BSP_DISABLE


#define COM2_DATABIT_Len		data_8_bit


#define COM2_FIFO_ENABLE		BSP_DISABLE


#define COM2_PARITY_SELECT		no_check


#define COM2_RFIFOINT_LEN		rcvr_1_int


#define COM2_RINT_ENABLE		BSP_DISABLE


#define COM2_STOPBIT_SELECT		stop_1_bit


#define COM2_TFIFOINT_LEN		tet_empty_int


#define COM2_TINT_ENABLE		BSP_DISABLE


#define COMP_PARAMS_1				(0xf4)	//IP配置参数寄存器1


#define COMP_PARAMS_2				(0xf0)	//IP配置参数寄存器2


#define COMP_TYPE					(0xfc)	//IP类型


#define COMP_VERSION				(0xf8)	//IP版本


#define CONTROL_UART			1


#define CPN_ARCSEC2RAD                  (PI/180.0/3600.0)


#define CPN_POLY1(a0, a1, x)            (((a0) + (a1)*(x)) * CPN_ARCSEC2RAD)


#define CPN_POLY3(a0, a1, a2, a3, x)    (((a0) + (x) * ((a1) + (a2)*(x) + (a3)*(x)*(x))) * CPN_ARCSEC2RAD)


#define CPU_FREQ				400


#define CPU_config_done_reg 			(0x31)


#define CRI_DATA_RECV_FAIL         0xAAAAAAAA


#define CRI_DATA_RECV_FAULT        0xFFFFFFFF


#define CRI_DATA_RECV_ING          0x22222222


#define CRI_DATA_RECV_SUB_FAIL   0xAAAAAAAA


#define CRI_DATA_RECV_SUB_ING    0x00000000


#define CRI_DATA_RECV_SUB_SUCC   0x55555555


#define CRI_DATA_RECV_SUCC         0x55555555


#define CRI_DATA_RECV_TYPE1        0x00000000


#define CRI_DATA_RECV_TYPE2        0x55555555


#define CS_COUNTER_DN(pre, cur, mask, zero)         ( ((pre) >= (cur)) ? ((pre) - (cur)) : ((mask) - ((cur) - (pre)) + (zero)) )


#define CS_COUNTER_UP(pre, cur, mask, zero)         ( ((cur) >= (pre)) ? ((cur) - (pre)) : ((mask) - ((pre) - (cur)) + (zero)) )


#define CS_ICOMDIAG_H


#define CS_MEMMAINTAIN_H


#define CS_MEM_MAINTAIN_CUR_MAX_LEN32    (128)


#define CS_MEM_MAINTAIN_DOWN_MAX_LEN32   (512)


#define CS_MEM_MAINTAIN_INJ_MAX_LEN32 (240u / 4u)


#define CS_MEM_MAINTAIN_UPLOAD_MAX_LEN32 (512)


#define CS_OFFSET_reg                   (0x06)


#define CS_PWR_INTER_CHANNEL_NULL (0xFFu)


#define CS_PWR_PART_DOWN (0xAAu)


#define CS_PWR_PART_NULL (0x00u)


#define CS_PWR_PART_UP (0x55u)


#define CS_STS_LONG_TIME_INVALID_FD_HHH


#define CS_TIMING_MAX                   10


#define CS_TTE_LENTYPE_DYNAMIC (0x01u)


#define CS_TTE_LENTYPE_FIXED (0x00u)


#define CS_TTE_MINPKG_LENBYTES (0x0Bu)


#define CTRL_CYCLE_T ((float64)(0.064))


#define Ceilx(x)        (ceil((float64)(x))               )


#define Ceilx(x)        (ceil((float64)(x))               )


#define Cosx(x)         (cos((float64)(x))                )


#define Cosx(x)         (cos((float64)(x))                )


#define DATAINST_CONF_SIZE (61u)


#define DATAINST_HASH_D_MSIZE (70u)


#define DATAINST_HASH_G_MAXSIZE (67u)


#define DATA_BLK_INV_NUM                    20u


#define DATA_BLK_INV_NUM                20u


#define DATA_BLK_NUM                    16u


#define DATA_ERROR 0


#define DATA_MAXIMUM_LEN					(FRAME_MAXIMUM_LEN - TTE_ETHERNET_MAC_HEADER_LENGTH)


#define DATA_MINIMUM_LEN					(FRAME_MINIMUM_LEN - TTE_ETHERNET_MAC_HEADER_LENGTH)


#define DATA_RD			0x1


#define DBL_TO_SI16(x)                  ((siint16)(llong64)(x))


#define DBL_TO_SI16(x)                  ((unint16)((siint32)((float32)(x))))


#define DBL_TO_SI32(x)                  ((siint32)(llong64)(x))


#define DBL_TO_SI32(x)                  ((unint32)((siint32)((float32)(x))))


#define DBL_TO_SI64(x)                  ((llong64)(x))


#define DBL_TO_SI64(x)                  ((ulong64)((llong64)(x)))


#define DBL_TO_UN08(x)                  ((unint08)(llong64)(x))


#define DBL_TO_UN08(x)                  ((unint08)(x))


#define DBL_TO_UN16(x)                  ((unint16)(llong64)(x))


#define DBL_TO_UN16(x)                  ((unint16)(x))


#define DBL_TO_UN32(x)                  ((unint32)(llong64)(x))


#define DBL_TO_UN32(x)                  ((unint32)(x))


#define DBL_TO_UN64(x)                  ((ulong64)(llong64)(x))


#define DBL_TO_UN64(x)                  ((ulong64)(x))


#define DEFAULT_ADKB_All_Num				DRV_ADKB_All_Num


#define DEFAULT_DAKB_All_Num				DRV_DAKB_All_Num


#define DEFAULT_VALUE_AD_B					(0)


#define DEFAULT_VALUE_AD_K					(1000)


#define DEFAULT_VALUE_DA_B					(2047500)


#define DEFAULT_VALUE_DA_K					(204800)


#define DERR_ADDR_REG					(0x0040)		//最近发生双错的访问字地址


#define DERR_DATA_REG					(0x0044)		//最近发生双错的访问字数据


#define DERR_EDAC_REG					(0x0048)		//最近发生双错的访问字EDAC码


#define DONT_SAVE_OLD_CONTEXT		(0x02)


#define DRV_AD_CDR_ADDR         0x10


#define DRV_AD_CDR_VALUE         0x0   //SPI时钟信号延时寄存器


#define DRV_AD_CIRCLE_AGR_ADDR     0x1C


#define DRV_AD_CPR_ADDR         0x4


#define DRV_AD_CPR_VALUE        0x1       //SPI时钟相位寄存器


#define DRV_AD_ENSTART_ADDR     0x14


#define DRV_AD_FRE_ADDR         0x0


#define DRV_AD_NUM_LIMIT (4)


#define DRV_AD_READ_ADDR   0x200


#define DRV_AD_SDR_ADDR         0xc


#define DRV_AD_SDR_VALUE         0x0    //SPI选通信号延迟时间寄存器


#define DRV_AD_SHR_ADDR         0x8


#define DRV_AD_SHR_VALUE         0x1     //SPI选通信号超前时间寄存器


#define DRV_AD_SINGLENUM_ADDR   0x20


#define DRV_AD_SPI_ADDR   0x9000


#define DRV_AD_SPI_MODE (1)


#define DRV_AD_SSI_MODE (0)


#define DRV_AD_SSI_WIDTH   (200)//同步串口模式下，ad采集发送的脉冲宽度，保证一个开关打开


#define DRV_AD_SUMNUM_ADDR      0x24


#define DRV_AD_SWITCH_TIME_ADDR 0x18


#define DRV_AD_WRIDATA_ADDR0   0x28


#define DRV_AD_WRIDATA_ADDR1   0x2c


#define DRV_BITIN_IO_PULSE_WidthAdd1 (200000)


#define DRV_BITIN_IO_PULSE_WidthAdd2 (200000)


#define DRV_BIT_DIR_ADDR            (0x00) //D(15:0)对应GPIO(15:0)


#define DRV_BIT_FILWID_ADDR          (0x1c)  //滤波长度GPIO(7:0)


#define DRV_BIT_FIL_0_ADDR          (0x14)  //D(1:0):GPIO(7:0)滤波当量选择，D(3:2):GPIO(15:8)滤波当量选择，以此类推


#define DRV_BIT_FIL_1_ADDR          (0x18)  //D(1:0):GPIO(71:64)滤波当量选择，D(3:2):GPIO(79:72)滤波当量选择


#define DRV_BIT_IN_ADDR            (0x44) //位口采集GPIO(15:0)


#define DRV_BIT_OUT_ADDR            (0x188) //位口状态GPIO(15:0)


#define DRV_BIT_SELOUT_ADDR          (0x180) //D(15:0)对应GPIO(63:48)


#define DRV_BUS_BUSRDY_ADDR(i)    (0x600+0x4*(i))


#define DRV_BUS_IO_ADDR    0x400


#define DRV_BUS_NCS0_ADDR(i)    (0x20000+0x4*(i))


#define DRV_BUS_NCS1_ADDR(i)    (0x28000+0x4*(i))


#define DRV_BUS_NCS2_ADDR(i)    (0x30000+0x4*(i))


#define DRV_BUS_NCS3_ADDR(i)    (0x38000+0x4*(i))


#define DRV_Bit_In_EQU0	(TEN_US )


#define DRV_Bit_In_EQU1	(TEN_US )


#define DRV_Bit_In_EQU10	(TEN_US )


#define DRV_Bit_In_EQU11	(TEN_US )


#define DRV_Bit_In_EQU12	(TEN_US )


#define DRV_Bit_In_EQU13	(TEN_US )


#define DRV_Bit_In_EQU14	(TEN_US )


#define DRV_Bit_In_EQU15	(TEN_US )


#define DRV_Bit_In_EQU16	(TEN_US )


#define DRV_Bit_In_EQU17	(TEN_US )


#define DRV_Bit_In_EQU18	(TEN_US )


#define DRV_Bit_In_EQU19	(HUNDRED_US)


#define DRV_Bit_In_EQU2	(TEN_US )


#define DRV_Bit_In_EQU20	(HUNDRED_US)


#define DRV_Bit_In_EQU21	(HUNDRED_US)


#define DRV_Bit_In_EQU22	(HUNDRED_US)


#define DRV_Bit_In_EQU3	(TEN_US )


#define DRV_Bit_In_EQU4	(TEN_US )


#define DRV_Bit_In_EQU5	(TEN_US )


#define DRV_Bit_In_EQU6	(TEN_US )


#define DRV_Bit_In_EQU7	(TEN_US )


#define DRV_Bit_In_EQU8	(TEN_US )


#define DRV_Bit_In_EQU9	(TEN_US )


#define DRV_Bit_In_Gather0	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather1	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather10	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather11	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather12	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather13	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather14	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather15	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather16	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather17	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather18	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather19	(DRV_BITIN_IO_PULSE)


#define DRV_Bit_In_Gather2	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather20	(DRV_BITIN_IO_PULSE)


#define DRV_Bit_In_Gather21	(DRV_BITIN_IO_PULSE)


#define DRV_Bit_In_Gather22	(DRV_BITIN_IO_PULSE)


#define DRV_Bit_In_Gather3	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather4	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather5	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather6	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather7	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather8	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_Gather9	(DRV_BITIN_IO_GPIO)


#define DRV_Bit_In_IoBase0	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase1	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase10	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase11	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase12	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase13	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase14	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase15	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase16	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase17	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase18	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase19	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase2	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase20	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase21	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase22	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase3	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase4	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase5	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase6	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase7	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase8	(DRV_IO_NUM0)


#define DRV_Bit_In_IoBase9	(DRV_IO_NUM0)


#define DRV_Bit_In_NumGpio0	(0)


#define DRV_Bit_In_NumGpio1	(1)


#define DRV_Bit_In_NumGpio10	(10)


#define DRV_Bit_In_NumGpio11	(11)


#define DRV_Bit_In_NumGpio12	(12)


#define DRV_Bit_In_NumGpio13	(13)


#define DRV_Bit_In_NumGpio14	(14)


#define DRV_Bit_In_NumGpio15	(15)


#define DRV_Bit_In_NumGpio16	(16)


#define DRV_Bit_In_NumGpio17	(24)


#define DRV_Bit_In_NumGpio18	(25)


#define DRV_Bit_In_NumGpio19	(0)


#define DRV_Bit_In_NumGpio2	(2)


#define DRV_Bit_In_NumGpio20	(1)


#define DRV_Bit_In_NumGpio21	(2)


#define DRV_Bit_In_NumGpio22	(3)


#define DRV_Bit_In_NumGpio3	(3)


#define DRV_Bit_In_NumGpio4	(4)


#define DRV_Bit_In_NumGpio5	(5)


#define DRV_Bit_In_NumGpio6	(6)


#define DRV_Bit_In_NumGpio7	(7)


#define DRV_Bit_In_NumGpio8	(8)


#define DRV_Bit_In_NumGpio9	(9)


#define DRV_Bit_In_Rev0	(DRVUNREV)


#define DRV_Bit_In_Rev1	(DRVUNREV)


#define DRV_Bit_In_Rev10	(DRVUNREV)


#define DRV_Bit_In_Rev11	(DRVUNREV)


#define DRV_Bit_In_Rev12	(DRVUNREV)


#define DRV_Bit_In_Rev13	(DRVUNREV)


#define DRV_Bit_In_Rev14	(DRVUNREV)


#define DRV_Bit_In_Rev15	(DRVUNREV)


#define DRV_Bit_In_Rev16	(DRVUNREV)


#define DRV_Bit_In_Rev17	(DRVUNREV)


#define DRV_Bit_In_Rev18	(DRVUNREV)


#define DRV_Bit_In_Rev19	(DRVUNREV)


#define DRV_Bit_In_Rev2	(DRVUNREV)


#define DRV_Bit_In_Rev20	(DRVUNREV)


#define DRV_Bit_In_Rev21	(DRVUNREV)


#define DRV_Bit_In_Rev22	(DRVUNREV)


#define DRV_Bit_In_Rev3	(DRVUNREV)


#define DRV_Bit_In_Rev4	(DRVUNREV)


#define DRV_Bit_In_Rev5	(DRVUNREV)


#define DRV_Bit_In_Rev6	(DRVUNREV)


#define DRV_Bit_In_Rev7	(DRVUNREV)


#define DRV_Bit_In_Rev8	(DRVUNREV)


#define DRV_Bit_In_Rev9	(DRVUNREV)


#define DRV_Bit_In_Width0	(100)


#define DRV_Bit_In_Width1	(100)


#define DRV_Bit_In_Width10	(100)


#define DRV_Bit_In_Width11	(100)


#define DRV_Bit_In_Width12	(100)


#define DRV_Bit_In_Width13	(100)


#define DRV_Bit_In_Width14	(100)


#define DRV_Bit_In_Width15	(100)


#define DRV_Bit_In_Width16	(100)


#define DRV_Bit_In_Width17	(100)


#define DRV_Bit_In_Width18	(100)


#define DRV_Bit_In_Width19	(1200000)


#define DRV_Bit_In_Width2	(100)


#define DRV_Bit_In_Width20	(1200000)


#define DRV_Bit_In_Width21	(1200000)


#define DRV_Bit_In_Width22	(1200000)


#define DRV_Bit_In_Width3	(100)


#define DRV_Bit_In_Width4	(100)


#define DRV_Bit_In_Width5	(100)


#define DRV_Bit_In_Width6	(100)


#define DRV_Bit_In_Width7	(100)


#define DRV_Bit_In_Width8	(100)


#define DRV_Bit_In_Width9	(100)


#define DRV_Bit_Out_Gather0	(DRV_BITOUT_IO_GPIO)


#define DRV_Bit_Out_Gather1	(DRV_BITOUT_IO_GPIO)


#define DRV_Bit_Out_Gather2	(DRV_BITOUT_IO_GPIO)


#define DRV_Bit_Out_Gather3	(DRV_BITOUT_IO_GPIO)


#define DRV_Bit_Out_Gather4	(DRV_BITOUT_IO_GPIO)


#define DRV_Bit_Out_Gather5	(DRV_BITOUT_IO_GPIO)


#define DRV_Bit_Out_Init0	(DRVLOW)


#define DRV_Bit_Out_Init1	(DRVLOW)


#define DRV_Bit_Out_Init2	(DRVLOW)


#define DRV_Bit_Out_Init3	(DRVLOW)


#define DRV_Bit_Out_Init4	(DRVLOW)


#define DRV_Bit_Out_Init5	(DRVLOW)


#define DRV_Bit_Out_IoBase0	(DRV_IO_NUM0)


#define DRV_Bit_Out_IoBase1	(DRV_IO_NUM0)


#define DRV_Bit_Out_IoBase2	(DRV_IO_NUM0)


#define DRV_Bit_Out_IoBase3	(DRV_IO_NUM0)


#define DRV_Bit_Out_IoBase4	(DRV_IO_NUM0)


#define DRV_Bit_Out_IoBase5	(DRV_IO_NUM0)


#define DRV_Bit_Out_NumGpio0	(31)


#define DRV_Bit_Out_NumGpio1	(32)


#define DRV_Bit_Out_NumGpio2	(33)


#define DRV_Bit_Out_NumGpio3	(34)


#define DRV_Bit_Out_NumGpio4	(35)


#define DRV_Bit_Out_NumGpio5	(36)


#define DRV_Bit_Out_Rev0	(DRVUNREV)


#define DRV_Bit_Out_Rev1	(DRVUNREV)


#define DRV_Bit_Out_Rev2	(DRVUNREV)


#define DRV_Bit_Out_Rev3	(DRVUNREV)


#define DRV_Bit_Out_Rev4	(DRVUNREV)


#define DRV_Bit_Out_Rev5	(DRVUNREV)


#define DRV_CAN1A           (0)


#define DRV_CAN1B           (1)


#define DRV_CAN1_BASEADDRA               (0x1400)


#define DRV_CAN1_BASEADDRB               (0x1800)


#define DRV_CAN1_BASE_ADDR                (0x1C00)


#define DRV_CAN2A           (2)


#define DRV_CAN2B           (3)


#define DRV_CAN2_BASEADDRA               (0x4000)


#define DRV_CAN2_BASEADDRB               (0x4400)


#define DRV_CAN2_BASE_ADDR                (0x4800)


#define DRV_CAN_RESET_TIME   (10)


#define DRV_CONTROL_CLOCK (DRVUSED)


#define DRV_COUNT_NUM_LIMIT (18)


#define DRV_CSB_BAUD   (0xC)


#define DRV_CSB_CTRL   (0x0)


#define DRV_CSB_DATA   (0x4)


#define DRV_CSB_IOBASEA   (0x9400)


#define DRV_CSB_IOBASEB   (0x9600)


#define DRV_CSB_REV_FAIL    (0x3)//接收字节数不够一包(4字节)


#define DRV_CSB_REV_NULL    (0x1)   //发送参数无效


#define DRV_CSB_SEND_FAIL   (0x3)//发送fifo剩余字节数小于要发送的字节数


#define DRV_CSB_SEND_NULL    (0x1)   //发送参数无效


#define DRV_CSB_TMFIFO   (0x8)


#define DRV_DA_9726Clock_KB_MODE (5)


#define DRV_DA_9726_CHIP_RESET_TIME (100)


#define DRV_DA_9726_PULSE_OVER_TIME (2000)


#define DRV_DA_9726_RESET_OVER_TIME (15000)


#define DRV_DA_9762KB_MODE (4)


#define DRV_DA_9762_MODE (3)


#define DRV_DA_BUS_MODE (2)


#define DRV_DA_GPIO_MODE (1)


#define DRV_DA_LSCS_DELAY_TIME    1        //单位us，DA输出时LS和CS之间延时时间，要求最小为80ns


#define DRV_DA_SSI_DELAY_TIME (1)


#define DRV_DA_SSI_MODE (0)


#define DRV_Def_AD_SPI_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_AD_SSI_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_BIT_IN_Num	(23)	 //总路数


#define DRV_Def_BIT_IN_Type	(DRVUSED)	 //使用该方式


#define DRV_Def_BIT_OUT_Num	(6)	 //总路数


#define DRV_Def_BIT_OUT_Type	(DRVUSED)	 //使用该方式


#define DRV_Def_BUS_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_CAN_INT_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_CAN_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_CSB_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_Count_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_DA_9726_CLOCK_KB_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_DA_9762KB_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_DA_9762_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_DA_BUS_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_DA_GPIO_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_DA_RESET_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_DA_SSI_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_Eight_FRE_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_Eight_INT_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_INT_GPI_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_IO_Num	(1)	 //总路数


#define DRV_Def_IO_Type	(DRVUSED)	 //使用该方式


#define DRV_Def_Latch_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_PULSE_OUT_Num	(8)	 //总路数


#define DRV_Def_PULSE_OUT_Type	(DRVUSED)	 //使用该方式


#define DRV_Def_Power_Mode1_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_Power_Mode2_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_Power_Mode3_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_Power_Mode4_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_SPI_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_SSI_IN_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_SSI_OUT_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_Syn_Source_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_TM_INT_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_TM_Type	(DRVUNUSED)	 //不使用该方式


#define DRV_Def_Time_Num	(6)	 //总路数


#define DRV_Def_Time_Type	(DRVUSED)	 //使用该方式


#define DRV_Def_UART_Num	(6)	 //总路数


#define DRV_Def_UART_Type	(DRVUSED)	 //使用该方式


#define DRV_EIGHT_FRE_CLEARDOG_ADDR         (0x3DC)//频率采集看门狗时间寄存器


#define DRV_EIGHT_FRE_COUNT_ADDR(i)         (0x3A0+0x4*(i))//频率采集数量寄存器


#define DRV_EIGHT_FRE_DATA_ADDR(i)          (0x380+0x4*(i))//频率采集计数寄存器


#define DRV_EIGHT_FRE_DELAY_ADDR            (0x3C4)//频率采集延时寄存器


#define DRV_EIGHT_FRE_EQU_ADDR                   (0x3CC)//频率采集当量寄存器


#define DRV_EIGHT_FRE_FIL_EQU_ADDR           (0x3D0)//频率采集滤波当量寄存器


#define DRV_EIGHT_FRE_FIL_WIDTH_ADDR         (0x3D4)//频率采集滤波宽度寄存器


#define DRV_EIGHT_FRE_PERIOD_ADDR           (0x3C0)//频率采集周期寄存器


#define DRV_EIGHT_FRE_RANGE_ADDR            (0x3C8)//频率采集区间寄存器


#define DRV_EIGHT_FRE_START_ADDR                 (0x3D8)//频率采集启动寄存器


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


#define DRV_ERR_EIGHT                           (0x14 << 8)


#define DRV_ERR_EIGHT_PASS_PARAMETER_NO                       (DRV_ERR_EIGHT |  0x1)


#define DRV_ERR_EQU                            (0x15 << 8)


#define DRV_ERR_EQU_PASS_PARAMETER_ADDR                        (DRV_ERR_EQU  | 0x1)


#define DRV_ERR_INT                            (0x11<< 8)


#define DRV_ERR_INT_PASS_PARAMETER_ASICNO                         (DRV_ERR_INT  | 0x2)


#define DRV_ERR_INT_PASS_PARAMETER_INTNO                         (DRV_ERR_INT  | 0x1)


#define DRV_ERR_INT_PASS_PARAMETER_MODE                         (DRV_ERR_INT  | 0x3)


#define DRV_ERR_INT_PASS_PARAMETER_NO                         (DRV_ERR_INT  | 0x4)


#define DRV_ERR_IO                           (0x16 << 8)


#define DRV_ERR_IO_PASS_PARAMETER_ADDR                        (DRV_ERR_IO  | 0x1)


#define DRV_ERR_LATCH                      (0xC << 8)


#define DRV_ERR_LATCH_PASS_PARAMETER_NO                    (DRV_ERR_LATCH |  0x1)


#define DRV_ERR_POWER                   (0x5 << 8)


#define DRV_ERR_POWER_PASS_PARAMETER_ACTION              (DRV_ERR_POWER |  0x2)


#define DRV_ERR_POWER_PASS_PARAMETER_NO                    (DRV_ERR_POWER |  0x1)


#define DRV_ERR_PULSE                     (0xA << 8)


#define DRV_ERR_PULSE_PASS_PARAMETER_DEFEND                    (DRV_ERR_PULSE |  0x2)


#define DRV_ERR_PULSE_PASS_PARAMETER_NO                    (DRV_ERR_PULSE |  0x1)


#define DRV_ERR_PULSE_PERIOD_WIDTH                     (0x13 << 8) // add by lcl


#define DRV_ERR_SET_ERRNO(errno)         (DRVErrNo = (errno))


#define DRV_ERR_SET_ERRNO(errno)         do {DRVErrNo = (errno);  print2("\r\nDRVErrNo: 0x%x",DRVErrNo); } while(0)


#define DRV_ERR_SPI                          (0xD << 8)


#define DRV_ERR_SPI_PASS_PARAMETER_INTRECV                    (DRV_ERR_SPI |  0x2)


#define DRV_ERR_SPI_PASS_PARAMETER_NO                    (DRV_ERR_SPI |  0x1)


#define DRV_ERR_SSI                           (0xE << 8)


#define DRV_ERR_SSI_PASS_PARAMETER_INTRECV                    (DRV_ERR_SSI |  0x3)


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


#define DRV_INT_ASIC0         (0)


#define DRV_INT_ASIC1         (1)


#define DRV_INT_ASIC2         (2)


#define DRV_INT_DISABLE       (0x91D0200A)


#define DRV_INT_ENABLE         (0xEB90146F)


#define DRV_INT_ENABLE_ADDR           (0xC40) //中断使能寄存器


#define DRV_INT_MODE_ADDR            (0xD80) //中断模式寄存器


#define DRV_INT_SEL_ADDR(i)              (0xD40+0xC*(i)) //中断选择寄存器


#define DRV_INT_SSI_RECV_ADDR              (0xCC0) //同步串口中断接收个数寄存器


#define DRV_INT_STATE_ADDR               (0xC00) //中断状态寄存器


#define DRV_INT_TM_SEND_ADDR              (0xD00) //TM遥测串口中断剩余发送个数寄存器


#define DRV_INT_UART_RECV_ADDR           (0xC80) //异步串口中断接收个数寄存器


#define DRV_IO_BASE0	(0x50000000)


#define DRV_IO_FRE0	(DRV_CLK_100M)


#define DRV_IO_NUM0	 (0)	//第0个IO板


#define DRV_IO_PERIOD0	(0)


#define DRV_IO_PROTECT_ALL0	(DRVUSED)


#define DRV_LATCH_NUM_LIMIT (4)


#define DRV_PULSE_ACT_0          (0x364) //脉冲启动GPIO48-63


#define DRV_PULSE_ACT_1          (0x368) //脉冲启动GPIO64-79


#define DRV_PULSE_CIR_0         0x1c4 //脉冲是否循环GPIO(63:48)


#define DRV_PULSE_CIR_1         0x1c8//脉冲是否循环GPIO(79:64)


#define DRV_PULSE_COUNT_EDGE         0x80


#define DRV_PULSE_COUNT_SEL          0x60


#define DRV_PULSE_COUNT_SOFT         0x68


#define DRV_PULSE_COUNT_VALUE        0x84


#define DRV_PULSE_DIS         (0x294) //GPIO(48)


#define DRV_PULSE_EN_0          (0x35c) //脉冲使能GPIO48-63


#define DRV_PULSE_EN_1          (0x360) //脉冲使能GPIO64-79


#define DRV_PULSE_EQU         (0x1c0) //脉冲当量D2-0 对应GPIO(55:48);D5-3 对应GPIO(63:56);D8-6 对应GPIO(71:64);D11-9对应GPIO(79:72)


#define DRV_PULSE_LATCH_EDGE         0x58


#define DRV_PULSE_LATCH_STATUS         0x5c


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


#define DRV_Power_Mode1  (1)//方式1： 无输出使能位，单个脉冲直接控制开关


#define DRV_Power_Mode2  (2)//方式2：1位输出使能位，单个脉冲和1位使能位控制开关


#define DRV_Power_Mode3  (3)//方式3：多位输出使能位(且连续)。单个脉冲和多位使能位控制开关


#define DRV_Power_Mode4  (4)//方式4：2个脉冲控制开关


#define DRV_Pulse_EQU0	(EQU_TEN)


#define DRV_Pulse_EQU1	(EQU_TEN)


#define DRV_Pulse_EQU2	(EQU_TEN)


#define DRV_Pulse_EQU3	(EQU_TEN)


#define DRV_Pulse_EQU4	(EQU_TEN)


#define DRV_Pulse_EQU5	(EQU_TEN)


#define DRV_Pulse_EQU6	(EQU_TEN)


#define DRV_Pulse_EQU7	(EQU_TEN)


#define DRV_Pulse_IoBase0	(DRV_IO_NUM0)


#define DRV_Pulse_IoBase1	(DRV_IO_NUM0)


#define DRV_Pulse_IoBase2	(DRV_IO_NUM0)


#define DRV_Pulse_IoBase3	(DRV_IO_NUM0)


#define DRV_Pulse_IoBase4	(DRV_IO_NUM0)


#define DRV_Pulse_IoBase5	(DRV_IO_NUM0)


#define DRV_Pulse_IoBase6	(DRV_IO_NUM0)


#define DRV_Pulse_IoBase7	(DRV_IO_NUM0)


#define DRV_Pulse_NumPulse0	(48)


#define DRV_Pulse_NumPulse1	(49)


#define DRV_Pulse_NumPulse2	(50)


#define DRV_Pulse_NumPulse3	(51)


#define DRV_Pulse_NumPulse4	(52)


#define DRV_Pulse_NumPulse5	(53)


#define DRV_Pulse_NumPulse6	(54)


#define DRV_Pulse_NumPulse7	(55)


#define DRV_Pulse_Periodicity0	(DRV_PULSE_SINGLE)


#define DRV_Pulse_Periodicity1	(DRV_PULSE_SINGLE)


#define DRV_Pulse_Periodicity2	(DRV_PULSE_SINGLE)


#define DRV_Pulse_Periodicity3	(DRV_PULSE_SINGLE)


#define DRV_Pulse_Periodicity4	(DRV_PULSE_SINGLE)


#define DRV_Pulse_Periodicity5	(DRV_PULSE_SINGLE)


#define DRV_Pulse_Periodicity6	(DRV_PULSE_SINGLE)


#define DRV_Pulse_Periodicity7	(DRV_PULSE_SINGLE)


#define DRV_REGS_NUM (40)


#define DRV_SPI_BASE 0x7400


#define DRV_SPI_CFR          (0x1C)


#define DRV_SPI_DATA          (0x00)


#define DRV_SPI_ICR         (0x04)


#define DRV_SPI_ISR         (0x08)


#define DRV_SPI_RBN        (0x0C)


#define DRV_SPI_RIC          (0x14)


#define DRV_SPI_STR         (0x18)


#define DRV_SPI_TBN        (0x10)


#define DRV_SSI_BASE_ADDR        0x800


#define DRV_SSI_BAUD_ADDR(i)         (0x50+0x40*(i))


#define DRV_SSI_BAUD_ERR    (0x1)    //接收参数无效


#define DRV_SSI_CTRL_ADDR         0x8


#define DRV_SSI_IN_MODE1 (0)//ML


#define DRV_SSI_IN_MODE2 (3)//DS


#define DRV_SSI_MODE_ERR   (0x3)   //接收超时


#define DRV_SSI_OUT_MODE1 (1)//ML


#define DRV_SSI_OUT_MODE2 (2)//DS


#define DRV_SSI_USCFR_ADDR         0xC


#define DRV_SSI_USCNTR_ADDR(i)          (0x48+0x40*(i))


#define DRV_SSI_USDR_ADDR(i)          (0x4c+0x40*(i))


#define DRV_SSI_USFR_ADDR(i)          (0x44+0x40*(i))


#define DRV_SSI_USFR_ERR    (0x5)   //状态错误


#define DRV_SSI_USMR_ADDR(i)          (0x40+0x40*(i))


#define DRV_SYN_SOURCE0_FLAG_TIME_ADDR            (0x1114)//SYN_SOURCE0


#define DRV_SYN_SOURCE1_FLAG_TIME_ADDR            (0x1118) //SYN_SOURCE1


#define DRV_SYN_SOURCE2_FLAG_TIME_ADDR           (0x111c) //SYN_SOURCE2


#define DRV_SYN_SOURCE3_FLAG_TIME_ADDR            (0x1120) //SYN_SOURCE3


#define DRV_SYN_SOURCE_FLAG_ADDR                 (0x1100)


#define DRV_Star_Time_IoBase0	(DRV_IO_NUM0)


#define DRV_Star_Time_IoBase1	(DRV_IO_NUM0)


#define DRV_Star_Time_IoBase2	(DRV_IO_NUM0)


#define DRV_Star_Time_IoBase3	(DRV_IO_NUM0)


#define DRV_Star_Time_IoBase4	(DRV_IO_NUM0)


#define DRV_Star_Time_IoBase5	(DRV_IO_NUM0)


#define DRV_Star_Time_NumTime0	(0)


#define DRV_Star_Time_NumTime1	(1)


#define DRV_Star_Time_NumTime2	(2)


#define DRV_Star_Time_NumTime3	(3)


#define DRV_Star_Time_NumTime4	(4)


#define DRV_Star_Time_NumTime5	(5)


#define DRV_TIMER_SCALER   (1)


#define DRV_TIME_0         (0x1004) //内部分频产生控制周期寄存器0  D[15:0]


#define DRV_TIME_1         (0x1008)//内部分频产生控制周期寄存器1  D[19:16]


#define DRV_TIME_EDGE         (0x1140)//基准信号源选择寄存器


#define DRV_TIME_EQU         (0x1000)//星时计时当量寄存器


#define DRV_TIME_READ         (0x1148)//星时读取寄存器


#define DRV_TIME_SEL         (0x1144)//星时锁存控制寄存器


#define DRV_TM_BAUD0   (0x20)


#define DRV_TM_BAUD1   (0x24)


#define DRV_TM_CODE   (0x0)


#define DRV_TM_DATA   (0x0)


#define DRV_TM_INIT0   (0x28)


#define DRV_TM_INIT1   (0x2c)


#define DRV_TM_IOBASEA   (0x6C00)


#define DRV_TM_IOBASEB   (0x7000)


#define DRV_TM_MCODE   (0x1)


#define DRV_TM_PCM   (0xC)


#define DRV_TM_RESET   (0x4)


#define DRV_TM_SCODE   (0x2)


#define DRV_TTE_MACRO_H_


#define DRV_UART_BASE          (0x2000)


#define DRV_UART_BAUDH         (0x08)


#define DRV_UART_BAUDL         (0x04)


#define DRV_UART_CTRL          (0x1C)


#define DRV_UART_DATA          (0x00)


#define DRV_UART_FIFO_0         (1024)


#define DRV_UART_FIFO_1         (256)


#define DRV_UART_INTR          (0x14)


#define DRV_UART_INT_MODE0	(DRV_INT_EDGE_TRIG)


#define DRV_UART_INT_MODE1	(DRV_INT_EDGE_TRIG)


#define DRV_UART_INT_MODE2	(DRV_INT_EDGE_TRIG)


#define DRV_UART_INT_MODE3	(DRV_INT_EDGE_TRIG)


#define DRV_UART_INT_MODE4	(DRV_INT_EDGE_TRIG)


#define DRV_UART_INT_MODE5	(DRV_INT_EDGE_TRIG)


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


#define DRV_Uart_IntFlag0	(DRV_INT_DISABLE)


#define DRV_Uart_IntFlag1	(DRV_INT_DISABLE)


#define DRV_Uart_IntFlag2	(DRV_INT_DISABLE)


#define DRV_Uart_IntFlag3	(DRV_INT_DISABLE)


#define DRV_Uart_IntFlag4	(DRV_INT_DISABLE)


#define DRV_Uart_IntFlag5	(DRV_INT_DISABLE)


#define DRV_Uart_IoBase0	(DRV_IO_NUM0)


#define DRV_Uart_IoBase1	(DRV_IO_NUM0)


#define DRV_Uart_IoBase2	(DRV_IO_NUM0)


#define DRV_Uart_IoBase3	(DRV_IO_NUM0)


#define DRV_Uart_IoBase4	(DRV_IO_NUM0)


#define DRV_Uart_IoBase5	(DRV_IO_NUM0)


#define DRV_Uart_Mux0	(8)


#define DRV_Uart_Mux1	(8)


#define DRV_Uart_Mux2	(8)


#define DRV_Uart_Mux3	(8)


#define DRV_Uart_Mux4	(8)


#define DRV_Uart_Mux5	(8)


#define DRV_Uart_NumUart0	(0)


#define DRV_Uart_NumUart1	(1)


#define DRV_Uart_NumUart2	(2)


#define DRV_Uart_NumUart3	(3)


#define DRV_Uart_NumUart4	(4)


#define DRV_Uart_NumUart5	(5)


#define DRV_WIDTH_PERIOD_ERROR (0xffffffff)


#define Data_Shift(data,bit)			(((data)>>(bit))&0x1)


#define ECSS_DBLK_DESP_BCNT(wrd) (UI32_BIT_GET8((wrd), 0u))


#define ECSS_DBLK_DESP_LEN08(wrd) (UI32_BIT_GET12((wrd), 16u))


#define ECSS_DBLK_DESP_MODE(wrd) (UI32_BIT_GET1((wrd), 13u))


#define ECSS_DBLK_DESP_RESET(wrd) (UI32_BIT_GET1((wrd), 14u))


#define EDAC_CONFIG_REG					(0x000C)		//EDAC操作配置


#define EDAC_CTL					(0xc0)	//EDAC控制寄存器


#define EDAC_ERROR 1


#define EMEM_NOT_SUPPORT					(0)


#define EMIF_INT_CLEAR_REG				(0x001C)		//清中断状态寄存器


#define EMIF_MULTI_ERR_INT				(0x1<<11)	//emif_twobits_err


#define ENHANCE_RECV_EN						(0x02)


#define ENHANCE_TX_START					(0x01)


#define EQUAL(a, b, c, d) ((a) == (b) ? (c) : (d))


#define EQU_FIFTY  (0x2)          //50 us


#define EQU_HUNDRED (0x3)      //100 us


#define EQU_ONE  (0x0)           // 1us


#define EQU_TEN  (0x1)               //10 us


#define ERROR					(-1)


#define EVENT_INJ_ADDR_ERR     (0x1D)


#define EVENT_INJ_CNT_ERR      (0x1E)


#define EVENT_INJ_ID_ERR       (0x1C)


#define EVENT_TCEXE_ADDR_ERR   (0x11)


#define EVENT_TCEXE_ALIGN_ERR  (0x12)


#define EVENT_TCEXE_DWLEN_ERR  (0x1B)


#define EVENT_TCEXE_EXIT_FAIL  (0x1F)


#define EVENT_TCEXE_LEN_ERR    (0x13)


#define EVENT_TCEXE_OPING_ERR  (0x1A)


#define EVENT_TCEXE_OPLEN_ERR  (0x15)


#define EVENT_TCEXE_TYPE_ERR   (0x19)


#define EVENT_TCEXE_WRITE_SUCC (0x10)


#define EVENT_TC_SUCC          (0)


#define Expx(x)         (exp((float64)(x))                )


#define Expx(x)         (exp((float64)(x))                )


#define FALSE					(0)


#define FALSE32             0x00000000u


#define FALSE32             0x00000000u


#define FALSE32     0x00u


#define FILLVALUE						(0xffffffff)


#define FIQ_MODE_STACK_SIZE				(8*1024)


#define FIQ_MODE_STACK_TOP			((MEM_INT_STK_BASE - IRQ_MODE_STACK_SIZE) & 0xfffffff0)


#define FIRSTWORKMODE ABSUI_TO_VADDR32(CCU_RAM_BASE + 0x00118200u)


#define FLASH256


#define FLASH256
#endif


#define FLI_OFFSET		(6)


#define FLOAT32_MAX         FLT_MAX


#define FLOAT32_MIN         FLT_MIN


#define FLOAT64_MAX         DBL_MAX


#define FLOAT64_MIN         DBL_MIN


#define FLOW_CTR		0x40


#define FLT32_TO_MEM(fptr)          (*((volatile unint32 *)(fptr)))


#define FLT32_TO_MEM(fptr)          (*((volatile unint32 *)(fptr)))


#define FLT64_TO_MEM(fptr)          (*((volatile ulong64 *)(fptr)))


#define FLT64_TO_MEM(fptr)          (*((volatile ulong64 *)(fptr)))


#define FLT_TO_SI08(x)                  ((siint08)(llong64)(x))


#define FLT_TO_SI08(x)                  ((unint08)((unint32)((siint32)(x)))


#define FLT_TO_SI16(x)                  ((siint16)(llong64)(x))


#define FLT_TO_SI16(x)                  ((unint16)((unint32)((siint32)(x)))


#define FLT_TO_SI32(x)                  ((siint32)(llong64)(x))


#define FLT_TO_SI32(x)                  ((unint32)((siint32)(x)))


#define FLT_TO_UN08(x)                  ((unint08)(llong64)(x))


#define FLT_TO_UN08(x)                  ((unint08)(x))


#define FLT_TO_UN16(x)                  ((unint16)(llong64)(x))


#define FLT_TO_UN16(x)                  ((unint16)(x))


#define FLT_TO_UN32(x)                  ((unint32)(llong64)(x))


#define FLT_TO_UN32(x)                  ((unint32)(x))


#define FPU_MASK				(0x87)


#define FRAME_ER		0x40


#define FRAME_MAXIMUM_LEN					(1514)			// 最大的帧长度


#define FRAME_MINIMUM_LEN					(60)			// 最小的帧长度


#define FREE_BLOCK	(0x1)


#define F_SyncState_reg					(0x62)


#define Fabsx(x)        (fabs((float64)(x))               )


#define Fabsx(x)        (fabs((float64)(x))               )


#define Fixx(x)         ((siint32)(x)                     )


#define Floorx(x)       (floor((float64)(x))              )


#define Floorx(x)       (floor((float64)(x))              )


#define GCS_EXTPERIOD_INT_IONUM					(0)


#define GCS_EXTPERIOD_INT_NO					(BSP_GPIO_6_IRQID)


#define GET_NEXT_BLOCK(_addr, _r)	((BHDR *) ((I8 *) (_addr) + (_r)))


#define GFH_ACC_TRACK_HHH


#define GFH_ATTACQ_H


#define GFH_ATT_MNV_PLAN_BASED_TIME_HHH


#define GFH_BAPCAPTRACE_H


#define GFH_CPN_CALC_H


#define GFH_ESTIMATEQ_H


#define GFH_EULERESTIMATE_H


#define GFH_GAMACALC_H


#define GFH_GRAVITYGRADIENTTORQUE_H


#define GFH_GYRODIAGBYWQS_H


#define GFH_GYROEQUATION_H


#define GFH_JETFAULTDIAG_H


#define GFH_MIXED_TRACK_H


#define GFH_MW_KEEP_HHH


#define GFH_ORBITLUNARPOS_H


#define GFH_ORBIT_CALCULATE_BASED_INTEGRAL_H


#define GFH_PARTSINTRACK_H


#define GFH_SGCMGCTRL_H


#define GFH_SINTRACK_H


#define GFH_STRUCTFILTER_H


#define GFH_STRUCT_HHH


#define GFH_STSGYROMODIFY_H


#define GFH_STSMODIFY_H


#define GFH_STSONBOARDCALBT_H


#define GFH_SUNEPHEMERISCALC_H


#define GFH_SUNPOINTATT_CALC_H


#define GFH_THROUTPUTFILTER_H


#define GFH_ZEROMOMENTUMCALC_H


#define GFS_1553B0_AVAILABLE					(0)


#define GFS_1553B1_AVAILABLE					(0)


#define GFS_A6017DEFEND_AVAILABLE				(1)


#define GFS_AB_MACHINE_SWITCH_FLAG				(1)


#define GFS_APP_CONTROLPERIOD_AVAILABLE			(0)


#define GFS_APP_TIMESILCE_AVAILABLE				(0)


#define GFS_AUTO_EN_SEUINT_ENABLE				(1)


#define GFS_CRT0_FORBID							(0)


#define GFS_DATA_CACHE_AVAILABLE				(0)


#define GFS_EEPROM_AVAILABLE					(0)


#define GFS_EMIF_SRAM_AVAILABLE					(0)


#define GFS_EMIF_SRAM_AVAILABLE					(1)


#define GFS_EXT_PERIOD_ENABLE					(0)


#define GFS_EXT_PERIOD_NEED_SET					(1)


#define GFS_FPGA_RESET_DELAY_MS					(0)


#define GFS_IDLETASK_SEU_ENABLE_SWITCH			(0)


#define GFS_INTR_CACHE_AVAILABLE				(0)


#define GFS_MACHINE_WORK_MODE					(0x2A)


#define GFS_MEMOPTEXECUTE_POSITION				(1)


#define GFS_MEMREFRESH_POSITION					(0)	//note 放在IdleTask中


#define GFS_NAND_FLASH_AVAILABLE				(0)


#define GFS_NOR_FLASH8BIT_AVAILABLE				(1)


#define GFS_NOR_FLASH_AVAILABLE					(0)


#define GFS_OBC_AUTOCMD_REFRESH					(0)


#define GFS_OBC_AUTOCMD_REFRESH					(1)


#define GFS_PARAMCFG_ENABLE						(0)


#define GFS_REBOOT_PROGLOAD_ENABLE				(1)


#define GFS_REFRESHPERIOD_DAY					(365)


#define GFS_SDRAM_AVAILABLE						(0)


#define GFS_SDRAM_AVAILABLE						(1)


#define GFS_SPW2_AVAILABLE						(0)


#define GFS_SPW3_AVAILABLE						(0)


#define GFS_TIME_SLICE_EXTRA					(1)


#define GLOBAL_TIMER_NO			(0x1)


#define GPI0Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI0Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI0_CFG					GPI_OUT


#define GPI0_DATA					GPI_LOW


#define GPI0_IntEn					BSP_DISABLE


#define GPI10Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI10Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI10_CFG					GPI_OUT


#define GPI10_DATA					GPI_LOW


#define GPI10_IntEn					BSP_DISABLE


#define GPI11Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI11Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI11_CFG					GPI_OUT


#define GPI11_DATA					GPI_HIGH


#define GPI11_IntEn					BSP_DISABLE


#define GPI12Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI12Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI12_CFG					GPI_IN


#define GPI12_DATA					GPI_LOW


#define GPI12_IntEn					BSP_DISABLE


#define GPI13Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI13Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI13_CFG					GPI_IN


#define GPI13_DATA					GPI_LOW


#define GPI13_IntEn					BSP_DISABLE


#define GPI14Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI14Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI14_CFG					GPI_IN


#define GPI14_DATA					GPI_LOW


#define GPI14_IntEn					BSP_DISABLE


#define GPI15Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI15Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI15_CFG					GPI_IN


#define GPI15_DATA					GPI_LOW


#define GPI15_IntEn					BSP_DISABLE


#define GPI1Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI1Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI1_CFG					GPI_IN


#define GPI1_DATA					GPI_LOW


#define GPI1_IntEn					BSP_DISABLE


#define GPI2Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI2Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI2_CFG					GPI_IN


#define GPI2_DATA					GPI_LOW


#define GPI2_IntEn					BSP_DISABLE


#define GPI3Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI3Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI3_CFG					GPI_IN


#define GPI3_DATA					GPI_LOW


#define GPI3_IntEn					BSP_DISABLE


#define GPI4Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI4Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI4_CFG					GPI_IN


#define GPI4_DATA					GPI_LOW


#define GPI4_IntEn					BSP_ENABLE


#define GPI5Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI5Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI5_CFG					GPI_IN


#define GPI5_DATA					GPI_LOW


#define GPI5_IntEn					BSP_ENABLE


#define GPI6Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI6Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI6_CFG					GPI_IN


#define GPI6_DATA					GPI_LOW


#define GPI6_IntEn					BSP_ENABLE


#define GPI7Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI7Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI7_CFG					GPI_IN


#define GPI7_DATA					GPI_LOW


#define GPI7_IntEn					BSP_ENABLE


#define GPI8Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI8Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI8_CFG					GPI_OUT


#define GPI8_DATA					GPI_LOW


#define GPI8_IntEn					BSP_DISABLE


#define GPI9Int_TRIG_MODE			INT_PULSE_TRIG


#define GPI9Int_TRIG_POLARITY		INT_HIGH_TRIG


#define GPI9_CFG					GPI_OUT


#define GPI9_DATA					GPI_LOW


#define GPI9_IntEn					BSP_DISABLE


#define GPIO_AGAINST_SHAKE_REG					(0x48)


#define GPIO_DATA_REG							(0x00)


#define GPIO_DIRECT_REG							(0x04)


#define GPIO_INT_ENABLE_REG						(0x30)


#define GPIO_INT_LEVEL_REG						(0x38)


#define GPIO_INT_MASK_REG						(0x34)


#define GPIO_INT_POLARITY_REG					(0x3c)


#define GPIO_INT_STATUS_REG						(0x40)


#define GPIO_LS_SYNC							(0x60)


#define GPIO_MODE_REG							(0x08)


#define GPIO_NUM   (32) //GPIO 路数80-48, 无需修改


#define GPIO_PORTA_EOI_REG						(0x4c)


#define GPIO_PORT_REG							(0x50)


#define GPS_MWFAULTJUDGE_H


#define GPS_PSEUDORATEMODULATOR_H


#define GROUPS_STS_K_CORR (NUM_SCOMPART_STGR + NUM_SCOMPART_STGR * (NUM_SCOMPART_STGR - 1u) / 2u)


#define HUNDRED_US   (0x3)   // 100 us


#define HW_RT_ADDR (24)		//RT地址


#define IACU_A_LOG_ADDR (0x35u)


#define IACU_B_LOG_ADDR (0x54u)


#define IACU_C_LOG_ADDR (0x75u)


#define ICDISER2	( 	(IRQ_DMA_SEU_EN<<15)|\
						(IRQ_SRAM_SEU_EN<<16)|\
						(IRQ_EMIF_SEU_EN<<17)|\
						(IRQ_EMIF_WR2ORE_EN<<18)|\
						(IRQ_EMIF_IORDYTO_EN<<19)|\
						(IRQ_SPW2_TxSEU_EN<<24)|\
						(IRQ_SPW2_RxSEU_EN<<25)|\
						(IRQ_SPW3_TxSEU_EN<<26)|\
						(IRQ_SPW3_RxSEU_EN<<27)|\
						(IRQ_SDRAM_SEU_EN<<28)|\
						(IRQ_1553B0_SEU_EN<<29)|\
						(IRQ_1553B1_SEU_EN<<30) )


#define IDLE_TASK_ID					SYSTASKNUM


#define IFG_frame_time_reg       		(0x26)


#define INTEGRATE_CYCLE_DURATION  		(0x0F)


#define INTEGRATION_CYCLE_CONFIG_reg    (0x08)


#define INTStackBlockBegin		(MEM_INT_STK_LOWBASE)


#define INTStackBlockSize		(MEM_INT_STK_SIZE)


#define INT_HIGH_TRIG						0x01


#define INT_LEVEL_TRIG						0x00


#define INT_LOW_TRIG						0x00


#define INT_PULSE_TRIG						0x01


#define INT_STA_IS_BULK_REOP				(0x40)


#define INVALID								(0xdeadbeef)


#define IN_RANGE_CLOSE(val, lo, up)     (((lo) <= (val)) && ((val) <= (up)))


#define IN_RANGE_CLOSE(val, lo, up)     (((lo) <= (val)) && ((val) <= (up)))


#define IN_RANGE_LCUO(val, lo, up)      (((lo) <= (val)) && ((val) < (up)))


#define IN_RANGE_LCUO(val, lo, up)      (((lo) <= (val)) && ((val) < (up)))


#define IN_RANGE_LOUC(val, lo, up)      (((lo) < (val)) && ((val) <= (up)))


#define IN_RANGE_LOUC(val, lo, up)      (((lo) < (val)) && ((val) <= (up)))


#define IN_RANGE_OPEN(val, lo, up)      (((lo) < (val)) && ((val) < (up)))


#define IN_RANGE_OPEN(val, lo, up)      (((lo) < (val)) && ((val) < (up)))


#define IN_WDT_RESET						(0x3)


#define IO_6017_EN_NUM (2) //6017使能寄存器的个数，无需修改


#define IO_CONFIG_REG					(0x0008)		//IO空间配置


#define IO_RDY_TIMEOUT_REG				(0x0018)		//IO空间使用Ready信号时，等待Ready信号到来的超时时间设置


#define IO_WS_CFG_REG					(0x0028)		//IO空间等待时序配置


#define IRQ_1553B0_SEU_EN				SEU_DISABLE


#define IRQ_1553B0_SEU_EN				SEU_ENABLE


#define IRQ_1553B1_SEU_EN				SEU_DISABLE


#define IRQ_1553B1_SEU_EN				SEU_ENABLE


#define IRQ_DMA_SEU_EN					SEU_DISABLE


#define IRQ_DMA_SEU_EN					SEU_ENABLE


#define IRQ_EMIF_IORDYTO_EN				SEU_DISABLE


#define IRQ_EMIF_IORDYTO_EN				SEU_ENABLE


#define IRQ_EMIF_SEU_EN					SEU_ENABLE


#define IRQ_EMIF_WR2ORE_EN				SEU_DISABLE


#define IRQ_EMIF_WR2ORE_EN				SEU_ENABLE


#define IRQ_MODE_STACK_SIZE				(20*1024)


#define IRQ_MODE_STACK_TOP			(MEM_INT_STK_BASE & 0xfffffff0)


#define IRQ_SDRAM_SEU_EN				SEU_DISABLE


#define IRQ_SDRAM_SEU_EN				SEU_ENABLE


#define IRQ_SPW2_RxSEU_EN				SEU_DISABLE


#define IRQ_SPW2_RxSEU_EN				SEU_ENABLE


#define IRQ_SPW2_TxSEU_EN				SEU_DISABLE


#define IRQ_SPW2_TxSEU_EN				SEU_ENABLE


#define IRQ_SPW3_RxSEU_EN				SEU_DISABLE


#define IRQ_SPW3_RxSEU_EN				SEU_ENABLE


#define IRQ_SPW3_TxSEU_EN				SEU_DISABLE


#define IRQ_SPW3_TxSEU_EN				SEU_ENABLE


#define IRQ_SRAM_SEU_EN					SEU_ENABLE


#define ISR_INT_NEST_SP				(0x00)


#define ISR_INT_NOT_NEST_SP			(0x01)


#define ISR_STACK_REST_PAR			(0x06)


#define JFM29GL256			(1)	//JFM29GL256芯片，32M大小


#define JFM29GL641			(3)	//JFM29GL641芯片，4M大小


#define LESS_COMMON_ERR						(0x2)


#define LIMIT_RANGE_FLT(val, lo, up)    (((float64)(val) < (float64)(lo)) ? (float64)(lo) : (((float64)(val) > (float64)(up)) ? (float64)(up) : (float64)(val)))


#define LIMIT_RANGE_INT(val, lo, up)    (((siint32)(val) < (siint32)(lo)) ? (siint32)(lo) : (((siint32)(val) > (siint32)(up)) ? (siint32)(up) : (siint32)(val)))


#define LIST_HEAD(name)     struct list_head name = LIST_HEAD_INIT(name)


#define LIST_HEAD_INIT(name) { &(name), &(name) }


#define LLONG64_MAX     0


#define LLONG64_MAX     LLONG_MAX


#define LLONG64_MAX     LONG_MAX


#define LLONG64_MIN     0


#define LLONG64_MIN     LLONG_MIN


#define LLONG64_MIN     LONG_MIN


#define LOOKUP_DEFAULT                  0x260u


#define LOOKUP_SANUM_MAX                64u


#define LOOKUP_SANUM_MAX                96u


#define LOOP_BCK		0x80


#define LSTORE_LOG_ADDR (0x44u)


#define LV_PWR_WAIT_CYCLE (0x5u)


#define Log10x(x)       (log10((float64)(x))              )


#define Log10x(x)       (log10((float64)(x))              )


#define Logx(x)         (log((float64)(x))                )


#define Logx(x)         (log((float64)(x))                )


#define MAC_BE_select_reg				(0x2B)


#define MAC_port_select_reg       		(0x25)


#define MAC_rcv_select_reg        		(0x29)


#define MASK64_40BIT                0x000000FFFFFFFFFFu


#define MASK64_48BIT                0x0000FFFFFFFFFFFFu


#define MASK64_56BIT                0x00FFFFFFFFFFFFFFu


#define MASK64_64BIT                0xFFFFFFFFFFFFFFFFu


#define MASK_08BIT            0x00000000000000FFu


#define MASK_16BIT            0x000000000000FFFFu


#define MASK_24BIT            0x0000000000FFFFFFu


#define MASK_32BIT            0x00000000FFFFFFFFu


#define MASK_40BIT            0x000000FFFFFFFFFFu


#define MASK_48BIT            0x0000FFFFFFFFFFFFu


#define MASK_56BIT            0x00FFFFFFFFFFFFFFu


#define MASK_64BIT            0xFFFFFFFFFFFFFFFFu


#define MASK_ALL8F                      0xFFFFFFFFu


#define MASK_ALL8F                  0xFFFFFFFFu


#define MASK_HI16                       0xFFFF0000u


#define MASK_HI16                   0xFFFF0000u


#define MASK_LO04                       0x0000000Fu


#define MASK_LO04                   0x0000000Fu


#define MASK_LO08                       0x000000FFu


#define MASK_LO08                   0x000000FFu


#define MASK_LO16                       0x0000FFFFu


#define MASK_LO16                   0x0000FFFFu


#define MASK_LO24                   0x00FFFFFFu


#define MATHLIB


#define MAX(a, b)                       ((a) > (b) ? (a): (b))


#define MAX_FLI			(30)


#define MAX_LOG2_SLI	(5)


#define MAX_SLI			(1 << MAX_LOG2_SLI)


#define MAX_TRANSMISSION_DELAY_reg_HIGH (0x01)


#define MAX_TRANSMISSION_DELAY_reg_LOW  (0x02)


#define MDIO_reg						(0x3F)


#define MEMBERSHIP_reg					(0x00)


#define MEMFRESHING				(0x0)


#define MEMFRESHOVER			(0x1)


#define MEM_ALIGN					((BLOCK_ALIGN) - 1)


#define MEM_APP_DATA_USED_BASEADDR		(BSP_EMIF_RAM_BASE_ADDR)		// 正样EMIF_SRAM


#define MEM_APP_DATA_USED_BASEADDR		(BSP_RAM_BASE_ADDR+0x98000)	// 模样片内SRAM


#define MEM_APP_DATA_USED_BASEADDR		(BSP_SDRAM_DATA_BASE_ADDR)		// 初样SDRAM


#define MEM_APP_DATA_USED_SIZE			(1024*1024)


#define MEM_APP_DATA_USED_SIZE			(512*1024)


#define MEM_APP_PROG_USED_BASEADDR		(BSP_RAM_BASE_ADDR+0x18000)


#define MEM_APP_PROG_USED_SIZE			(1024*1024)


#define MEM_APP_PROG_USED_SIZE			(512*1024)


#define MEM_BOOT_USED_BASEADDR			(BSP_RAM_BASE_ADDR)


#define MEM_BOOT_USED_SIZE				(96*1024)


#define MEM_EMIFSRAM_BIT		(1)


#define MEM_INDEX_NULL                   (0xFFFF)


#define MEM_INT_STK_BASE				(MEM_INT_STK_LOWBASE + MEM_INT_STK_SIZE - 8)


#define MEM_INT_STK_LOWBASE				(MEM_SYS_STK_LOWBASE + MEM_SYS_STK_SIZE + MEM_ISOLATION_SIZE)


#define MEM_INT_STK_SIZE				(IRQ_MODE_STACK_SIZE + FIQ_MODE_STACK_SIZE)


#define MEM_ISOLATION_SIZE				(512)


#define MEM_NAND_DATA_POSITION				1


#define MEM_NAND_DATA_SIZE					(1536*1024)


#define MEM_NOR8_MAP_TYPE					0x3201


#define MEM_OS_USED_BASEADDR			(MEM_INT_STK_LOWBASE + MEM_INT_STK_SIZE+MEM_ISOLATION_SIZE)


#define MEM_OS_USED_SIZE				(256*1024)


#define MEM_SDRAM_BIT			(2)


#define MEM_SRAM_BIT			(0)


#define MEM_SYS_STK_BASE				(MEM_SYS_STK_LOWBASE + MEM_SYS_STK_SIZE - 8)


#define MEM_SYS_STK_LOWBASE				(MEM_TRI32_USED_BASEADDR + MEM_TRI32_USED_SIZE)


#define MEM_SYS_STK_SIZE				(SVC_MODE_STACK_SIZE + SYS_MODE_STACK_SIZE + UND_MODE_STACK_SIZE + ABT_MODE_STACK_SIZE + MON_MODE_STACK_SIZE)


#define MEM_TO_FLT32(uptr)          (*((volatile float32 *)(uptr)))


#define MEM_TO_FLT32(uptr)          (*((volatile float32 *)(uptr)))


#define MEM_TO_FLT64(ulptr)         (*((volatile float64 *)(ulptr)))


#define MEM_TO_FLT64(ulptr)         (*((volatile float64 *)(ulptr)))


#define MEM_TRAP_INFO_RECORD_BASE		(MEM_OS_USED_BASEADDR + MEM_OS_USED_SIZE + MEM_ISOLATION_SIZE)


#define MEM_TRAP_INFO_RECORD_SIZE		(16*1024)


#define MEM_TRI32_USED_BASEADDR			(BSP_RAM_BASE_ADDR+0x118000+MEM_ISOLATION_SIZE)


#define MEM_TRI32_USED_SIZE				(40*1024+MEM_ISOLATION_SIZE)


#define MGKEY								(0x36303137)


#define MIN(a, b)                       ((a) < (b) ? (a): (b))


#define MIN_BLOCK_SIZE	(0x8)


#define MODE_COLD_AUTO			(0x2A)


#define MODE_COLD_NONE			(0x2B)


#define MODE_QUADRA_			(0x4)


#define MODE_SINGLE				(0x1)


#define MODE_TRIPLE_HOT			(0x3)


#define MON_MODE_STACK_SIZE				(8*1024)


#define MON_MODE_STACK_TOP			((ABT_MODE_STACK_TOP - ABT_MODE_STACK_SIZE) & 0xfffffff0)


#define MULERRADDR						(0xA00E0000	)


#define NELEMENTS(array)		(sizeof (array)/ sizeof ((array)[0]))


#define NONEXT (0u)


#define NOR_FLASH_SECTOR_SIZE (128*1024)


#define NOR_FLASH_TOTAL_SIZE				(2*1024*1024)

#define NOR_FLASH_TOTAL_SIZE				(32*1024*1024)

#define NOR_FLASH_TOTAL_SIZE				(4*1024*1024)

#define NOWAIT (0u)


#define NO_WAIT				(0)


#define NPRIO								(64)


#define NULL 					(0)


#define NULL            (0x00u)


#define NULL_STATEMENT() \
    do                   \
    {                    \
    } while (0)


#define NULL_STATEMENT() __asm("nop")


#define NUM_ACAM (5u)


#define NUM_ACCGR (3u)


#define NUM_ASSGR (3u)


#define NUM_CMGGR (8u)


#define NUM_COMPART (3u)


#define NUM_CSR_OH_ACQ (2u)


#define NUM_CSR_OH_TARGET (2u)


#define NUM_ET (6u)


#define NUM_FACTION	8


#define NUM_FIT_COEF (14u)


#define NUM_FSEL (7u)


#define NUM_GYRGR (12u)


#define NUM_INJ_MAX            (51)


#define NUM_JET_CYCLE (32u)


#define NUM_JET_WIN (80u)


#define NUM_MNVTAB (4u)


#define NUM_P2PType (6u)


#define NUM_RMSGR (4u)


#define NUM_RWGR (12u)


#define NUM_SADAGR (4u)


#define NUM_SCOMPART_CMGGR (4u)


#define NUM_SCOMPART_DSSGR (1u)


#define NUM_SCOMPART_GYRGR (4u)


#define NUM_SCOMPART_STGR (3u)


#define NUM_SCOM_ACC_AXISGR (4u)


#define NUM_SF (1u)


#define NUM_STGR (9u)


#define NUM_STGRAD (6u)


#define NUM_STGRDELAY (16u)


#define NUM_THRGR (20u)


#define NUM_THRGR_OC (1u)


#define NUM_TPAM (4u)


#define NUM_WKMD (13u)


#define NUM_W_FILTER (16u)


#define NUM_ZMC_CMG (5u)


#define Nfs (20u)


#define NorFlash_DataEdacInSameSectorAddr	(0x8180000)


#define NorFlash_DataEdacInSameSectorAddr	(0x8320000)


#define NorFlash_DataEdacInSameSectorAddr	(0x9980000)


#define NorFlash_DataMaxAddr				(0x8199998)


#define NorFlash_DataMaxAddr				(0x8333330)


#define NorFlash_DataMaxAddr				(0x9999994)


#define NorFlash_DeviceID					(0x7E)


#define NorFlash_DeviceID					(0xC4)


#define NorFlash_DeviceID					(0xD7)


#define NorFlash_EraseMinWtimeS				(6)


#define NorFlash_PhysicalSectorSize			(0x08000)


#define NorFlash_PhysicalSectorSize			(0x10000)


#define NorFlash_PhysicalSectorSize			(0x20000)


#define NorFlash_SectorNum_Allbit			(0xFFF80000)


#define NorFlash_SectorNum_Allbit			(0xFFFE0000)


#define NorFlash_SectorNum_Allbit			(0xFFFc0000)


#define NorFlash_SectorSize					(0x20000)


#define NorFlash_SectorSize					(0x40000)


#define NorFlash_SectorSize					(0x80000)


#define NorFlash_SectorSize_AddrBit_Num		(17)


#define NorFlash_SectorSize_AddrBit_Num		(18)


#define NorFlash_SectorSize_AddrBit_Num		(19)


#define NorFlash_SectorSize_bit				(0x1FFFF)


#define NorFlash_SectorSize_bit				(0x3FFFF)


#define NorFlash_SectorSize_bit				(0x7FFFF)


#define NorFlash_WriteMinWtimeUs			(200)


#define NorflashType		(AM29LV160D)


#define NorflashType		(JFM29GL256)


#define NorflashType		(JFM29GL641)


#define OC_JET_PWR_BACK_DOWN (0x55u)


#define OC_JET_PWR_MAIN_DOWN (0xAAu)


#define OK						(0)


#define OMU_1_LOG_ADDR (0x28u)


#define OMU_2_LOG_ADDR (0x48u)


#define OMU_3_LOG_ADDR (0x64u)


#define OMU_PWR_WAIT_CYCLE (0x5u)


#define ONEBIT_ERR_ADDR				(0xc4)	//单错地址寄存器


#define ONEBIT_ERR_DATA				(0xc8)	//单错数据寄存器


#define ONEBIT_ERR_EDAC				(0xcc)	//单错校验码寄存器


#define ONE_US   (0x1)   // 1 us


#define ORMEM_CONFIG_REG				(0x0004)		//ROM空间配置


#define OR_WS_CFG_REG					(0x0024)		//ROM空间等待时序配置


#define OSERROR				(-1)


#define OSFALSE				(0)


#define OSINTCLR_INIT BSP_INTR_CLR


#define OSIntLock			IntLock


#define OSIntUnlock			IntUnlock


#define OSMECBASE 0x80000000


#define OSNULL				(0)


#define OSOK				(0)


#define OSTRUE				(1)


#define OS_CPU_INT_CNT					BSP_CPU_INT_CNT

#define OS_ERR_PRIOSET_ID_NULL				(OS_ERR_INTERNAL_LIB  | ( 0x2<<8) | 0x1)


#define OS_ERR_RDYSTAT_YET					(OS_ERR_INTERNAL_LIB  | ( 0x1<<8) | 0x4)


#define OS_ERR_TASKDELETE_CALL_IN_LOCK		(OS_ERR_TASK_LIB | ( 0x1<<8) | 0x5)


#define OS_IDLE_PRIO						(63)


#define OS_IDLE_TASK_STACKSIZE			(0x4000)


#define OS_INTSTK_SIZE					MEM_INT_STK_SIZE


#define OS_INT_STK_HIGHBASE						(MEM_INT_STK_BASE + OS_INTSTK_SIZE - 8)


#define OS_INT_STK_LOWBASE						(MEM_INT_STK_BASE)


#define OS_INVALID_ID		(0)


#define OS_IRQ_TICK_PRIORITY			(BSP_HIGHEST_PRIORITY+1)


#define OS_MEM_CHK_ID		(4)


#define OS_MEM_POOL_ADDR						(MEM_OS_USED_BASEADDR)


#define OS_MEM_POOL_SIZE				MEM_OS_USED_SIZE

#define OS_MQ_CHK_ID		(3)


#define OS_PERIODIC_INT		(-1)


#define OS_SEM_CHK_ID		(2)


#define OS_SINGLE_INT		(0)


#define OS_SLICE_NO						BSP_TimeSlice_No

#define OS_SYSIDLETASK_NAME					(0x1001)


#define OS_SYS_TRAP			BSP_SYS_TRAP


#define OS_TASKINFOREC_SIZE				(0)


#define OS_TASK_CHK_ID		(1)


#define OS_TASK_DEFAULT_OPTION				(0x0)


#define OS_TASK_DEFAULT_STACKSIZE			(0x400)


#define OS_TASK_DELAY						(0x02)


#define OS_TASK_DELETED						(0x0f)


#define OS_TASK_INFO_REC_HIGHBASE				(0)


#define OS_TASK_INFO_REC_LOWBASE				(0)


#define OS_TASK_PEND						(0x04)


#define OS_TASK_READY						(0x01)


#define OS_TASK_RR_TICKS				(1)


#define OS_TASK_RUN							(0x10)


#define OS_TASK_STACK_FILL_DATA				(0x0)


#define OS_TASK_STACK_FILL_DATA_SIZE		(400)


#define OS_TASK_STACK_INIT_ALL


#define OS_TASK_SUSPEND						(0x08)


#define OS_TIME_TICKS					(1000/OS_TIME_TICKS_PER_SEC)


#define OS_TIME_TICKS_PER_SEC			(500)


#define OUT_WDT_RESET						(0x2)


#define OVERRUN			0x10


#define PACK_BIT(b, x, y) (((x) == (y)) ? BIT(b) : (0))


#define PART_PWR_WAIT_CYCLE (0x3u)


#define PART_RESV (0xFFu)


#define PAR_EN			0x20


#define PAR_ER			0x20


#define PAR_SEL			0x10


#define PCF_TRANSPARENT_CLOCK_ES01_reg_HIGH		(0x90)


#define PCF_TRANSPARENT_CLOCK_ES01_reg_LOW      (0x91)


#define PCF_TRANSPARENT_CLOCK_ES02_reg_HIGH		(0x92)


#define PCF_TRANSPARENT_CLOCK_ES02_reg_LOW      (0x93)


#define PCF_TRANSPARENT_CLOCK_ES03_reg_HIGH     (0x94)


#define PCF_TRANSPARENT_CLOCK_ES03_reg_LOW      (0x95)


#define PCF_TRANSPARENT_CLOCK_SW01_reg      	(0xC0)


#define PCF_TRANSPARENT_CLOCK_SW02_reg      	(0xC1)


#define PCF_TRANSPARENT_CLOCK_SW03_reg      	(0xC2)


#define PCF_TRANSPARENT_CLOCK_SW04_reg      	(0xC3)


#define PCF_TRANSPARENT_CLOCK_SW05_reg      	(0xC4)


#define PCF_TRANSPARENT_CLOCK_SW06_reg      	(0xC5)


#define PCF_TRANSPARENT_CLOCK_SW07_reg      	(0xC6)


#define PCF_TRANSPARENT_CLOCK_SW08_reg      	(0xC7)


#define PCF_TRANSPARENT_CLOCK_SW09_reg      	(0xC8)


#define PCF_TRANSPARENT_CLOCK_SW10_reg      	(0xC9)


#define PORT_ERR_ADDR						(0xfff)


#define PORT_ERR_FLAG						(3<<14)


#define PORT_SEU_FLAG						(1<<14)


#define PORT_TBE_FLAG						(1<<15)


#define POWER_OFF							(0x0)


#define PREAMBLE_reg_HIGH               (0x16)


#define PREAMBLE_reg_LOW                (0x15)


#define PRECISION_reg					(0x50)


#define PREV_FREE	(0x2)


#define PREV_STATE	(0x2)


#define PREV_USED	(0x0)


#define PRE_READ_TIME             		(0x28)


#define PRIVATE_TIMER_NO		(0x0)


#define PTR_MASK		(3)


#define PWRCMD_HASH_G_MAXSIZE (233u)


#define PWR_GROUP_IACUA_ID (0x0u)


#define PWR_GROUP_IACUB_ID (0x1u)


#define PWR_GROUP_IACUC_ID (0x2u)


#define PWR_GROUP_NUM (5u)


#define PWR_GROUP_OMU_ID (0x4u)


#define PWR_GROUP_PUSHF_ID (0x3u)


#define PWR_QUEUE_MLEN (120u)


#define PoolBlockBegin			(MEM_OS_USED_BASEADDR)


#define PoolBlockSize			(MEM_OS_USED_SIZE)


#define Powx(x, y)      (pow((float64)(x), (float64)(y))  )


#define Powx(x, y)      (pow((float64)(x), (float64)(y))  )


#define QFirstNode(qhead)		((qhead)->Head)


#define QInsertHead(qhead, qnode)	do	 			\
			{											\
				QInsert((qhead), (Q_NODE *)OSNULL, (qnode));	\
			}while(0)


#define QInsertTail(qhead, qnode)	do				\
	 		{											\
				QInsert((qhead), (qhead)->Tail, (qnode));	\
			}while(0)


#define QLastNode(qhead)		((qhead)->Tail)


#define QNextNode(qnode)		((qnode)->Next)


#define QPrevNode(qnode)		((qnode)->Prev)


#define RAMA_ERR							(0x1)


#define RAMBUFFADDR 0x40180000


#define RAMB_ERR							(0x2)


#define RAM_BLOCK_NUM	(sizeof(RamBlocks)/sizeof(MemBlock))


#define RAM_DOUBLE_AND_SINGLE_ERR				(0x03)


#define RAM_DOUBLE_ERR							(0x02)


#define RAM_NO_ERR								(0x00)


#define RAM_SEU_ERR							(0x0) // 单错


#define RAM_SINGLE_ERR							(0x01)


#define RAM_TBE_ERR							(0x1) // 双错


#define RCV_PCF_PROCESS_DELAY_ES01_reg		 	(0x96)


#define RCV_PCF_PROCESS_DELAY_ES02_reg		 	(0x97)


#define RCV_PCF_PROCESS_DELAY_ES03_reg		 	(0x98)


#define RCV_PCF_PROCESS_DELAY_SW01_reg			(0xCC)


#define RCV_PCF_PROCESS_DELAY_SW02_reg			(0xCD)


#define RCV_PCF_PROCESS_DELAY_SW03_reg			(0xCE)


#define RCV_PCF_PROCESS_DELAY_SW04_reg			(0xCF)


#define RCV_PCF_PROCESS_DELAY_SW05_reg			(0xD0)


#define RCV_PCF_PROCESS_DELAY_SW06_reg			(0xD1)


#define RCV_PCF_PROCESS_DELAY_SW07_reg			(0xD2)


#define RCV_PCF_PROCESS_DELAY_SW08_reg			(0xD3)


#define RCV_PCF_PROCESS_DELAY_SW09_reg			(0xD4)


#define RCV_PCF_PROCESS_DELAY_SW10_reg			(0xD5)


#define RCV_PCF_PROCESS_DELAY_reg		(0x14)


#define RD_DATA_BYPASS				(0xe4)	//EDAC读旁路数据寄存器


#define RD_EDAC_ADDR_BYPASS			(0xdc)	//EDAC读旁路地址寄存器


#define RD_EDAC_BYPASS				(0xe0)	//EDAC读旁路校验码寄存器


#define READ_TIME_OUT			  		(0x30)


#define READ_U16(buf08)        (UI16_MAKE(((unint08 *)(buf08))[0], ((unint08 *)(buf08))[1]))


#define READ_U24(buf08) \
    (UI32_MAKE16(((unint08 *)(buf08))[0], READ_U16(((unint08 *)(buf08) + 1))))


#define READ_U32(buf08) \
    (UI32_MAKE16(READ_U16(((unint08 *)(buf08))), READ_U16(((unint08 *)(buf08) + 2))))


#define READ_U48(buf08) \
    (UI64_MAKE32(READ_U16((unint08 *)(buf08)), READ_U32((unint08 *)(buf08) + 2)))


#define READ_U64(buf08) \
    (UI64_MAKE32(READ_U32((unint08 *)(buf08)), READ_U32((unint08 *)(buf08) + 4)))


#define READ_U8(buf08)         (((unint08 *)(buf08))[0])


#define REAL(i)     	(U32)(*((V_U32*)(&i)))


#define REAL64(i)     	(U64)(*((V_U64*)(&i)))


#define REAL_FLI		(MAX_FLI - FLI_OFFSET)


#define REG_BC_CTW_D00_RT2RT_FORMAT         0x0001


#define REG_BC_CTW_D01_BRD_FORMAT           0x0002


#define REG_BC_CTW_D02_MODE_FORMAT          0x0004


#define REG_BC_CTW_D03_1553AB_SELE          0x0008


#define REG_BC_CTW_D04_EOMINT_EN            0x0010


#define REG_BC_CTW_D05_BRDCAST_MASK         0x0020


#define REG_BC_CTW_D06_OFF_TEST             0x0040


#define REG_BC_CTW_D07_CHNL_AB              0x0080


#define REG_BC_CTW_D08_RETRY_EN             0x0100


#define REG_BC_CTW_D09_REVDFLG_MASK         0x0200


#define REG_BC_CTW_D10_TERFLG_MASK          0x0400


#define REG_BC_CTW_D11_SUBFLG_MASK          0x0800


#define REG_BC_CTW_D12_SUBBUSY_MASK         0x1000


#define REG_BC_CTW_D13_SERACQ_MASK          0x2000


#define REG_BC_CTW_D14_MSGERR_MASK          0x4000


#define REG_BC_CTW_D15_RESERVED             0x8000


#define REG_CFG1_D00_BC_MSG_IN_PROG         0x0001


#define REG_CFG1_D00_MT_MSG_IN_PRO          0x0001


#define REG_CFG1_D00_RT_MSG_IN_PRO          0x0001


#define REG_CFG1_D00_RT_MSG_IN_PRO          0x0001u


#define REG_CFG1_D01_BC_FRAME_IN_PROG       0x0002


#define REG_CFG1_D01_MT_MONI_TRIG           0x0002


#define REG_CFG1_D01_RT_NOT_USED            0x0002


#define REG_CFG1_D01_RT_NOT_USED            0x0002u


#define REG_CFG1_D02_BC_ENABLED             0x0004


#define REG_CFG1_D02_MT_MONI_EN_R           0x0004


#define REG_CFG1_D02_RT_NOT_USED            0x0004


#define REG_CFG1_D02_RT_NOT_USED            0x0004u


#define REG_CFG1_D03_BC_DBL_RETRY           0x0008


#define REG_CFG1_D03_MT_NOT_USED            0x0008


#define REG_CFG1_D03_RT_NOT_USED            0x0008


#define REG_CFG1_D03_RT_NOT_USED            0x0008u


#define REG_CFG1_D04_BC_RETRY_EN            0x0010


#define REG_CFG1_D04_MT_NOT_USED            0x0010


#define REG_CFG1_D04_RT_NOT_USED            0x0010


#define REG_CFG1_D04_RT_NOT_USED            0x0010u


#define REG_CFG1_D05_BC_MSG_GAPTIMER        0x0020


#define REG_CFG1_D05_MT_NOT_USED            0x0020


#define REG_CFG1_D05_RT_MSG_GAPTIMER        0x0020


#define REG_CFG1_D05_RT_MSG_GAPTIMER        0x0020u


#define REG_CFG1_D06_BC_INTL_TRIGGER        0x0040


#define REG_CFG1_D06_MT_NOT_USED            0x0040


#define REG_CFG1_D06_RT_INTL_TRIGGER        0x0040


#define REG_CFG1_D06_RT_INTL_TRIGGER        0x0040u


#define REG_CFG1_D07_BC_EXTL_TRIGGER        0x0080


#define REG_CFG1_D07_MT_EX_TRIG_EN          0x0080


#define REG_CFG1_D07_RT_NOT_RTFLAG          0x0080


#define REG_CFG1_D07_RT_NOT_RTFLAG          0x0080u


#define REG_CFG1_D08_BC_FRAME_AUTO          0x0100


#define REG_CFG1_D08_MT_NOT_USED            0x0100


#define REG_CFG1_D08_RT_NOT_SUBSYS_FLAG     0x0100


#define REG_CFG1_D08_RT_NOT_SUBSYS_FLAG     0x0100u


#define REG_CFG1_D09_BC_ST_SET_STOF         0x0200


#define REG_CFG1_D09_MT_STOP_ON_TRIG        0x0200


#define REG_CFG1_D09_RT_NOT_SERVICE_REQ     0x0200


#define REG_CFG1_D09_RT_NOT_SERVICE_REQ     0x0200u


#define REG_CFG1_D10_BC_ST_SET_STOM         0x0400


#define REG_CFG1_D10_MT_START_ON_TRIG       0x0400


#define REG_CFG1_D10_RT_NOT_BUSY            0x0400


#define REG_CFG1_D10_RT_NOT_BUSY            0x0400u


#define REG_CFG1_D11_BC_FRAME_STOP_ERR      0x0800


#define REG_CFG1_D11_MT_TRIG_EN             0x0800


#define REG_CFG1_D11_RT_NOT_DYN_BUS         0x0800


#define REG_CFG1_D11_RT_NOT_DYN_BUS         0x0800u


#define REG_CFG1_D12_BC_MSG_STOP_ERR        0x1000


#define REG_CFG1_D12_MT_MSG_MONI_EN         0x1000


#define REG_CFG1_D12_RT_MSG_MONI_EN         0x1000


#define REG_CFG1_D12_RT_MSG_MONI_EN         0x1000u


#define REG_CFG1_D13_BC_AREA_B_SELECT       0x2000


#define REG_CFG1_D13_MT_AREA_B_SELECT       0x2000


#define REG_CFG1_D13_RT_AREA_B_SELECT       0x2000


#define REG_CFG1_D13_RT_AREA_B_SELECT       0x2000u


#define REG_CFG1_D14_BC_MT_SELECT           0x4000


#define REG_CFG1_D14_MT_MT_SELECT           0x4000


#define REG_CFG1_D14_RT_MT_SELECT           0x4000


#define REG_CFG1_D14_RT_MT_SELECT           0x4000u


#define REG_CFG1_D15_BC_RT_SELECT           0x8000


#define REG_CFG1_D15_MT_RT_SELECT           0x8000


#define REG_CFG1_D15_RT_RT_SELECT           0x8000


#define REG_CFG1_D15_RT_RT_SELECT           0x8000u


#define REG_CFG2_D00_SEP_BCST_DATA          0x0001


#define REG_CFG2_D01_EHD_RT_MEMM            0x0002


#define REG_CFG2_D02_CLEAR_SR               0x0004


#define REG_CFG2_D03_LEVEL_INT              0x0008


#define REG_CFG2_D04_INT_AUTO_CLEAR         0x0010


#define REG_CFG2_D05_LOAD_TTAG_SYN          0x0020


#define REG_CFG2_D06_CLEAR_TTAG_SYN         0x0040


#define REG_CFG2_D07_TTAG_R0                0x0080


#define REG_CFG2_D08_TTAG_R1                0x0100


#define REG_CFG2_D09_TTAG_R2                0x0200


#define REG_CFG2_D10_256_DISBL              0x0400


#define REG_CFG2_D11_INVALID_DATA           0x0800


#define REG_CFG2_D12_DBL_BUF_EN             0x1000


#define REG_CFG2_D13_BUSY_LUT_EN            0x2000


#define REG_CFG2_D14_RAM_PTY_EN             0x4000


#define REG_CFG2_D15_EHD_INT                0x8000


#define REG_CFG3_D00_RT_EHD_HDL             0x0001


#define REG_CFG3_D01_1553A_EN               0x0002


#define REG_CFG3_D02_RT_FFW_EN              0x0004


#define REG_CFG3_D03_BUSY_TRAN_EN           0x0008


#define REG_CFG3_D04_ILL_TRAN_DIS           0x0010


#define REG_CFG3_D05_RT_ALT_ST_EN           0x0020


#define REG_CFG3_D06_RT_OVERRIDE_T_ERR      0x0040


#define REG_CFG3_D07_RT_ILL_DIS             0x0080


#define REG_CFG3_D08_MT_DATSTK_SIZE_0       0x0100


#define REG_CFG3_D09_MT_DATSTK_SIZE_1       0x0200


#define REG_CFG3_D10_MT_DATSTK_SIZE_2       0x0400


#define REG_CFG3_D11_MT_CMDSTK_SIZE_0       0x0800


#define REG_CFG3_D12_MT_CMDSTK_SIZE_1       0x1000


#define REG_CFG3_D13_BCRT_CMDSTK_SIZE0      0x2000


#define REG_CFG3_D14_BCRT_CMDSTK_SIZE1      0x4000


#define REG_CFG3_D15_ENHANCED_EN            0x8000


#define REG_CFG4_D00_TM0                    0x0001


#define REG_CFG4_D01_TM1                    0x0002


#define REG_CFG4_D02_TM2                    0x0004


#define REG_CFG4_D03_RTADDR_CFG5            0x0008


#define REG_CFG4_D04_MT_TAG_OPTION          0x0010


#define REG_CFG4_D05_VALID_BUSY_BIT         0x0020


#define REG_CFG4_D06_VALID_MSG_ERR          0x0040


#define REG_CFG4_D07_SEC_RETRY_ALT          0x0080


#define REG_CFG4_D08_FST_RETRY_ALT          0x0100


#define REG_CFG4_D09_RETRY_ST_SET           0x0200


#define REG_CFG4_D10_RETRY_MSG_ERR          0x0400


#define REG_CFG4_D11_BC_BCST_MK_EN          0x0800


#define REG_CFG4_D12_BC_EXPD_CW_EN          0x1000


#define REG_CFG4_D13_RT_MODE_OV_BUSY        0x2000


#define REG_CFG4_D14_RT_INBW_BUSY           0x4000


#define REG_CFG4_D15_RT_EXBW_EN             0x8000


#define REG_CFG5_D00_RT_ADDRPTY_R           0x0001


#define REG_CFG5_D01_RT_A0_R                0x0002


#define REG_CFG5_D02_RT_A1_R                0x0004


#define REG_CFG5_D03_RT_A2_R                0x0008


#define REG_CFG5_D04_RT_A3_R                0x0010


#define REG_CFG5_D05_RT_A4_R                0x0020


#define REG_CFG5_D06_RT_A_LATCH             0x0040


#define REG_CFG5_D07_BCST_DIS               0x0080


#define REG_CFG5_D08_GAP_CHK_EN             0x0100


#define REG_CFG5_D09_RTIME_SELE0            0x0200


#define REG_CFG5_D10_RTIME_SELE1            0x0400


#define REG_CFG5_D11_EXPD_CROSS_EN          0x0800


#define REG_CFG5_D12_EXT_TX_B               0x1000


#define REG_CFG5_D13_EXT_TX_A               0x2000


#define REG_CFG5_D14_SNGL_SELT              0x4000


#define REG_CFG5_D15_12M_SELT               0x8000


#define REG_INTMK_D00_EOM                   0x0001


#define REG_INTMK_D01_BC_ST_SET             0x0002


#define REG_INTMK_D01_MT_TRIGGER            0x0002


#define REG_INTMK_D01_RT_MD_CODE            0x0002


#define REG_INTMK_D02_FORMAT_ERR            0x0004


#define REG_INTMK_D03_BC_EOF                0x0008


#define REG_INTMK_D04_BC_MSG_EOM            0x0010


#define REG_INTMK_D04_RT_CTRL_EOM           0x0010


#define REG_INTMK_D05_RT_CIRC_ROLL          0x0020


#define REG_INTMK_D06_TIME_TAG_ERR          0x0040


#define REG_INTMK_D07_RT_ADDR_PERR          0x0080


#define REG_INTMK_D08_BC_RETRY              0x0100


#define REG_INTMK_D09_HDSHAKE_FAIL          0x0200


#define REG_INTMK_D10_MT_DATA_ROLL          0x0400


#define REG_INTMK_D11_MT_CMD_ROLL           0x0800


#define REG_INTMK_D12_CMD_ROLL              0x1000


#define REG_INTMK_D13_TX_TOUT               0x2000


#define REG_INTMK_D14_RAM_PERR              0x4000


#define REG_INTMK_D15_RSERVED               0x8000


#define REG_INT_ST_D00_EOM                  0x0001


#define REG_INT_ST_D01_BC_STATUS            0x0002


#define REG_INT_ST_D01_MT_TRIGGER           0x0002


#define REG_INT_ST_D01_RT_MODE              0x0002


#define REG_INT_ST_D02_FMAT_ERR             0x0004


#define REG_INT_ST_D03_BC_EOF               0x0008


#define REG_INT_ST_D04_RT_CTRL_EOM          0x0010


#define REG_INT_ST_D05_RT_BUF_ROLL          0x0020


#define REG_INT_ST_D06_TIME_TAG_ERR         0x0040


#define REG_INT_ST_D07_RT_ADDR_ERR          0x0080


#define REG_INT_ST_D08_BC_RETRY             0x0100


#define REG_INT_ST_D09_HDSHAKE              0x0200


#define REG_INT_ST_D10_MT_DATA_ROLL         0x0400


#define REG_INT_ST_D11_MTCMD_ROLL           0x0800


#define REG_INT_ST_D12_CMD_ROLL             0x1000


#define REG_INT_ST_D13_TRAN_TOUT            0x2000


#define REG_INT_ST_D14_RAM_ERR              0x4000


#define REG_INT_ST_D15_MASTER               0x8000


#define REG_RT_SACW_D00_BCST_MM0            0x0001


#define REG_RT_SACW_D01_BCST_MM1            0x0002


#define REG_RT_SACW_D02_BCST_MM2            0x0004


#define REG_RT_SACW_D03_BCST_CIRC_BUF_INT   0x0008


#define REG_RT_SACW_D04_BCST_EOM_INT        0x0010


#define REG_RT_SACW_D05_RX_MM0              0x0020


#define REG_RT_SACW_D06_RX_MM1              0x0040


#define REG_RT_SACW_D07_RX_MM2              0x0080


#define REG_RT_SACW_D08_RX_CIRC_BUF_INT     0x0100


#define REG_RT_SACW_D09_RX_EOM_INT          0x0200


#define REG_RT_SACW_D10_TX_MM0              0x0400


#define REG_RT_SACW_D11_TX_MM1              0x0800


#define REG_RT_SACW_D12_TX_MM2              0x1000


#define REG_RT_SACW_D13_TX_CIRC_BUF_INT     0x2000


#define REG_RT_SACW_D14_TX_EOM_INT          0x4000


#define REG_RT_SACW_D15_RX_DBUF_EN          0x8000


#define REG_START_D00_RESET                 0x0001


#define REG_START_D01_BC_START              0x0002


#define REG_START_D01_MT_START              0x0002


#define REG_START_D02_INT_RESET             0x0004


#define REG_START_D03_TTAG_RESET            0x0008


#define REG_START_D04_TTAG_CLOCK            0x0010


#define REG_START_D05_BC_STOF               0x0020


#define REG_START_D06_BC_STOM               0x0040


#define REG_START_D06_MT_STOM               0x0040


#define REG_START_D15_D07_RESERVED          0x0000


#define REV_EN			0x1


#define REV_INT_EN		0x4


#define ROUNDDOWN_SIZE(_r)			((_r) & (U32)(~MEM_ALIGN))


#define ROUNDUP(_x, _v)				((((U32)(~(_x)) + 1) & ((_v)-1)) + (_x))


#define ROUNDUP_SIZE(_r)			(((_r) + MEM_ALIGN) &(U32)(~MEM_ALIGN))


#define ROUND_DOWN(x, align)	((U32)(x) & (U32)(~((align) - 1)))


#define ROUND_UP(x, align)		(((U32) (x) + ((align) - 1)) & (U32)(~((align) - 1)))


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


#define RT_DEBUG_ENABLE             0


#define RT_INSTANCE_MAX             1


#define RT_INTERRUPT_IF1_ENABLE     0


#define RT_INTERRUPT_IF2_ENABLE     0


#define RT_INTERRUPT_STACK_POLL         3u


#define RT_MEM_BUSY_TABBASE             0x0240


#define RT_MEM_CMDSTACK_PTR             (sRtStatus.stackPtr)


#define RT_MEM_CMDSTACK_PTR(instNo)     (sRtStatus[(instNo)].stackPtr)


#define RT_MEM_CMDSTACK_PTR_A           0x0100


#define RT_MEM_CMDSTACK_PTR_B           0x0104


#define RT_MEM_CMD_ILL_TABBASE          0x0300


#define RT_MEM_LOOKUP_TABBASE_A         0x0140


#define RT_MEM_LOOKUP_TABBASE_B         0x01C0


#define RT_MEM_MODE_CODE_DATA           0x0110


#define RT_MEM_MODE_CODE_INTTAB         0x0108


#define RT_MEM_SATAB_BCST(i)            (sRtStatus.areaSelFixSt + 0x40 + (i))


#define RT_MEM_SATAB_BCST(instNo, i)    (sRtStatus[(instNo)].areaSelLookup + 0x40 + (i))


#define RT_MEM_SATAB_CTRLW(i)           (sRtStatus.areaSelFixSt + 0x60 + (i))


#define RT_MEM_SATAB_CTRLW(instNo, i)   (sRtStatus[(instNo)].areaSelLookup + 0x60 + (i))


#define RT_MEM_SATAB_RECV(i)            (sRtStatus.areaSelFixSt + 0x00 + (i))


#define RT_MEM_SATAB_RECV(instNo, i)    (sRtStatus[(instNo)].areaSelLookup + 0x00 + (i))


#define RT_MEM_SATAB_TRANS(i)           (sRtStatus.areaSelFixSt + 0x20 + (i))


#define RT_MEM_SATAB_TRANS(instNo, i)   (sRtStatus[(instNo)].areaSelLookup + 0x20 + (i))


#define RT_MSGBLOCK_VALID(blkStatus)       (((blkStatus) & (RT_BSTW_D12_ERRFLG | RT_BSTW_D06_ILLCMD)) == 0x0)


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


#define RX_BLOCKING_ENABLE_INT_BIT (0x1000u)


#define RX_BULK_REOP_ENABLE_INT_BIT			(0x100)


#define RX_FIFO_EMPTY_BIT				(0x02)


#define RX_FIFO_ERROR_BITS					(0x0f)


#define RX_FIFO_NOT_EMPTY				(0x00)


#define RX_FIFO_NOT_REOP				(0x00)


#define RX_FIFO_REOP_BIT				(0x20)


#define RX_FIFO_REOP_DISABLE_INT_MASK	(0xffffff7f)


#define RX_FIFO_REOP_ENABLE_INT_BIT		(0x80)


#define RX_PKT128_BASE					(0xFFF)


#define RX_PKT1_BASE					(0x110)


#define RX_PKT2_BASE					(0x210)


#define RX_PKT3_BASE					(0x310)


#define RX_PKT4_BASE					(0x410)


#define RX_PKT5_BASE					(0x610)


#define RX_PKT6_BASE					(0xFFF)


#define RX_PKT7_BASE					(0xFFF)


#define RX_STACK_REOP_ENABLE_INT_BIT		(0x200)


#define RX_TX_BULK_MODE				(0x05)


#define RX_TX_EMEM_MODE				(0x35)


#define RX_TX_FIFO_MODE				(0x00)


#define RX_TX_STACK_MODE			(0x0F)


#define Roundx(x)       (((x)>0) ? Floorx((x)+0.5) : Ceilx((x)-0.5))


#define Roundx(x)       (round((float64)(x))              )


#define SADA_CMD_RESET (0xEB91u)


#define SADA_CMD_SADA_CONTROL (0xEB90u)


#define SADA_MODE_ANGLE_HOLD (0x04u)


#define SADA_MODE_EMERGENCY_RETURN (0x05u)


#define SADA_MODE_FORWARD_ROTATE (0x02u)


#define SADA_MODE_HOLD (0x01u)


#define SADA_MODE_REVERSE_ROTATE (0x03u)


#define SADA_MODE_STANDBY (0x00u)


#define SCONR	 					(0x0)	//SDRAM配置寄存器


#define SCSLR0_LOW	 				(0x14)	//片选0地址寄存器


#define SCTLR	 					(0xc)	//SDRAM控制寄存器


#define SDRAM_EDAC_AHBERR_EN	(BSP_ENABLE)


#define SDRAM_EDAC_EN			(BSP_ENABLE)


#define SDRAM_INIT_FILL_SIZE				(128*1024*1024)


#define SDRAM_INIT_FILL_StartAdd			(BSP_SDRAM_DATA_BASE_ADDR+SDRAM_INIT_LOADER_FILLED_SIZE)


#define SDRAM_INIT_LOADER_FILLED_SIZE		(0x00000)


#define SDRAM_SCONR 			(0x001C3388)


#define SDRAM_SCTLR				(0x3288)


#define SDRAM_SIZE				(128 * 1024 * 1024)


#define SDRAM_SREFR				(0x13D)


#define SDRAM_STMG0R 			(0x2261495)


#define SDRAM_STMG1R 			(0x70008)


#define SDRAM_TWO_BITS_ERR_INT			(0x1)		//sdram_twobits_err


#define SECONDWORKMODE ABSUI_TO_VADDR32(CCU_RAM_BASE + 0x0011B800u)


#define SECTORSIZE  128*1024


#define SECTORSIZE  32*1024


#define SECTORSIZE  64*1024


#define SELF_CMDCNT (2u)


#define SET_BITS(addr, mask, val)			\
	{										\
		U32 temp_reg_val = BSP_Get((addr));	\
		temp_reg_val &= ~(mask);			\
		temp_reg_val |= (val) & (mask);		\
		BSP_Set((addr), temp_reg_val);		\
	}


#define SEU_DISABLE							(0x0)


#define SEU_ENABLE							(0x1)


#define SEU_ERR								(0x1)


#define SI08_TO_DBL(x)                  ((float64)((siint08)(x)))


#define SI08_TO_DBL(x)                  ((float64)((siint08)(x)))


#define SI16_TO_DBL(x)                  ((float64)((siint16)(x)))


#define SI16_TO_DBL(x)                  ((float64)((siint16)(x)))


#define SI16_TO_FLT(x)                  ((float32)((siint16)(x)))


#define SI16_TO_FLT(x)                  ((float32)((siint16)(x)))


#define SI32_TO_DBL(x)                  ((float64)((siint32)(x)))


#define SI32_TO_DBL(x)                  ((float64)((siint32)(x)))


#define SI32_TO_FLT(x)                  ((float32)((siint32)(x)))


#define SI32_TO_FLT(x)                  ((float32)((siint32)(x)))


#define SIINT08_MAX         SCHAR_MAX


#define SIINT08_MIN         SCHAR_MIN


#define SIINT16_MAX         SHRT_MAX


#define SIINT16_MIN         SHRT_MIN


#define SIINT32_MAX         INT_MAX


#define SIINT32_MIN         INT_MIN


#define SINGLEBITERROR 1


#define SIZEOF(v)                       ((unint32)sizeof(v))


#define SIZEOF(v)                       ((unint32)sizeof(v))


#define SMALL_BLOCK		(128)


#define SMC_CLOCK_CORR_PIT_reg          (0x0D)


#define SMSKR0						(0x54)	//片选0地址掩码寄存器


#define SM_COLDSTART_TIMT_reg           (0x04)


#define SM_LISTEN_TIME_OUT_reg          (0x03)


#define SM_RESTART_TIMT_reg             (0x05)


#define SM_SCH_REC_PIT_reg              (0x0B)


#define SM_SC_SEL_reg					(0x7B)


#define SM_SYNC_EVAL_PIT_reg            (0x0E)


#define SOFT_APP_RESET						(0xeb90146f)


#define SOFT_RESET							(0x1)

#define SOFT_SYS_RESET						(0xeb9090eb)


#define SPEED_SEL_reg					(0x7C)


#define SPW0_RX_RAM_BASE			(0x2a004000)


#define SPW0_TX_RAM_BASE			(0x2a000000)


#define SPW1_RX_RAM_BASE			(0x2b004000)


#define SPW1_TX_RAM_BASE			(0x2b000000)


#define SPW2_BASE 						(0xA0070000)


#define SPW2_ERR							(0x1)


#define SPW2_RAMA_ERR					(0x4)	//spw2_twobits_err


#define SPW2_RX_MEM_BASE 				(0x2c004000)


#define SPW2_RX_RAM_BASE			(0x2c004000)


#define SPW2_RX_TWO_BITS_ERR_INT		(0x10)


#define SPW2_RX_TWO_BITS_ERR_INT	(0x1<<4)


#define SPW2_TX_MEM_BASE 				(0x2c000000)


#define SPW2_TX_RAM_BASE			(0x2c000000)


#define SPW2_TX_TWO_BITS_ERR_INT		(0x08)


#define SPW2_TX_TWO_BITS_ERR_INT	(0x1<<3)


#define SPW3_BASE						(0xA0080000)


#define SPW3_ERR							(0x2)


#define SPW3_RAMA_ERR					(0x8)	//spw3_twobits_err


#define SPW3_RX_MEM_BASE 				(0x2d004000)


#define SPW3_RX_RAM_BASE			(0x2d004000)


#define SPW3_RX_TWO_BITS_ERR_INT		(0x04)


#define SPW3_RX_TWO_BITS_ERR_INT	(0x1<<2)


#define SPW3_TX_MEM_BASE 				(0x2d000000)


#define SPW3_TX_RAM_BASE			(0x2d000000)


#define SPW3_TX_TWO_BITS_ERR_INT		(0x02)


#define SPW3_TX_TWO_BITS_ERR_INT	(0x1<<1)


#define SPW_BULK_EOP_TYPE_ADDR				(0x3C)


#define SPW_BULK_RX_BASE_ADDR				(0x34)


#define SPW_BULK_RX_CNT_ADDR				(0x1C)


#define SPW_BULK_RX_END_ADDR				(0x38)


#define SPW_BULK_RX_PACK_STA_ADDR			(0x20)


#define SPW_BULK_TX_PACKET_CFG_ADDR			(0x18)


#define SPW_CLR_INT_STATUS			(0x01)


#define SPW_CLR_ISR_STATUS_ADDR				(0x1C)


#define SPW_CODEC_ADDR						(0x14)


#define SPW_CONNECT_BIT				(0x06)


#define SPW_CTRL_ADDR						(0x04)


#define SPW_DISCONNECT_BIT			(0x01)


#define SPW_DISCONNECT_ERR					(0x1)


#define SPW_EMEM_RX_BASE_ADDR				(0x88)


#define SPW_EMEM_RX_BUF_BYTE_LEN (1024u * 8u)


#define SPW_EMEM_RX_END_ADDR				(0x8C)


#define SPW_EMEM_TX_BASE_ADDR				(0x80)


#define SPW_EMEM_TX_BUF_BYTE_LEN (1024u * 8u)


#define SPW_EMEM_TX_CNT_ADDR				(0x84)


#define SPW_ENHANCE_CTRL_ADDR				(0x10)


#define SPW_ERR_HEAD						(0xfffffff0)


#define SPW_ESC_ERR							(0x4)


#define SPW_FIFO_TX_EOP_ADDR				(0x14)


#define SPW_FIFO_TX_OVER_ERR				(0x0)


#define SPW_INQUIRE					(0x00)


#define SPW_INT						(0x01)


#define SPW_INT_STA_ADDR					(0x24)


#define SPW_MEM_GAP						(0x1000)


#define SPW_MODE_ADDR						(0x0C)


#define SPW_MODE_BULK				(0x02)


#define SPW_MODE_EMEM				(0x04)


#define SPW_MODE_FIFO				(0x01)


#define SPW_MODE_STACK				(0x03)


#define SPW_NUM						(4)


#define SPW_NUM_0					(0x00)


#define SPW_NUM_1					(0x01)


#define SPW_NUM_2					(0x02)


#define SPW_NUM_3					(0x03)


#define SPW_OTHER_ERR					(0x3)


#define SPW_PARITY_ERR						(0x2)


#define SPW_REG_0					(0xa0050000)


#define SPW_REG_1					(0xa0060000)


#define SPW_REG_2					(0xa0070000)


#define SPW_REG_3					(0xa0080000)


#define SPW_RFIFO_ADDR						(0x00)


#define SPW_RXRAM_A_ADDR					(0x40)


#define SPW_RXRAM_A_ADDR				(0x40)


#define SPW_RXRAM_B_ADDR					(0x44)


#define SPW_RXRAM_B_ADDR				(0x44)


#define SPW_RXRAM_EDAC_ERR_CLR_ADDR			(0x44)


#define SPW_RXRAM_EDAC_ERR_CLR_ADDR		(0x44)


#define SPW_RX_CREDIT_ERR					(0x8)


#define SPW_RX_ERR							(0x0)


#define SPW_RX_ERR						(0x0)


#define SPW_RX_NO_ERR						(0x0)


#define SPW_RX_TIMEOUT_HOLD_ADDR			(0x30)


#define SPW_RX_TIME_CODE_CFG_ADDR			(0x2C)


#define SPW_STUP_VCDU_PKGHEAD_BYTE_SIZE (44u)


#define SPW_STUP_VCDU_PKG_BYTE_SIZE (898u)


#define SPW_TFIFO_ADDR						(0x00)


#define SPW_TIMEOUT_ERR						(0x9)


#define SPW_TIME_CODE_CFG_ADDR				(0x28)


#define SPW_TWO_BITS_ERR_INT			(0xf<<1)	//b15531_twobits_err


#define SPW_TXBPS_100M				(100)


#define SPW_TXBPS_10M				(10)


#define SPW_TXBPS_133M				(133)


#define SPW_TXBPS_160M				(160)


#define SPW_TXBPS_200M				(200)


#define SPW_TXBPS_20M				(20)


#define SPW_TXBPS_266M				(266)


#define SPW_TXBPS_2M				(2)


#define SPW_TXBPS_400M				(400)


#define SPW_TXBPS_40M				(40)


#define SPW_TXBPS_4M				(4)


#define SPW_TXBPS_50M				(50)


#define SPW_TXBPS_66M				(66)


#define SPW_TXBPS_80M				(80)


#define SPW_TXBPS_8M				(8)


#define SPW_TXRAM_A_ADDR					(0x48)


#define SPW_TXRAM_A_ADDR				(0x48)


#define SPW_TXRAM_B_ADDR					(0x4c)


#define SPW_TXRAM_B_ADDR				(0x4c)


#define SPW_TXRAM_EDAC_ERR_CLR_ADDR			(0x40)


#define SPW_TXRAM_EDAC_ERR_CLR_ADDR		(0x40)


#define SPW_TX_CLK					(800)


#define SPW_TX_ERR							(0x1)


#define SPW_TX_ERR						(0x1)


#define SPW_TX_RATE_ADDR					(0x08)


#define SPW_TX_TIME_CODE_CFG_ADDR			(0x2C)


#define SPW_test_mode_reg				(0x3)


#define SRAM_REG_BASE							(0x40200000)


#define SRAM_TWO_BITS_ERR_INT			(0x1<<12)	//sram_twobits_err


#define SREFR			 			(0x10)	//SDRAM刷新寄存器


#define STABLE_THRLD_ES_reg				(0x13)


#define STACK_CUR_ADDR					(0x100 * 4)		//堆栈区当前地址


#define STACK_NOT_SUPPORT					(0)


#define STACK_PKT_CNT_ADDR				(0x101 * 4)		//当前堆栈中有效packe个数


#define STACK_RX_PKT_CNT				(5)


#define STACK_TX_PKT_CNT				(5)


#define STD_1553_BC_H


#define STD_1553_H


#define STD_1553_REG_H


#define STD_1553_RT_H


#define STD_ADDR_H


#define STD_ADDR_H


#define STD_BASAL_H


#define STD_BASAL_H


#define STD_BIT_OPERATION_H


#define STD_BIT_OPERATION_H


#define STD_COMMON_H


#define STD_COMMON_H


#define STD_CONST_H


#define STD_CRI_DATA_SR_IN_HHH


#define STD_MACRO_FUN_EXP_H


#define STD_MACRO_FUN_EXP_H


#define STD_TYPE_CONVERT_H


#define STD_TYPE_CONVERT_H


#define STD_UTILS_H


#define STD_UTILS_H


#define STMG0R	 					(0x4)	//SDRAM时序寄存器0


#define STMG1R	 					(0x8)	//SDRAM时序寄存器1


#define SUBMD_AAM_RDSM (0x00u)


#define SUBMD_AAM_SASM (0x01u)


#define SUBMD_AAM_SCSM (0x09u)


#define SUBMD_AAM_SESM (0x08u)


#define SUBMD_AAM_SPSM (0x02u)


#define SUBMD_AAM_SSSM (0x07u)


#define SUM_VALUE					(0xdeadbeef)


#define SVC_MODE_STACK_SIZE				(8*1024)


#define SVC_MODE_STACK_TOP			(MEM_SYS_STK_BASE & 0xfffffff0)


#define SWITCH_ENABLE					(0x42)


#define SYNC_THRLD_ES_reg				(0x12)


#define SYSDataBegin			(MEM_APP_DATA_USED_BASEADDR)


#define SYSDataSize				(MEM_APP_DATA_USED_SIZE)


#define SYSFALSE				(0x0)


#define SYSHOOKMAXNUM						16


#define SYSLoadBegin			(MEM_BOOT_USED_BASEADDR)


#define SYSLoadSize				(MEM_BOOT_USED_SIZE)


#define SYSProgBegin			(MEM_APP_PROG_USED_BASEADDR)


#define SYSProgSize				(MEM_APP_PROG_USED_SIZE)


#define SYSStackBlockBegin		(MEM_SYS_STK_LOWBASE)


#define SYSStackBlockSize		(MEM_SYS_STK_SIZE)


#define SYSTRUE					(0xeb90146f)


#define SYS_BOOT_RUN_INFO_BASEADDR		(BSP_RAM_BASE_ADDR+0xD200)


#define SYS_BOOT_RUN_INFO_SIZE			(1*1024)


#define SYS_BOOT_TRAP_INFO_BASEADDR		(BSP_RAM_BASE_ADDR+0xC400)


#define SYS_BOOT_TRAP_INFO_SIZE			(3*1024)


#define SYS_CLOCK  (0x0)//系统时钟


#define SYS_DISABLE							(0x0)


#define SYS_ENABLE							(0xeb90146f)


#define SYS_ERROR							(0x0)


#define SYS_GPT_DATR	*(V_U32 *)0x3fff0604


#define SYS_LESS_COMMON_TRAP_INFO_RECORD_SIZE 		(4*1024)


#define SYS_MAX_CAUSERELOAD_REBOOTCNT		(3)


#define SYS_MAX_CAUSESWITCH_REBOOTCNT		(5)


#define SYS_MAX_FLASH_Auto_Check_Size		(0x80)


#define SYS_MAX_FLASH_Repair_Read_Size  	(0x80)


#define SYS_MAX_FLASH_Repair_Write_Size  	(0x08)


#define SYS_MAX_FLASH_SetSum_Read_Size  	(0x80)


#define SYS_MAX_FLASH_SetSum_Write_Size  	(0x08)


#define SYS_MAX_PERIOD_TIME_MS				(SYS_PERIOD_TIME_MS)


#define SYS_MAX_TICKNUM_PER_PERIOD			(SYS_MAX_PERIOD_TIME_MS/OS_TIME_TICKS)


#define SYS_MAX_TICK_INDEXNUM_PER_PERIOD	((SYS_MAX_TICKNUM_PER_PERIOD>>5)+1)


#define SYS_MODE_STACK_SIZE				(20*1024)


#define SYS_MODE_STACK_TOP			((SVC_MODE_STACK_TOP - SVC_MODE_STACK_SIZE) & 0xfffffff0)


#define SYS_NORFLASH_CONTROL_ADDR			(0xa00d0000)


#define SYS_NORFLASH_CONTROL_BIT			(0)


#define SYS_NORFLASH_DISABLE_VALUE			(0x0)


#define SYS_NORFLASH_ENABLE_VALUE			(0x1)


#define SYS_NORFLASH_STATUS_ADDR			(0xa00d0000)


#define SYS_NORFLASH_STATUS_BIT				(0)


#define SYS_NORF_ASK						(0x02)//   Y                   查询操作


#define SYS_NORF_ASK (0x02u)


#define SYS_NORF_DOUBLE_ERR					(0x08)//        Y           Y  在norflash读写过程表示单份出现双错


#define SYS_NORF_DOUBLE_ERR (0x08u)


#define SYS_NORF_MODE_ERR					(0x0C)//        Y              本次操作失败，mode参数错误


#define SYS_NORF_MODE_ERR (0x0Cu)


#define SYS_NORF_NOTALIGN_ERR				(0x09)//        Y              本次操作失败，NORF或SRAM地址不对齐


#define SYS_NORF_NOTALIGN_ERR (0x09u)


#define SYS_NORF_NOTINNORF_ERR				(0x0A)//        Y              本次操作失败，不在Norflash有效地址空间


#define SYS_NORF_NOTINNORF_ERR (0x0Au)


#define SYS_NORF_NOTINSRAM_ERR				(0x0B)//        Y              本次操作失败，不在SRAM有效地址空间


#define SYS_NORF_NOTINSRAM_ERR (0x0Bu)


#define SYS_NORF_OK							(0x07)//        Y           Y  可以进行新操作


#define SYS_NORF_OK (0x07u)


#define SYS_NORF_OPTNULL					(0x06)//             Y         空操作


#define SYS_NORF_OPTNULL (0x06u)


#define SYS_NORF_OPT_ERR					(0x0D)//        Y              当前操作指令不被执行，flash正响应其他操作指令


#define SYS_NORF_OPT_ERR (0x0Du)


#define SYS_NORF_READ						(0x00)//   Y    Y    Y      Y  读操作


#define SYS_NORF_READ (0x00u)


#define SYS_NORF_REFRESH					(0x04)//        Y    Y      Y  刷新norflash


#define SYS_NORF_REFRESH (0x04u)


#define SYS_NORF_REPAIR						(0x05)//        Y    Y      Y  修复norflash


#define SYS_NORF_REPAIR (0x05u)


#define SYS_NORF_SUM						(0x03)//   Y    Y    Y      Y  计算程序累加和并写入


#define SYS_NORF_SUM (0x03u)


#define SYS_NORF_WRITE						(0x01)//   Y    Y    Y      Y  写操作


#define SYS_NORF_WRITE (0x01u)


#define SYS_NorFlash1_EndAddr 			NorFlash_DataEdacInSameSectorAddr


#define SYS_NorFlash1_StartAddr			(0x08000000)


#define SYS_NorFlash2_DieNum			(0x1)


#define SYS_NorFlash2_DieSize			(0x01000000)


#define SYS_NorFlash2_EndAddr			(0x10000000)


#define SYS_NorFlash2_Size 				(0x04000000)


#define SYS_NorFlash2_StartAddr			(0x0c000000)


#define SYS_NorFlash_ADDAParam1_Base		(0x08080000)


#define SYS_NorFlash_ADDAParam1_Base		(0x080C0000)


#define SYS_NorFlash_ADDAParam1_Base		(0x08140000)


#define SYS_NorFlash_ADDAParam1_Base		(0x08280000)


#define SYS_NorFlash_ADDAParam2_Base		(0x08100000)


#define SYS_NorFlash_ADDAParam2_Base		(0x08160000)


#define SYS_NorFlash_ADDAParam2_Base		(0x08260000)


#define SYS_NorFlash_ADDAParam2_Base		(0x08480000)


#define SYS_NorFlash_Data1_Base				(0x08080000)


#define SYS_NorFlash_Data1_Base				(0x080C0000)


#define SYS_NorFlash_Data1_Base				(0x08140000)


#define SYS_NorFlash_Data1_Base				(0x08280000)


#define SYS_NorFlash_Data1_Base				(0xFFFFFFFF)


#define SYS_NorFlash_Data1_Size				SYS_NorFlash_Data_Size


#define SYS_NorFlash_Data2_Base				(0x08100000)


#define SYS_NorFlash_Data2_Base				(0x08160000)


#define SYS_NorFlash_Data2_Base				(0x08260000)


#define SYS_NorFlash_Data2_Base				(0x08480000)


#define SYS_NorFlash_Data2_Base				(0xFFFFFFFF)


#define SYS_NorFlash_Data2_Size				SYS_NorFlash_Data_Size


#define SYS_NorFlash_DataArea				(0x6A)


#define SYS_NorFlash_DataArea_A				(0xAA)


#define SYS_NorFlash_DataArea_B				(0x5A)


#define SYS_NorFlash_DataBaseCheck


#define SYS_NorFlash_DataIntervalSectorNum	((SYS_NorFlash_Data2_Base-SYS_NorFlash_Data1_Base)>>NorFlash_SectorSize_AddrBit_Num)


#define SYS_NorFlash_Data_Size				(0x00000000)


#define SYS_NorFlash_IllegalArea			(0xFFFFFFFF)


#define SYS_NorFlash_Prog1_Base				(0x08040000)


#define SYS_NorFlash_Prog1_Base				(0x08100000)


#define SYS_NorFlash_Prog1_Size 			SYS_NorFlash_Prog_Size


#define SYS_NorFlash_Prog2_Base				(0x080C0000)


#define SYS_NorFlash_Prog2_Base				(0x080E0000)


#define SYS_NorFlash_Prog2_Base				(0x08160000)


#define SYS_NorFlash_Prog2_Base				(0x08300000)


#define SYS_NorFlash_Prog2_Size 			SYS_NorFlash_Prog_Size


#define SYS_NorFlash_ProgArea				(0x95)


#define SYS_NorFlash_ProgArea_A				(0x55)


#define SYS_NorFlash_ProgArea_B				(0xA5)


#define SYS_NorFlash_ProgIntervalSectorNum	((SYS_NorFlash_Prog2_Base-SYS_NorFlash_Prog1_Base)>>NorFlash_SectorSize_AddrBit_Num)


#define SYS_NorFlash_ProgNum				(2)


#define SYS_NorFlash_Prog_Size				(0x100000)


#define SYS_NorFlash_Prog_Size				(0x40000)


#define SYS_NorFlash_Prog_Size				(0x80000)


#define SYS_NorFlash_RefreshData_Enable				(0)


#define SYS_NorFlash_Repair_Buff_BaseAddr			(0x4017AC00)


#define SYS_NorFlash_Repair_Erase			(0x3)


#define SYS_NorFlash_Repair_EraseErr		(0x8)


#define SYS_NorFlash_Repair_ErrorInfo_BaseAddr		(0x405AF400)


#define SYS_NorFlash_Repair_ErrorInfo_Size			(0x8000)


#define SYS_NorFlash_Repair_Init			(0x1)


#define SYS_NorFlash_Repair_OK				(0x0)


#define SYS_NorFlash_Repair_OtherErr		(0x9)


#define SYS_NorFlash_Repair_Read			(0x2)


#define SYS_NorFlash_Repair_ReadErr			(0x6)


#define SYS_NorFlash_Repair_Record			(0x5)


#define SYS_NorFlash_Repair_Write			(0x4)


#define SYS_NorFlash_Repair_WriteErr		(0x7)


#define SYS_NorFlash_SectorSize					(0x40000)


#define SYS_NorFlash_SectorSize_bit				(0x3FFFF)


#define SYS_NorFlash_SetSum_Erase			(0x3)


#define SYS_NorFlash_SetSum_EraseErr		(0x8)


#define SYS_NorFlash_SetSum_Init			(0x1)


#define SYS_NorFlash_SetSum_OK				(0x0)


#define SYS_NorFlash_SetSum_OtherErr		(0x9)


#define SYS_NorFlash_SetSum_Read			(0x2)


#define SYS_NorFlash_SetSum_ReadErr			(0x6)


#define SYS_NorFlash_SetSum_Record			(0x5)


#define SYS_NorFlash_SetSum_Write			(0x4)


#define SYS_NorFlash_SetSum_WriteErr		(0x7)


#define SYS_NorFlash_TrapRecord_BaseAddr	(0x08140000)


#define SYS_NorFlash_TrapRecord_BaseAddr	(0x08180000)


#define SYS_NorFlash_TrapRecord_BaseAddr	(0x08280000)


#define SYS_NorFlash_TrapRecord_BaseAddr	(0x08500000)


#define SYS_NorFlash_TrapRecord_BaseAddr	(0x08500000)


#define SYS_NorFlash_TrapRecord_Enable			(0)


#define SYS_NorFlash_TrapRecord_Enable			(1)


#define SYS_NorFlash_TrapRecord_Size		(128*1024)


#define SYS_NorFlash_TrapRecord_Size		(256*1024)


#define SYS_NorFlash_TrapRecord_Size		(512*1024)


#define SYS_OK								(0xeb90146f)


#define SYS_PERIOD1_PERIOD_TIME_MS			SYS_PERIOD_TIME_MS


#define SYS_PERIOD1_TASK_NUM				SYSTASKNUM


#define SYS_PERIOD1_TASK_OFFSET				(0)


#define SYS_PERIOD2_PERIOD_TIME_MS			(0)


#define SYS_PERIOD2_TASK_NUM				(0)


#define SYS_PERIOD2_TASK_OFFSET				SYS_PERIOD1_TASK_NUM


#define SYS_PERIOD3_PERIOD_TIME_MS			(0)


#define SYS_PERIOD3_TASK_NUM				(0)


#define SYS_PERIOD3_TASK_OFFSET				(0)


#define SYS_PERIOD4_PERIOD_TIME_MS			(0)


#define SYS_PERIOD4_TASK_NUM				(0)


#define SYS_PERIOD4_TASK_OFFSET				(0)


#define SYS_ProgOfNorFlash_SectorNum		(SYS_NorFlash_Prog1_Size>>NorFlash_SectorSize_AddrBit_Num)


#define SYS_RAM_BLOCK_BEGIN_A	(SYSTRI32_A_BASEADDR+SYSTRI32_EACHSIZE-SYS_RAM_BLOCK_SIZE)


#define SYS_RAM_BLOCK_BEGIN_B	(SYSTRI32_B_BASEADDR+SYSTRI32_EACHSIZE-SYS_RAM_BLOCK_SIZE)


#define SYS_RAM_BLOCK_BEGIN_C	(SYSTRI32_C_BASEADDR+SYSTRI32_EACHSIZE-SYS_RAM_BLOCK_SIZE)


#define SYS_RAM_BLOCK_SIZE 							(1*1024)


#define SYS_SCHEDULE_BASED_ON_TIME_TABLE	(1)


#define SYS_SCHED_MODE_NUM					(1)


#define SYS_SEU_TRAP_INFO_RECORD_SIZE 				(12*1024)


#define SYS_Self_JK_Flag					(0x0)


#define SYS_Self_Not_JK_Flag				(0xeb90146f)


#define SYS_TASK10_Allocated_TIME_MS		(0)


#define SYS_TASK10_LEVEL					LEVEL_NORMAL


#define SYS_TASK10_STACK_SIZE				(16*1024)


#define SYS_TASK10_START_TIME_MS			(0xFFFFFFFF)


#define SYS_TASK11_Allocated_TIME_MS		(0)


#define SYS_TASK11_LEVEL					LEVEL_NORMAL


#define SYS_TASK11_STACK_SIZE				(16*1024)


#define SYS_TASK11_START_TIME_MS			(0xFFFFFFFF)


#define SYS_TASK12_Allocated_TIME_MS		(0)


#define SYS_TASK12_LEVEL					LEVEL_NORMAL


#define SYS_TASK12_STACK_SIZE				(16*1024)


#define SYS_TASK12_START_TIME_MS			(0xFFFFFFFF)


#define SYS_TASK13_Allocated_TIME_MS		(0)


#define SYS_TASK13_LEVEL					LEVEL_NORMAL


#define SYS_TASK13_STACK_SIZE				(16*1024)


#define SYS_TASK13_START_TIME_MS			(0xFFFFFFFF)


#define SYS_TASK14_Allocated_TIME_MS		(0)


#define SYS_TASK14_LEVEL					LEVEL_NORMAL


#define SYS_TASK14_STACK_SIZE				(16*1024)


#define SYS_TASK14_START_TIME_MS			(0xFFFFFFFF)


#define SYS_TASK15_Allocated_TIME_MS		(0)


#define SYS_TASK15_LEVEL					LEVEL_NORMAL


#define SYS_TASK15_STACK_SIZE				(16*1024)


#define SYS_TASK15_START_TIME_MS			(0xFFFFFFFF)


#define SYS_TASK16_Allocated_TIME_MS		(0)


#define SYS_TASK16_LEVEL					LEVEL_NORMAL


#define SYS_TASK16_STACK_SIZE				(16*1024)


#define SYS_TASK16_START_TIME_MS			(0xFFFFFFFF)


#define SYS_TASK1_LEVEL						LEVEL_CRITICAL


#define SYS_TASK1_STACK_SIZE				(32*1024)


#define SYS_TASK1_START_TIME_MS				(0)


#define SYS_TASK2_LEVEL						LEVEL_CRITICAL


#define SYS_TASK2_STACK_SIZE				(32*1024)


#define SYS_TASK3_STACK_SIZE				(32*1024)


#define SYS_TASK4_LEVEL						LEVEL_NORMAL


#define SYS_TASK4_STACK_SIZE				(16*1024)


#define SYS_TASK5_Allocated_TIME_MS			(0)


#define SYS_TASK5_LEVEL						LEVEL_NORMAL


#define SYS_TASK5_STACK_SIZE				(16*1024)


#define SYS_TASK5_START_TIME_MS				(0xFFFFFFFF)


#define SYS_TASK6_Allocated_TIME_MS			(0)


#define SYS_TASK6_LEVEL						LEVEL_NORMAL


#define SYS_TASK6_STACK_SIZE				(16*1024)


#define SYS_TASK6_START_TIME_MS				(0xFFFFFFFF)


#define SYS_TASK7_Allocated_TIME_MS			(0)


#define SYS_TASK7_LEVEL						LEVEL_NORMAL


#define SYS_TASK7_STACK_SIZE				(16*1024)


#define SYS_TASK7_START_TIME_MS				(0xFFFFFFFF)


#define SYS_TASK8_Allocated_TIME_MS			(0)


#define SYS_TASK8_LEVEL						LEVEL_NORMAL


#define SYS_TASK8_STACK_SIZE				(16*1024)


#define SYS_TASK8_START_TIME_MS				(0xFFFFFFFF)


#define SYS_TASK9_Allocated_TIME_MS			(0)


#define SYS_TASK9_LEVEL						LEVEL_NORMAL


#define SYS_TASK9_STACK_SIZE				(16*1024)


#define SYS_TASK9_START_TIME_MS				(0xFFFFFFFF)


#define SYS_TRI32_BASEADDR					(MEM_TRI32_USED_BASEADDR)

#define Sgn3f(x)        (Sgn3(x) )


#define Sinx(x)         (sin((float64)(x))                )


#define Sinx(x)         (sin((float64)(x))                )


#define Sqrtx(x)        (sqrt((float64)(x))               )


#define Sqrtx(x)        (sqrt((float64)(x))               )


#define TASKINFOTM_WIDTH			(5)


#define TASK_DONT_RUN						(0x55555555)


#define TASK_IS_OVER						(0xBBBBBBBB)


#define TASK_RUN_ALLOW						(0x0)


#define TASK_RUN_IN_ALL						(0x0)


#define TASK_RUN_IN_PART					(0xeb90146f)

#define TASK_START_RUN						(0xAAAAAAAA)


#define TBE_ERR								(0x2)


#define TC_COMPARE_FAIL        (0x2)


#define TC_COMPARE_NULL        (0x0)


#define TC_COMPARE_OK          (0x1)


#define TC_RESET							(0x4)


#define TEN_US   (0x2)   // 10 us


#define TF_FULL			0x200


#define THIRDWORKMODE ABSUI_TO_VADDR32(CCU_RAM_BASE + 0x0011EE00u)


#define THR_PULSE_WIDTH (CTRL_CYCLE_T / UN32_TO_DBL(NUM_JET_CYCLE))


#define THR_PWR_WAIT_CYCLE (0x2u)


#define TIMER_RELOAD_MODE 						(0x01)


#define TIMER_SCALER 			1


#define TIMER_SINGLE_MODE 						(0x00)


#define TLSF_SIGNATURE	(0x2A59FA59)


#define TM0_cnt 14//字段个数


#define TM10_cnt 15//字段个数  TM1_cnt


#define TM11_cnt 1//字段个数  TM2_cnt


#define TM12_cnt 1//字段个数  TM2_cnt


#define TM13_cnt 1//字段个数  TM3_cnt


#define TM14_cnt 1//字段个数  TM3_cnt


#define TM15_cnt 23//字段个数  TM4_cnt


#define TM16_cnt 23//字段个数  TM4_cnt


#define TM17_cnt 15//字段个数 TM5_cnt


#define TM18_cnt 15//字段个数 TM5_cnt


#define TM1_cnt 15//字段个数


#define TM2_cnt 1//字段个数


#define TM3_cnt 1//字段个数


#define TM4_cnt 23//字段个数


#define TM5_cnt 15//字段个数


#define TM6_cnt 16//字段个数


#define TM7_cnt 14//字段个数  TM0_cnt


#define TM8_cnt 14//字段个数  TM0_cnt


#define TM9_cnt 15//字段个数   TM1_cnt


#define TPAM_INST_NUM_DISINST (0x8001u)


#define TPAM_INST_NUM_MAINTAIN (0x8003u)


#define TPAM_INST_NUM_PULSE_NUMBER (0x8005u)


#define TPAM_INST_NUM_TARGET_ANGLE (0x8004u)


#define TPAM_JOINT_ANGLE_S_1 (0x11u)


#define TPAM_JOINT_ANGLE_S_2 (0x22u)


#define TPAM_PULSE_VALUE_MAX_RANGE (11.25)


#define TPAM_PWR_TPAP1_OFF (0x47FFD002u)


#define TPAM_PWR_TPAP1_ON (0x47FFE001u)


#define TPAM_PWR_TPAP2_OFF (0x47FFB004u)


#define TPAM_PWR_TPAP2_ON (0x47FFC003u)


#define TPAM_PWR_TPAP3_OFF (0x47FF9006u)


#define TPAM_PWR_TPAP3_ON (0x47FFA005u)


#define TPAM_PWR_TPAP4_OFF (0x47FF7008u)


#define TPAM_PWR_TPAP4_ON (0x47FF8007u)


#define TPAM_TARGET_ANGLE_MAX_RANGE (180.0)


#define TR32BlockBegin			(MEM_TRI32_USED_BASEADDR)


#define TR32BlockSize			(MEM_TRI32_USED_SIZE)


#define TRANSPARENT_CLOCK_reg_HIGH      (0x22)


#define TRANSPARENT_CLOCK_reg_LOW       (0x23)


#define TRANS_EN		0x2


#define TRANS_INT_EN	0x8


#define TRAP_GET_INT_NEST_CNT 		0x0D


#define TRAP_GET_SLICE_INT_NO		0x12


#define TRAP_GET_TRAP_SYS 			0x0C


#define TRAP_INT_CONNECT 			0x02


#define TRAP_INT_DISCONNECT 		0x03


#define TRAP_NULL					0x00


#define TRAP_SWITCH 				0x01


#define TRAP_TASK_DELETE_SELF	 	0x0F


#define TRAP_TASK_START_SELF	 	0x0E


#define TRUE					(1)


#define TRUE32              0xEB90146Fu


#define TRUE32              0xEB90146Fu


#define TRUE32      0xEB90146Fu


#define TS_EMPTY		0x2


#define TTE_AOCC_A_MAC_ADDR (0xabcdefabcd0au)


#define TTE_AOCC_B_MAC_ADDR (0xabcdefabcd0bu)


#define TTE_AOCC_C_MAC_ADDR (0xabcdefabcd0cu)


#define TTE_BASE						(0x20000000)


#define TTE_BE_BROADCAST_ADDR				(0xFFFFFFFFFFFF)


#define TTE_BE_RECV_VLINK_LEN (0x03u)


#define TTE_BE_SEND_VLINK_LEN (0x01u)


#define TTE_BRCST_MAC_ADDR (0xffffffffffffu)


#define TTE_BUF_MAX_BYTES (0x800u)


#define TTE_BYTES_AOCC_KZ_TO_IACU (1000u)


#define TTE_BYTES_IACUA_TO_AOCC (900u)


#define TTE_BYTES_IACUB_TO_AOCC (840u)


#define TTE_BYTES_IACUC_TO_AOCC (900u)


#define TTE_ERR_CHECKSUM (0x4u)


#define TTE_ERR_CONFIG (0x7u)


#define TTE_ERR_FRAME_CNT (0x6u)


#define TTE_ERR_MAC (0x9u)


#define TTE_ERR_MSG_HEAD (0x5u)


#define TTE_ERR_NULL (0x0u)


#define TTE_ERR_OS_DRV (0x1u)


#define TTE_ERR_RECV_LEN (0x2u)


#define TTE_ERR_SEND_LEN (0x8u)


#define TTE_ERR_VLNO_NOEXIST (0x3u)


#define TTE_ETHERNET_MAC_BE_FRAME_ID		(0x0800)		// 以太网V2 MAC帧类型	BE


#define TTE_ETHERNET_MAC_HEADER_LENGTH		(TTE_MAC_ADDR_BYTES*2 + TTE_MAC_TYPE_BYTES)


#define TTE_ETHERNET_MAC_TT_FRAME_ID		(0x88D7)		//						TT


#define TTE_IACUa0_MAC_ADDR (0xABCDEFABCD0Du)


#define TTE_IACUa1_MAC_ADDR (0xABCDEFABCD0Eu)


#define TTE_IACUb0_MAC_ADDR (0xABCDEFABCD0Fu)


#define TTE_IACUb1_MAC_ADDR (0xABCDEFABCD10u)


#define TTE_IACUc0_MAC_ADDR (0xABCDEFABCD11u)


#define TTE_IACUc1_MAC_ADDR (0xABCDEFABCD12u)


#define TTE_MAC_ADDR_BYTES					(6)				// MAC地址长度为6个字节


#define TTE_MAC_TYPE_BYTES					(2)				// MAC类型为2个字节


#define TTE_MONI_NUM					(0x80)


#define TTE_MSG_HEAD_HI8 (0xEBu)


#define TTE_MSG_HEAD_LO8 (0x90u)


#define TTE_PARTITION_SIZE					(2*1024)


#define TTE_SOFT_RESET           		(0xFFF)


#define TTE_TT_MAC_LABEL					(0xABADBABE)


#define TTE_TT_RECV_VLINK_LEN (0x06u)


#define TTE_TT_SEND_VLINK_LEN (0x01u)


#define TTE_VLID_AOCCA_KZ_TO_IACU (0x0040u)


#define TTE_VLID_AOCCB_KZ_TO_IACU (0x0080u)


#define TTE_VLID_AOCCC_KZ_TO_IACU (0x0100u)


#define TTE_VLID_IACUAB_TO_AOCC (0x0002u)


#define TTE_VLID_IACUAM_TO_AOCC (0x0001u)


#define TTE_VLID_IACUBB_TO_AOCC (0x0008u)


#define TTE_VLID_IACUBM_TO_AOCC (0x0004u)


#define TTE_VLID_IACUCB_TO_AOCC (0x0020u)


#define TTE_VLID_IACUCM_TO_AOCC (0x0010u)


#define TTTableSendbase					(0x100000)		//


#define TT_MAC_LABEL_reg		  		(0x2A)


#define TT_RECV_RAM_START_ADDR			(0x02000000)


#define TT_SEND_RAM_START_ADDR			(0x01000000)//每块占用32*2k空间


#define TT_SERVICE							(0x1)


#define TT_partition_state_reg			(0x72)


#define TT_recv_partition_base_addr 	(0x3C)


#define TT_recv_rd_frame_done_reg		(0x38)


#define TT_recv_vl_id_reg				(0x4C)


#define TT_recv_vl_length_reg			(0x4D)


#define TT_recv_vl_num_reg				(0x38)


#define TT_recv_vl_partition_addr		(0x4D)


#define TT_send_partition_addr_reg		(0x33)


#define TT_send_partition_base_addr 	(0x3A)


#define TT_send_vl_length_reg			(0x34)


#define TT_send_wr_done_reg				(0x36)


#define TWOBITERROR 2


#define TWOBITS_ERR_ADDR			(0xd0)	//双错地址寄存器


#define TWOBITS_ERR_DATA	 	 	(0xd4)	//双错数据寄存器


#define TWOBITS_ERR_EDAC	 	 	(0xd8)	//双错校验码寄存器


#define TX_BULK_TEOP_ENABLE_INT_BIT (0x10u)


#define TX_FIFO_EOP						(0x03)


#define TX_FIFO_TXFLUSH_BIT				(0x03)


#define TX_PKT128_BASE					(0xFFF)


#define TX_PKT128_BYTE_CNT				(1024)


#define TX_PKT128_END_TYPE				(0)


#define TX_PKT128_TIME_GAP				(5000)


#define TX_PKT1_BASE					(0x120)


#define TX_PKT1_BYTE_CNT				(32)


#define TX_PKT1_END_TYPE				(0)


#define TX_PKT1_TIME_GAP				(5000)


#define TX_PKT2_BASE					(0x220)


#define TX_PKT2_BYTE_CNT				(64)


#define TX_PKT2_END_TYPE				(0)


#define TX_PKT2_TIME_GAP				(5000)


#define TX_PKT3_BASE					(0x320)


#define TX_PKT3_BYTE_CNT				(128)


#define TX_PKT3_END_TYPE				(0)


#define TX_PKT3_TIME_GAP				(5000)


#define TX_PKT4_BASE					(0x420)


#define TX_PKT4_BYTE_CNT				(256)


#define TX_PKT4_END_TYPE				(0)


#define TX_PKT4_TIME_GAP				(5000)


#define TX_PKT5_BASE					(0x620)


#define TX_PKT5_BYTE_CNT				(512)


#define TX_PKT5_END_TYPE				(0)


#define TX_PKT5_TIME_GAP				(5000)


#define TX_PKT6_BASE					(0xFFF)


#define TX_PKT6_BYTE_CNT				(1024)


#define TX_PKT6_END_TYPE				(0)


#define TX_PKT7_BASE					(0xFFF)


#define TYPE_reg                        (0x20)


#define Tanx(x)         (tan((float64)(x))                )


#define Tanx(x)         (tan((float64)(x))                )


#define Test_MaxRunTimeAddr 0x40122200


#define TmCnt 19   //遥测字个数


#define TrapErr								(0x0)


#define TrapTrue							(0xeb90146f)


#define UARTPORT				0


#define UART_DLH (0x04)


#define UART_DLL (0x00)


#define UART_FCR (0x08)


#define UART_IER (0x04)


#define UART_IIR (0x08)


#define UART_LCR (0x0C)


#define UART_LSR (0x14)


#define UART_MCR (0x10)


#define UART_MSR (0x18)


#define UART_RBR (0x00) // 寄存器


#define UART_THR (0x00)


#define UI08_BIT_CLR(uv, bp)            ((uv) = (((unint32)(uv)) & ((0x01u << (bp)) ^ MASK_LO08)))


#define UI08_BIT_CLR(uv, bp)            ((uv) = (((unint32)(uv)) & ((0x01u << (bp)) ^ MASK_LO08)))


#define UI08_BIT_GET(uv, bp)            ((unint08)((((unint32)(uv)) >> (bp)) & 0x01u))


#define UI08_BIT_GET(uv, bp)            ((unint08)((((unint32)(uv)) >> (bp)) & 0x01u))


#define UI08_BIT_SET(uv, bp)            ((uv) = (((unint32)(uv)) | ((0x01u << (bp)) & MASK_LO08)))


#define UI08_BIT_SET(uv, bp)            ((uv) = (((unint32)(uv)) | ((0x01u << (bp)) & MASK_LO08)))


#define UI08_MAKE04(h4, l4)             ((((unint32)(h4)) << 4u) | ((unint32)(l4)))


#define UI08_MAKE04(h4, l4)             ((unint08)((((unint32)((h4) & MASK_LO04)) << 4u) | ((unint32)((l4) & MASK_LO04))))


#define UI16_BIT_CLR(uv, bp)            ((uv) = (((unint32)(uv)) & ((0x01u << (bp)) ^ MASK_LO16)))


#define UI16_BIT_CLR(uv, bp)            ((uv) = (((unint32)(uv)) & ((0x01u << (bp)) ^ MASK_LO16)))


#define UI16_BIT_GET(uv, bp)            ((unint16)((((unint32)(uv)) >> (bp)) & 0x01u))


#define UI16_BIT_GET(uv, bp)            ((unint16)((((unint32)(uv)) >> (bp)) & 0x01u))


#define UI16_BIT_GET1(uv, bp)           ((unint16)((((unint32)(uv)) >> (bp)) & 0x01))


#define UI16_BIT_GET1(uv, bp)           ((unint16)((((unint32)(uv)) >> (bp)) & 0x01))


#define UI16_BIT_GET2(uv, bp)           ((unint16)((((unint32)(uv)) >> (bp)) & 0x03))


#define UI16_BIT_GET2(uv, bp)           ((unint16)((((unint32)(uv)) >> (bp)) & 0x03))


#define UI16_BIT_SET(uv, bp)            ((uv) = (((unint32)(uv)) | ((0x01u << (bp)) & MASK_LO16)))


#define UI16_BIT_SET(uv, bp)            ((uv) = (((unint32)(uv)) | ((0x01u << (bp)) & MASK_LO16)))


#define UI16_BIT_SET1(uv, bp, bv)       ((uv) = (unint16)((((unint32)(uv)) & ((0x01 << (bp)) ^ (MASK_LO16))) | ((bv) << (bp))))


#define UI16_BIT_SET1(uv, bp, bv)       ((uv) = (unint16)((((unint32)(uv)) & ((0x01 << (bp)) ^ (MASK_LO16))) | ((bv) << (bp))))


#define UI16_BIT_SET2(uv, bp, bv)       ((uv) = (unint16)((((unint32)(uv)) & ((0x03 << (bp)) ^ (MASK_LO16))) | ((bv) << (bp))))


#define UI16_BIT_SET2(uv, bp, bv)       ((uv) = (unint16)((((unint32)(uv)) & ((0x03 << (bp)) ^ (MASK_LO16))) | ((bv) << (bp))))


#define UI16_BIT_SET4(uv, bp, bv)       ((uv) = (unint16)((((unint32)(uv)) & ((0x0F << (bp)) ^ (MASK_LO16))) | ((bv) << (bp))))


#define UI16_HI8(ui16)                  ((unint08)((((unint32)(ui16)) >> 8u) & MASK_LO08))


#define UI16_HI8(ui16)                  ((unint08)((((unint32)(ui16)) >> 8u) & MASK_LO08))


#define UI16_LO8(ui16)                  ((unint08)((((unint32)(ui16))      ) & MASK_LO08))


#define UI16_LO8(ui16)                  ((unint08)((((unint32)(ui16))      ) & MASK_LO08))


#define UI16_MAKE(hi8, lo8)             ((unint16)((((unint32)((hi8) & MASK_LO08)) <<  8u) | ((unint32)((lo8) & MASK_LO08))))


#define UI16_MAKE(hi8, lo8)             ((unint16)((((unint32)(hi8)) <<  8u) | ((unint32)(lo8))))


#define UI16_MAKE_HI12(hi8, lo8)        ((unint16)((((unint32)(hi8)) << 4u) | (((unint32)(lo8)) >> 4u)))


#define UI32_BIT_CLR(uv, bp)            (BIT_CLR((uv), (bp), MASK_ALL8F))


#define UI32_BIT_CLR(uv, bp)            BIT_CLR((uv), (bp), MASK_ALL8F)


#define UI32_BIT_GET(uv, bp)            (BIT_GET((uv), (bp)))


#define UI32_BIT_GET(uv, bp)            BIT_GET((uv), (bp))


#define UI32_BIT_GET1(uv, bp)           (((uv) >> (bp)) & 0x001u)


#define UI32_BIT_GET1(uv, bp)           (((uv) >> (bp)) & 0x001u)


#define UI32_BIT_GET10(uv, bp)          (((uv) >> (bp)) & 0x3FFu)


#define UI32_BIT_GET10(uv, bp)          (((uv) >> (bp)) & 0x3FFu)


#define UI32_BIT_GET12(uv, bp)          (((uv) >> (bp)) & 0xFFFu)


#define UI32_BIT_GET12(uv, bp)          (((uv) >> (bp)) & 0xFFFu)


#define UI32_BIT_GET2(uv, bp)           (((uv) >> (bp)) & 0x003u)


#define UI32_BIT_GET2(uv, bp)           (((uv) >> (bp)) & 0x003u)


#define UI32_BIT_GET20(uv, bp)          (((uv) >> (bp)) & 0xFFFFFu)


#define UI32_BIT_GET23(uv, bp)          (((uv) >> (bp)) & 0x7FFFFFu)


#define UI32_BIT_GET3(uv, bp)           (((uv) >> (bp)) & 0x007u)


#define UI32_BIT_GET3(uv, bp)           (((uv) >> (bp)) & 0x007u)


#define UI32_BIT_GET4(uv, bp)           (((uv) >> (bp)) & 0x00Fu)


#define UI32_BIT_GET4(uv, bp)           (((uv) >> (bp)) & 0x00Fu)


#define UI32_BIT_GET5(uv, bp)           (((uv) >> (bp)) & 0x01Fu)


#define UI32_BIT_GET5(uv, bp)           (((uv) >> (bp)) & 0x01Fu)


#define UI32_BIT_GET6(uv, bp)           (((uv) >> (bp)) & 0x03Fu)


#define UI32_BIT_GET6(uv, bp)           (((uv) >> (bp)) & 0x03Fu)


#define UI32_BIT_GET7(uv, bp)           (((uv) >> (bp)) & 0x07Fu)


#define UI32_BIT_GET7(uv, bp)           (((uv) >> (bp)) & 0x07Fu)


#define UI32_BIT_GET8(uv, bp)           (((uv) >> (bp)) & 0x0FFu)


#define UI32_BIT_GET8(uv, bp)           (((uv) >> (bp)) & 0x0FFu)


#define UI32_BIT_GETN(uv, bp, n)        (((uv) >> (bp)) & UI32_BIT_MASKN((n)))


#define UI32_BIT_GETN(uv, bp, n)        (((uv) >> (bp)) & UI32_BIT_MASKN((n)))


#define UI32_BIT_MASKN(n)               (MASK_ALL8F >> (32u - (n)))


#define UI32_BIT_MASKN(n)               (MASK_ALL8F >> (32u - (n)))


#define UI32_BIT_SET(uv, bp)            (BIT_SET((uv), (bp), MASK_ALL8F))


#define UI32_BIT_SET(uv, bp)            BIT_SET((uv), (bp), MASK_ALL8F)


#define UI32_BIT_SET1(uv, bp, bv)       ((uv) = ((uv) & ((0x01u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET1(uv, bp, bv)       ((uv) = ((uv) & ((0x01u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET2(uv, bp, bv)       ((uv) = ((uv) & ((0x03u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET2(uv, bp, bv)       ((uv) = ((uv) & ((0x03u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET3(uv, bp, bv)       ((uv) = ((uv) & ((0x07u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET3(uv, bp, bv)       ((uv) = ((uv) & ((0x07u << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET4(uv, bp, bv)       ((uv) = ((uv) & ((0x0Fu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET4(uv, bp, bv)       ((uv) = ((uv) & ((0x0Fu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET5(uv, bp, bv)       ((uv) = ((uv) & ((0x1Fu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET5(uv, bp, bv)       ((uv) = ((uv) & ((0x1Fu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET6(uv, bp, bv)       ((uv) = ((uv) & ((0x3Fu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET7(uv, bp, bv)       ((uv) = ((uv) & ((0x7Fu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BIT_SET8(uv, bp, bv)       ((uv) = ((uv) & ((0xFFu << (bp)) ^ (MASK_ALL8F))) | ((bv) << (bp)))


#define UI32_BYTE_CLR(uv, hl)           ((uv) = ((uv) & ((0xFFu << ((3u - (hl)) << 3u)) ^ (MASK_ALL8F))))


#define UI32_BYTE_CLR(uv, hl)           ((uv) = ((uv) & ((0xFFu << ((3u - (hl)) << 3u)) ^ (MASK_ALL8F))))


#define UI32_BYTE_GET(uv, hl)           (((uv) >> ((3u - (hl)) << 3u)) & 0xFFu)


#define UI32_BYTE_GET(uv, hl)           (((uv) >> ((3u - (hl)) << 3u)) & 0xFFu)


#define UI32_BYTE_SET(uv, hl, byv)      ((uv) = ((uv) & ((0xFFu << ((3u - (hl)) << 3u)) ^ (MASK_ALL8F))) | ((byv) << ((3u - (hl)) << 3u)))


#define UI32_BYTE_SET(uv, hl, byv)      ((uv) = ((uv) & ((0xFFu << ((3u - (hl)) << 3u)) ^ (MASK_ALL8F))) | ((byv) << ((3u - (hl)) << 3u)))


#define UI32_BYTE_SET_HIHI8(ui08, val)  (((ui08) & 0x00FFFFFFu) | ((val) << 24u))


#define UI32_BYTE_SET_HILO8(ui08, val)  (((ui08) & 0xFF00FFFFu) | ((val) << 16u))


#define UI32_BYTE_SET_LOHI8(ui08, val)  (((ui08) & 0xFFFF00FFu) | ((val) <<  8u))


#define UI32_BYTE_SET_LOLO8(ui08, val)  (((ui08) & 0xFFFFFF00u) | ((val)      ))


#define UI32_HI16(ui32)                 ((unint16)(((ui32) >> 16u) & MASK_LO16))


#define UI32_HI16(ui32)                 ((unint16)(((ui32) >> 16u) & MASK_LO16))


#define UI32_HIHI8(ui32)                ((unint08)(((ui32) >> 24u) & MASK_LO08))


#define UI32_HIHI8(ui32)                ((unint08)(((ui32) >> 24u) & MASK_LO08))


#define UI32_HIHI8_SET(val32, ui08)     ((val32) = ((val32) & 0x00FFFFFFu) | (((ui08) & MASK_LO08) << 24u))


#define UI32_HILO8(ui32)                ((unint08)(((ui32) >> 16u) & MASK_LO08))


#define UI32_HILO8(ui32)                ((unint08)(((ui32) >> 16u) & MASK_LO08))


#define UI32_HILO8_SET(val32, ui08)     ((val32) = ((val32) & 0xFF00FFFFu) | (((ui08) & MASK_LO08) << 16u))


#define UI32_LO16(ui32)                 ((unint16)(((ui32)       ) & MASK_LO16))


#define UI32_LO16(ui32)                 ((unint16)(((ui32)       ) & MASK_LO16))


#define UI32_LOHI8(ui32)                ((unint08)(((ui32) >>  8u) & MASK_LO08))


#define UI32_LOHI8(ui32)                ((unint08)(((ui32) >>  8u) & MASK_LO08))


#define UI32_LOHI8_SET(val32, ui08)     ((val32) = ((val32) & 0xFFFF00FFu) | (((ui08) & MASK_LO08) <<  8u))


#define UI32_LOLO8(ui32)                ((unint08)(((ui32)       ) & MASK_LO08))


#define UI32_LOLO8(ui32)                ((unint08)(((ui32)       ) & MASK_LO08))


#define UI32_LOLO8_SET(val32, ui08)     ((val32) = ((val32) & 0xFFFFFF00u) | (((ui08) & MASK_LO08)       ))


#define UI32_MAKE(hh8, hl8, lh8, ll8)   ((((unint32)((hh8) & MASK_LO08)) << 24u) | (((unint32)((hl8) & MASK_LO08)) << 16u) | (((unint32)((lh8) & MASK_LO08)) << 8u) | ((unint32)((ll8) & MASK_LO08)))


#define UI32_MAKE(hh8, hl8, lh8, ll8)   ((((unint32)(hh8)) << 24u) | (((unint32)(hl8)) << 16u) | (((unint32)(lh8)) << 8u) | ((unint32)(ll8)))


#define UI32_MAKE16(h16, l16)           ((((unint32)((h16) & MASK_LO16)) << 16u) | ((unint32)((l16) & MASK_LO16)))


#define UI32_MAKE16(h16, l16)           ((((unint32)(h16)) << 16u) | ((unint32)(l16)))


#define UI64_HI32(ui64)                 ((unint32)(((ui64) >> 32u) & MASK_ALL8F))


#define UI64_HIHI16(ui64)               ((unint16)(((ui64) >> 48u) & MASK_LO16))


#define UI64_HILO16(ui64)               ((unint16)(((ui64) >> 32u) & MASK_LO16))


#define UI64_LO32(ui64)                 ((unint32)(((ui64)       ) & MASK_ALL8F))


#define UI64_LOHI16(ui64)               ((unint16)(((ui64) >> 16u) & MASK_LO16))


#define UI64_LOLO16(ui64)               ((unint16)(((ui64)       ) & MASK_LO16))


#define UI64_MAKE16(hh, hl, lh, ll)     ((((ulong64)((hh) & MASK_LO16)) << 48u) | (((ulong64)((hl) & MASK_LO16)) << 32u) | (((ulong64)((lh) & MASK_LO16)) << 16u) | ((ulong64)((ll) & MASK_LO16)))


#define UI64_MAKE16(hh, hl, lh, ll)     ((((ulong64)(hh)) << 48u) | (((ulong64)(hl)) << 32u) | (((ulong64)(lh)) << 16u) | ((ulong64)(ll)))


#define UI64_MAKE32(hh, ll)             ((((ulong64)((hh) & MASK_ALL8F)) << 32u) | ((ulong64)((ll) & MASK_ALL8F)))


#define UI64_MAKE32(hh, ll)             ((((ulong64)(hh)) << 32u) | ((ulong64)(ll)))


#define UI8_HI4(ui8)                    ((unint08)((((unint32)(ui8)) >> 4u) & MASK_LO04))


#define UI8_HI4(ui8)                    ((unint08)((((unint32)(ui8)) >> 4u) & MASK_LO04))


#define UI8_LO4(ui8)                    ((unint08)((((unint32)(ui8))      ) & MASK_LO04))


#define UI8_LO4(ui8)                    ((unint08)((((unint32)(ui8))      ) & MASK_LO04))


#define ULONG64_MAX     0u


#define ULONG64_MAX     ULLONG_MAX


#define ULONG64_MAX     ULONG_MAX


#define ULONG64_MIN     0u


#define ULONG64_MIN     0u


#define UN08_TO_DBL(x)                  ((float64)(x))


#define UN08_TO_DBL(x)                  ((float64)(x))


#define UN16_TO_DBL(x)                  ((float64)(x))


#define UN16_TO_DBL(x)                  ((float64)(x))


#define UN16_TO_FLT(x)                  ((float32)(x))


#define UN16_TO_FLT(x)                  ((float32)(x))


#define UN32_TO_DBL(x)                  ((float64)(x))


#define UN32_TO_DBL(x)                  ((float64)(x))


#define UN32_TO_FLT(x)                  ((float32)(x))


#define UN32_TO_FLT(x)                  ((float32)(x))


#define UND_MODE_STACK_SIZE				(8*1024)


#define UND_MODE_STACK_TOP			((SYS_MODE_STACK_TOP - SYS_MODE_STACK_SIZE) & 0xfffffff0)


#define UNINT08_MAX         UCHAR_MAX


#define UNINT08_MIN         0u


#define UNINT16_MAX         USHRT_MAX


#define UNINT16_MIN         0u


#define UNINT32_MAX         UINT_MAX


#define UNINT32_MIN         0u


#define UNSYNC2SYNC_THRLD_ES_reg		(0x11)


#define USED_BLOCK	(0x0)


#define USE_NEW_PAR_CONTEXT			(0x03)


#define USE_NEW_TASK_CONTEXT		(0x05)


#define USE_OLD_PAR_CONTEXT			(0x04)


#define USR_CP_AOCC_SYNC	0xBBBB


#define USR_CP_TIMESLICE	0xAAAA


#define USR_CP_TTE_SYNC		0xCCCC


#define USR_EMIFRAM_REFRESHwordSize			USR_RAMREFRESHwordSize


#define USR_MAXCNT_SEU						(10)


#define USR_RAMREFRESHwordSize				(0x400)


#define USR_SDRAM_REFRESHwordSize			USR_RAMREFRESHwordSize


#define USR_SRAM_REFRESHwordSize			USR_RAMREFRESHwordSize


#define USR_TTE_AOCCa_MAC_ADDR		0xABCDEFABCD0A


#define USR_TTE_AOCCb_MAC_ADDR		0xABCDEFABCD0B


#define USR_TTE_AOCCc_MAC_ADDR		0xABCDEFABCD0C


#define USR_TTE_IACUa0_MAC_ADDR		0xABCDEFABCD0D


#define USR_TTE_IACUa1_MAC_ADDR		0xABCDEFABCD0E


#define USR_TTE_IACUb0_MAC_ADDR		0xABCDEFABCD0F


#define USR_TTE_IACUb1_MAC_ADDR		0xABCDEFABCD10


#define USR_TTE_IACUc0_MAC_ADDR		0xABCDEFABCD11


#define USR_TTE_IACUc1_MAC_ADDR		0xABCDEFABCD12


#define WAIT_FOREVER		(-1)


#define WDT_RESET_TIME				(4000000)


#define WKMD_AAM (0x08u)


#define WKMD_AEM (0x0Au)


#define WKMD_AFM (0x05u)


#define WKMD_AMM (0x04u)


#define WKMD_EIM (0x01u)


#define WKMD_ETM (0x06u)


#define WKMD_FIM (0x0Bu)


#define WKMD_IOM (0x0Cu)


#define WKMD_NCM (0x09u)


#define WKMD_NWM (0x02u)


#define WKMD_SBM (0x00u)


#define WKMD_SCM (0x03u)


#define WKMD_SKM (0x07u)


#define WRMEM_CONFIG_REG				(0x0000)		//RAM空间配置


#define WR_EDAC_ADDR_BYPASS			(0xe8) 	//EDAC写旁路地址寄存器


#define WR_EDAC_DATA_BYPASS			(0xec) 	//EDAC写旁路数据寄存器


#define WR_WS_CFG_REG					(0x0020)		//RAM空间等待时序配置


#define XWTRI32_A_BASEADDR					(APPTRI32_A_BASEADDR+APPTRI32_EACHSIZE+SYS_ISOLATION_SIZE)

#define XWTRI32_B_BASEADDR					(APPTRI32_B_BASEADDR+APPTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define XWTRI32_C_BASEADDR					(APPTRI32_C_BASEADDR+APPTRI32_EACHSIZE+SYS_ISOLATION_SIZE)


#define _AD_Param_Init_HANDLE_FUNC_			Drv_AD_CHIP_Param_Init


#define _BSP_SPW_H_


#define _BSP_SPW_MACRO_H_


#define _CPH_R_Version_					"1.03(0.0s)"


#define _CS_COUNTER_H_


#define _CS_TIME_H_


#define _DA_Param_Init_HANDLE_FUNC_			Drv_DA_CHIP_Param_Init


#define _DRV_SPW_H_


#define _DRV_TTE_H_


#define _INCLUDE_SADA_DBL_


#define _SYS_1553B_TRAP_H_


#define _XH_R_Version_					"2.00(0.0h4)"


#define __ADD_DATA_NORFLASH__			(0)


#define __ADD_NORFLASH__


#define __ADKB_ENABLE__						(0)


#define __ALL_TIMER_NUM__			(10)


#define __APB_TIMER_NUM__			(8)


#define __AppTask10__						AppTask9


#define __AppTask11__						AppTask10


#define __AppTask12__						AppTask11


#define __AppTask13__						AppTask12


#define __AppTask14__						AppTask13


#define __AppTask15__						AppTask14


#define __AppTask16__						AppTask15


#define __AppTask1__						AppTask1


#define __AppTask2__						AppTask2


#define __AppTask5__						AppTask4


#define __AppTask6__						AppTask5


#define __AppTask7__						AppTask6


#define __AppTask8__						AppTask7


#define __AppTask9__						AppTask8


#define __BSP_BOARD_H__


#define __BSP_CACHE_H__


#define __BSP_CONFIG_H__


#define __BSP_CORE_H__


#define __BSP_CORE_V7_DEF_H__


#define __BSP_CORE_V7_H__


#define __BSP_CORE_V7_MACRO_H__


#define __BSP_CORE_V7_SET_H__


#define __BSP_CPU_TIMER_H__


#define __BSP_CPU_UART_H__


#define __BSP_CPU_WDT_H__


#define __BSP_DATA_H__


#define __BSP_DEF_H__


#define __BSP_EMIF_H__


#define __BSP_EMIF_SET_H__


#define __BSP_GPIO_H__


#define __BSP_HOOK_H__


#define __BSP_INT_H__


#define __BSP_IO_H__


#define __BSP_MACRO_H__


#define __BSP_PRINT_H__


#define __BSP_SDRAM_H__


#define __BSP_SET_H__


#define __BSP_SPW_CLAP_H__


#define __BSP_SRAM_H__


#define __BSP_TRAP_H__


#define __ComNum__	2


#define __ComNum__	3


#define __DAKB_ENABLE__						(0)


#define __DATA_END__			LITTLE_ENDIAN


#define __DOUBLE__


#define __DRV_ADDA_H__


#define __DRV_BIT_H__


#define __DRV_CAN_H__


#define __DRV_COM_H__


#define __DRV_CSB_H__


#define __DRV_DEFEND_H__


#define __DRV_Def_BIT_IN_H__
#include "DRV_BIT.h"


#define __DRV_Def_BIT_OUT_H__
#include "DRV_BIT.h"


#define __DRV_Def_Header_H__
#include "DRV_Def_IO.h"


#define __DRV_Def_IO_H__
#include "DRV_BIT.h"


#define __DRV_Def_Msg_H__
#include "UTILStd.h"


#define __DRV_Def_PULSE_OUT_H__
#include "DRV_BIT.h"


#define __DRV_Def_Time_H__
#include "DRV_BIT.h"


#define __DRV_Def_UART_H__
#include "DRV_BIT.h"


#define __DRV_NORFLASH_256TYPE_H__


#define __DRV_NORFLASH_H__


#define __DRV_NORFLASH_TYPE_H__


#define __DRV_PARAM_H__


#define __DRV_PULSE_H__


#define __DRV_SPI_H__


#define __DRV_SSI_H__


#define __DRV_TIME_H__


#define __DRV_UART_H__


#define __DRV_UsrDef_H__


#define __FLOAT__


#define __GPIO_NUMBER__				(16)


#define __INT_1553B_0_FUNC__				SYS_ISR_Default_Hook


#define __INT_1553B_1_FUNC__				SYS_ISR_Default_Hook


#define __INT_GPIO_4_FUNC__					SYS_ISR_Default_Hook


#define __INT_GPIO_5_FUNC__					ISR_AOCCSycPeriod


#define __INT_IOASIC_0_FUNC__				SYS_ISR_Default_Hook


#define __INT_IOASIC_1_FUNC__				SYS_ISR_Default_Hook


#define __INT_IOASIC_2_FUNC__				SYS_ISR_Default_Hook


#define __INT_SPW_0_FUNC__					SYS_ISR_Default_Hook


#define __INT_SPW_1_FUNC__					SYS_ISR_Default_Hook


#define __INT_SPW_2_FUNC__					SYS_ISR_Default_Hook


#define __INT_SPW_3_FUNC__					SYS_ISR_Default_Hook


#define __IN_RNGLIB_H__


#define __MEM_CONFIG_H__


#define __MEM_H__


#define __OSCONFIG_H__


#define __OSCONSOLE_H__


#define __OSDEF_H__


#define __OSERRNO_H__


#define __OSINCLUDEALL_H__


#define __OSINFOREC_H__
#include "UTILStd.h"


#define __OSINTA_H__


#define __OSINT_H__


#define __OSKERNEL_H__


#define __OSMEM_H__


#define __OSMQ_H__


#define __OSSEM_H__


#define __OSTASK_H__


#define __OSTIME_H__


#define __OS_CONSOLE_EN__ 				0


#define __OS_MEM_USED_COMPUTE__ 		0


#define __OS_MQ_EN__ 					0


#define __OS_RRSCHED_EN__				1


#define __OS_SCHED_REC_EN__ 			0


#define __OS_SEM_EN__ 					0


#define __OS_STACK_REC_EN__ 			0


#define __OS_TIME_EN__ 					1


#define __OS_TIME_JDE_EN__				0


#define __QLIB_H__


#define __STD_1553_CONF_H__


#define __STD_HASH_H__


#define __STD_LIST_H__


#define __STD_SORT_CONF_H__


#define __STD_SORT_H__


#define __SYSCALL_H__


#define __SYS_CONTROL_MEM__


#define __SYS_HOOK_H__


#define __SYS_INFO_H__


#define __SYS_INTERFACE_H__


#define __SYS_LIB_HOOK_H__


#define __SYS_MACRO_H__


#define __SYS_MEM_REFRESH_H__


#define __SYS_NORFLASH_H__


#define __SYS_PARAM_DEF_H__


#define __SYS_ROM_H__


#define __SYS_SPACELIB_H__


#define __SYS_TASKCONFIG_H__


#define __SYS_TASK_H__


#define __SYS_TM_HANDLER_H__


#define __SYS_TR32_INFO_H__


#define __SYS_TRAP_HANDLER_H__


#define __SYS_TRAP_HOOK_H__


#define __SYS_USR_DEF_H__


#define __SYS_VARIABLES_H__


#define __SYS_WATCH_DOG_H__


#define __TEST_BSP_H__


#define __TEST_INTERFACE_H__


#define __TEST_INT_TRAP_H__


#define __Tolerant_ERR_H__


#define __UART_NUM__				(2)


#define __UPD_INFO_H__


#define __USE_FUDANWEI_SMALLSECTOR__	(0)


#define __USE_REPAIR_BUFFER__						(1)


#define __USE_REPAIR_ERRORINFO_BUFFER__ 			(0)


#define __UTIL_LIB_H__


#define __UTIL_STD_H__


#define check_even 							(1<<3)|(0x1<<4)


#define check_odd							(1<<3)|(0x0<<4)


#define container_of(address, type, field) \
            ((type *)((char *)(address) - offsetof(type, field)))


#define csMw_CVoltageEnCodeMax (0xFFFu)


#define csMw_ControlVoltageMax ((float64)(9.99512))


#define csMw_ControlVoltageMin ((float64)(-10.0))


#define csMw_PulseQueueCap (16u)


#define data_5_bit							(0x0)


#define data_6_bit							(0x1)


#define data_7_bit							(0x2)


#define data_8_bit							(0x3)


#define flag 0


#define flag 1


#define freq 400


#define hash_find(pos, table, userkey, type_of)     \
    do {                                            \
            list_for_each_entry(pos, type_of, &table[hash_key(table, userkey)], list) \
            {                                       \
                if (pos->key == userkey) {break;}   \
            }                                       \
            if ((&pos->list) == (&table[hash_key(table, userkey)])) {pos = 0;}        \
        } while (0)


#define hash_init(node) INIT_LIST_HEAD(&node)


#define hash_insert(table, cell)  list_add_tail(&(cell.list), &(table[hash_key(table, cell.key)]))


#define hash_key(table, userkey)    (userkey % ARRAY_SIZE(table))


#define inline __inline


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


#define monaddr 0xA00D0050


#define monbit 0xc


#define no_check							(0x0<<3)


#define norwpaddr 0xA00D0000


#define norwpbit 0


#define offsetof(type, field)    ((int)&((type *)0)->field)


#define outWdtaddr 0xA00D0000


#define outWdtbit 0x8


#define poweronaddr 0xA00D0050


#define poweronbit 0xd


#define progdestaddr 0x40018000


#define progsize 0x00040000


#define progsize 0x00080000


#define progsize 0x00100000


#define progsize 0x80000


#define progsrcaddr1 0x08040000


#define progsrcaddr1 0x08100000


#define progsrcaddr1 0x08600000


#define progsrcaddr2 0x080C0000


#define progsrcaddr2 0x080E0000


#define progsrcaddr2 0x08160000


#define progsrcaddr2 0x08300000


#define progsrcaddr2 0x08800000


#define progsum1 0xdeadbeef


#define progsum2 0xdeadbeef


#define r16(addr)				(*(volatile U16 *)(addr))


#define r32(addr)				(*(volatile U32 *)(addr))


#define r8(addr)				(*(volatile U8 *)(addr))


#define rcvr_1_int							(0x0)


#define rcvr_full_int						(0x3)


#define rcvr_half_half_int					(0x1)


#define rcvr_half_int						(0x2)


#define readSPW(spwBaseAddr,offsetAddr)			(Bsp_IO_Read((spwBaseAddr) + (offsetAddr)))


#define softResetaddr 0xA00D0000


#define softResetbit 0xb


#define stop_1_5_bit						(0x1<<2)


#define stop_1_bit							(0x0<<2)


#define stop_2_bit							(0x1<<2)


#define tcResetAddr 0x40017A00


#define tcResetBit 0x0


#define tet_1_int							(0x1)


#define tet_empty_int						(0x0)


#define tet_half_half_int					(0x2)


#define tet_half_int						(0x3)


#define uart_ref_clk						(0<<0)


#define uart_ref_clk_div8					(0x1<<0)


#define uploadcfgaddr 0x0


#define uploadcfgaddr 0x081A0000


#define uploadcfgaddr 0x08580000


#define uploadmode 0x55555555


#define w16(addr, val)			(*(volatile U16 *)(addr)= (val))


#define w32(addr, val)			(*(volatile U32 *)(addr)= (val))


#define w8(addr, val)			(*(volatile U8 *)(addr)= (val))


#define work_pattern_reg				(0x7D)


#define writeSPW(spwBaseAddr,offsetAddr, val)	Bsp_IO_Write(((spwBaseAddr) + (offsetAddr)), (U32)(val))




enum _tte_unit_id_ { TTE_UNIT_A = 0x0, TTE_UNIT_B, TTE_UNIT_C };

typedef enum
{
	COMDIAG_INDEX_SADA_B = 0u,
	COMDIAG_INDEX_STS_B = COMDIAG_INDEX_SADA_B + (NUM_SADAGR * 2),
	COMDIAG_INDEX_GYRO_B = COMDIAG_INDEX_STS_B + NUM_STGR,
	COMDIAG_INDEX_ACC_B = COMDIAG_INDEX_GYRO_B + NUM_GYRGR,
	COMDIAG_INDEX_CSROH_B = COMDIAG_INDEX_ACC_B + NUM_ACCGR,
	COMDIAG_INDEX_IACU_B = COMDIAG_INDEX_CSROH_B + (NUM_CSR_OH_ACQ * 2u),
	COMDIAG_INDEX_TPAE_B = COMDIAG_INDEX_IACU_B + (NUM_COMPART * 2),
	COMDIAG_INDEX_EPCU_B = COMDIAG_INDEX_TPAE_B + 2u,
	COMDIAG_INDEX_PCU_B = COMDIAG_INDEX_EPCU_B + 2u,
	COMDIAG_INDEX_ACAM_B = COMDIAG_INDEX_PCU_B + 2u,
	COMDIAG_INDEX_END = COMDIAG_INDEX_ACAM_B + NUM_ACAM,
} CS_COMDIAG_INDEX;

typedef enum
{
    ECSS_ATR_BUSY_FREE = 0,
    ECSS_ATR_BUSY_RESET,
    ECSS_ATR_BUSY_Q_AOCC_IMP,
    ECSS_ATR_BUSY_TM_CONVERT,
    ECSS_ATR_BUSY_S_MEMDOWN,
    ECSS_ATR_BUSY_S_AOCC_IMP,
    ECSS_ATR_BUSY_REQ_LAUNCH,
    ECSS_ATR_BUSY_S_PART_PWR,
} CS_ECSS_ATR_BUSY_T;

typedef enum
{
    ECSS_PID_ATTCTRLFASTDATA = 0,
    ECSS_PID_ATTSLOWDATA,
    ECSS_PID_CABATT1SLOWDATA,
    ECSS_PID_CABATT2SLOWDATA,
    ECSS_PID_CABATTFLAGDATA,
    ECSS_PID_OCSADADATA,
    ECSS_PID_JETFASTDATA,
    ECSS_PID_JETSLOWDATA,
    ECSS_PID_WACQDATA,
    ECSS_PID_CABATT3SLOWDATA,
    ECSS_PID_ACCDATA,
    ECSS_PID_ETDATA,
    ECSS_PID_SYSWORKCOND,
    ECSS_PID_PARTWORKCOND,
    ECSS_PID_ORBITDATA,
    ECSS_PID_RMSDATA,
    ECSS_PID_VICTRLDATA,
    ECSS_PID_ATTCTRLMWDATA,
    ECSS_PID_STEADYSADADATA,
    ECSS_PID_ATTIASSIT,
    ECSS_PID_IMP_REQAOCC,
    ECSS_PID_REQ_TMCONVERT,
    ECSS_PID_S_MEMDOWN,
    ECSS_PID_IMP_SENDAOCC,
    ECSS_PID_REQ_LAUNCH,
    ECSS_PID_S_PART_PWR,
} CS_ECSS_TM_PID_T;

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
    NO_HC = 0u,
    WAIT_HC,
    EXEC_HC,
    CLOSE_HC,
    HOLD_HC,
    LOCK_HC,
    DONE_HC,
    ROTOR_S_HC,
    ROTOR_D_HC,
} CMG_HUNT_CIRCLE_P;

typedef enum
{
    PART_MW = 0,
    PART_CMG,
    PART_SADA,
    PART_STS,
    PART_GYRO,
    PART_ACC,
    PART_CSROH,
    PART_SLV,
    PART_THR,
    PART_IACU,
    PART_TPAP,
    PART_TPAE,
    PART_PCU,
    PART_EPCU,
    PART_ACAM,
    APP_PWR_PART_NUM,
} PART_TYPE;

typedef enum
{
    PWRRESERVE = 0,

    PWR_INDEX_MW_1_ON,
    PWR_INDEX_MW_2_ON,
    PWR_INDEX_MW_3_ON,
    PWR_INDEX_MW_4_ON,
    PWR_INDEX_MW_5_ON,
    PWR_INDEX_MW_6_ON,
    PWR_INDEX_MW_7_ON,
    PWR_INDEX_MW_8_ON,
    PWR_INDEX_MW_9_ON,
    PWR_INDEX_MW_10_ON,
    PWR_INDEX_MW_11_ON,
    PWR_INDEX_MW_12_ON,

    PWR_INDEX_MW_1_OFF,
    PWR_INDEX_MW_2_OFF,
    PWR_INDEX_MW_3_OFF,
    PWR_INDEX_MW_4_OFF,
    PWR_INDEX_MW_5_OFF,
    PWR_INDEX_MW_6_OFF,
    PWR_INDEX_MW_7_OFF,
    PWR_INDEX_MW_8_OFF,
    PWR_INDEX_MW_9_OFF,
    PWR_INDEX_MW_10_OFF,
    PWR_INDEX_MW_11_OFF,
    PWR_INDEX_MW_12_OFF,

    PWR_INDEX_CMG_1_ON,
    PWR_INDEX_CMG_2_ON,
    PWR_INDEX_CMG_3_ON,
    PWR_INDEX_CMG_4_ON,
    PWR_INDEX_CMG_5_ON,
    PWR_INDEX_CMG_6_ON,
    PWR_INDEX_CMG_7_ON,
    PWR_INDEX_CMG_8_ON,

    PWR_INDEX_CMG_1_OFF,
    PWR_INDEX_CMG_2_OFF,
    PWR_INDEX_CMG_3_OFF,
    PWR_INDEX_CMG_4_OFF,
    PWR_INDEX_CMG_5_OFF,
    PWR_INDEX_CMG_6_OFF,
    PWR_INDEX_CMG_7_OFF,
    PWR_INDEX_CMG_8_OFF,

    PWR_INDEX_SADA_1_M_ON,
    PWR_INDEX_SADA_2_M_ON,
    PWR_INDEX_SADA_3_M_ON,
    PWR_INDEX_SADA_4_M_ON,
    PWR_INDEX_SADA_1_B_ON,
    PWR_INDEX_SADA_2_B_ON,
    PWR_INDEX_SADA_3_B_ON,
    PWR_INDEX_SADA_4_B_ON,

    PWR_INDEX_SADA_1_M_OFF,
    PWR_INDEX_SADA_2_M_OFF,
    PWR_INDEX_SADA_3_M_OFF,
    PWR_INDEX_SADA_4_M_OFF,
    PWR_INDEX_SADA_1_B_OFF,
    PWR_INDEX_SADA_2_B_OFF,
    PWR_INDEX_SADA_3_B_OFF,
    PWR_INDEX_SADA_4_B_OFF,

    PWR_INDEX_STS_1_ON,
    PWR_INDEX_STS_2_ON,
    PWR_INDEX_STS_3_ON,
    PWR_INDEX_STS_4_ON,
    PWR_INDEX_STS_5_ON,
    PWR_INDEX_STS_6_ON,
    PWR_INDEX_STS_7_ON,
    PWR_INDEX_STS_8_ON,
    PWR_INDEX_STS_9_ON,

    PWR_INDEX_STS_1_OFF,
    PWR_INDEX_STS_2_OFF,
    PWR_INDEX_STS_3_OFF,
    PWR_INDEX_STS_4_OFF,
    PWR_INDEX_STS_5_OFF,
    PWR_INDEX_STS_6_OFF,
    PWR_INDEX_STS_7_OFF,
    PWR_INDEX_STS_8_OFF,
    PWR_INDEX_STS_9_OFF,

    PWR_INDEX_GYRO_1_ON,
    PWR_INDEX_GYRO_2_ON,
    PWR_INDEX_GYRO_3_ON,
    PWR_INDEX_GYRO_4_ON,
    PWR_INDEX_GYRO_5_ON,
    PWR_INDEX_GYRO_6_ON,
    PWR_INDEX_GYRO_7_ON,
    PWR_INDEX_GYRO_8_ON,
    PWR_INDEX_GYRO_9_ON,
    PWR_INDEX_GYRO_10_ON,
    PWR_INDEX_GYRO_11_ON,
    PWR_INDEX_GYRO_12_ON,

    PWR_INDEX_GYRO_1_OFF,
    PWR_INDEX_GYRO_2_OFF,
    PWR_INDEX_GYRO_3_OFF,
    PWR_INDEX_GYRO_4_OFF,
    PWR_INDEX_GYRO_5_OFF,
    PWR_INDEX_GYRO_6_OFF,
    PWR_INDEX_GYRO_7_OFF,
    PWR_INDEX_GYRO_8_OFF,
    PWR_INDEX_GYRO_9_OFF,
    PWR_INDEX_GYRO_10_OFF,
    PWR_INDEX_GYRO_11_OFF,
    PWR_INDEX_GYRO_12_OFF,

    PWR_INDEX_ACC_1_ON,
    PWR_INDEX_ACC_2_ON,
    PWR_INDEX_ACC_3_ON,

    PWR_INDEX_ACC_1_OFF,
    PWR_INDEX_ACC_2_OFF,
    PWR_INDEX_ACC_3_OFF,

    PWR_INDEX_CSROH_A_ON,
    PWR_INDEX_CSROH_B_ON,
    PWR_INDEX_CSROH_C_ON,
    PWR_INDEX_CSROH_D_ON,

    PWR_INDEX_CSROH_A_OFF,
    PWR_INDEX_CSROH_B_OFF,
    PWR_INDEX_CSROH_C_OFF,
    PWR_INDEX_CSROH_D_OFF,

    PWR_INDEX_TPAE_M_ON,
    PWR_INDEX_TPAE_B_ON,

    PWR_INDEX_TPAE_M_OFF,
    PWR_INDEX_TPAE_B_OFF,

    PWR_INDEX_CMG_1_RESET,
    PWR_INDEX_CMG_2_RESET,
    PWR_INDEX_CMG_3_RESET,
    PWR_INDEX_CMG_4_RESET,
    PWR_INDEX_CMG_5_RESET,
    PWR_INDEX_CMG_6_RESET,
    PWR_INDEX_CMG_7_RESET,
    PWR_INDEX_CMG_8_RESET,

    PWR_INDEX_ISOLATION_AREA,

    PWR_INDEX_THR_ADIPM_ON,
    PWR_INDEX_THR_ADIPB_ON,
    PWR_INDEX_THR_AC_ON,
    PWR_INDEX_THR_BD_ON,
    PWR_INDEX_THR_CIPA_ON,
    PWR_INDEX_THR_CIPB_ON,
    PWR_INDEX_THR_750N_M_SW_ON,
    PWR_INDEX_THR_750N_B_SW_ON,
    PWR_INDEX_SLV_1_4_ON,
    PWR_INDEX_SLV_5_ON,
    PWR_INDEX_SLV_6_ON,
    PWR_INDEX_SLV_9_ON,
    PWR_INDEX_SLV_10_ON,
    PWR_INDEX_SLV_11_ON,
    PWR_INDEX_SLV_12_ON,
    PWR_INDEX_SLV_13_ON,
    PWR_INDEX_SLV_2_3_ON,
    PWR_INDEX_SLV_7_ON,
    PWR_INDEX_SLV_8_ON,
    PWR_INDEX_SLV_101_ON,
    PWR_INDEX_SLV_102_ON,
    PWR_INDEX_SLV_107_ON,
    PWR_INDEX_THR_750N_M_DRV_ON,
    PWR_INDEX_THR_750N_B_DRV_ON,
    PWR_INDEX_SLV_108_ON,
    PWR_INDEX_SLV_109_ON,
    PWR_INDEX_SLV_110_ON,

    PWR_INDEX_THR_ADIPM_OFF,
    PWR_INDEX_THR_ADIPB_OFF,
    PWR_INDEX_THR_AC_OFF,
    PWR_INDEX_THR_BD_OFF,
    PWR_INDEX_THR_CIPA_OFF,
    PWR_INDEX_THR_CIPB_OFF,
    PWR_INDEX_THR_750N_M_SW_OFF,
    PWR_INDEX_THR_750N_B_SW_OFF,
    PWR_INDEX_SLV_1_4_OFF,
    PWR_INDEX_SLV_5_OFF,
    PWR_INDEX_SLV_6_OFF,
    PWR_INDEX_SLV_9_OFF,
    PWR_INDEX_SLV_10_OFF,
    PWR_INDEX_SLV_11_OFF,
    PWR_INDEX_SLV_12_OFF,
    PWR_INDEX_SLV_13_OFF,
    PWR_INDEX_SLV_2_3_OFF,
    PWR_INDEX_SLV_7_OFF,
    PWR_INDEX_SLV_8_OFF,
    PWR_INDEX_SLV_101_OFF,
    PWR_INDEX_SLV_102_OFF,
    PWR_INDEX_SLV_107_OFF,
    PWR_INDEX_THR_750N_M_DRV_OFF,
    PWR_INDEX_THR_750N_B_DRV_OFF,
    PWR_INDEX_SLV_108_OFF,
    PWR_INDEX_SLV_109_OFF,
    PWR_INDEX_SLV_110_OFF,

    PWR_INDEX_ISOLATION_AREA_2,

    PWR_INDEX_IACUA_M_ON,
    PWR_INDEX_IACUB_M_ON,
    PWR_INDEX_IACUC_M_ON,
    PWR_INDEX_IACUA_B_ON,
    PWR_INDEX_IACUB_B_ON,
    PWR_INDEX_IACUC_B_ON,

    PWR_INDEX_IACUA_M_OFF,
    PWR_INDEX_IACUB_M_OFF,
    PWR_INDEX_IACUC_M_OFF,
    PWR_INDEX_IACUA_B_OFF,
    PWR_INDEX_IACUB_B_OFF,
    PWR_INDEX_IACUC_B_OFF,

    PWR_INDEX_PCU_M_ON,
    PWR_INDEX_PCU_B_ON,

    PWR_INDEX_PCU_M_OFF,
    PWR_INDEX_PCU_B_OFF,

    PWR_INDEX_EPCU_M_ON,
    PWR_INDEX_EPCU_B_ON,

    PWR_INDEX_EPCU_M_OFF,
    PWR_INDEX_EPCU_B_OFF,

    PWR_INDEX_ACAM_A_ON,
    PWR_INDEX_ACAM_B_ON,
    PWR_INDEX_ACAM_C_ON,
    PWR_INDEX_ACAM_D_ON,
    PWR_INDEX_ACAM_E_ON,

    PWR_INDEX_ACAM_A_OFF,
    PWR_INDEX_ACAM_B_OFF,
    PWR_INDEX_ACAM_C_OFF,
    PWR_INDEX_ACAM_D_OFF,
    PWR_INDEX_ACAM_E_OFF,

    PWR_INDEX_ISOLATION_AREA_3,

    PWR_INDEX_TPAP1_ON,
    PWR_INDEX_TPAP2_ON,
    PWR_INDEX_TPAP3_ON,
    PWR_INDEX_TPAP4_ON,

    PWR_INDEX_TPAP1_OFF,
    PWR_INDEX_TPAP2_OFF,
    PWR_INDEX_TPAP3_OFF,
    PWR_INDEX_TPAP4_OFF,

    PWR_INDEX_ISOLATION_AREA_4,

    PWR_INDEX_THR_750N_M_VAR_OFF,
    PWR_INDEX_THR_750N_B_VAR_OFF,

    PWR_INDEX_TOTAL,

} CS_PWR_INDEX;

typedef enum
{
    REF_ORBIT = 0,
    REF_DN = 1
} REF_FRAME_TYPE;

typedef enum
{
    THRGR_ID_2a = 0u,
    THRGR_ID_2b = 1u,
    THRGR_ID_3a = 2u,
    THRGR_ID_3b = 3u,
    THRGR_ID_4a = 4u,
    THRGR_ID_4b = 5u,
    THRGR_ID_5a = 6u,
    THRGR_ID_5b = 7u,
    THRGR_ID_6a = 8u,
    THRGR_ID_6b = 9u,
    THRGR_ID_7a = 10u,
    THRGR_ID_7b = 11u,

    THRGR_ID_2c = 12u,
    THRGR_ID_2d = 13u,
    THRGR_ID_3c = 14u,
    THRGR_ID_3d = 15u,
    THRGR_ID_4c = 16u,
    THRGR_ID_4d = 17u,
    THRGR_ID_5c = 18u,
    THRGR_ID_5d = 19u,
} THRGR_ID_INDEX;

typedef enum TAG_AOCS_FILTER_TYPE
{
    SFILTER_DIRECT = 0x00u,
    SFILTER_F11 = 0x0Fu,
    SFILTER_F12_F22 = 0xF0u,
} SFilterType;

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
