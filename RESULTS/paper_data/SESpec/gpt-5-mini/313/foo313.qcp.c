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
    (index >= 1) &&
    (0 <= ret) &&
    (ret <= (index - 1) * (2 * count)) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter)
    */
for (int index = 1; index <= 2 * count; index++) {

        /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant index >= 1 && index <= 2 * count;
          loop invariant 0 <= ret;
          loop invariant ret <= (index - 1) * (2 * count) + (i - 1);
          loop assigns ret, i;
        */
        /*@ Inv
    (1 <= i && i <= 2 * count + 1) &&
    (index >= 1 && index <= 2 * count) &&
    (0 <= ret) &&
    (ret <= (index - 1) * (2 * count) + (i - 1))
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