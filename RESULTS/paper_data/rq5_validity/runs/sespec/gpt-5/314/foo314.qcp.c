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
    (rectangles >= 0) &&
    (diameter == 2 * radius@pre) &&
    (diameterSquare == (2 * radius@pre) * (2 * radius@pre)) &&
    (radius == radius@pre) &&
    (a >= 1 => rectangles >= 0)
    */
for (int a = 1; a <= 2 * radius; a++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant rectangles >= 0;
          loop invariant diameter == 2 * \at(radius,Pre);
          loop invariant diameterSquare == (2 * \at(radius,Pre)) * (2 * \at(radius,Pre));
          loop invariant radius == \at(radius,Pre);
          loop assigns rectangles, b;
            */
            /*@ Inv
    (rectangles >= 0) &&
    (diameter == 2 * radius@pre) &&
    (diameterSquare == (2 * radius@pre) * (2 * radius@pre)) &&
    (radius == radius@pre)
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