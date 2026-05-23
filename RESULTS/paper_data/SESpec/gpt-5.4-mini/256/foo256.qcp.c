#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo256(int * args, int args_len, int Array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int top = args_len - 1;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    ((0 <= args_len@pre - 1) => (ret <= top + 1)) &&
    ((0 <= args_len@pre - 1) => (((top == args_len@pre - 1)&&(ret == 0)&&(Array == Array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (ret <= top + 1))) &&
    ((!(0 <= args_len@pre - 1)) => ((top == args_len@pre - 1)&&(ret == 0)&&(Array == Array@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (Array == Array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre)
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