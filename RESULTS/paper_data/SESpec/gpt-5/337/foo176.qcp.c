#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo176(int num);

int foo176(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (j >= 2) &&
(ret == 0 || (ret >= 2 && ret <= j)
          loop assigns j, ret, num)
    */
    
            for (int j = 2; j <= num; j++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant j >= 2;
              loop invariant num >= 1;
              loop invariant ret == 0 || (ret >= 2 && ret <= j);
              loop assigns ret, num;
            */
            while (num % j == 0) {
				ret = j;
				num /= j;
			}
            
		}
		return ret;
}