#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo311(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Inv
    (1 <= index && index <= 2 * count + 1) &&
    (result >= 0) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter) &&
    (count == count@pre) &&
    (result <= (index - 1) * (2 * count))
    */
for (int index = 1; index <= 2 * count; index++) {
			
            /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant result >= 0;
          loop invariant index * index + i * i >= 0;
          loop invariant result <= (index - 1) * (2 * count) + (i - 1);
          loop assigns i, result;
            */
            /*@ Inv
    (1 <= i && i <= 2 * count + 1) &&
    (result >= 0) &&
    (index * index + i * i >= 0) &&
    (result <= (index - 1) * (2 * count) + (i - 1))
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