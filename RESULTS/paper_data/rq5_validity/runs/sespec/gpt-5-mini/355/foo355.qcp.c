#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo355(int num);

int foo355(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int end = 0;
		int sum = num;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((num@pre > 0) => (sum >= 0)) &&
((num@pre > 0) => (result >= 0)) &&
((!(num@pre > 0)) => ((sum == num@pre)&&(end == 0)&&(result == 0)&&(num == num@pre))) &&
(sum == num@pre || sum >= 0) &&
(num == num@pre
          loop assigns end, sum, result)
    */
    
            while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
		return (num | end);
}