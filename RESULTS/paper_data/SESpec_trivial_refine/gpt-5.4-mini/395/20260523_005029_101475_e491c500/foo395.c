
/*@
logic integer pow4(integer x) = x * x * x * x;

logic integer sum_even_pow4(integer n) =
  n <= 0 ? 0 : sum_even_pow4(n - 1) + pow4(2 * n);
*/

/*@
  assigns \nothing;
  ensures p <= 0 ==> \result == 0;
  ensures p > 0 ==> \result == sum_even_pow4(p);
  ensures \result >= 0;
*/
int foo395(int p) {
    if (p <= 0) {
        return 0;
    }

    int odd = 0;

    /*@
      loop invariant 1 <= c <= p + 1;
      loop invariant odd == sum_even_pow4(c - 1);
      loop invariant odd >= 0;
      loop assigns c, odd;
      loop variant p - c + 1;
    */
    for (int c = 1; c <= p; c++) {
        int tmp = 2 * c;
        odd = odd + (tmp * tmp * tmp * tmp);
    }

    return odd;
}
