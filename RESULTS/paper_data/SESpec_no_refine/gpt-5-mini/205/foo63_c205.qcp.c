#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo63_c205(int * args, int args_len, int * arr, int arr_len, int Array);

int foo63_c205(int * args, int args_len, int * arr, int arr_len, int Array) 
/*@
With args_l arr_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 && store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int len = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
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