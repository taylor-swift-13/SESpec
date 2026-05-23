#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_b_prefix : Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_b : Z -> Z -> Z -> Z) */
/*@ Extern Coq (sum_count : Z -> Z -> Z -> Z) */
int foo314(int radius) 
/*@

Require emp
Ensure Results(__return)
*/{

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
       
  /*@ Inv
    (0 <= rectangles) &&
    (diameter == 2 * radius) &&
    (diameterSquare == diameter * diameter)
    */
for (int a = 1; a <= 2 * radius; a++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= rectangles;
              loop invariant diameter == 2 * radius;
              loop invariant diameterSquare == diameter * diameter;
              loop assigns b, rectangles;
            */
            /*@ Inv
    (0 <= rectangles) &&
    (diameter == 2 * radius) &&
    (diameterSquare == diameter * diameter)
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