#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo91(int * pairs, int pairs_len, int array);

int foo91(int * pairs, int pairs_len, int array) 
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
    (0 <= count) &&
(total == pairs_len) &&
(array == array@pre) &&
(pairs_len == pairs_len@pre) &&
(pairs == pairs@pre
              loop assigns index, count)
    */
    
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= count;
              loop assigns index, c, count;
            */
            for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
            
		}
		return count;
}