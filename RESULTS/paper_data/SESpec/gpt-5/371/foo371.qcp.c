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
    (z == z@pre) &&
    (p == p@pre) &&
    (value == value@pre) &&
    (result != 0 => (result % p) == z) &&
    (result == 0 => forall (k:Z), 1 <= k && k < c => (k % p) != z) &&
    (result != 0 => (forall (k:Z), result < k && k < c => (k % p) != z)) &&
    ((c <= value@pre) => (result == 0 || (result % p) == z))
    */
for (int c = 1; c <= value; c++) {
        if ((c % p) == z) {
            result = c;
        }
    }
		return result;
}