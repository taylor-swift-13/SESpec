#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo308(int * positions, int positions_len) 
/*@
With positions_l
Require store_int_array(positions, positions_len, positions_l)
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) &&
    (0 <= index && index <= positions_len) &&
    (result >= 0) &&
    (forall (i:Z), 0 <= i && i < index => positions_l[i] <= 0 || positions_l[i] <= result)
    */
for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
		return result;
}