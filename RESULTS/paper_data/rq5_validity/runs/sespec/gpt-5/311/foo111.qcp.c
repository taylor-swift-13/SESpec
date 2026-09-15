#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo111(int count);

int foo111(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= index) &&
(center == (2 * count) * (2 * count)) &&
(diameter == 2 * count) &&
(result >= 0
          loop assigns index, result)
    */
    
            for (int index = 1; index <= 2 * count; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= i <= 2 * count + 1;
              loop invariant 1 <= index && index <= 2 * count;
              loop invariant result >= 0;
              loop invariant center == (2 * count) * (2 * count);
              loop assigns result, i;
            */
            for (int i = 1; i <= 2 * count; i++) {
				int diagnalLengthSquare = (index * index + i * i);
				if (diagnalLengthSquare <= center) {
					result++;
				}
			}
            
		}
		return result;
}