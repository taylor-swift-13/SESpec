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
       
  /*0*/ 
 /*@ Inv
    (0 <= rectangles) &&
    (1 <= a && a <= 2 * radius + 1)
    */
for (int a = 1; a <= 2 * radius; a++) {
           
  /*1*/ 
 /*@ Inv
    (0 <= rectangles) &&
    (1 <= b && b <= 2 * radius + 1)
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