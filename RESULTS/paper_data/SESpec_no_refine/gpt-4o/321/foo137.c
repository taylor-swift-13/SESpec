
/*@
  logic integer gcd(int a, int b) =
    b == 0 ? a : gcd(b, a % b);
*/

/*@
  logic integer lcm(int a, int b) =
    (a * b) / gcd(a, b);
*/

/*@
  predicate is_gcd(int a, int b, int g) =
    g > 0 && a % g == 0 && b % g == 0 &&
    \forall integer d; d > 0 && a % d == 0 && b % d == 0 ==> d <= g;
*/

/*@
  requires n > 0 && y > 0;
  assigns \nothing;
  ensures is_lcm(\old(n), \old(y), \result);
*/
int foo137(int n, int y) {

    int ret = 1;
    int r = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }

    /*@
      loop invariant 1 <= l <= n + 1;
      loop invariant (l <= \at(y,Pre)) ==> 
        (((r == 1) && (ret == 1) && (y == \at(n,Pre)) && (n == \at(y,Pre))) || 
         (ret > 0 && is_gcd(\at(n,Pre), \at(y,Pre), ret)));
      loop invariant (!(l <= \at(y,Pre))) ==> 
        ((r == 1) && (ret == 1) && (y == \at(n,Pre)) && (n == \at(y,Pre)));
      loop invariant r == 1;
      loop invariant y == \at(n,Pre);
      loop invariant n == \at(y,Pre);
      loop assigns l, ret;
    */
    for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l;
        }
    }

    r = (n * y) / ret;
    return r;
}
