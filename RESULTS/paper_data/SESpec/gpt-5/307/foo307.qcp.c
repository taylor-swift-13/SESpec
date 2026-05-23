#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (max_prefix : Z -> Z -> Z) */
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
    (largest == max_prefix(positions, count)) &&
    (positions_len == positions_len@pre) &&
    (positions == positions@pre) &&
    (forall (k:Z), 0 <= k && k < positions_len => positions_l[k] == positions_l[k]@pre) &&
    (count == 0 => largest == 0) &&
    (count == positions_len => largest == max_prefix(positions, positions_len))
    */
for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
		return largest;
}