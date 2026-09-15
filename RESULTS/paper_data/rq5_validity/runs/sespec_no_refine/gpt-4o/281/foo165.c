
/*@
  logic integer count_divisors(integer num, integer limit) =
    limit <= 0 ? 0 : count_divisors(num, limit - 1) + (num % limit == 0 ? 1 : 0);
*/

/*@
  requires num >= 0;
  assigns \nothing;
*/
const char * foo165(int num) {

    int result = 0;

    /*@
      loop invariant 1 <= index <= num + 1;
      loop invariant result == count_divisors(num, index - 1);
      loop invariant num == \at(num, Pre);
      loop assigns index, result;
    */
    for (int index = 1; index <= num; index++) {
        if (num % index == 0) {
            result++;
        }
    }

    /*@
      assert result == count_divisors(num, num);
    */
    if (result % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}
