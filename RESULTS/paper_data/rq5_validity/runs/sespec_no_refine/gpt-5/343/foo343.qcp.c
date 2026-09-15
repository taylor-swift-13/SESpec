#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo343(int code, int b, int l, int c);

int foo343(int code, int b, int l, int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (ret == count_not_divisible(l, loop - 1, code)) &&
(0 <= ret) &&
((loop >= l) => (ret <= (loop - l))) &&
((loop <= c@pre) => (ret + (((loop % code) != 0) ? 1 : 0) == count_not_divisible(l, loop, code))) &&
((loop <= c@pre) => (ret <= (loop - l@pre))) &&
(c == c@pre) &&
(l == l@pre) &&
(b == b@pre) &&
(code == code@pre
          loop assigns loop, ret)
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