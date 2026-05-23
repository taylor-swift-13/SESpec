
/*@
  logic integer count_div(integer n, integer k) =
    k <= 0 ? 0 : count_div(n, k - 1) + ((n % k) == 0 ? 1 : 0);
*/

/*@
   requires number >= 0;
   assigns \nothing;
   ensures \result == count_div(number, number);
   ensures number == 0 ==> \result == 0;
   ensures number > 0 ==> \result >= 0;
 */
int foo374(int number) {
    int div = 0;

    /*@
      loop invariant 1 <= c <= \at(number,Pre) + 1;
      loop invariant 0 <= div <= c - 1;
      loop invariant div == count_div(\at(number,Pre), c - 1);
      loop invariant number == \at(number,Pre);
      loop assigns c, div;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }

    return div;
}
