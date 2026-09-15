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
    (0 <= arr_len => -1 <= stop && stop <= arr_len - 1) &&
    (0 <= arr_len => 0 <= ret && ret <= arr_len) &&
    ((ret <= stop) => (0 <= ret && stop < arr_len)) &&
    ((ret <= stop) => (ret <= (ret + (stop - ret) / 2) <= stop)) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((ret == 0 && stop == arr_len@pre - 1) || (ret >= 1 || stop <= arr_len@pre - 2) || (ret > stop)) &&
    ((0 <= arr_len@pre - 1) => (ret == 0 || (0 <= ret && ret <= stop + 1))) &&
    ((0 <= arr_len@pre - 1) => (-1 <= stop && stop <= arr_len@pre - 1)) &&
    ((!(0 <= arr_len@pre - 1)) => ((stop == arr_len@pre - 1)&&(ret == 0)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
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