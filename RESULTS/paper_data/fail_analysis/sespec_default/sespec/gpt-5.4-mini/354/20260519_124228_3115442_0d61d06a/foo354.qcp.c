#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo354(int num);

int foo354(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
		int result = 0;
		int sum = num;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= even) &&
(sum == num@pre >> even) &&
(num == num@pre
          loop assigns result, sum, even)
    */
    
            while (sum > 0) {
			if (even % 2 == 1) {
				result |= (1 << even);
			}
			even++;
			sum >>= 1;
		}
		return (num | result);
}