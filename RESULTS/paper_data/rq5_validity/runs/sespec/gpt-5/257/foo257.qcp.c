#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo257(int * args, int args_len, int array) 
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
    (0 <= ret && ret <= args_len@pre) &&
    (-1 <= top && top < args_len@pre) &&
    (ret <= top + 1) &&
    (forall (k:Z), 0 <= k && k < args_len@pre => args_l[k] == args_l[k]@pre) &&
    ((0 <= args_len@pre - 1) => (ret <= top + 1)) &&
    ((0 <= args_len@pre - 1) => (((top == args_len@pre - 1)&&(ret == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (0 <= ret && ret <= args_len@pre))) &&
    ((0 <= args_len@pre - 1) => (((top == args_len@pre - 1)&&(ret == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (-1 <= top && top < args_len@pre))) &&
    ((!(0 <= args_len@pre - 1)) => ((top == args_len@pre - 1)&&(ret == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre)
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