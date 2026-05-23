#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo307(int * positions, int positions_len) 
/*@
With positions_l
Require store_int_array(positions, positions_len, positions_l)
Ensure Results(__return)
*/{

		int largest = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) &&
    (positions_len < 0 || (0 <= count && count <= positions_len)) &&
    (largest >= 0) &&
    (forall (i:Z), 0 <= i && i < count => positions_l[i] <= largest) &&
    (largest == 0 || (exists (i:Z), 0 <= i && i < count && positions_l[i] == largest))
    */
for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
		return largest;
}