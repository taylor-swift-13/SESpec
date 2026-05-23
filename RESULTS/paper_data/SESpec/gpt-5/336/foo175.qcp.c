#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo175(int num);

int foo175(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (c >= 2) &&
(result == 0 || result <= c
          loop assigns c, result, num)
    */
    
            for (int c = 2; c <= num; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant c >= 2;
              loop invariant result == 0 || result <= c;
              loop assigns result, num;
            */
            while (num % c == 0) {
				result = c;
				num /= c;
			}
            
		}
		return result;
}