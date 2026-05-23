
/*@
  logic integer count_divisors(integer n, integer limit) =
    limit <= 0 ? 0
               : count_divisors(n, limit - 1) + (n % limit == 0 ? 1 : 0);
*/

const char * foo164(int number) {

    int result = 0;

    /*@
      loop invariant number == \at(number, Pre);
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
