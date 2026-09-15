
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer sum_of_even_powers(integer n) =
    n <= 0 ? 0 : power(2 * n, 4) + sum_of_even_powers(n - 1);
*/

/*@
  requires (even == 0) * (p == \at(p,Pre));
*/
int foo323(int p) {

    int even = 0;

    /*@
      loop invariant 1 <= c <= \at(p,Pre) + 1;
      loop invariant even == sum_of_even_powers(c - 1);
      loop invariant p == \at(p,Pre);
      loop assigns c, tmp, even;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        even = even + (tmp * tmp * tmp * tmp);
    }

    return even;
}
