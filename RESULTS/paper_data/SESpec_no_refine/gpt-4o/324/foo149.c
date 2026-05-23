
/*@
  logic integer factorial(integer n) =
    n <= 1 ? 1 : n * factorial(n - 1);
*/

/*@
  requires number >= 2;
  requires number == \at(number, Pre);
  ensures \result >= 0;
  ensures \result == factorial(number) % 10;
  assigns \nothing;
*/
int foo149(int number) {

    int first = 1;

    /*@
      loop invariant 2 <= c <= number + 1;
      loop invariant first == factorial(c - 1);
      loop invariant number == \at(number, Pre);
      loop assigns c, first;
    */
    for (int c = 2; c <= number; c++) {
        first *= c;
    }

    int result = 0;

    /*@
      loop invariant result >= 0;
      loop assigns first, result;
      loop variant first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    /*@
      assert result == factorial(number) % 10;
    */
    return result;
}
