#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (sorted : Z -> Z -> Z -> Prop) */
int foo169(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int r = 0;
		int stop = arr_len - 1;
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
while (r <= stop) {
        int i = r + (stop - r) / 2;
        if (i < stop && arr[i] > arr[i + 1]) {
            return i + 1;
        } else if (i > r && arr[i] < arr[i - 1]) {
            return i;
        }
        if (arr[i] >= arr[r]) {
            r = i + 1;
        } else {
            stop = i - 1;
        }
    }
		return 0;
}