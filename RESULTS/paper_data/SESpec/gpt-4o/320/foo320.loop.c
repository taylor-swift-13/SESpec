
/*@
  predicate gcd_property(integer n, integer y, integer l, integer ret) =
    (n % l == 0 && y % l == 0) ==> (ret >= l);
*/

int foo320(int n, int y) {

    int ret = 1;
    int g = 1;
    if (n > y) {
        int r = n;
        n = y;
        y = r;
    }

    /*@
      loop invariant ret >= 1;
      loop invariant \forall integer k; 1 <= k < l ==> gcd_property(n, y, k, ret);
      loop invariant \exists integer k; 1 <= k <= l && n % k == 0 && y % k == 0 && ret == k;
      loop invariant (l <= \at(y,Pre)) ==> ((ret >= 1) && (ret <= l));
      loop invariant g == 1;
      loop invariant y == \at(n,Pre) || y == \at(y,Pre);
      loop invariant n == \at(y,Pre) || n == \at(n,Pre);
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
