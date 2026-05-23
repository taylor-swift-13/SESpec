
/*@
  requires number >= 0;
  ensures \result >= 0;
*/
int foo316(int number) {
    int result = 0;
    if (number == 1)
        return 1;

    /*@
      loop invariant result >= 0;
      loop invariant \forall integer k; 2 <= k < c ==> (number % k == 0 ==> result >= 1);
      loop invariant (!(c <= number / c)) ==> (result >= 0);
      loop assigns c, result;
    */
    for (int c = 2; c <= number / c; c++) {
        if (number % c == 0) {
            result++;
            if (number / c == c) {
                break;
            }
        }
    }

    return result;
}
