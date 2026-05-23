#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_nondiv : Z -> Z -> Z -> Z) */
int foo343(int code, int b, int l, int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    (0 <= ret) &&
    (l <= loop) &&
    (ret == count_nondiv(code, l, loop)) &&
    (ret <= loop - l) &&
    (code == code@pre) &&
    (b == b@pre) &&
    (c == c@pre) &&
    (l == l@pre)
    */
for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
		return -1;
}