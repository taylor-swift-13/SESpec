
/*@
  logic integer count_divisors(integer n, integer limit) =
    limit <= 0 ? 0
               : count_divisors(n, limit - 1) + (n % limit == 0 ? 1 : 0);
*/

/*@
  requires num >= 0; // Ensure num is non-negative
  assigns \nothing;
*/
const char * foo166(int num) {

    int result = 0;

    /*@
      loop invariant 1 <= c <= num + 1;
      loop invariant result == count_divisors(num, c - 1);
      loop invariant num == \at(num, Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= num; c++) {
        if (num % c == 0) {
            result++;
        }
    }

    /*@
      assert result == count_divisors(num, num);
    */

    if (result % 2 == 0) {
        /*@
          assert count_divisors(num, num) % 2 == 0;
        */
        return "Even";
    } else {
        /*@
          assert count_divisors(num, num) % 2 != 0;
        */
        return "Odd";
    }
}
