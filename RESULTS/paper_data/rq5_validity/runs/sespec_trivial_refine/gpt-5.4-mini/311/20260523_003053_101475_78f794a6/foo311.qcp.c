#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (square : Z -> Z) */

int foo311(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
	
 	/*0*/ 
 /*@ Inv
    (1 <= index && index <= 2 * count + 1) &&
    (0 <= result)
    */
for (int index = 1; index <= 2 * count; index++) {
		
 	/*1*/ 
 /*@ Inv
    (1 <= i && i <= 2 * count + 1) &&
    (0 <= result)
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