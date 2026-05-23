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
	
 	/*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) &&
    (0 <= count && count <= positions_len) &&
    (largest >= 0) &&
    (positions_len == positions_len@pre) &&
    (positions == positions@pre) &&
    (forall (k:Z), 0 <= k && k < count => positions_l[k] <= largest) &&
    (count == positions_len => (forall (k:Z), 0 <= k && k < positions_len => positions_l[k] <= largest)) &&
    ((count < positions_len@pre) => (forall (k:Z), 0 <= k && k < count => positions_l[k] <= largest)) &&
    (forall (k:Z), 0 <= k && k < positions_len => positions_l[k] == positions_l[k]@pre)
    */
for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
		return largest;
}