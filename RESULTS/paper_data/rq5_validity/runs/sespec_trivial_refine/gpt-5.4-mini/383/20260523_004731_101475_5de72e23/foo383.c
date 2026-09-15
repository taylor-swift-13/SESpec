
/*@ logic integer divisor_count(integer n, integer i) =
      i <= 0 ? 0 : divisor_count(n, i - 1) + ((n % i) == 0 ? 1 : 0); */
/*@
  assigns \nothing;
  ensures n < 1 ==> \result == 0;
  ensures n >= 1 ==> \result == divisor_count(n, n);
*/
int foo383(int n) {
    if (n < 1) {
        return 0;
    }

    int count = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant count == divisor_count(n, i - 1);
      loop assigns i, count;
      loop variant n - i + 1;
    */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    return count;
}
