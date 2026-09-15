
/*@
  requires n >= 0;
  requires m > 0;
  assigns \nothing;
  ensures \result == -1 || (0 <= \result && \result <= n);
  ensures \result != -1 ==> \result % m == 0;
  ensures \result != -1 ==> \exists integer k; 0 <= k <= n && k % m == 0 && \result == k;
  ensures \result == -1 ==> \forall integer k; 0 <= k <= n ==> k % m != 0;
*/
int foo385(int n, int m) {
  /*@
    loop invariant -1 <= i <= n;
    loop invariant \forall integer k; i < k <= n ==> k % m != 0;
    loop assigns i;
    loop variant i + 1;
  */
  for (int i = n; i >= 0; i--) {
    if (i % m == 0) {
      return i;
    }
  }

  return -1;
}
