#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo255(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int result = 0;
		int top = args_len - 1;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (forall (k:Z), 0 <= k && k < args_len@pre => args_l[k] == args_l[k]@pre) &&
    ((0 <= args_len@pre - 1) => (0 <= result && result <= args_len@pre && -1 <= top && top <= args_len@pre - 1 && result <= top + 1)) &&
    ((0 <= args_len@pre - 1) => (((top == args_len@pre - 1)&&(result == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (0 <= result && result <= args_len@pre))) &&
    ((0 <= args_len@pre - 1) => (((top == args_len@pre - 1)&&(result == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (-1 <= top && top <= args_len@pre - 1))) &&
    ((!(0 <= args_len@pre - 1)) => ((top == args_len@pre - 1)&&(result == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < args_len@pre => args_l[k] == args_l[k]@pre)
    */
while (result <= top) {
			int i = (result + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				result = i + 1;
			} else {
				top = i - 1;
			}
		}
		return result;
}