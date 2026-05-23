
/*@ 
  logic integer factorial(integer n) = 
    (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result >= 0 && \result < 10;
*/
int foo149(int number) {

    int first = 1;

    /*@
      loop invariant number == \at(number,Pre);
      loop invariant 2 <= c <= number + 1 || c == 2; // Adjusted invariant to include initial value
      loop invariant first == factorial(c - 1);
      loop assigns first;
      loop variant number - c;
    */
    for (int c = 2; c <= number; c++) {
        first *= c;
    }

    int result = 0;

    /*@
      loop invariant first >= 0;
      loop invariant result >= 0 && result < 10;
      loop assigns first, result;
      loop variant first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    return result;
}
