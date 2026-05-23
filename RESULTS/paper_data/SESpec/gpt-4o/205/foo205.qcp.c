#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo205(int * args, int args_len, int * arr, int arr_len, int Array) 
/*@
With args_l arr_l
Require store_int_array(args, args_len, args_l) && store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int len = 0;
	
 	/*@ Inv
    exists  args_l arr_l,    
    store_int_array(args, args_len, args_l) && store_int_array(arr, arr_len, arr_l) &&
    ((0 < args_len@pre && 0 < arr_len@pre) => (ret + len <= args_len + arr_len)) &&
    ((!(0 < args_len@pre && 0 < arr_len@pre)) => ((len == 0)&&(ret == 0)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (Array == Array@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre)
    */
while (ret < args_len && len < arr_len) {
        if (args[ret] < arr[len]) {
            ret++;
        } else if (args[ret] > arr[len]) {
            len++;
        } else {
            ret++;
            len++;
        }
    }
		return ret < args_len ? ret : len;
}