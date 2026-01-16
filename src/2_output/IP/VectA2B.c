
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

void VectA2B(float64 *ptrB, const float64 *ptrA, siint32 num)

/*@
With ptrB_l ptrA_l
Require store_int_array(ptrB, ptrA, ptrB_l) && ptrA > 0 && ptrA < 100 && store_int_array(ptrA, num, ptrA_l) && num > 0 && num < 100
Ensure emp
*/{

	siint32 si;


 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  ptrB_l ptrA_l,    
    store_int_array(ptrB, ptrA, ptrB_l) && ptrA > 0 && ptrA < 100 && store_int_array(ptrA, num, ptrA_l) && num > 0 && num < 100 &&
    (0 <= si && si <= num) &&
(forall (k:Z), 0 <= k && k < si => ptrB_l[k] == ptrA_l[k])
    */
    
	for(si=0; si<num; si++)
	{
		ptrB[si] = ptrA[si];
	}

	return;
}