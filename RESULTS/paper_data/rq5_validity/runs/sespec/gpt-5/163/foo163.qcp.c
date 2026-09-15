#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (is_even : Z -> Prop) */
/*@ Extern Coq (cnt_even_pairs_prefix : Z -> Z -> Z -> Z) */

int foo163(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= arr_len) &&
    (0 <= evenPairCount <= (arr_len * (arr_len - 1)) / 2) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => 0 <= arr_l[k] && arr_l[k] <= 100) &&
    (evenPairCount == cnt_even_pairs_prefix(arr, arr_len, i)) &&
    ((i == 0) => (evenPairCount == 0)) &&
    ((i < arr_len) => (evenPairCount <= cnt_even_pairs_prefix(arr, arr_len, i + 1))) &&
    ((i == arr_len) => (evenPairCount == cnt_even_pairs_prefix(arr, arr_len, arr_len)))
    */
for (int i = 0; i < arr_len; i++) {
		
 	/*1*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= arr_len) &&
    (evenPairCount >= 0)
    */
for (int c = i + 1; c < arr_len; c++) {
				int odd = arr[i];
				int b = arr[c];
				int even = odd ^ b;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
}