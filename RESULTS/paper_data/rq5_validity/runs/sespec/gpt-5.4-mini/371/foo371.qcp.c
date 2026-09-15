#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo371(int value, int p, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (c >= 1) &&
    (value < 1 || c <= value + 1) &&
    (result == 0 || (1 <= result && result < c)) &&
    (result == 0 || (result % p) == z) &&
    (forall (i:Z), 1 <= i && i < c && (i % p) == z => i <= result) &&
    (value < 1 || (c <= value + 1 && (result == 0 || (1 <= result && result <= value))))
    */
for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
}