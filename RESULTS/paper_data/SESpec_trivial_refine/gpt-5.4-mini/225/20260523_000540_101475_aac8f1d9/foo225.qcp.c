#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo225(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
	
 	/*0*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (1 <= remaining && remaining <= array + 1) &&
    (remaining == 1 => find == 1) &&
    (remaining > 1 => find == remaining - 1) &&
    (forall (i:Z), 1 <= i && i < remaining => args_l[i - 1] == i)
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