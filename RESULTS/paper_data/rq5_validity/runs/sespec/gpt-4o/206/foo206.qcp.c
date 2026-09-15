#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo206(int * args, int args_len, int * arr, int arr_len, int array) 
/*@
With args_l arr_l
Require store_int_array(args, args_len, args_l) && store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int r = 0;
	
 	/*@ Inv
    exists  args_l arr_l,    
    store_int_array(args, args_len, args_l) && store_int_array(arr, arr_len, arr_l) &&
    (0 <= ret && ret <= args_len) &&
    (0 <= r && r <= arr_len) &&
    (forall (k:Z), 0 <= k && k < ret => (exists (j:Z), 0 <= j && j < r && args_l[k] == arr_l[j]) || (forall (j:Z), 0 <= j && j < r => args_l[k] != arr_l[j])) &&
    (forall (k:Z), 0 <= k && k < r => (exists (j:Z), 0 <= j && j < ret && arr_l[k] == args_l[j]) || (forall (j:Z), 0 <= j && j < ret => arr_l[k] != args_l[j])) &&
    (forall (k:Z), 0 <= k && k < ret => args_l[k] == args_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < r => arr_l[k] == arr_l[k]@pre) &&
    (array == array@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre)
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