#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo120_c257(int * args, int args_len, int array);

int foo120_c257(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int top = args_len - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (0 <= ret && ret <= args_len@pre) &&
(-1 <= top && top <= args_len@pre - 1) &&
(ret <= top + 1) &&
(array == array@pre) &&
(args_len == args_len@pre) &&
(args == args@pre) &&
(forall (v:Z), count_eq(args, 0, args_len, v) == \at(count_eq(args, 0, args_len, v), Pre)
          loop assigns ret, top)
    */
    
            while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
}