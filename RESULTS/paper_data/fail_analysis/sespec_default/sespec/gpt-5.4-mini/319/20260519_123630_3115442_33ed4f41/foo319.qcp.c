#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo319(int n, int y);

int foo319(int n, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (l == 1
          loop assigns j, ret)
    */
    
            for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
		l = (n * y) / ret;
		return l;
}