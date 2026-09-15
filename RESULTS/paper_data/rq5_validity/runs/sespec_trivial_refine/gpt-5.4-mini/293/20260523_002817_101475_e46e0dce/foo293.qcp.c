#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo293(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 0;
		arr[1] = 1;
	
 	/*@ Inv
    (p >= 2) &&
    (arr[0] == 0 && arr[1] == 1) &&
    (forall (i:Z), 2 <= i && i < p => arr[i] == (2 * arr[i - 1] + arr[i - 2]) % 1000000000)
    */
for (int p = 2; p <= seed; p++) {
		arr[p] = (2 * arr[p - 1] + arr[p - 2]) % 1000000000;
	}
		return arr[seed];
}