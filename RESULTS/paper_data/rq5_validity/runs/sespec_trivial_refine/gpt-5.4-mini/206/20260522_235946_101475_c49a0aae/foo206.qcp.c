#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo206(int * args, int args_len, int * arr, int arr_len, int array);

int foo206(int * args, int args_len, int * arr, int arr_len, int array) 
/*@
With args_l arr_l
Require store_int_array(args, args_len, args_l) && store_int_array(arr, arr_len, arr_l)
Ensure (exists args_l_93 arr_l_90 r_86, __return < args_len && r_86 >= arr_len && __return < args_len && 0 <= __return && __return <= args_len && 0 <= r_86 && r_86 <= arr_len && store_int_array(args, args_len, args_l_93) * store_int_array(arr, arr_len, arr_l_90)) || (exists args_l_93 arr_l_90 ret_87, ret_87 >= args_len && ret_87 >= args_len && 0 <= ret_87 && ret_87 <= args_len && 0 <= __return && __return <= arr_len && store_int_array(args, args_len, args_l_93) * store_int_array(arr, arr_len, arr_l_90))
*/
{

		int ret = 0;
		int r = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  args_l arr_l,    
    store_int_array(args, args_len, args_l) && store_int_array(arr, arr_len, arr_l) &&
    (0 <= ret && ret <= args_len) &&
    (0 <= r && r <= arr_len)
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