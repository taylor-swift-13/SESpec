int countRectangles(int radius);

/*@ logic integer count_b_upto(integer r, integer a, integer b) =
      (b <= 0) ? 0 :
      count_b_upto(r,a,b-1) + ((a*a + b*b <= (2*r)*(2*r)) ? 1 : 0);

    logic integer count_pairs_upto(integer r, integer a) =
      (a <= 0) ? 0 :
      count_pairs_upto(r,a-1) + count_b_upto(r,a, 2*r);
*/

/*@ 
  requires 0 <= radius <= 16383;
  assigns \nothing;
  ensures \result == count_pairs_upto(radius, 2*radius);
  ensures 0 <= \result <= (2*radius)*(2*radius);
*/
int countRectangles(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        /*@ 
          loop invariant 1 <= a <= 2*radius + 1;
          loop invariant 0 <= rectangles <= (2*radius)*(2*radius);
          loop invariant rectangles == count_pairs_upto(radius, a-1);
          loop assigns a, rectangles;
          loop variant (2*radius - a + 1);
        */
        for (int a = 1; a <= 2 * radius; a++) {
            /*@ 
              loop invariant 1 <= b <= 2*radius + 1;
              loop invariant 0 <= rectangles - count_pairs_upto(radius, a-1) <= 2*radius;
              loop invariant rectangles == count_pairs_upto(radius, a-1) + count_b_upto(radius, a, b-1);
              loop assigns b, rectangles;
              loop variant (2*radius - b + 1);
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
