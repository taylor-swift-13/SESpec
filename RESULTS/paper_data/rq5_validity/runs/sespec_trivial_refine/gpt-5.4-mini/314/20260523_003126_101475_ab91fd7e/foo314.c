
/*@
*/

logic boolean is_inside(int a, int b, int diameterSquare) = (a * a + b * b <= diameterSquare);
        

int foo314(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= rectangles;
          loop invariant 1 <= a <= 2 * radius + 1;
          loop assigns rectangles, a;
            */
            for (int a = 1; a <= 2 * radius; a++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= rectangles;
          loop invariant 1 <= b <= 2 * radius + 1;
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
