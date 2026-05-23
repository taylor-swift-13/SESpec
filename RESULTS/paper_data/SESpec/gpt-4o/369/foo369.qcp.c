#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (modulo : Z -> Z -> Z) */
int foo369(int value, int p, int dy) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (1 <= c && c <= value + 1) &&
    ((result == 0) || (1 <= result && result <= c - 1 && modulo(result, p) == dy)) &&
    (forall (k:Z), 1 <= k && k < c => ((modulo(k, p) == dy) => (result >= k))) &&
    (dy == dy@pre) &&
    (p == p@pre) &&
    (value == value@pre)
    */
for (int c = 1; c <= value; c++) {
        if ((c % p) == dy) {
            result = c;
        }
    }
		return result;
}