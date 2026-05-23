
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer sum_of_even_powers(integer p) =
    p <= 0 ? 0 : power(2 * p, 4) + sum_of_even_powers(p - 1);
*/

/*@
  requires p >= 0;
  assigns \nothing;
*/
int foo321(int p) {

    int odd = 0;

    /*@
      loop invariant 1 <= c <= p + 1;
      loop invariant p == \at(p, Pre);
      loop assigns c, odd;
      loop variant p - c;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }

    return odd;
}
