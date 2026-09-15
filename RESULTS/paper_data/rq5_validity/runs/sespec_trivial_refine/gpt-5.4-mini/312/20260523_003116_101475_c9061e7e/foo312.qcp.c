#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (inside_circle : Z -> Z -> Z -> Prop) */
int foo312(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Inv
    (ret >= 0) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter) &&
    (i >= 1)
    */
for (int i = 1; i <= 2 * count; i++) {
			
            /*@
              loop invariant ret >= 0;
              loop invariant i >= 1;
              loop invariant c >= 1;
              loop invariant diameter == 2 * count;
              loop invariant center == diameter * diameter;
              loop assigns c, ret;
              loop variant 2 * count - c + 1;
            */
            /*@ Inv
    (ret >= 0) &&
    (i >= 1) &&
    (c >= 1) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter)
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