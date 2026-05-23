
/*@ 
  logic integer count_b_prefix(integer aa, integer k, integer diamSq) =
    k <= 0 ? 0 : count_b_prefix(aa, k-1, diamSq) + ((aa*aa + k*k <= diamSq) ? 1 : 0);

  logic integer count_b(integer aa, integer R, integer diamSq) =
    count_b_prefix(aa, 2 * R, diamSq);

  logic integer sum_count(integer n, integer R, integer diamSq) =
    n <= 0 ? 0 : sum_count(n-1, R, diamSq) + count_b(n, R, diamSq);
*/


int foo314(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= rectangles;
          loop invariant diameter == 2 * radius;
          loop invariant diameterSquare == diameter * diameter;
          loop assigns a, rectangles;
        */
        for (int a = 1; a <= 2 * radius; a++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
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
