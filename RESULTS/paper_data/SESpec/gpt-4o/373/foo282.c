
/*@
  logic integer count_divisors(integer n, integer limit) =
    (limit == 0) ? 0 :
    (n % limit == 0 ? 1 : 0) + count_divisors(n, limit - 1);
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result == count_divisors(number, number);
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
