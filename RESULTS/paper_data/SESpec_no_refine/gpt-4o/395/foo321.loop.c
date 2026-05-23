
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer sum_of_powers(integer n) =
    n <= 0 ? 0 : power(2 * n, 4) + sum_of_powers(n - 1);
*/

/*@
  requires p >= 0;
  ensures \result == sum_of_powers(p);
*/
int foo321(int p) {

    int odd = 0;

    /*@
      loop invariant 1 <= c <= p + 1;
      loop invariant odd == sum_of_powers(c - 1);
      loop invariant p == \at(p,Pre);
      loop assigns c, tmp, odd;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }

    return odd;
}
