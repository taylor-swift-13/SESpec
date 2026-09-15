
/*@
  logic integer sum_of_odd_divisors(integer n) =
    \sum(1, n, \lambda integer i; (n % i == 0 && i % 2 != 0) ? i : 0);
*/

/*@
  requires n >= 0;
  assigns \nothing;
*/
int foo204(int n) {
    int sum = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant n == \at(n,Pre);
      loop assigns i, sum;
      loop variant n - i;
    */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
    }

    return sum;
}
