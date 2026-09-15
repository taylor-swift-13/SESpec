
/*@
  requires radius >= 0;
  requires radius == 0;
  assigns \nothing;
  
  ensures \result >= 0;
  ensures radius > 0 ==> \result >= 0;
  ensures \result >= 0;
*/
int foo314(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        
        /*@
          loop invariant 1 <= a;
          loop invariant radius == \at(radius, Pre);
          loop invariant diameter == 2 * \at(radius, Pre);
          loop invariant diameterSquare == diameter * diameter;
          loop invariant rectangles >= 0;
          loop assigns a, rectangles;
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
            for (int b = 1; b <= 2 * radius; b++) {
                int diagnalLengthSquare = (a * a + b * b);
                if (diagnalLengthSquare <= diameterSquare) {
                    rectangles++;
                }
            }
            
        }
            
        return rectangles;
}
