
        /*@ logic integer strip4(integer x) =
      x % 4 == 0 ? strip4(x / 4) : x; */
/*@
  assigns \nothing;
  ensures \old(n) <= 0 ==> \result == 0;
  ensures \old(n) > 0 ==> \result == (strip4(\old(n)) == 1);
  ensures \result == 1 <==> (\old(n) > 0 && strip4(\old(n)) == 1);
*/
int foo146(int n) {
    int orig = n;

    if (n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;
      loop invariant strip4(n) == strip4(orig);
      loop assigns n;
      loop variant n;
    */
    while (n % 4 == 0) {
        n /= 4;
    }

    return n == 1;
}
