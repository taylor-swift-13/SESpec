#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo311(int count);

int foo311(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (center == 2 * count@pre * (2 * count@pre)) &&
(diameter == 2 * count@pre) &&
(count == count@pre
          loop assigns index, result)
    */
    
        for (int index = 1; index <= 2 * count; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant count == \at(count,Pre);
            loop invariant diameter == 2 * \at(count,Pre);
            loop invariant center == diameter * diameter;
            loop assigns i, result;
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