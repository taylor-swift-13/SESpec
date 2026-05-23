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
    (0 <= index && index <= pairs_len@pre - 1) &&
(0 <= count) &&
(total == pairs_len@pre) &&
(array == array@pre) &&
(pairs_len == pairs_len@pre) &&
(pairs == pairs@pre) &&
(forall (i:Z), 0 <= i && i < pairs_len@pre => pairs_l[i] == pairs_l[i]@pre
          loop assigns index, count)
    */
    
            for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant index + 1 <= c <= total;
              loop invariant 0 <= index <= total - 1;
              loop invariant count >= 0;
              loop invariant total == \at(pairs_len,Pre);
              loop invariant array == \at(array,Pre);
              loop invariant pairs_len == \at(pairs_len,Pre);
              loop invariant pairs == \at(pairs,Pre);
              loop invariant \forall integer i; 0 <= i < \at(pairs_len,Pre) ==> pairs[i] == \at(pairs[i],Pre);
              loop assigns c, count;
            */
            for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
            
		}
		return count;
}