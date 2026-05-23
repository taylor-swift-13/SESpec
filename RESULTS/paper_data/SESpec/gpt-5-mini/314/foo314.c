
/*@
  requires radius >= 0;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo314(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        
        /*@
          loop invariant 0 <= rectangles;
          loop invariant diameter == 2 * radius;
          loop invariant diameterSquare == diameter * diameter;
          loop assigns a, rectangles;
        */
        for (int a = 1; a <= 2 * radius; a++) {
            
            
            /*@
              loop invariant 0 <= rectangles;
              loop invariant diameter == 2 * radius;
              loop invariant diameterSquare == diameter * diameter;
              loop assigns b, rectangles;
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
