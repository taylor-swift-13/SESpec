#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (max_in_prefix : Z -> Z -> Z) */
/*@ Extern Coq (min_in_prefix : Z -> Z -> Z) */
int foo234(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int big = arr[0];
		int sum = arr[0];
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
for (int n = 1; n < arr_len; n++) {
        if (arr[n] > big) {
            big = arr[n];
        }
        if (arr[n] < sum) {
            sum = arr[n];
        }
    }
		return big - sum;
}