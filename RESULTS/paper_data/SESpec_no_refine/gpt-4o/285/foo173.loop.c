
/*@
  logic integer count_divisors(integer n, integer limit) =
    limit <= 0 ? 0 : count_divisors(n, limit - 1) + (n % limit == 0 ? 1 : 0);
*/

/*@
  requires n >= 0;
  ensures \result == ((count_divisors(n, n) % 2 == 0) ? "Even" : "Odd");
*/
const char * foo173(int n) {

    int count = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant count == count_divisors(n, i - 1);
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
