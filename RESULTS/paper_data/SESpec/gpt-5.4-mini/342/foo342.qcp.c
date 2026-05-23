#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_nondiv : Z -> Z -> Z -> Z) */
int foo342(int code, int b, int l, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (c >= l) &&
    (0 <= result) &&
    (result == count_nondiv(code, l, c - 1)) &&
    (0 <= result && result <= c - l) &&
    (result == 0 || (exists (i:Z), l <= i && i < c && i % code != 0)) &&
    (m == m@pre) &&
    (l == l@pre) &&
    (b == b@pre) &&
    (code == code@pre) &&
    ((c > m) => (result == count_nondiv(code, l, m)))
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