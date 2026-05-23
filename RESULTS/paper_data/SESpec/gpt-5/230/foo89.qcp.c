#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo89(int * pairs, int pairs_len, int array);

int foo89(int * pairs, int pairs_len, int array) 
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
(total == pairs_len@pre) &&
(array == array@pre) &&
(pairs_len == pairs_len@pre) &&
(pairs == pairs@pre) &&
(forall (t:Z), 0 <= t && t < pairs_len => pairs_l[t] == pairs_l[t]@pre) &&
(0 <= count
          loop assigns index, count)
    */
    
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant index + 1 <= k <= total;
              loop invariant 0 <= count;
              loop invariant \forall integer t; 0 <= t < pairs_len ==> pairs[t] == \at(pairs[t],Pre);
              loop assigns count, k;
            */
            for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
            
		}
		return count;
}