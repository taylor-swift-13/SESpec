
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  requires \true;
  assigns c, y, x;
  ensures (k <= 0) ==> (c == 0 && y == 0 && x == 0);
  ensures (k > 0) ==> (c == k && y == k && x == polynomial_sum(k));
*/
void foo397(int k) {
    int y = 0;
    int x = 0;
    int c = 0;

    /*@
      loop invariant (0 < \at(k, Pre)) ==> (y == c);
      loop invariant (0 < \at(k, Pre)) ==> (c <= k);
      loop invariant (!(0 < \at(k, Pre))) ==> ((c == 0) && (x == 0) && (y == 0) && (k == \at(k, Pre)));
      loop invariant k == \at(k, Pre);
      loop assigns c, y, x;
    */
    while (c < k) {
        c = c + 1;
        y = y + 1;
        x = y * y * y * y * y + x;
    }
}
