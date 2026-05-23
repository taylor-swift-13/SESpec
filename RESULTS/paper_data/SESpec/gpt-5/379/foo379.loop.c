
/*@
  logic integer even_contrib(integer x) = (x % 2 == 0) ? x : 0;
*/

/* Sum of even contributions on the integer interval [a..b]. */
 /*@
   logic integer sum_even_range(integer a, integer b) =
     (a > b) ? 0 : even_contrib(b) + sum_even_range(a, b - 1);
 */

int foo379(int l, int r) {

        int sum = 0;

        /*@
          loop invariant r == \at(r,Pre);
          loop invariant l == \at(l,Pre);

          // i always starts at l and only increases by 1
          loop invariant i >= l;
          // only demand the usual upper bound when the loop could still run
          loop invariant (l <= r + 1) ==> (i <= r + 1);

          // functional meaning of sum at the loop head:
          // sum equals the sum of all even i' in [l .. i-1]
          loop invariant sum == sum_even_range(l, i - 1);

          // basic semantic facts about even_contrib on the processed prefix
          loop invariant \forall integer k; l <= k < i ==> (k % 2 == 0 ==> even_contrib(k) == k);
          loop invariant \forall integer k; l <= k < i ==> (k % 2 != 0 ==> even_contrib(k) == 0);

          // a useful bound when the interval is well-ordered

          loop assigns i, sum;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }

        return sum;
}
