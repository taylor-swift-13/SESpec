
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  requires num == \at(num, Pre);
  requires c == \at(c, Pre);
  requires r == \at(r, Pre);
  requires c > 0;
  requires r >= 0; // Strengthened precondition to ensure r is non-negative
  requires num >= 0; // Strengthened precondition to ensure num is non-negative
*/
int foo387(int num, int c, int r) {

    int ret = 0;

    /*@
      loop invariant r >= 0; // r is non-negative during the loop
      loop invariant num >= 0; // num is non-negative during the loop
      loop invariant c == \at(c, Pre); // c remains unchanged
      loop invariant ret >= 0; // ret is non-negative during the loop
      loop invariant (\at(r, Pre) > 0) ==> (r <= \at(r, Pre)); // r decreases but remains within bounds
      loop invariant (!(\at(r, Pre) > 0)) ==> ((ret == 0) && (r == \at(r, Pre)) && (c == \at(c, Pre)) && (num == \at(num, Pre))); // Validity when r <= 0
      loop assigns r, num, ret;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        ret = num / c;
        num %= c;
    }

    return ret;
}
