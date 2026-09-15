
/*@
  logic integer gcd(int a, int b) =
    (b == 0) ? a : gcd(b, a % b);
*/

/*@
  requires n > 0 && y > 0;
  assigns n, y, ret, l;
  ensures \result == (n * y) / gcd(\old(n), \old(y));
  ensures n == \old(y) && y == \old(n);
*/
int foo135(int n, int y) {

    int ret = 1;
    int l = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }

    /*@
      loop invariant 1 <= j <= n;
      loop invariant ret == gcd(\old(n), \old(y)) || ret == 1;
      loop assigns j, ret;
      loop variant n - j;
    */
    for (int j = 1; j <= n; j++) {
        if (n % j == 0 && y % j == 0) {
            ret = j;
        }
    }

    l = (n * y) / ret;
    return l;
}
