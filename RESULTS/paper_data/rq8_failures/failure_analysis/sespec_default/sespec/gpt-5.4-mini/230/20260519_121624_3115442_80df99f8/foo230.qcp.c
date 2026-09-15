#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo230(int * pairs, int pairs_len, int array);

int foo230(int * pairs, int pairs_len, int array) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l) && pairs_len > 0 && pairs_len < 100
Ensure Results(__return)
*/{

		int count = 0;
		int total = pairs_len;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) && pairs_len > 0 && pairs_len < 100 &&
    (0 <= index && index <= total - 1) &&
(0 <= count) &&
(total == pairs_len@pre) &&
(array == array@pre) &&
(pairs_len == pairs_len@pre) &&
(pairs == pairs@pre) &&
(\valid(&pairs_l[0] + (0..pairs_len-1))
          loop assigns index, count)
    */
    
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= index <= total - 1;
            loop invariant 0 <= count;
            loop assigns index, count;
            */
            for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
            
		}
		return count;
}