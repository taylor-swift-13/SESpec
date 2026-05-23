
/*@
  logic integer gcd(int a, int b) = 
    (b == 0) ? a : gcd(b, a % b);
*/

/*@
  logic integer max_divisor(int a, int b, int limit) =
    (limit == 0) ? 0 : 
    ((a % limit == 0 && b % limit == 0) ? limit : max_divisor(a, b, limit - 1));
*/

/*@
  predicate valid_ret(int a, int b, int ret) =
    (ret == max_divisor(a, b, a < b ? a : b));
*/

int foo136(int n, int y) {

    int ret = 1;
    int g = 1;
    if (n > y) {
        int r = n;
        n = y;
        y = r;
    }

    /*@
      loop invariant (l <= \at(y,Pre)) ==> (((g == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre))) || valid_ret(\at(n,Pre), \at(y,Pre), ret));
      loop invariant (!(l <= \at(y,Pre))) ==> ((g == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre)));
      loop invariant g == 1;
      loop invariant y == \at(n,Pre);
      loop invariant n == \at(y,Pre);
      loop assigns l, ret;
    */
    for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l;
        }
    }

    g = (n * y) / ret;
    return g;
}
