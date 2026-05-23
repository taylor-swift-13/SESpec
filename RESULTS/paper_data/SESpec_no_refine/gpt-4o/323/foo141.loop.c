
/*@
  logic integer div_floor(integer a, integer b) = (a / b);
*/

/*@
  logic integer mod(integer a, integer b) = (a % b);
*/

/*@
  predicate is_divisor(integer n, integer i) = (mod(n, i) == 0);
*/

/*@
  predicate count_divisors(int n, integer count) =
    \exists integer i; 2 <= i <= div_floor(n, i) && is_divisor(n, i);
*/

int foo141(int n) {

    int count = 0;
    if (n == 1) return 1;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant (!(i <= n / i)) ==> ();
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
