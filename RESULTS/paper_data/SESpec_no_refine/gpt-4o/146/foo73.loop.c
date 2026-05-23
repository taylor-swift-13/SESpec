
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  predicate is_power_of_4(integer n) =
    \exists integer k; k >= 0 && n == power(4, k);
*/

int foo73(int n) {

    if (n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;
      loop assigns n;
    */
    while (n % 4 == 0) {
        n /= 4;
    }

    return n == 1;
}
