
/*@
  logic integer factorial(integer n) =
    (n <= 1) ? 1 : n * factorial(n - 1);
*/

/*@
  requires (first == 1) * (num == \at(num,Pre));
*/
int foo151(int num) {

    int first = 1;

    /*@
      loop invariant 2 <= c <= \at(num,Pre) + 1;
      loop invariant first == factorial(c - 1);
      loop invariant num == \at(num,Pre);
      loop assigns c, first;
    */
    for (int c = 2; c <= num; c++) {
        first *= c;
    }

    int result = 0;
    /*@
      loop invariant first >= 0;
      loop assigns result, first;
    */

    /*@
      loop invariant first >= 0;
      loop invariant (first == 0) ==> (result >= 0 && result <= 9);
      loop assigns result, first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    return result;
}
