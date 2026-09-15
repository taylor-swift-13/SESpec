#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (pow4 : Z -> Z) */
/*@ Extern Coq (sum_pow4 : Z -> Z) */
int foo397(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
	
 	/*@ Inv
    (p == p@pre) &&
    (1 <= c) &&
    ((p >= 0) => (c <= p + 1)) &&
    (0 <= even) &&
    (even == 16 * sum_pow4(c - 1)) &&
    ((c > p) => (even == 16 * sum_pow4(p)))
    */
for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}