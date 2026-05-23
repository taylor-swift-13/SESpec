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
    ((result != 0) => ((result % k@pre) == z@pre)) &&
    ((result != 0) => (forall (t:Z), result < t && t <= c - 1 => (t % k@pre) != z@pre)) &&
    ((forall (t:Z), 1 <= t && t <= c - 1 => (((t % k@pre) == z@pre) => t <= (result == 0 ? 0 : result)))) &&
    ((c == value@pre + 1) => ((result == 0) || ((result % k@pre) == z@pre && (forall (t:Z), result < t && t <= value@pre => (t % k@pre) != z@pre)))) &&
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