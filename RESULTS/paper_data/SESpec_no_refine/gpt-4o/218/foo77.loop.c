
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer largest_power_of_2_dividing(integer n) =
    n <= 0 ? 0 : (n % 2 != 0 ? 0 : 1 + largest_power_of_2_dividing(n / 2));
*/

int foo77(int n) {

    if (n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;
      loop invariant \exists integer k; n == \old(n) / power(2, k) && k == largest_power_of_2_dividing(\old(n));
      loop assigns n;
    */
    while (n % 2 == 0) {
        n /= 2;
    }

    return n == 1;
}
