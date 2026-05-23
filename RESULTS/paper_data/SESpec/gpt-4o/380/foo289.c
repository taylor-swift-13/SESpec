
/*@
  logic integer sum_of_divisors(int n) =
    \sum(1, n / 2, \lambda integer i; (n % i == 0) ? i : 0);
*/

/*@
  requires number >= 0; // Ensure number is non-negative
  requires number <= 100000; // Add an upper bound to prevent overflow
  assigns \nothing;
*/
int foo289(int number) {
    int sum = 0;

    /*@
      loop invariant 1 <= i <= number / 2 + 1; // Bounds for i
      loop invariant number == \at(number, Pre); // number remains unchanged
      loop assigns i, sum; // Variables modified in the loop
      loop variant number / 2 - i; // Decreasing variant to ensure termination
    */
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return sum;
}
