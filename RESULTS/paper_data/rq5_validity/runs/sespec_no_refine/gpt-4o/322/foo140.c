
/*@
  logic integer gcd_logic(integer a, integer b) =
    (b == 0) ? a : gcd_logic(b, a % b);
*/

/*@
  predicate gcd_property(integer a, integer b, integer g) =
    g > 0 && a % g == 0 && b % g == 0 &&
    (\forall integer k; k > 0 && a % k == 0 && b % k == 0 ==> k <= g);
*/

/*@
  requires x > 0 && y > 0;
  assigns x, y, gcd, foo140;
  ensures gcd_property(\old(x), \old(y), gcd);
  ensures foo140 == (\old(x) * \old(y)) / gcd;
  ensures \result == foo140;
*/
int foo140(int x, int y) {

    int gcd = 1;
    int foo140 = 1;
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

    /*@
      loop invariant 1 <= i <= x + 1;
      loop invariant gcd_property(x, y, gcd);
      loop assigns i, gcd;
      loop variant x - i;
    */
    for (int i = 1; i <= x; i++) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }

    foo140 = (x * y) / gcd;
    return foo140;
}
