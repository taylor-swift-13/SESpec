
/*@ logic integer foo387_final(integer num, integer c, integer r) =
      r <= 0 ? 0 : (r == 1 ? (10 * num) / c : foo387_final((10 * num) % c, c, r - 1)); */
/*@
  requires c != 0;
  requires r >= 0;
  assigns \nothing;
*/
int foo387(int num, int c, int r) {
    /*@ ghost int num0 = num; */
    /*@ ghost int r0 = r; */

    int ret = 0;

    /*@
      loop assigns r, num, ret;
      loop invariant r >= 0;
      loop invariant c != 0;
      loop invariant 0 <= r0 - r <= r0;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        ret = num / c;
        num %= c;
    }

    return ret;
}
