#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo343(int code, int b, int l, int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    (l <= loop && loop <= c + 1) &&
    (ret >= 0) &&
    (c == c@pre) &&
    (l == l@pre) &&
    (b == b@pre) &&
    (code == code@pre) &&
    (forall (k:Z), l <= k && k < loop => (k % code != 0 => ret >= 1)) &&
    (forall (k:Z), l <= k && k < loop => (k % code != 0 => (exists (m:Z), m == ret)))
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