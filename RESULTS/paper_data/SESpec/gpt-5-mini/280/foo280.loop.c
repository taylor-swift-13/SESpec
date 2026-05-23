
/*@
  logic integer count_div_prefix(int n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_div_prefix(n, lo, hi - 1) + (n % (hi - 1) == 0 ? 1 : 0);
*/

const char * foo280(int number) {

    int result = 0;

    /*@
      loop invariant 1 <= c;
      loop invariant 0 <= result <= c - 1;
      loop invariant result == count_div_prefix(number, 1, c);
      loop invariant number == \at(number,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            result++;
        }
    }

    if (result % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}
