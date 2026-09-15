#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo387(int num, int c, int r);

int foo387(int num, int c, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (\true) &&
(c == c@pre) &&
((!(r@pre > 0)) => ((ret == 0)&&(r == r@pre)&&(c == c@pre)&&(num == num@pre))) &&
(c == c@pre
          loop assigns r, num, ret)
    */
    
        while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
		return ret;
}