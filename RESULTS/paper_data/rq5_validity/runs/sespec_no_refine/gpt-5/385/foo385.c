
/*@
  assigns \nothing;
  ensures
    (m != 0 && \result >= 0) ==> (\result <= n && \result % m == 0 && no_divisible_in_range(n, \result, m));
  ensures
    (m != 0 && \result == -1) ==> (\forall integer k; 0 <= k <= n ==> k % m != 0);
  ensures
    (m != 0) ==> (\result == -1 || (0 <= \result <= n));
*/
int foo385(int n, int m) {

    /*@
      loop invariant m == \at(m,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant i <= n;
      loop invariant no_divisible_in_range(n, i, m);
      loop invariant (!(i >= 0)) ==> ((m == \at(m,Pre))&&(n == \at(n,Pre)));
      loop invariant m == \at(m,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns i;
    */
    for (int i = n; i >= 0; i--) {
        if (i % m == 0) {
            return i;
        }
    }

    return -1;
}
