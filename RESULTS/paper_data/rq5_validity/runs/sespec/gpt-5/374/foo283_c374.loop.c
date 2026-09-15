
/*@
  // Counts how many integers in [1..k] divide n
  logic integer count_divisors_prefix(integer n, integer k) =
    (k <= 0) ? 0 : count_divisors_prefix(n, k - 1) + ((k != 0 && n % k == 0) ? 1 : 0);
*/

int foo283_c374(int number) {

    int div = 0;
        
    /*@
      loop invariant 1 <= c;
      loop invariant number == \at(number,Pre);
      loop invariant 0 <= div <= c - 1;
      loop invariant div == count_divisors_prefix(number, c - 1);
      loop assigns c, div;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }
        
    return div;
}
