
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

int foo314(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= a <= 2 * radius + 1;
          loop invariant 0 <= rectangles;
          loop invariant rectangles <= (a - 1) * 2 * radius;
          loop invariant diameter == 2 * radius;
          loop invariant diameterSquare == diameter * diameter;
          loop invariant radius == \at(radius,Pre);
          loop assigns a, rectangles;
            */
            for (int a = 1; a <= 2 * radius; a++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 1 <= a <= 2 * radius + 1;
            loop invariant 1 <= b <= 2 * radius + 1;
            loop invariant 0 <= rectangles;
            loop invariant rectangles <= (a - 1) * 2 * radius + (b - 1);
            loop invariant diameter == 2 * radius;
            loop invariant diameterSquare == diameter * diameter;
            loop invariant radius == \at(radius,Pre);
            loop assigns b, diagnalLengthSquare, rectangles;
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
