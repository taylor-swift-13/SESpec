
/*@
  logic integer count_divisors(integer n, integer i) =
    (i <= 0) ? 0 : (n % i == 0 ? 1 : 0) + count_divisors(n, i - 1);
*/

/*@
  requires n >= 0;
  ensures \result == count_divisors(n, n);
*/
int foo294(int n) {

    int count = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant count == count_divisors(n, i - 1);
      loop invariant n == \at(n,Pre);
      loop assigns i, count;
    */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    return count;
}
