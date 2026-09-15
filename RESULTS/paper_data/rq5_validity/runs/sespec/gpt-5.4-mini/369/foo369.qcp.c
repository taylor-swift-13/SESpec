#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo369(int value, int p, int dy) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (0 <= result) &&
    (result == 0 || (1 <= result && result < c)) &&
    (result == 0 || result % p == dy) &&
    (result == 0 || (forall (k:Z), 1 <= k && k < c => k % p != dy || k <= result)) &&
    ((exists (k:Z), 1 <= k && k < c && k % p == dy) => result != 0) &&
    ((exists (k:Z), 1 <= k && k < c && k % p == dy) => result % p == dy) &&
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