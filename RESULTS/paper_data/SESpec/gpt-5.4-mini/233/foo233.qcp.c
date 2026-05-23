#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo233(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int result = arr[0];
		int num = arr[0];
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (1 <= n) &&
    (result >= num) &&
    (result >= arr_l[0]) &&
    (num <= arr_l[0]) &&
    (forall (k:Z), 0 <= k && k < n => arr_l[k] <= result) &&
    (forall (k:Z), 0 <= k && k < n => arr_l[k] >= num) &&
    (exists (k:Z), 0 <= k && k < n && arr_l[k] == result) &&
    (exists (k:Z), 0 <= k && k < n && arr_l[k] == num) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((n >= arr_len) => result - num >= 0)
    */
for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
		return result - num;
}