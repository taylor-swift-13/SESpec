#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo312(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Inv
    (diameter == 2 * count) &&
    (center == diameter * diameter) &&
    (ret >= 0) &&
    (1 <= i && i <= 2 * count + 1) &&
    ((i <= 2 * count@pre) => true) &&
    ((i <= 2 * count@pre) => (ret >= 0))
    */
for (int i = 1; i <= 2 * count; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= 2 * count + 1;
          loop invariant ret >= 0;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant 1 <= i <= 2 * count;
            */
            /*@ Inv
    (1 <= c && c <= 2 * count + 1) &&
    (ret >= 0) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter) &&
    (1 <= i && i <= 2 * count)
    */
for (int c = 1; c <= 2 * count; c++) {
				int diagnalLengthSquare = (i * i + c * c);
				if (diagnalLengthSquare <= center) {
					ret++;
				}
			}
            
		}
		return ret;
}