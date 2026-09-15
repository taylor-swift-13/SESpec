#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo21(int * arr, int arr_len);

int foo21(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int stop = arr_len - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= ret) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (i:Z), 0 <= i && i < arr_len@pre => arr_l[i] == arr_l[i]@pre) &&
((0 <= arr_len@pre - 1) => (((stop == arr_len@pre - 1)&&(ret == 0)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (0 <= ret && ret <= stop + 1))) &&
((0 <= arr_len@pre - 1) => (((stop == arr_len@pre - 1)&&(ret == 0)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (-1 <= stop && stop < arr_len@pre))) &&
((!(0 <= arr_len@pre - 1)) => ((stop == arr_len@pre - 1)&&(ret == 0)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (i:Z), 0 <= i && i < arr_len@pre => arr_l[i] == arr_l[i]@pre
          loop assigns ret, stop)
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