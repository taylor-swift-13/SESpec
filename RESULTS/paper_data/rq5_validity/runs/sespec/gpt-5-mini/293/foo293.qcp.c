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
    (2 <= p && p <= seed + 1) &&
    (0 <= arr[0] && arr[0] < 1000000000) &&
    (0 <= arr[1] && arr[1] < 1000000000) &&
    (forall (k:Z), 2 <= k && k < p => arr[k] == ((2 * arr[k-1] + arr[k-2]) % 1000000000)) &&
    ((!(p <= seed)) => (p == seed + 1))
    */
for (int p = 2; p <= seed; p++) {
		arr[p] = (2 * arr[p - 1]
				+ arr[p - 2]) % 1000000000;
	}
		return arr[seed];
}