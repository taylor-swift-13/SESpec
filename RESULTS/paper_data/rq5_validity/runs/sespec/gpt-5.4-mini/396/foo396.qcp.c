#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum4 : Z -> Z) */
int foo396(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (c <= p@pre + 1 || p@pre < 0) &&
    (even == 16 * sum4(c - 1)) &&
    ((c <= p@pre) => (even == 16 * sum4(c - 1))) &&
    (p == p@pre)
    */
for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
}