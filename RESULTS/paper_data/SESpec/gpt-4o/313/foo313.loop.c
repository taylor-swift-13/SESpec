
/*@
  requires count >= 0;
  ensures \result >= 0;
*/

int foo313(int count) {

    int ret = 0;
    int diameter = 2 * count;
    int center = diameter * diameter;

    /*@
      loop invariant 1 <= index <= 2 * count + 1;
      loop invariant ret >= 0;
      loop invariant diameter == 2 * count;
      loop invariant center == diameter * diameter;
      loop assigns index, ret;
    */
    for (int index = 1; index <= 2 * count; index++) {

        /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant ret >= 0;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant count == \at(count, Pre);
          loop invariant \forall integer k; 1 <= k < i ==> (index * index + k * k) <= center ==> ret >= k;
          loop assigns i, diagnalLengthSquare, ret;
        */
        for (int i = 1; i <= 2 * count; i++) {
            int diagnalLengthSquare = (index * index + i * i);
            if (diagnalLengthSquare <= center) {
                ret++;
            }
        }
    }

    return ret;
}
