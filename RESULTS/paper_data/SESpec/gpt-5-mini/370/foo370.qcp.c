#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo370(int value, int k, int z) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    ((result == 0) || (result % k == z)) &&
    (forall (x:Z), 1 <= x && x < c => ( (x % k == z) => (result >= x) )) &&
    ((exists (x:Z), 1 <= x && x < c && (x % k == z)) => (result != 0)) &&
    (z == z@pre) &&
    (k == k@pre) &&
    (value == value@pre)
    */
for (int c = 1; c <= value; c++) {
		if ((c % k) == z) {
			result = c;
		}
	}
		return result;
}