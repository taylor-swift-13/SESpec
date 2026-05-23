#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo159(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (0 <= ret) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < ret => (args_l[k] <= 0 || args_l[k] > array || args_l[k] == k + 1)) &&
    (forall (v:Z), 0 <= v && v <= array => count_eq(args, 0, ret, v) == count_eq(args@pre, 0, ret, v))
    */
while (ret < array) {
        if (args[ret] <= 0 || args[ret] > array || args[ret] == ret + 1) {
            ret++;
        } else {
            int j = args[ret];
            args[ret] = args[j - 1];
            args[j - 1] = j;
        }
    }
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (forall (k:Z), 0 <= k && k < ret => args_l[k] == k + 1) &&
    (forall (v:Z), 0 <= v && v <= array => count_eq(args, 0, array, v) == count_eq(args@pre, 0, array, v)) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre)
    */
for (ret = 0; ret < array; ret++) {
        if (args[ret] != ret + 1) {
            return ret + 1;
        }
    }
		return array + 1;
}