
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
  requires n > 0 && y > 0;
  assigns \nothing;
  ensures \result == (n * y) / gcd(n, y);
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
      loop invariant 1 <= l <= n;
      loop invariant valid_ret(\at(n,Pre), \at(y,Pre), ret);
      loop invariant n == \at(n,Pre) && y == \at(y,Pre);
      loop assigns l, ret;
      loop variant n - l;
    */
    for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l;
        }
    }

    g = (n * y) / ret;
    return g;
}
