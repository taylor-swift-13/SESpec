
/*@
  logic integer factorial(integer n) =
    (n <= 1) ? 1 : n * factorial(n - 1);
*/

/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result >= 0 && \result <= 9;
*/
int foo150(int num) {

    int first = 1;

    /*@
      loop invariant num == \at(num, Pre);
      loop assigns j, first;
      loop variant num - j;
    */
    for (int j = 2; j <= num; j++) {
        first *= j;
    }

    int result = 0;

    /*@
      loop invariant result >= 0 && result <= 9;
      loop assigns result, first;
      loop variant first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    return result;
}
