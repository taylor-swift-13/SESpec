/*@
    requires num1 >= INT_MIN && num1 <= INT_MAX;
    requires num2 >= INT_MIN && num2 <= INT_MAX;
    ensures \result >= -1;
    ensures \result == -1 <==> (num1 == 0 && num2 == 0);
    ensures \result >= 0 ==> \result == 0 || (\exists integer k1, k2; num1 == k1 * \result && num2 == k2 * \result && \forall integer d; d > 0 && d <= \result ==> (num1 % d == 0 && num2 % d == 0));
    assigns \nothing;
*/
int gcd(int num1, int num2) {

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
        loop invariant result >= 1;
        loop invariant \forall integer j; 1 <= j < i ==> (num1 % j == 0 && num2 % j == 0) ==> result >= j;
        loop assigns i, result;
        loop variant num1 + 1 - i;
        */
		for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
       			result = i;
			}
        }
		return result;
}
