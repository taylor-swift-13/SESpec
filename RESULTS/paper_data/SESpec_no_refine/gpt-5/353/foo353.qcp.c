#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo353(int num);

int foo353(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
		int sum = num;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((num@pre > 0) => (sum == (num@pre >> result))) &&
((num@pre > 0) => (result >= 0)) &&
((num@pre > 0) => (max == odd_mask(result))) &&
((!(num@pre > 0)) => ((sum == num@pre)&&(max == 0)&&(result == 0)&&(num == num@pre))) &&
(num == num@pre
          loop assigns max, sum, result)
    */
    
            while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | max);
}