
/*@
  logic integer count_divisors(integer num, integer limit) =
    (limit <= 0) ? 0 : (num % limit == 0 ? 1 : 0) + count_divisors(num, limit - 1);
*/

int foo283(int number) {

    int div = 0;

    /*@
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
