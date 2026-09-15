
/*@
  requires count >= 0;
  assigns \nothing;
  ensures \result >= 0;
  
*/
int foo312(int count) {

    int ret = 0;
    int diameter = 2 * count;
    int center = diameter * diameter;

    /*@
      loop invariant 1 <= i <= 2 * count + 1;
      loop invariant ret >= 0;
      loop invariant diameter == 2 * count;
      loop invariant center == diameter * diameter;
      loop invariant count == \at(count, Pre);
      loop assigns i, ret;
    */
    for (int i = 1; i <= 2 * count; i++) {

        /*@
          loop invariant 1 <= c <= 2 * count + 1;
          loop invariant ret >= 0;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant count == \at(count, Pre);
          loop invariant \forall integer x, y; 1 <= x <= i && 1 <= y <= 2 * count ==> ret >= 0;
          loop assigns c, ret;
        */
        for (int c = 1; c <= 2 * count; c++) {
            int diagnalLengthSquare = (i * i + c * c);
            if (diagnalLengthSquare <= center) {
                ret++;
            }
        }
    }

    return ret;
}
