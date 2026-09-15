#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo144(int * args, int args_len, int array);

int foo144(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int start = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (array == array@pre) &&
(args_len == args_len@pre) &&
(args == args@pre
      loop assigns index, ret, start)
    */
    
    for (int index = 0; index < array; index++) {
        if (args[index] % 2 != 0) {
            start++;
            if (start % 2 != 0) {
                ret = args[index];
            }
        }
    }
		return ret;
}