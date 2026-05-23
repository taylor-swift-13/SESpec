
/*@
  logic integer factorial(integer n) =
    (n <= 1) ? 1 : n * factorial(n - 1);
*/

/*@
  requires num >= 0;
  assigns \nothing;
*/
int foo151(int num) {

    int first = 1;

    /*@
      loop invariant num == \at(num,Pre);
      loop assigns first, c;
      loop variant num - c;
    */
    for (int c = 2; c <= num; c++) {
        first *= c;
    }

    int result = 0;

    /*@
      loop invariant (first == 0) ==> (result >= 0 && result <= 9);
      loop assigns result, first;
      loop variant first;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    return result;
}
