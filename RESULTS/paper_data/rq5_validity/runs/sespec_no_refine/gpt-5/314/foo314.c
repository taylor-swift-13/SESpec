
/*@
*/

/*@ logic integer count_pairs_up_to(integer r, integer a, integer b) =
      a <= 0 || b <= 0 ? 0 :
      (a*a + b*b <= (2*r)*(2*r) ? 1 : 0)
      + (b > 1 ? count_pairs_up_to(r, a, b - 1) : 0)
      + (a > 1 ? count_pairs_up_to(r, a - 1, b) - (a > 1 && b > 1 ? count_pairs_up_to(r, a - 1, b - 1) : 0) : 0); */
/*@
  assigns \nothing;
  ensures \result == count_pairs_up_to(radius, 2 * radius, 2 * radius);
*/
int foo314(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant radius == \at(radius,Pre);
          loop invariant diameter == 2 * \at(radius,Pre);
          loop invariant diameterSquare == (2 * \at(radius,Pre)) * (2 * \at(radius,Pre));
          loop invariant 1 <= a <= 2 * \at(radius,Pre) + 1;
          loop invariant rectangles >= 0;
          loop assigns a, b, diagnalLengthSquare, rectangles;
            */
            for (int a = 1; a <= 2 * radius; a++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= a <= 2 * radius + 1;
          loop assigns a, b, rectangles;
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
