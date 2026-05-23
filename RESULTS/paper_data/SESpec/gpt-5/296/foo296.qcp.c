#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo296(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
	
 	/*@ Inv
    (c >= 2) &&
    (result_len == seed + 1) &&
    (result[0] == 2) &&
    (result[1] == 1) &&
    (forall (k:Z), 2 <= k && k < c => result[k] == result[k - 1] + result[k - 2])
    */
for (int c = 2; c <= seed; c++) {
        result[c] = result[c - 1]
                    + result[c - 2];
    }
		return result[seed];
}