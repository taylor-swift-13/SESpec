
int foo314(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant rectangles >= 0;
          loop invariant diameter == 2 * \at(radius,Pre);
          loop invariant diameterSquare == (2 * \at(radius,Pre)) * (2 * \at(radius,Pre));
          loop invariant radius == \at(radius,Pre);
          loop invariant a >= 1 ==> rectangles >= 0;
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
            for (int b = 1; b <= 2 * radius; b++) {
                int diagnalLengthSquare = (a * a + b * b);
                if (diagnalLengthSquare <= diameterSquare) {
                    rectangles++;
                }
            }
            
        }
            
        return rectangles;
}
