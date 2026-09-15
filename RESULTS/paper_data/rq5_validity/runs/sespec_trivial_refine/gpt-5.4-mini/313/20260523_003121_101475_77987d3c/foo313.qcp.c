#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (nonnegative : Z -> Prop) */
/*@ Extern Coq (square : Z -> Z) */

int foo313(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*0*/ 
 /*@ Inv
    (nonnegative(ret)) &&
    (nonnegative(index))
    */
for (int index = 1; index <= 2 * count; index++) {
		
 	/*1*/ 
 /*@ Inv
    (nonnegative(ret)) &&
    (nonnegative(i))
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