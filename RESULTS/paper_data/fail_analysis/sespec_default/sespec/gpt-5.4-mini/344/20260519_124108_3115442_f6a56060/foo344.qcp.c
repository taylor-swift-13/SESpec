#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo344(int code, int b, int l, int m);

int foo344(int code, int b, int l, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (c >= l) &&
(0 <= ret) &&
(ret <= c - l) &&
(m == m@pre) &&
(l == l@pre) &&
(b == b@pre) &&
(code == code@pre
          loop assigns c, ret)
    */
    
            for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				ret++;
			}
			if (ret == b) {
				return c;
			}
		}
		return -1;
}