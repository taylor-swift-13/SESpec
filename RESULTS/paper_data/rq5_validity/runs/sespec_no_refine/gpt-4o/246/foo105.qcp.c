#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo105(int * args, int args_len, int num);

int foo105(int * args, int args_len, int num) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int ret = 0;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int index = 0; index < num; index++) {
		
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (index + 1 <= k && k <= num) &&
(ret >= 0) &&
(\forall integer i, j 0 <= i && i < index && index <= j && j < k => args_l[i] <= args_l[j] => ret >= 0
          loop assigns k, ret)
    */
    
        for (int k = index + 1; k < num; k++) {
            if (args[index] > args[k]) {
                ret++;
            }
        }
		}
		return ret;
}