
/*@
  assigns \nothing;
*/
int foo385(int n, int m) {

    /*@
      loop invariant i == n ==> (\forall integer k; 0 <= k && k <= n ==> \true);
      loop invariant (i >= 0) ==> (0 <= i <= n);
      loop invariant \forall integer k; i < k && k <= n ==> k % m != 0;
      loop invariant (i < 0) ==> (\forall integer k; 0 <= k && k <= n ==> k % m != 0);
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
