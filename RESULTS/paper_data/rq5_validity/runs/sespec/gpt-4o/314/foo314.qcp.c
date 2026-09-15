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
    (1 <= a && a <= 2 * radius + 1) &&
    (rectangles >= 0) &&
    (diameter == 2 * radius) &&
    (diameterSquare == diameter * diameter) &&
    (radius == radius@pre) &&
    (forall (i:Z), 1 <= i && i < a => (forall (j:Z), 1 <= j && j <= 2 * radius => ((i * i + j * j) <= diameterSquare => rectangles >= (i - 1) * (2 * radius) + j)))
    */
for (int a = 1; a <= 2 * radius; a++) {
           
  /*1*/ 
 /*@ Inv
    (1 <= b && b <= 2 * radius + 1) &&
    (rectangles >= 0) &&
    (diameter == 2 * radius) &&
    (diameterSquare == diameter * diameter) &&
    (radius == radius@pre) &&
    (forall (j:Z), 1 <= j && j < b => ((a * a + j * j) <= diameterSquare => rectangles >= (a - 1) * (2 * radius) + j))
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