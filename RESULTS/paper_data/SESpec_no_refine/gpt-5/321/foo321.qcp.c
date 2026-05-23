#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo321(int n, int y);

int foo321(int n, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (r == 1
          loop assigns l, ret)
    */
    
            for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		r = (n * y) / ret;
		return r;
}