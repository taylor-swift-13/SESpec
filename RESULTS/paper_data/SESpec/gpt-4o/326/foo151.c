
/*@ 
  logic integer factorial(integer n) = 
    (n == 0 ? 1 : n * factorial(n - 1));
*/

/*@
  requires num >= 1 && num <= 12; // Ensure num is within a safe range to avoid overflow and loop execution
  assigns \nothing;
  ensures \result >= 0 && \result < 10;
*/
int foo151(int num) {

    int first = 1;

    /*@
      loop invariant 2 <= c <= num + 1;
      loop invariant first == factorial(c - 1); // Ensure first represents factorial(c - 1)
      loop invariant num == \at(num, Pre);
      loop assigns c, first;
    */
    for (int c = 2; c <= num; c++) {
        first *= c;
    }

    int result = 0;

    /*@
      loop invariant first >= 0;
      loop invariant result >= 0 && result < 10;
      loop assigns result, first;
      loop variant first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    return result;
}
