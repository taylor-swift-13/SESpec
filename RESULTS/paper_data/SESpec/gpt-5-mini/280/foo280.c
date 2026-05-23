
/*@
  logic integer count_div_prefix(integer n, integer a, integer b) =
    a >= b ? 0
    : ((n % a) == 0 ? 1 + count_div_prefix(n, a + 1, b) : count_div_prefix(n, a + 1, b));
*/
/*@
   requires \true;
   assigns \nothing;
   ensures \result == \null ==> \false;
   ensures \result != \null;
 */
const char * foo280(int number) {

    int result = 0;

    /*@
      loop invariant 1 <= c;
      loop invariant 0 <= result <= c - 1;
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
