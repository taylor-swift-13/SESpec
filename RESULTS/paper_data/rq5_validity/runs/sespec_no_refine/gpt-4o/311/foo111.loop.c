
/*@
  requires count >= 0;
  ensures \result >= 0;
*/

int foo111(int count) {

    int result = 0;
    int diameter = 2 * count;
    int center = diameter * diameter;

    /*@
      loop invariant 1 <= index <= 2 * count + 1;
      loop invariant result >= 0;
      loop invariant diameter == 2 * count;
      loop invariant center == diameter * diameter;
      loop invariant count == \at(count, Pre);
      loop assigns index, i, diagnalLengthSquare, result;
    */
    for (int index = 1; index <= 2 * count; index++) {
        
        /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant result >= 0;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant count == \at(count, Pre);
          loop invariant index == \at(index, Here);
          loop assigns i, diagnalLengthSquare, result;
        */
        for (int i = 1; i <= 2 * count; i++) {
            int diagnalLengthSquare = (index * index + i * i);
            if (diagnalLengthSquare <= center) {
                result++;
            }
        }
    }
    
    return result;
}
