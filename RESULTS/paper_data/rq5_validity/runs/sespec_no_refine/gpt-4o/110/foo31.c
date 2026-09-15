
/*@
  logic integer gcd_logic(integer a, integer b) =
    (b == 0) ? a : gcd_logic(b, a % b);
*/

/*@
  requires num1 >= INT_MIN && num1 <= INT_MAX;
  requires num2 >= INT_MIN && num2 <= INT_MAX;
  ensures \result == gcd_logic(\abs(num1), \abs(num2));
  ensures \result >= 0;
  ensures (num1 == 0 && num2 == 0) ==> \result == -1;
  ensures (num1 == 0 || num2 == 0) ==> \result == \max(\abs(num1), \abs(num2));
  ensures (num1 != 0 && num2 != 0) ==> \result == max_divisor(\abs(num1), \abs(num2), \min(\abs(num1), \abs(num2)));
  assigns \nothing;
*/
int foo31(int num1, int num2) {

    int result = 1;
    num1 = (0 <= num1) ? num1 : -num1;
    num2 = (0 <= num2) ? num2 : -num2;

    if (num1 == 0 && num2 == 0) {
        return -1;
    }

    if (num1 == 0 || num2 == 0) {
        return (num1 > num2) ? num1 : num2;
    }

    /*@
      loop invariant 1 <= i <= \min(num1, num2) + 1;
      loop invariant result > 0;
      loop invariant result <= i - 1;
      loop invariant result == max_divisor(num1, num2, i - 1);
      loop assigns i, result;
      loop variant \min(num1, num2) - i;
    */
    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            result = i;
        }
    }

    return result;
}
