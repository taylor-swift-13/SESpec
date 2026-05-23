#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_div : Z -> Z -> Z) */
int foo374(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int div = 0;
	
 	/*@ Inv
    (1 <= c && c <= number@pre + 1) &&
    (0 <= div && div <= c - 1) &&
    (div == count_div(number@pre, c - 1)) &&
    (number == number@pre)
    */
for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }
		return div;
}