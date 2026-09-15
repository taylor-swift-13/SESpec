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
    (1 <= i && i <= 2 * count + 1) &&
    (ret >= 0) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter) &&
    (count == count@pre)
    */
for (int i = 1; i <= 2 * count; i++) {

        /*@
          loop invariant 1 <= c <= 2 * count + 1;
          loop invariant ret >= 0;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant count == \at(count, Pre);
          loop invariant \forall integer x, y; 1 <= x <= i && 1 <= y <= 2 * count ==> ret >= 0;
          loop assigns c, ret;
        */
        /*@ Inv
    (1 <= c && c <= 2 * count + 1) &&
    (ret >= 0) &&
    (diameter == 2 * count) &&
    (center == diameter * diameter) &&
    (count == count@pre) &&
    (forall (x:Z), forall (y:Z), 1 <= x && x <= i && 1 <= y && y <= 2 * count => ret >= 0)
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