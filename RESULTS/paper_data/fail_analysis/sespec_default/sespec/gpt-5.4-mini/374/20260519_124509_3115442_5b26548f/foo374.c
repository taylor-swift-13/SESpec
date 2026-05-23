
/*@ logic integer divisor_count(integer n, integer c) =
      c > n ? 0 : ((n % c == 0) ? 1 : 0) + divisor_count(n, c + 1); */
/*@
  requires number >= 0;
  assigns \nothing;
*/
int foo374(int number) {

    int div = 0;

    /*@
      loop invariant 1 <= c;
      loop invariant number == \at(number,Pre);
      loop invariant div >= 0;
      loop assigns c, div;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }

    return div;
}
