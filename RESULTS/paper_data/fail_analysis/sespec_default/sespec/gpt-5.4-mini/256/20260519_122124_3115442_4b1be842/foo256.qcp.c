#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo256(int * args, int args_len, int Array);

int foo256(int * args, int args_len, int Array) 
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
    ((0 <= args_len@pre - 1) => (0 <= ret && ret <= top + 1)) &&
((!(0 <= args_len@pre - 1)) => ((top == args_len@pre - 1)&&(ret == 0)&&(Array == Array@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
(Array == Array@pre) &&
(args_len == args_len@pre) &&
(args == args@pre
          loop assigns ret, top)
    */
    
            while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
}