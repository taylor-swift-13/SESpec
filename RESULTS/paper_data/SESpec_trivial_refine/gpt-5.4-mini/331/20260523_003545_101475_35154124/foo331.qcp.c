#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prod_mod10 : Z -> Z -> Z) */
int foo331(int n, int c) 
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
    (n + 1 <= index) &&
    (-9 <= result && result <= 9)
    */
for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
			return result % 10;
		}
}