#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo294(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (p + 1));
int arr_len = p + 1;
		arr[0] = 0;
		arr[1] = 1;
	
 	/*@ Inv
    (2 <= count && count <= p + 1) &&
    (forall (k:Z), 2 <= k && k < count => arr[k] == (2 * arr[k-1] + arr[k-2]) % 1000000000) &&
    ((count == p + 1) => (forall (k:Z), 2 <= k && k <= p => arr[k] == (2 * arr[k-1] + arr[k-2]) % 1000000000))
    */
for (int count = 2; count <= p; count++) {
		arr[count] = (2 * arr[count - 1]
				+ arr[count - 2]) % 1000000000;
	}
		return arr[p];
}