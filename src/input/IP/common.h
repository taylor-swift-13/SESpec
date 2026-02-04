/**
 * @file common.h
 * @brief 自动提取的项目全局宏和枚举定义
 * @note 此文件由 create_common_h.py 脚本自动生成于 2025-12-05 14:38:59
 */

 #ifndef AUTO_GENERATED_COMMON_H
 #define AUTO_GENERATED_COMMON_H
 
 /* --- 自动提取的宏定义 (MACROS) --- */
 
 #define     ReadReg(Addr)                (ADDR_READ(Addr))
 
 
 #define  FALSE32                    0x00  /* زٶ */
 
 
 #define  FLT32_ZERO                 1.0E-6
 
 
 #define  TRUE32                     0x90  /* ز涨 */
 
 
 #define ABS(a)                  	(((a) > 0) ? (a) : -(a))
 
 
 #define ADDR_AD_START				0xA000		/* ַ0xA000ADת */
 
 
 #define ADDR_READ(addr)             (*((volatile unint32 *)(addr)))
 
 
 #define ADDR_STATE				    0xE000		/* SP */
 
 
 #define ADDR_WRITE(addr, value)     {(*((volatile unint32 *)(addr))) = (value);}
 
 
 #define AD_SS_GYRO_HI8				0xA001		/* A/Dת12λ,0xA001D[7:0]8λ */
 
 
 #define AD_SS_GYRO_LO4				0xA003		/* A/Dת12λ,0xA003D[7:4]4λ */
 
 
 #define DIVIATION_TO_FLOAT_DSS(x)	DiviationToFloat((x), 0xFFF, 0x800, 2.44140625e-3f)  /*  5/2048 -5~5 */
 
 
 #define DIVIATION_TO_FLOAT_FOG(x)   DiviationToFloat((x), 0xFFF, 0x800, 9.765625e-4f)      /*    1/1024 */
 
 
 #define DIVIATION_TO_FLOAT_GYRO(x)  DiviationToFloat((x), 0xFFF, 0x800, 1.62760417e-3f)    /*  5/3072 -2.5~2.5/S  */
 
 
 #define FALSE           			0x00
 
 
 #define FST_BIAS_WXRO       		((volatile float32 *)0x7D18)
 
 
 #define FST_BIAS_WYPI       		((volatile float32 *)0x7D1C)
 
 
 #define FST_FLGMODE					((volatile unint08 *)0x7D00)
 
 
 #define FST_FT_HEALTHWORD      	    ((volatile unint32 *)0x7D24)
 
 
 #define MIN(a, b)                   (((a) > (b)) ? (b) : (a))
 
 
 #define NOCTRL						0x44	/*  */
 
 
 #define PS_C000						0xC000		/* ̫ȵԴ״̬ */
 
 
 #define RAM_VALIDATE(addr)      ((0x0  <= (addr)) && ((addr) <= 0x7FFF))
 
 
 #define SAM_CRUISE          		0x33	/* SAMѲʽ */
 
 
 #define SAM_DAMP            		0x00	/* SAM᷽ʽ */
 
 
 #define SAM_PITCH           		0x11	/* SAMʽ */
 
 
 #define SAM_ROLL            		0x22	/* SAMʽ */
 
 
 #define SND_BIAS_WXRO       		((volatile float32 *)0x7E6C)
 
 
 #define SND_BIAS_WYPI       		((volatile float32 *)0x7E70)
 
 
 #define SND_FLGMODE					((volatile unint08 *)0x7E54)
 
 
 #define SND_FT_HEALTHWORD       	((volatile unint32 *)0x7E78)
 
 
 #define TBS_A               		0x00     /* ѡA֧ */
 
 
 #define TBS_AB              		0xCC     /* ѡAB֧ */
 
 
 #define TBS_B               		0x33     /* ѡB֧ */
 
 
 #define TR16_VALUE(pA,pB,pC,nval)   {*(pA) = (nval);    *(pB) = (nval);    *(pC) = (nval);}
 
 
 #define TR32_BIAS_WXRO()			Tr32Float(FST_BIAS_WXRO, SND_BIAS_WXRO, TRD_BIAS_WXRO)
 
 
 #define TR32_BIAS_WXRO_VALUE(x)		TR32_VALUE(FST_BIAS_WXRO, SND_BIAS_WXRO, TRD_BIAS_WXRO, (x))
 
 
 #define TR32_BIAS_WYPI()			Tr32Float(FST_BIAS_WYPI, SND_BIAS_WYPI, TRD_BIAS_WYPI)
 
 
 #define TR32_BIAS_WYPI_VALUE(x)		TR32_VALUE(FST_BIAS_WYPI, SND_BIAS_WYPI, TRD_BIAS_WYPI, (x))
 
 
 #define TR32_FLGMODE()				Tr32Uint08(FST_FLGMODE, SND_FLGMODE, TRD_FLGMODE)
 
 
 #define TR32_FLGMODE_VALUE(x)		TR32_VALUE(FST_FLGMODE, SND_FLGMODE, TRD_FLGMODE, (x))
 
 
 #define TR32_FT_HEALTHWORD()		Tr32Uint(FST_FT_HEALTHWORD, SND_FT_HEALTHWORD, TRD_FT_HEALTHWORD)
 
 
 #define TR32_VALUE(pA,pB,pC,nval)   {*(pA) = (nval);    *(pB) = (nval);    *(pC) = (nval);}
 
 
 #define TRD_BIAS_WXRO       		((volatile float32 *)0x7FC0)
 
 
 #define TRD_BIAS_WYPI       		((volatile float32 *)0x7FC4)
 
 
 #define TRD_FLGMODE					((volatile unint08 *)0x7FA8)
 
 
 #define TRD_FT_HEALTHWORD       	((volatile unint32 *)0x7FCC)
 
 
 #define TRUE            			0xEB
 
 
 #define UI16_HI8(ui16)                  (((ui16) >>  8) & MASK_LOLO_08)
 
 
 #define UI16_LO8(ui16)                  (((ui16)      ) & MASK_LOLO_08)
 
 
 #define UI32_HIHI8(ui32)                (((ui32) >> 24) & MASK_LOLO_08)
 
 
 #define UI32_HILO8(ui32)                (((ui32) >> 16) & MASK_LOLO_08)
 
 
 #define UI32_LOHI8(ui32)                (((ui32) >>  8) & MASK_LOLO_08)
 
 
 #define UI32_LOLO8(ui32)                (((ui32)      ) & MASK_LOLO_08)
 
 
 #define USCFR                    0x00C3 /* fifoλĴ */
 
 
 #define USCNTR3                  0x00D2 /* FIFOĴ                                                     */
 
 
 #define USDR3                    0x00D3 /* USݼĴ */
 
 
 #define USDR5                    0x00DB /* USݼĴ                                                       */
 
 
 #define WR_FST_FT_HEALTHWORD(x)    {*(FST_FT_HEALTHWORD) = (x);}
 
 
 #define WR_SND_FT_HEALTHWORD(x)    {*(SND_FT_HEALTHWORD) = (x);}
 
 
 #define WR_TRD_FT_HEALTHWORD(x)    {*(TRD_FT_HEALTHWORD) = (x);}
 
 
 #define WriteAsicReg(addr, value)       (ADDR_READ(addr) = (value))            /* ASICĴд */
 
 
 #define zrm 1
 
 
 #endif // AUTO_GENERATED_COMMON_H
 