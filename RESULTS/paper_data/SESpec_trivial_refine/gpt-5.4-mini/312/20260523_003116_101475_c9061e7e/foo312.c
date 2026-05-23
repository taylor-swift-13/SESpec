
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures count <= 0 ==> \result == 0;
  ensures count > 0 ==> \result <= 4 * count * count;
*/
int foo312(int count) {
  int ret = 0;
  int diameter = 2 * count;
  int center = diameter * diameter;

  /*@
    loop invariant ret >= 0;
    loop invariant ret <= (i - 1) * (2 * count);
    loop invariant diameter == 2 * count;
    loop invariant center == diameter * diameter;
    loop invariant i >= 1;
    loop invariant count > 0 ==> i <= 2 * count + 1;
    loop assigns i, ret;
    loop variant 2 * count - i + 1;
  */
  for (int i = 1; i <= 2 * count; i++) {

    /*@
      loop invariant ret >= 0;
      loop invariant ret <= (i - 1) * (2 * count) + c - 1;
      loop invariant diameter == 2 * count;
      loop invariant center == diameter * diameter;
      loop invariant i >= 1;
      loop invariant c >= 1;
      loop invariant count > 0 ==> i <= 2 * count + 1;
      loop invariant count > 0 ==> c <= 2 * count + 1;
      loop assigns c, ret;
      loop variant 2 * count - c + 1;
    */
    for (int c = 1; c <= 2 * count; c++) {
      int diagnalLengthSquare = i * i + c * c;
      if (diagnalLengthSquare <= center) {
        ret++;
      }
    }
  }

  /*@
    assert count <= 0 ==> ret == 0;
  */

  return ret;
}
