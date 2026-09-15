
/*@
  logic integer integer_division(integer a, integer b) = (b != 0) ? a / b : 0;
*/

/*@
  logic integer integer_modulo(integer a, integer b) = (b != 0) ? a % b : 0;
*/

/*@
  logic integer count_divisors(integer num, integer limit) =
    (limit <= 1) ? 0 :
    (num % limit == 0) ? 1 + count_divisors(num, limit - 1) :
                         count_divisors(num, limit - 1);
*/

/*@
  requires num >= 1;
  ensures \result >= 0;
  ensures \result == count_divisors(num, num / 2);
*/
int foo134(int num) {

    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant result >= 0;
      loop assigns c, result;
    */
    for (int c = 2; c <= num / c; c++) {
        if (num % c == 0) {
            result++;
            if (num / c == c) {
                break;
            }
        }
    }

    return result;
}
