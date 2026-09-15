
/*@
  logic integer count_divisors(int number, integer limit) =
    limit <= 0 ? 0 : count_divisors(number, limit - 1) + (number % limit == 0 ? 1 : 0);
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result == "Even" || \result == "Odd";
  ensures \result == "Even" <==> (count_divisors(number, number) % 2 == 0);
  ensures \result == "Odd" <==> (count_divisors(number, number) % 2 != 0);
*/
const char * foo280(int number) {

    int result = 0;

    /*@
      loop invariant 1 <= c <= number + 1;
      loop invariant 0 <= result <= c - 1;
      loop invariant result == count_divisors(number, c - 1);
      loop invariant number == \at(number, Pre);
      loop assigns c, result;
      loop variant number - c;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            result++;
        }
    }

    /*@
      ensures \result == "Even" ==> (result % 2 == 0);
      ensures \result == "Odd" ==> (result % 2 != 0);
      ensures result == count_divisors(number, number);
    */
    if (result % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}
