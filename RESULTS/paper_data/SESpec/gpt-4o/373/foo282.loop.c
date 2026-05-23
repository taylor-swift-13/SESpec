
/*@
  logic integer count_divisors(integer num, integer limit) =
    (\sum integer i; 1 <= i <= limit && num % i == 0; 1);
*/

int foo282(int number) {

    int div = 0;

    /*@
      loop invariant 1 <= index <= number + 1;
      loop invariant div == count_divisors(\at(number, Pre), index - 1);
      loop invariant number == \at(number, Pre);
      loop assigns index, div;
    */
    for (int index = 1; index <= number; index++) {
        if (number % index == 0) {
            div++;
        }
    }

    return div;
}
