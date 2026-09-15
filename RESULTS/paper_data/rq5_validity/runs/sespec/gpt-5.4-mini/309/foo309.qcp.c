#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (max0 : Z -> Z -> Z -> Z) */
int foo309(int * positions, int positions_len) 
/*@
With positions_l
Require store_int_array(positions, positions_len, positions_l)
Ensure Results(__return)
*/{

		int largest = 0;
	
 	/*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) &&
    (0 <= index && index <= positions_len) &&
    (0 <= largest) &&
    (largest == max0(positions, 0, index)) &&
    (positions_len == positions_len@pre) &&
    (positions == positions@pre) &&
    (forall (k:Z), 0 <= k && k < positions_len => positions_l[k] == positions_l[k]@pre)
    */
for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
		return largest;
}