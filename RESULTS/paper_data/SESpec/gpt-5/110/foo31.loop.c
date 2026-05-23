
/*@
  predicate is_common_divisor(integer a, integer b, integer d) =
    d >= 1 && a % d == 0 && b % d == 0;
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
		  loop invariant 1 <= i;
		  loop invariant i <= num1 + 1;
		  loop invariant i <= num2 + 1;
		  loop invariant result >= 1;
		  loop invariant result <= i;
		  loop invariant is_common_divisor(num1, num2, result);
		  loop invariant \forall integer d; 1 <= d < i ==> (is_common_divisor(num1, num2, d) ==> d <= result);
		  loop assigns i, result;
		*/
		for (int i = 1; i <= num1 && i <= num2; i++) {
			if (num1 % i == 0 && num2 % i == 0) {
				result = i;
			}
		}

		return result;
}
