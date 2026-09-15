#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo225(int * args, int args_len, int array);

int foo225(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (1 <= remaining && remaining <= array + 1) &&
(1 <= find && find <= remaining) &&
(count_mismatch(args, remaining - 1) == 0) &&
(forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre
          loop assigns remaining, find)
    */
    
        for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				find = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
		return find;
}