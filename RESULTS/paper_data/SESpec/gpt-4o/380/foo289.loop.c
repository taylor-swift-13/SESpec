
/*@
  logic integer sum_of_divisors(int n) =
    \sum(1, n / 2, \lambda integer i; (n % i == 0) ? i : 0);
*/

/*@
  requires number >= 0;
  ensures \result == sum_of_divisors(number);
*/
int foo289(int number) {
    int sum = 0;

    /*@
      loop invariant 1 <= i <= number / 2 + 1;
      loop invariant number == \at(number, Pre);
      loop assigns i, sum;
    */
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return sum;
}
