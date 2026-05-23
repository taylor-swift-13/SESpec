
/*@
  requires ar_len >= 0;
  requires 0 <= n <= ar_len;
  requires n == 0 || \valid_read(ar + (0 .. n-1));
  assigns \nothing;

  ensures n <= 1 ==> \result == 1;
  ensures n > 1 ==> 1 <= \result <= n;

  ensures n > 1 && \result < n ==> ar[\result - 1] != \result;
  ensures n > 1 && \result < n ==> (\forall integer j; 1 <= j < \result ==> ar[j - 1] == j);

  ensures n > 1 && \result == n ==> (\forall integer j; 1 <= j < n ==> ar[j - 1] == j);
*/
int foo239(int *ar, int ar_len, int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant (\forall integer j; 1 <= j < i ==> ar[j - 1] == j);
      loop assigns i;
      loop variant n - i + 1;
    */
    for (int i = 1; i <= n; i++) {
        if (ar[i - 1] != i) {
            return i;
        }
    }

    return n;
}
