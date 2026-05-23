#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo170(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int stop = arr_len - 1;
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= ret && ret <= arr_len) &&
    (0 <= stop && stop < arr_len) &&
    (ret <= stop + 1) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (exists (k:Z), ret <= k && k <= stop => arr_l[k] == arr_l[ret]) &&
    (exists (k:Z), ret <= k && k <= stop => arr_l[k] == arr_l[stop]) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
    */
while (ret <= stop) {
        int r = ret + (stop - ret) / 2;
        if (r < stop
                && arr[r] > arr[r + 1]) {
            return r + 1;
        } else if (r > ret
                && arr[r] < arr[r - 1]) {
            return r;
        }
        if (arr[r] >= arr[ret]) {
            ret = r + 1;
        } else {
            stop = r - 1;
        }
    }
		return 0;
}