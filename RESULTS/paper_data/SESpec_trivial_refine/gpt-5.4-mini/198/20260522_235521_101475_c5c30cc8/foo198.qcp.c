#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo198(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
int arr_len = c + 1;
		arr[0] = 1;
	
 	/*0*/ 
 /*@ Inv
    (1 <= cat && cat <= c + 1) &&
    (arr[0] == 1) &&
    (forall (i:Z), 0 <= i && i < cat => arr[i] >= 0)
    */
for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
		
 	/*1*/ 
 /*@ Inv
    (0 <= n && n <= cat) &&
    (arr[cat] == \sum integer k 0 <= k && k < n arr[k] * arr[cat - k - 1])
    */
for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
		}
		return arr[c];
}