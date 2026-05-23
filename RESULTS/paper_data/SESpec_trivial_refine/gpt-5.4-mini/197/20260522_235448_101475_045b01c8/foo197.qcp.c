#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo197(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
	
 	/*0*/ 
 /*@ Inv
    (1 <= c && c <= n + 1) &&
    (arr[0] == 1) &&
    (forall (i:Z), 0 <= i && i < c && i > 0 => arr[i] == \sum(integer j = 0 j < i arr[j] * arr[i - j - 1]))
    */
for (int c = 1; c <= n; c++) {
			arr[c] = 0;
		
 	/*1*/ 
 /*@ Inv
    (0 <= k && k <= c) &&
    (arr[c] == \sum(integer i = 0 i < k arr[i] * arr[c - i - 1]))
    */
for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
		}
		return arr[n];
}