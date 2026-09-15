#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (min_prefix : Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo277(int * arg, int arg_len) 
/*@
With arg_l
Require store_int_array(arg, arg_len, arg_l)
Ensure Results(__return)
*/{

		int g = 0;
		int ret = arg[0];
	
 	/*@ Inv
    exists  arg_l,    
    store_int_array(arg, arg_len, arg_l) &&
    (1 <= j && j <= arg_len) &&
    (0 <= g) &&
    (ret == min_prefix(arg, 0, j)) &&
    (exists (t:Z), 0 <= t && t < j && ret == arg_l[t]) &&
    (forall (k:Z), 0 <= k && k < arg_len => arg_l[k] == arg_l[k]@pre) &&
    ((!(j < arg_len)) => ( ret == min_prefix(arg,0,arg_len) ))
    */
for (int j = 1; j < arg_len; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
		return g;
}