
/*@
  requires m > 0;
  requires n >= 0;
  assigns \nothing;
  ensures \result == -1 ==> (\forall integer k; 0 <= k <= n ==> k % m != 0);
  ensures \result != -1 ==> (\forall integer k; \result < k <= n ==> k % m != 0);
*/
int foo385(int n, int m) {
    /*@
      loop invariant 0 <= i <= n + 1;
      loop invariant m > 0;
      loop invariant n >= 0;
      loop invariant m == \at(m,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant \forall integer k; i <= k <= n ==> k % m != 0 || k == i;
      loop invariant (i >= 0) ==> (\forall integer k; i <= k <= n ==> k % m != 0 || k == i);
      loop invariant (!(i >= 0)) ==> ((m == \at(m,Pre)) && (n == \at(n,Pre)));
      loop assigns i;
      loop variant i;
    */
    for (int i = n; i >= 0; i--) {
        if (i % m == 0) {
            return i;
        }
    }
    return -1;
}
