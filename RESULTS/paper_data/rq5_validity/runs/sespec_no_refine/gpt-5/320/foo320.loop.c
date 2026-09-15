
/*@
  // No additional predicates or logic functions are required.
*/
int foo320(int n, int y) {

    int ret = 1;
    int g = 1;
    if (n > y) {
        int r = n;
        n = y;
        y = r;
    }

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant 1 <= l <= n + 1;
      loop invariant ret >= 1;
      loop invariant n == \at(y,Pre);
      loop invariant y == \at(n,Pre);
      loop invariant g == 1;
      loop invariant (n % ret == 0) && (y % ret == 0);
      loop invariant \forall integer d; 1 <= d < l ==> (((n % d == 0) && (y % d == 0)) ==> d <= ret);
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
