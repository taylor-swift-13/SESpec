#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo94_c235(int * arr, int arr_len);

int foo94_c235(int * arr, int arr_len) 
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
    (1 <= n && n <= arr_len) &&
((n < arr_len) => result == max_prefix(arr, 0, n)) &&
((n < arr_len) => sum == min_prefix(arr, 0, n)) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (v:Z), count_eq(arr, 0, arr_len, v) == \at(count_eq(arr, 0, arr_len, v), Pre)
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