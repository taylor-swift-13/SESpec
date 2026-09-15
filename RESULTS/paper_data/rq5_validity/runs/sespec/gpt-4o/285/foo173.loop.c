
/*@
  logic integer count_divisors(integer n, integer lo, integer hi) =
    lo > hi ? 0
            : count_divisors(n, lo, hi - 1) + (hi > 0 && n % hi == 0 ? 1 : 0);
*/

/*@
  requires n >= 0;
  ensures \result == ((count_divisors(n, 1, n) % 2 == 0) ? "Even" : "Odd");
*/
const char * foo173(int n) {

    int count = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant count == count_divisors(n, 1, i - 1);
      loop invariant n == \at(n, Pre);
      loop assigns i, count;
    */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    if (count % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}
