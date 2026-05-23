#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo207(int * args, int args_len, int * arr, int arr_len, int array);

int foo207(int * args, int args_len, int * arr, int arr_len, int array) 
/*@
With args_l arr_l
Require store_int_array(args, args_len, args_l) && store_int_array(arr, arr_len, arr_l)
Ensure (exists args_l_93 arr_l_90 len_86, __return < args_len && len_86 >= arr_len && __return < args_len && 0 <= __return && __return <= args_len && 0 <= len_86 && len_86 <= arr_len && store_int_array(args, args_len, args_l_93) * store_int_array(arr, arr_len, arr_l_90)) || (exists args_l_93 arr_l_90 ret_87, ret_87 >= args_len && ret_87 >= args_len && 0 <= ret_87 && ret_87 <= args_len && 0 <= __return && __return <= arr_len && store_int_array(args, args_len, args_l_93) * store_int_array(arr, arr_len, arr_l_90))
*/
{

		int ret = 0;
		int len = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  args_l arr_l,    
    store_int_array(args, args_len, args_l) && store_int_array(arr, arr_len, arr_l) &&
    (0 <= ret && ret <= args_len) &&
    (0 <= len && len <= arr_len)
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