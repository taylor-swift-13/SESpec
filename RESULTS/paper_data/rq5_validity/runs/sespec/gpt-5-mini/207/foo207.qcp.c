#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq_int : Z -> Z -> Z -> Z -> Z) */
int foo207(int * args, int args_len, int * arr, int arr_len, int array) 
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
    (0 <= ret && ret <= args_len) &&
    (0 <= len && len <= arr_len) &&
    (exists (i:Z), 0 <= i && i < ret => (exists (j:Z), 0 <= j && j < len && args_l[i] == arr_l[j]) || (forall (k:Z), 0 <= k && k < len => args_l[i] != arr_l[k])) &&
    (forall (v:Z), count_eq_int(args, 0, ret, v) == count_eq_int(arr, 0, len, v) + (count_eq_int(args, 0, ret, v) - count_eq_int(arr, 0, len, v))) &&
    ((ret == args_len || len == arr_len) => (ret <= args_len && len <= arr_len)) &&
    (ret + len >= 0) &&
    ((0 < args_len@pre && 0 < arr_len@pre) => (ret >= 0 && len >= 0)) &&
    ((0 < args_len@pre && 0 < arr_len@pre) => (ret <= args_len@pre && len <= arr_len@pre)) &&
    ((0 < args_len@pre && 0 < arr_len@pre) => (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre)) &&
    ((0 < args_len@pre && 0 < arr_len@pre) => (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)) &&
    ((!(0 < args_len@pre && 0 < arr_len@pre)) => ((len == 0)&&(ret == 0)&&(array == array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (array == array@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre)
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