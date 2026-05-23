#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo313(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*@ Inv
    (1 <= index && index <= 2 * count + 1) &&
    (0 <= ret) &&
    (ret <= (index - 1) * (2 * count)) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter) &&
    (count == count@pre)
    */
for (int index = 1; index <= 2 * count; index++) {
			
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant 0 <= ret;
          loop invariant ret <= (index - 1) * (2 * count) + (i - 1);
          loop invariant 1 <= index <= 2 * count + 1;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant count == \at(count,Pre);
          loop assigns ret, i;
            */
            /*@ Inv
    (1 <= i && i <= 2 * count + 1) &&
    (0 <= ret) &&
    (ret <= (index - 1) * (2 * count) + (i - 1)) &&
    (1 <= index && index <= 2 * count + 1) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter) &&
    (count == count@pre)
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