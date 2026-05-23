#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_nd : Z -> Z -> Z -> Z) */
int foo342(int code, int b, int l, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (l <= c && c <= m + 1) &&
    ((c <= m && b > 0) => result < b) &&
    (m == m@pre) &&
    (l == l@pre) &&
    (b == b@pre) &&
    (code == code@pre)
    */
for (int c = l; c <= m; c++) {
		if (c % code != 0) {
			result++;
		}
		if (result == b) {
			return c;
		}
	}
		return -1;
}