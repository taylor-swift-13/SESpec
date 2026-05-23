
/*@ 
  logic integer factorial(integer n) = 
    (n <= 1) ? 1 : n * factorial(n - 1);
*/
/*@
  requires num >= 0;
  requires num == \at(num, Pre);
  assigns \nothing;
  ensures \result >= 0 && \result <= 9;
  ensures num == \at(num, Pre);
*/
int foo325(int num) {

    int first = 1;

    /*@
      loop invariant num == \at(num, Pre);
      loop assigns j, first;
    */
    for (int j = 2; j <= num; j++) {
        first *= j;
    }

    int result = 0;

    /*@
      loop invariant result >= 0 && result <= 9;
      loop invariant num == \at(num, Pre);
      loop assigns first, result;
    */
    while (first > 0) {
        result = first % 10;
        first /= 10;
    }

    return result;
}
