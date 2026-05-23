#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo314(int radius) 
/*@

Require emp
Ensure Results(__return)
*/{

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
       
  /*@ Inv
    (1 <= a) &&
    (radius == radius@pre) &&
    (diameter == 2 * radius@pre) &&
    (diameterSquare == diameter * diameter) &&
    (rectangles >= 0)
    */
for (int a = 1; a <= 2 * radius; a++) {
            
            /*@
              loop invariant 1 <= a <= 2 * radius + 1;
              loop invariant 1 <= b;
              loop invariant radius == \at(radius, Pre);
              loop invariant diameterSquare == diameter * diameter;
              loop invariant rectangles >= 0;
              loop assigns rectangles, b;
            */
            /*@ Inv
    (1 <= a && a <= 2 * radius + 1) &&
    (1 <= b) &&
    (radius == radius@pre) &&
    (diameterSquare == diameter * diameter) &&
    (rectangles >= 0)
    */
for (int b = 1; b <= 2 * radius; b++) {
                int diagnalLengthSquare = (a * a + b * b);
                if (diagnalLengthSquare <= diameterSquare) {
                    rectangles++;
                }
            }
            
        }
        return rectangles;
}