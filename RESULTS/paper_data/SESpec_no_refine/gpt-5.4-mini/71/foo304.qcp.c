#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo304(int num, int c, int r);

int foo304(int num, int c, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((r@pre > 0) => (r >= 0)) &&
((!(r@pre > 0)) => ((result == 0)&&(r == r@pre)&&(c == c@pre)&&(num == num@pre))) &&
(c == c@pre
          loop assigns r, num, result)
    */
    
            while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}