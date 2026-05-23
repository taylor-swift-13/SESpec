#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (dummy_predicate : Z -> Prop) */
int foo371(int value, int p, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (0 <= result) &&
    (result == 0 || (1 <= result && result < c && (result % p) == z)) &&
    (forall (i:Z), 1 <= i && i < c && (i % p) == z => i <= result)
    */
for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
}