#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (maxpos : Z -> Z -> Z -> Z) */
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
    (0 <= index) &&
    (0 <= largest) &&
    (largest == maxpos(positions, 0, index)) &&
    (forall (k:Z), 0 <= k && k < index => positions_l[k] == positions_l[k]@pre) &&
    ((index < positions_len@pre) => (largest >= 0)) &&
    ((index < positions_len@pre) => (((largest == 0)&&(positions_len == positions_len@pre)&&(positions == positions@pre)) || (largest == maxpos(positions, 0, index)))) &&
    ((!(index < positions_len@pre)) => ((largest == 0 && (forall (k:Z), 0 <= k && k < positions_len => positions_l[k] <= 0)) || (largest == maxpos(positions, 0, positions_len)))) &&
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