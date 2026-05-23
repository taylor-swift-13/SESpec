/*@
    requires n >= 0 && c >= 0;
    ensures \result >= 0 && \result < 10;
    behavior equal_case:
        assumes n == c;
        ensures \result == 1;
    behavior large_difference_case:
        assumes c - n >= 5;
        ensures \result == 0;
    behavior general_case:
        assumes c - n < 5 && n != c;
        ensures \result == (\prod integer i; n+1 <= i <= c; (i % 10)) % 10;
    complete behaviors equal_case, large_difference_case, general_case;
    disjoint behaviors equal_case, large_difference_case, general_case;
*/
int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			/*@
			    loop invariant n+1 <= var <= c+1;
			    loop invariant result >= 0 && result < 10;
			    loop invariant result == (\prod integer i; n+1 <= i < var; (i % 10)) % 10;
			    loop assigns var, result;
			    loop variant c - var;
			*/
			for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
