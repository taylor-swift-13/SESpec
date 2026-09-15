#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_non_divisible : Z -> Z -> Z -> Z) */
int foo344(int code, int b, int l, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    (m == m@pre) &&
    (l == l@pre) &&
    (b == b@pre) &&
    (code == code@pre)
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