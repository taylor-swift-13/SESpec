#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo394(int num);

int foo394(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((loop <= num@pre) => (num@pre == num)) &&
(num == num@pre
      loop assigns loop, ret)
    */
    
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }
		int result = (int) (ret % 100);
		return result;
}