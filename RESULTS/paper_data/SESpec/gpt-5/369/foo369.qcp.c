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
    ((value@pre >= 1) => (c <= value@pre + 1)) &&
    ((value@pre < 1) => (c == 1)) &&
    (dy == dy@pre) &&
    (p == p@pre) &&
    (value == value@pre) &&
    (result == 0 || (1 <= result && result < c)) &&
    (result == 0 || (result % p) == dy) &&
    (forall (k:Z), (1 <= k && k < c) => (((k % p) == dy) => (k <= result))) &&
    (forall (k:Z), (result < k && k < c) => ((k % p) != dy))
    */
for (int c = 1; c <= value; c++) {
        if ((c % p) == dy) {
            result = c;
        }
    }
		return result;
}