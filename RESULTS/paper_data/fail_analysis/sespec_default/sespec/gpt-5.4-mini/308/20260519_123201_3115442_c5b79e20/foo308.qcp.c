#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo308(int * positions, int positions_len);

int foo308(int * positions, int positions_len) 
/*@
With positions_l
Require store_int_array(positions, positions_len, positions_l) && positions_len > 0 && positions_len < 100
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) && positions_len > 0 && positions_len < 100 &&
    (positions_len == positions_len@pre) &&
(positions == positions@pre) &&
(forall (k:Z), 0 <= k && k < positions_len@pre => positions_l[k] == positions_l[k]@pre) &&
(result >= 0) &&
(forall (k:Z), 0 <= k && k < index => positions_l[k] <= result) &&
((index < positions_len@pre) => (result >= 0)) &&
((index < positions_len@pre) => (((result == 0)&&(positions_len == positions_len@pre)&&(positions == positions@pre)) || (result >= 0))) &&
((!(index < positions_len@pre)) => (result >= 0)
          loop assigns index, result)
    */
    
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
		return result;
}