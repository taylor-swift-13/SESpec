
/*@
  logic integer sum_of_divisors(int n) =
    \sum(1, n / 2, \lambda integer i; (n % i == 0) ? i : 0);
*/

/*@
  requires number >= 0;
  assigns \nothing;
*/
int foo289(int number) {
    int sum = 0;

    /*@
      loop invariant 1 <= i <= number / 2 + 1;
      loop invariant number == \at(number, Pre);
      loop assigns i, sum;
      loop variant number / 2 - i;
    */
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return sum;
}
