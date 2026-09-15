
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer sum_of_even_powers(integer n) =
    n <= 0 ? 0 : power(2 * n, 4) + sum_of_even_powers(n - 1);
*/

int foo321(int p) {

    int odd = 0;

    /*@
      loop invariant p == \at(p,Pre);
      loop assigns c, odd;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }

    return odd;
}
