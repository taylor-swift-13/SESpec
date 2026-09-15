
/*@
  requires num >= 0;
  requires c > 0;
  requires r >= 0;
  requires num < c; // Ensure num starts less than c
  requires r == 0 || num * (10 ^ r) < c; // Ensure num does not grow beyond c during the loop
  ensures \result >= 0;
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
      loop invariant num < c; // Ensure num remains bounded by c
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
