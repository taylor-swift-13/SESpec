#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo92_c233(int * arr, int arr_len);

int foo92_c233(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int result = arr[0];
		int num = arr[0];
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (1 <= n && n <= arr_len) &&
(result == max_prefix(arr, n)) &&
(num == min_prefix(arr, n)) &&
(forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre
          loop assigns n, result, num)
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