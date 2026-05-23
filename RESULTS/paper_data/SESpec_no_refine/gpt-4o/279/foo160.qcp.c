#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo160(int * args, int args_len);

int foo160(int * args, int args_len) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int g = 0;
		int ret = args[0];
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (1 <= j && j <= args_len@pre) &&
(args_len == args_len@pre) &&
(args == args@pre
      loop assigns j, g, ret)
    */
    
    for (int j = 1; j < args_len; j++) {
        if (args[j] > ret) {
            g = g > ret ? g : ret;
        } else {
            ret = args[j];
        }
    }
		return g;
}