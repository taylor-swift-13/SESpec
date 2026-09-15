/*@
    requires number >= 0;
    assigns \nothing;
    ensures \result == "Even" || \result == "Odd";
    ensures (\exists integer r; r >= 0 &&
             r == (\sum integer c; 1 <= c <= number && number % c == 0 ? 1 : 0) &&
             ((r % 2 == 0) ==> \result == "Even") &&
             ((r % 2 != 0) ==> \result == "Odd"));
*/
const char * countDivisors(int number);

 /*@
    requires number >= 0;
    assigns \nothing;
    ensures \result == "Even" || \result == "Odd";
    ensures (\exists integer r; r >= 0 &&
             r == (\sum integer c; 1 <= c <= number && number % c == 0 ? 1 : 0) &&
             ((r % 2 == 0) ==> \result == "Even") &&
             ((r % 2 != 0) ==> \result == "Odd"));
*/
const char * countDivisors(int number) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= number + 1;
		    loop invariant 0 <= result <= c - 1;
		    loop invariant result == (\numof integer k; 1 <= k < c && number % k == 0);
		    loop assigns c, result;
		    loop variant number - c + 1;
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
