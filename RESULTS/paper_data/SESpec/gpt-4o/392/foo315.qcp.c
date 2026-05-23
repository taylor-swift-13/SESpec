#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo315(int num);

int foo315(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= number && number <= num + 1) &&
(ret == factorial(number - 1)) &&
(num == num@pre
      loop assigns number, ret)
    */
    
    for (int number = 1; number <= num; number++) {
        ret *= number;
    }
		int result = (int) (ret % 100);
		return result;
}