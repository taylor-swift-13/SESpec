#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo102(int * pairs, int pairs_len, int num, int p);

int foo102(int * pairs, int pairs_len, int num, int p) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l) && pairs_len > 0 && pairs_len < 100
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int index = 0; index < num; index++) {
		
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) && pairs_len > 0 && pairs_len < 100 &&
    (index + 1 <= j && j <= num) &&
(result >= 0) &&
(valid_bounds(pairs, pairs_len)) &&
(0 <= num && num <= pairs_len
          loop assigns j, result
          loop variant num - j)
    */
    
        for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                result++;
            }
        }
		}
		return result;
}