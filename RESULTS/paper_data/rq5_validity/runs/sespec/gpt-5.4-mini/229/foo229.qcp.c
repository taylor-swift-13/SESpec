#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */

int foo229(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 1;
	
 	/*0*/ 
 /*@ Inv
    (1 <= d && d <= seed + 1) &&
    (arr[0] == 1) &&
    (d <= arr_len) &&
    (forall (k:Z), 0 <= k && k < d => arr[k] >= 1) &&
    (forall (k:Z), 0 < k && k < d => arr[k] == sum(arr, 0, k + 1)) &&
    (!(d <= seed) => d == seed + 1)
    */
for (int d = 1; d <= seed; d++) {
		
 	/*1*/ 
 /*@ Inv
    (forall (k:Z), 0 <= k && k < d => arr[k] >= 1) &&
    (arr[d] >= arr[d]@pre) &&
    (0 <= c && c <= d) &&
    (arr[d] == arr[d]@pre + sum(arr, 0, c))
    */
for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[seed];
}