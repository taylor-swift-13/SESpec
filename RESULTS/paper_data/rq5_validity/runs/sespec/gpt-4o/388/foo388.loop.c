
/*@
  requires num >= 0;
  requires c > 0;
  requires r >= 0;
  ensures \result >= 0;
  ensures \result < c;
*/
int foo388(int num, int c, int r) {

    int result = 0;

    /*@
      loop invariant r >= 0;
      loop invariant num >= 0;
      loop invariant result >= 0;
      loop invariant c == \at(c, Pre);
      loop invariant r <= \at(r, Pre);
      loop invariant (!(\at(r, Pre) > 0)) ==> ((result == 0) && (r == \at(r, Pre)) && (c == \at(c, Pre)) && (num == \at(num, Pre)));
      loop assigns r, num, result;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / c;
        num %= c;
    }

    return result;
}
