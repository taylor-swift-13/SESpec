#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo158(int * arg, int arg_len);

int foo158(int * arg, int arg_len) 
/*@
With arg_l
Require store_int_array(arg, arg_len, arg_l) && arg_len > 0 && arg_len < 100
Ensure Results(__return)
*/{

		int g = 0;
		int ret = arg[0];
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int j = 1; j < arg_len; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
		return g;
}