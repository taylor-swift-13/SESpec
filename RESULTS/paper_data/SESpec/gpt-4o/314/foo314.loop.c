
/*@
  // No additional predicate or logic function is required for this program.
*/

int foo314(int radius) {

    int rectangles = 0;
    int diameter = 2 * radius;
    int diameterSquare = diameter * diameter;

    /*@
      loop invariant 1 <= a <= 2 * radius + 1;
      loop invariant rectangles >= 0;
      loop invariant diameter == 2 * radius;
      loop invariant diameterSquare == diameter * diameter;
      loop invariant radius == \at(radius, Pre);
      loop invariant \forall integer i; 1 <= i < a ==> 
          (\forall integer j; 1 <= j <= 2 * radius ==> 
              ((i * i + j * j) <= diameterSquare ==> rectangles >= (i - 1) * (2 * radius) + j));
      loop assigns a, rectangles;
    */
    for (int a = 1; a <= 2 * radius; a++) {
        
        /*@
          loop invariant 1 <= b <= 2 * radius + 1;
          loop invariant rectangles >= 0;
          loop invariant diameter == 2 * radius;
          loop invariant diameterSquare == diameter * diameter;
          loop invariant radius == \at(radius, Pre);
          loop invariant \forall integer j; 1 <= j < b ==> 
              ((a * a + j * j) <= diameterSquare ==> rectangles >= (a - 1) * (2 * radius) + j);
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
