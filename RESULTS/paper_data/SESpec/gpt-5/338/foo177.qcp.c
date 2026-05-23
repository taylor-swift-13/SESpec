#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo177(int num);

int foo177(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (\true
          loop assigns j, result, num)
    */
    
            for (int j = 2; j <= num; j++) {

        /* >>> LOOP INVARIANT TO FILL <<< */

        /*@
          loop invariant \true;
          loop assigns result, num;
        */
        while (num % j == 0) {
            result = j;
            num /= j;
        }

    }
		return result;
}