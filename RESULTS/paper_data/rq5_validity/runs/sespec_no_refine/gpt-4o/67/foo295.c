
/*@
  requires n >= 0;
  requires k >= 0 && k <= n;
  assigns \nothing;
  ensures \result == combination(n, k);
*/
int foo295(int n, int k) {

    if (k > n - k)
        k = n - k;
    int c = 1;

    /*@
      loop invariant n == \at(n,Pre);
      loop invariant 0 <= i <= k + 1;
      loop invariant c == combination(n, i - 1);
      loop assigns i, c;
      loop variant k - i;
    */
    for (int i = 1; i <= k; i++) {
        c = c * (n - i + 1) / i;
    }

    return c;
}
