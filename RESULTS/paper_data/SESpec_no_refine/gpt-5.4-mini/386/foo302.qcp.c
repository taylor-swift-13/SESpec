#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo302(int num, int b, int r);

int foo302(int num, int b, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((r@pre > 0) => (0 <= r && r <= r@pre)) &&
((!(r@pre > 0)) => ((result == 0)&&(r == r@pre)&&(b == b@pre)&&(num == num@pre))) &&
(b == b@pre
          loop assigns r, num, result)
    */
    
            while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
}