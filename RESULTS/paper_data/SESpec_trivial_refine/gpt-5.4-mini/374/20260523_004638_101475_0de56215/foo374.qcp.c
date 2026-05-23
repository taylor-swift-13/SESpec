#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (nb_div : Z -> Z -> Z) */
int foo374(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*@ Inv
    (div == nb_div(number, c - 1)) &&
    (c >= 1)
    */
for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				div++;
			}
		}
		return div;
}