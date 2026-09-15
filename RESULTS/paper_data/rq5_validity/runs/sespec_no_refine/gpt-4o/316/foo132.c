
/*@
  logic integer square(integer x) = x * x;
*/

/*@
  requires number > 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures number == 1 ==> \result == 1;
  ensures number > 1 ==> \result >= 0;
*/
int foo132(int number) {
    int result = 0;
    if (number == 1)
        return 1;

    /*@
      loop invariant result >= 0;
      loop assigns c, result;
      loop variant number / c - c;
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
