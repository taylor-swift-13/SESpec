#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo64(int * args, int args_len, int * arr, int arr_len, int array);

int foo64(int * args, int args_len, int * arr, int arr_len, int array) 
/*@
With args_l arr_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 && store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int r = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l arr_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 && store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((!(0 < args_len@pre && 0 < arr_len@pre)) => 
            ((r == 0)&&(ret == 0)&&(array == array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
(array == array@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(args_len == args_len@pre) &&
(args == args@pre
          loop assigns ret, r)
    */
    
        while (ret < args_len && r < arr_len) {
			if (args[ret] < arr[r]) {
				ret++;
			} else if (args[ret] > arr[r]) {
				r++;
			} else {
				ret++;
				r++;
			}
		}
		return ret < args_len ? ret : r;
}