
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  predicate is_power_of_two(integer n) =
    n > 0 && (\exists integer k; n == power(2, k));
*/

int foo77(int n) {

    if (n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;
      loop assigns n;
    */
    while (n % 2 == 0) {
        n /= 2;
    }

    return n == 1;
}
