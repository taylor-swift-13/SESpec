#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (product_mod_10 : Z -> Z -> Z) */
int foo333(int n, int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
		
 	/*@ Inv
    (c == c@pre) &&
    (n == n@pre)
    */
for (int var = n + 1; var < c + 1; var++) {
            result = (result * (var % 10)) % 10;
        }
			return result % 10;
		}
}