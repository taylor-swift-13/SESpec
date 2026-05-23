#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo217(int num);

int foo217(int num) 
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
((num@pre > 0) => (sum == (num@pre >> even))) &&
((!(num@pre > 0)) => ((sum == num@pre)&&(result == 0)&&(even == 0)&&(num == num@pre))) &&
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