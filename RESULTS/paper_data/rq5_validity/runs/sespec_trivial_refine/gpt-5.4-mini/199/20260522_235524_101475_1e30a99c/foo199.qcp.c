#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo199(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 1;
	
 	/*0*/ 
 /*@ Inv
    (PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS) &&
    (1 <= c && c <= number + 1) &&
    (arr[0] == 1) &&
    (forall (k:Z), 1 <= k && k < c => arr[k] == \sum integer i 0 <= i && i < k arr[i] * arr[k - i - 1])
    */
for (int c = 1; c <= number; c++) {
			arr[c] = 0;
		
 	/*1*/ 
 /*@ Inv
    (0 <= n && n <= c) &&
    (arr[c] == \sum integer i 0 <= i && i < n arr[i] * arr[c - i - 1])
    */
for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
		}
		return arr[number];
}