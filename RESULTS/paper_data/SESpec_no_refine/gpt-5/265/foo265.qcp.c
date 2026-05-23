#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo265(int * ints, int ints_len, int array);

int foo265(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
		int start = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  ints_l,    
    store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100 &&
    (array == array@pre) &&
(ints_len == ints_len@pre) &&
(ints == ints@pre) &&
(forall (k:Z), 0 <= k && k < index => ints_l[k] == ints_l[k]@pre 
          loop assigns index, ret, start)
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