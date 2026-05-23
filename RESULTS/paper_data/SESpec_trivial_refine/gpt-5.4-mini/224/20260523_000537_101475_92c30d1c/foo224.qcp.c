#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo224(int * args, int args_len, int array) 
/*@
With args_l
Require store_int_array(args, args_len, args_l)
Ensure Results(__return)
*/{

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
	
 	/*0*/ 
 /*@ Inv
    exists  args_l,    
    store_int_array(args, args_len, args_l) &&
    (PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS) &&
    (1 <= num && num <= array + 1) &&
    (found == num || found == num - 1) &&
    (forall (i:Z), 0 <= i && i < num - 1 => args_l[i] == i + 1)
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