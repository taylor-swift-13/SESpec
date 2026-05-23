#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo113_c313(int count);

int foo113_c313(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (index >= 1) &&
(center == (2 * count) * (2 * count)) &&
(diameter == 2 * count) &&
(count == count@pre) &&
(0 <= ret
              loop assigns index, ret)
    */
    
            for (int index = 1; index <= 2 * count; index++) {
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant i >= 1;
              loop invariant center == (2 * count) * (2 * count);
              loop invariant diameter == 2 * count;
              loop invariant count == \at(count,Pre);
              loop invariant 0 <= ret;
              loop assigns i, ret;
            */
            for (int i = 1; i <= 2 * count; i++) {
                int diagnalLengthSquare = (index * index + i * i);
                if (diagnalLengthSquare <= center) {
                    ret++;
                }
            }
            
        }
		return ret;
}