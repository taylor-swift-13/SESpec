
/*@
  logic integer count_divisors_upto(integer n, integer k) =
    (k <= 1) ? 0 :
    (n % (k - 1) == 0 ? 1 : 0) + count_divisors_upto(n, k - 1);
*/

int foo372(int num) {

    int div = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant 0 <= div;
      loop invariant num == \at(num,Pre);
      loop assigns c, div;
    */
    for (int c = 1; c <= num; c++) {
        if (num % c == 0) {
            div++;
        }
    }

    return div;
}
