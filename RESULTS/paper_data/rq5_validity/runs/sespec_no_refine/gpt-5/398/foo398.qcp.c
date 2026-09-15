#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo398(int number);

int foo398(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (ret >= 0) &&
(number <= number@pre
      loop assigns number, ret)
    */
    
    while (number > 0) {
        number /= 10;
        ret++;
    }
		return ret;
}