
/*@ predicate no_divisible_in_range(integer start, integer end, integer m) =
      \forall integer k; end < k <= start ==> (m == 0 ? \true : k % m != 0);
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
