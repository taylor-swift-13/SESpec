#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo168(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int count = arr_len - 1;
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (ret <= count => (0 <= ret && ret <= arr_len - 1 && 0 <= count && count <= arr_len - 1)) &&
    (arr_len@pre == arr_len && arr@pre == arr) &&
    (count == arr_len - 1 || count < arr_len - 1) &&
    (ret <= count => (exists (r0:Z), r0 == ret + (count - ret)/2 && ret <= r0 && r0 <= count)) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((ret == arr_len || count == -1) => (ret > count))
    */
while (ret <= count) {
        int r = ret + (count - ret) / 2;
        if (r < count
                && arr[r] > arr[r + 1]) {
            return r + 1;
        } else if (r > ret
                && arr[r] < arr[r - 1]) {
            return r;
        }
        if (arr[r] >= arr[ret]) {
            ret = r + 1;
        } else {
            count = r - 1;
        }
    }
		return 0;
}