
/*@
  logic integer even_contrib(integer x) = (x % 2 == 0) ? x : 0;
*/

/*@
  logic integer sum_even_range(integer l, integer r) =
    (l > r) ? 0 : sum_even_range(l, r - 1) + even_contrib(r);
*/

/*@
  assigns \nothing;
  ensures l <= r ==> \result == sum_even_range(l, r - 1) + even_contrib(r);
*/
int foo379(int l, int r) {

        int sum = 0;

        /*@
          loop invariant r == \at(r,Pre);
          loop invariant l == \at(l,Pre);

          loop invariant i >= l;
          loop invariant (l <= r + 1) ==> (i <= r + 1);

          loop invariant sum == sum_even_range(l, i - 1);

          loop invariant \forall integer k; l <= k < i ==> (k % 2 == 0 ==> even_contrib(k) == k);
          loop invariant \forall integer k; l <= k < i ==> (k % 2 != 0 ==> even_contrib(k) == 0);

          loop assigns i, sum;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }

        return sum;
}
