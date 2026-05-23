#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_fourth_powers : Z -> Z) */
int foo397(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
	
 	/*@ Inv
    (1 <= c && c <= p + 1) &&
    (p == p@pre) &&
    (even >= 0) &&
    (even % 2 == 0) &&
    (even == sum_fourth_powers(c - 1)) &&
    ((c > p@pre) => (even == sum_fourth_powers(p@pre))) &&
    ((c <= p@pre) => (even % 2 == 0))
    */
for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}