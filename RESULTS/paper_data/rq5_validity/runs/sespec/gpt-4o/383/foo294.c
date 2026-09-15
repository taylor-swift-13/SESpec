
/*@
  logic integer count_divisors(integer n, integer i) =
    (i == 0) ? 0 : (n % i == 0 ? 1 : 0) + count_divisors(n, i - 1);
*/

/*@
  requires n >= 0;
  assigns \nothing;
  ensures \result == count_divisors(n, n);
*/
int foo294(int n) {

    int count = 0;

    /*@
      loop invariant n == \at(n, Pre);
      loop invariant count == count_divisors(n, i - 1);
      loop invariant 1 <= i <= n + 1;
      loop assigns i, count;
      loop variant n - i;
    */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    return count;
}
