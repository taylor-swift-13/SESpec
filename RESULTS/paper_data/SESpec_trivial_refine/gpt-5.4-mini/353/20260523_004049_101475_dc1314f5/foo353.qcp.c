#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo353(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int max = 0;
		int sum = num;
	
 	/*0*/ 
 /*@ Inv
    (result >= 0) &&
    (max >= 0) &&
    (result == 0 || sum <= num)
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