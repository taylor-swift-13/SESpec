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
    (0 <= ret) &&
    (forall (k:Z), 0 <= k && k < array@pre => args_l[k] == args_l[k]@pre) &&
    (array == array@pre) &&
    (args_len == args_len@pre) &&
    (args == args@pre)
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