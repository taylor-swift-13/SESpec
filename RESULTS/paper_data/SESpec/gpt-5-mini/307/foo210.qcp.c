#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo210(int * positions, int positions_len);

int foo210(int * positions, int positions_len) 
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
    (0 <= count && count <= positions_len) &&
(largest >= 0) &&
((count == 0 => largest == 0)) &&
(forall (k:Z), 0 <= k && k < count => largest >= positions_l[k]) &&
(largest == max_prefix(positions, count)) &&
(positions_len == positions_len@pre) &&
(positions == positions@pre) &&
(forall (k:Z), 0 <= k && k < positions_len => positions_l[k] == positions_l[k]@pre
      loop assigns count, largest)
    */
    
    for (int count = 0; count < positions_len; count++) {
        if (positions[count] > 0 && positions[count] > largest) {
            largest = positions[count];
        }
    }
		return largest;
}