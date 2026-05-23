
/*@
  logic integer sum_to(integer n) = n <= 0 ? 0 : n + sum_to(n - 1);
*/

int foo289(int number) {
    int sum = 0;

    /*@
      loop invariant number == \at(number,Pre);
      loop assigns i, sum;
    */
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return sum;
}
