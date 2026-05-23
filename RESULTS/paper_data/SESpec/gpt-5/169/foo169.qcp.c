#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (0 <= arr_len) &&
    (-1 <= stop && stop <= arr_len - 1) &&
    (0 <= r && r <= arr_len) &&
    (r <= stop + 1) &&
    ((r <= stop) => (0 <= r && stop < arr_len)) &&
    ((r <= stop) => (r <= r + (stop - r) / 2 <= stop)) &&
    (arr == arr@pre) &&
    (arr_len == arr_len@pre) &&
    ((forall (k:Z), 0 <= k && k < arr_len => true)) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
while (r <= stop) {
        int i = r + (stop - r) / 2;
        if (i < stop
                && arr[i] > arr[i + 1]) {
            return i + 1;
        } else if (i > r
                && arr[i] < arr[i - 1]) {
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