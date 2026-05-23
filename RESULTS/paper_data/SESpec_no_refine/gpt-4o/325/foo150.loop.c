
/*@
  logic integer factorial(integer n) =
    (n <= 1) ? 1 : n * factorial(n - 1);
*/

/*@
  requires num >= 0;
  ensures \result >= 0 && \result <= 9;
  ensures factorial(num) == \result * 10^(num - 1) + \result * 10^(num - 2) + ... + \result;
*/
int foo150(int num) {

    int first = 1;

    /*@
      loop invariant 2 <= j <= num + 1;
      loop invariant first == factorial(j - 1);
      loop invariant num == \at(num, Pre);
      loop assigns j, first;
    */
    for (int j = 2; j <= num; j++) {
        first *= j;
    }

    int result = 0;

    /*@
      loop invariant first >= 0;
      loop invariant result >= 0 && result <= 9;
      loop invariant factorial(num) == (first * 10) + result;
      loop assigns result, first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    return result;
}
