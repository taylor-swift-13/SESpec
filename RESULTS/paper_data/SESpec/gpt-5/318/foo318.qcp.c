#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo318(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (num == 1)
			return 1;
	
 	/*@ Inv
    (2 <= c) &&
    (c <= num || num < 2) &&
    (0 <= result) &&
    (result <= (c >= 2 ? c - 2 : 0)) &&
    (forall (d:Z), 2 <= d && d < c => (num % d == 0 => d <= num))
    */
for (int c = 2; c <= num / c; c++) {
        if (num % c == 0) {
            result++;
            if (num / c == c) {
                break;
            }
        }
    }
		return result;
}