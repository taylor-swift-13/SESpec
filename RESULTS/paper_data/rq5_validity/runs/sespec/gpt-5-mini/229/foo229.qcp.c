#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_slice : Z -> Z -> Z -> Z) */
int foo229(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 1;
	
 	/*@ Inv
    (1 <= d && d <= seed + 1) &&
    (arr[0] == 1) &&
    (forall (i:Z), 0 <= i && i < d => arr[i] >= 1) &&
    (forall (i:Z), 0 <= i && i < d => arr[i] == sum_slice(arr, 0, i+1))
    */
for (int d = 1; d <= seed; d++) {

        /*@
          loop invariant 0 <= c <= d;
          loop invariant \forall integer i; 0 <= i < d ==> arr[i] >= 1;
          loop assigns arr[0..seed];
        */
        /*@ Inv
    (0 <= c && c <= d) &&
    (forall (i:Z), 0 <= i && i < d => arr[i] >= 1)
    */
for (int c = 0; c < d; c++) {
            arr[d] = arr[d] + arr[c];
        }

    }
		return arr[seed];
}