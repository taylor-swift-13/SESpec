#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (is_odd : Z -> Prop) */
int foo265(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l)
Ensure Results(__return)
*/{

		int ret = 0;
		int start = 0;
	
 	/*@ Inv
    exists  ints_l,    
    store_int_array(ints, ints_len, ints_l) &&
    (0 <= index) &&
    (0 <= start && start <= index)
    */
for (int index = 0; index < array; index++) {
			if (ints[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = ints[index];
				}
			}
		}
		return ret;
}