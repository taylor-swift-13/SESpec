
/*@
  logic integer gcd_logic(integer a, integer b) =
    (b == 0) ? a : gcd_logic(b, a % b);
*/

/*@
  requires num1 >= INT_MIN && num1 <= INT_MAX;
  requires num2 >= INT_MIN && num2 <= INT_MAX;
  ensures \result == gcd_logic(\abs(num1), \abs(num2));
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
      loop invariant 1 <= i <= num1 + 1;
      loop invariant 1 <= i <= num2 + 1;
      loop invariant result > 0;
      loop invariant result <= i - 1;
      loop invariant result == \max(\lambda integer k; 1 <= k < i && num1 % k == 0 && num2 % k == 0 ? k : 1);
      loop assigns i, result;
    */
    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            result = i;
        }
    }

    return result;
}
