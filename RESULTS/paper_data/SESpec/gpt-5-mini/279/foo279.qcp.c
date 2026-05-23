#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo279(int * args, int args_len);

int foo279(int * args, int args_len) 
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
    (1 <= j && j <= args_len) &&
((j < args_len@pre) => (exists (k:Z), 0 <= k && k < j && ret == args_l[k])) &&
((j < args_len@pre) => (((ret == args_l[0])&&(g == 0)&&(args_len == args_len@pre)&&(args == args@pre)) || (exists (k:Z), 0 <= k && k < j && ret == args_l[k]))) &&
(args_len == args_len@pre) &&
(args == args@pre) &&
(forall (t:Z), 0 <= t && t < args_len => args_l[t] == args_l[t]@pre 
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