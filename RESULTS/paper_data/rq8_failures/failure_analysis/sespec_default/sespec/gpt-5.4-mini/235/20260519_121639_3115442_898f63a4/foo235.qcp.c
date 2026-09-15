#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo235(int * arr, int arr_len);

int foo235(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int result = arr[0];
		int sum = arr[0];
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((n < arr_len@pre) => (result >= arr_l[0] && sum <= arr_l[0])) &&
((n < arr_len@pre) => (((sum == arr_l[0])&&(result == arr_l[0])&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (result >= arr_l[0]))) &&
((n < arr_len@pre) => (((sum == arr_l[0])&&(result == arr_l[0])&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (sum <= arr_l[0]))) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre
          loop assigns n, result, sum)
    */
    
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
		return result - sum;
}