#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo224(int * args, int args_len, int array);

int foo224(int * args, int args_len, int array) 
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
    (forall (k:Z), 0 <= k && k < args_len => args_l[k] == args_l[k]@pre
      // All previously checked positions (0..num-2) satisfy args_l[i] == i+1) &&
(count_matches(args, 0, num-1) == num-1
      // found tracks the last matched index within the processed prefix) &&
((num == 1) => (found == 1)) &&
((num > 1) => (found == num-1)
      loop assigns num, found)
    */
    
    for (int num = 1; num <= array; num++) {
        if (args[num - 1] == num) {
            found = num;
        } else if (args[num - 1] != num) {
            return num;
        }
    }
		return found;
}