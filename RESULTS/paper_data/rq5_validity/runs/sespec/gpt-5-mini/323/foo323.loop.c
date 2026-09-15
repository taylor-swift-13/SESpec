
/*@
  logic integer divisors_count_prefix(integer n, integer up) =
    up <= 2 ? 0
    : (n % (up - 1) == 0 ? divisors_count_prefix(n, up - 1) + 1
                         : divisors_count_prefix(n, up - 1));
*/

int foo323(int n) {

    int count = 0;
    if (n == 1) return 1;

    /*@
      loop invariant 2 <= i;                                   // established at loop entry (i == 2)
      loop invariant 0 <= count <= i - 2;                      // count is non-negative and at most processed indices
      loop invariant count == divisors_count_prefix(n, i);     // functional progress: count equals number of divisors in [2, i)
      loop invariant (i <= n / i) ==> (count >= 0);            // preserved trivial goal-shaped clause
      loop invariant (!(i <= n / i)) ==> (i > n / i);          // explicit negation form
      loop assigns i, count;
    */
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            count++;
            if (n / i == i) {
                break;
            }
        }
    }

    return count;
}
