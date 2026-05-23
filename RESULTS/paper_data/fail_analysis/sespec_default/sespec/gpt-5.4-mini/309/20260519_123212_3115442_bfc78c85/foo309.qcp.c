#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo309(int * positions, int positions_len);

int foo309(int * positions, int positions_len) 
/*@
With positions_l
Require store_int_array(positions, positions_len, positions_l) && positions_len > 0 && positions_len < 100
Ensure Results(__return)
*/{

		int largest = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) && positions_len > 0 && positions_len < 100 &&
    (largest >= 0) &&
(forall (k:Z), 0 <= k && k < index => positions_l[k] <= largest || positions_l[k] <= 0) &&
(positions_len == positions_len@pre) &&
(positions == positions@pre) &&
(forall (k:Z), 0 <= k && k < positions_len => positions_l[k] == positions_l[k]@pre
          loop assigns index, largest)
    */
    
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
		return largest;
}