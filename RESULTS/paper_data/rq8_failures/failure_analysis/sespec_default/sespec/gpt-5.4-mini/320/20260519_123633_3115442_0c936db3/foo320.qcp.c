#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo320(int n, int y);

int foo320(int n, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (ret > 0) &&
(ret <= l) &&
(n % ret == 0 && y % ret == 0) &&
(g == 1
          loop assigns l, ret)
    */
    
            for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		g = (n * y) / ret;
		return g;
}