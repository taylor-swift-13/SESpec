#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (max_pos : Z -> Z -> Z -> Z) */
int foo308(int * positions, int positions_len) 
/*@
With positions_l
Require store_int_array(positions, positions_len, positions_l)
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) &&
    (0 <= index && index <= positions_len) &&
    (positions_len >= 0) &&
    (true)) &&
    (positions_len == positions_len@pre) &&
    (positions == positions@pre) &&
    (forall (k:Z), 0 <= k && k < positions_len => positions_l[k] == positions_l[k]@pre) &&
    (result == max_pos(positions, 0, index)) &&
    (result >= 0) &&
    (forall (k:Z), 0 <= k && k < index && positions_l[k] > 0 => positions_l[k] <= result) &&
    ((index >= positions_len) => (result == max_pos(positions, 0, positions_len)))
    */
for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
		return result;
}