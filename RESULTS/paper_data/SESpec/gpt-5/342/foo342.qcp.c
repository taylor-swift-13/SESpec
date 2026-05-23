#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo342(int code, int b, int l, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (l <= c) &&
    (0 <= result && result <= c - l) &&
    ((c == l) => (result == 0)) &&
    ((c <= m@pre) => (c >= l@pre)) &&
    ((c <= m@pre) => (0 <= result && result <= c - l@pre)) &&
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