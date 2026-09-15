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
/*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) && pairs_len > 0 && pairs_len < 100 &&
    (0 <= index) &&
(0 <= result) &&
(p == p@pre) &&
(num == num@pre) &&
(pairs_len == pairs_len@pre) &&
(pairs == pairs@pre) &&
(forall (i:Z), 0 <= i && i < pairs_len => 0 <= pairs_l[i] <= 100
          loop assigns index, result)
    */
    
            for (int index = 0; index < num; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant index >= 0;
              loop invariant result >= 0;
              loop assigns j, result;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
            
		}
		return result;
}