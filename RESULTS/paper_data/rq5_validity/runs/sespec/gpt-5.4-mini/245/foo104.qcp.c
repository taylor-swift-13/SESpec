#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo104(int * pairs, int pairs_len, int num, int p);

int foo104(int * pairs, int pairs_len, int num, int p) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l) && pairs_len > 0 && pairs_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) && pairs_len > 0 && pairs_len < 100 &&
    (0 <= index) &&
(0 <= ret) &&
(p == p@pre) &&
(num == num@pre) &&
(pairs_len == pairs_len@pre) &&
(pairs == pairs@pre) &&
(forall (i:Z), 0 <= i && i < pairs_len => 0 <= pairs_l[i] <= 100
          loop assigns index, ret)
    */
    
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= index <= num;
              loop invariant 0 <= ret;
              loop assigns index, ret;
            */
            for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
            
		}
		return ret;
}