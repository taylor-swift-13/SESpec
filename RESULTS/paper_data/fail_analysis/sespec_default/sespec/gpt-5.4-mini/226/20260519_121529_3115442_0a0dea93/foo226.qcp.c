#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo226(int * args, int args_len, int array);

int foo226(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100
Ensure Results(__return)
*/{

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) && args_len > 0 && args_len < 100 &&
    (1 <= found && found <= remaining) &&
(forall (k:Z), 0 <= k && k < remaining - 1 => args_l[k] == k + 1) &&
(found == 1 || (exists (k:Z), 1 <= k && k < remaining && found == k && args_l[k - 1] == k)
          loop assigns remaining, found)
    */
    
        for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				found = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
		return found;
}