/*@
    requires num > 0;
    ensures \result == "Even" || \result == "Odd";
    ensures \result == "Even" <==> (\exists integer count; count == (\sum integer c; 1 <= c <= num && num % c == 0) && count % 2 == 0);
    ensures \result == "Odd" <==> (\exists integer count; count == (\sum integer c; 1 <= c <= num && num % c == 0) && count % 2 != 0);
    assigns \nothing;
*/
const char * countDivisors(int num) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= num + 1;
		    loop invariant result == (\sum integer k; 1 <= k < c && num % k == 0);
		    loop assigns c, result;
		    loop variant num - c;
		*/
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
