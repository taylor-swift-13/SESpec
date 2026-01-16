
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void Bsp_ClearGicPendInt(U32 isrNo)

/*@

Require emp
Ensure emp
*/{
	U32 i,m=0;
	V_U32 *mec = (V_U32 *)(BSP_GIC_ICD_BASEADDR);
	U32 itlinesNumber;

	if(isrNo == ALL_USR_ISR)
	{
		itlinesNumber = (mec[BSP_INTR_ICDICTR / 4] & 0x1f) + 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= i && i <= itlinesNumber) &&
(forall (j:Z), 0 <= j && j < i => mec_l[(BSP_INTR_ICDICPR + j * 4) / 4] == 0xffffffff)
    */
    
        for(i = 0; i < itlinesNumber; i++)
		{
			mec[ (BSP_INTR_ICDICPR + i * 4) / 4] = 0xffffffff;/*清指定挂起中断*/
		}
	}
	else
	{
		
		m = isrNo / 32;
		mec[ (BSP_INTR_ICDICPR + (m * 4))/4 ] = (U32)(1 << (isrNo % 32));
	}

	return;
}