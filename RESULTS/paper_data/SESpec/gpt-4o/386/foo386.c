
/*@
  requires r >= 0;
  requires b > 0;
  requires num >= 0;
  ensures \result >= 0;
*/
int foo386(int num, int b, int r) {

    int result = 0;

    /*@
      loop invariant r >= 0;
      loop invariant num >= 0;
      loop invariant result >= 0;
      loop invariant b == \at(b, Pre);
      loop assigns r, num, result;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / b;
        num %= b;
    }

    return result;
}
