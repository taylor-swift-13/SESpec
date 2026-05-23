#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo260(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int stop = array - 1;
	
 	/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    ((ret <= stop) => (0 <= ret && stop < array@pre)) &&
    ((0 <= array@pre - 1) => (((stop == array@pre - 1)&&(ret == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (0 <= ret && ret <= array@pre))) &&
    ((0 <= array@pre - 1) => (((stop == array@pre - 1)&&(ret == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre)) || (-1 <= stop && stop <= array@pre - 1))) &&
    ((!(0 <= array@pre - 1)) => ((stop == array@pre - 1)&&(ret == 0)&&(array == array@pre)&&(args_len == args_len@pre)&&(args == args@pre))) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre) &&
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre)
    */
while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return -1;
}