#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo277(int * arg, int arg_len);

int foo277(int * arg, int arg_len) 
/*@
With arg_l
Require store_int_array(arg, arg_len, arg_l) && arg_len > 0 && arg_len < 100
Ensure Results(__return)
*/{

		int g = 0;
		int ret = arg[0];
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arg_l,    
    store_int_array(arg, arg_len, arg_l) && arg_len > 0 && arg_len < 100 &&
    ((j < arg_len@pre) => (g == 0 || g >= ret)) &&
(arg_len == arg_len@pre) &&
(arg == arg@pre) &&
(forall (k:Z), 0 <= k && k < arg_len@pre => arg_l[k] == arg_l[k]@pre
          loop assigns j, g, ret)
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