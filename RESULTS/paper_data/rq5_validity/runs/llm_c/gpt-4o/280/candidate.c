/*@
    requires number > 0;
    ensures \result == "Even" || \result == "Odd";
    ensures \result == "Even" <==> (\exists integer result; result == (\sum integer c; 1 <= c <= number && number % c == 0) && result % 2 == 0);
    ensures \result == "Odd" <==> (\exists integer result; result == (\sum integer c; 1 <= c <= number && number % c == 0) && result % 2 != 0);
    assigns \nothing;
*/
const char * countDivisors(int number) {

		int result = 0;
		/*@
        loop invariant 1 <= c <= number + 1;
        loop invariant result == (\sum integer k; 1 <= k < c && number % k == 0);
        loop assigns c, result;
        loop variant number - c;
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
