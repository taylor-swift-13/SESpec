
/*@
  predicate gcd_condition(int n, int y, int j) = 
    (n % j == 0 && y % j == 0);
*/

int foo319(int n, int y) {

    int ret = 1;
    int l = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }

    /*@
      loop invariant ret >= 1;
      loop invariant ret <= j;
      loop invariant \forall int k; 1 <= k < j ==> (gcd_condition(n, y, k) ==> ret >= k);
      loop invariant \exists int k; 1 <= k <= j && gcd_condition(n, y, k) && ret == k;
      loop invariant l == 1;
      loop invariant n <= y;
      loop assigns j, ret;
    */
    for (int j = 1; j <= n; j++) {
        if (n % j == 0 && y % j == 0) {
            ret = j;
        }
    }

    l = (n * y) / ret;
    return l;
}
