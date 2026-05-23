/*@
    requires num >= 0 && c >= 0;
    ensures \result >= 0 && \result < 10;
    behavior equal_case:
        assumes num == c;
        ensures \result == 1;
    behavior large_difference:
        assumes c - num >= 5;
        ensures \result == 0;
    behavior general_case:
        assumes c - num < 5 && num != c;
        ensures \result >= 0 && \result < 10;
    complete behaviors equal_case, large_difference, general_case;
    disjoint behaviors equal_case, large_difference, general_case;
*/
int computeLastDigit(int num, int c) {

		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
			/*@
			    loop invariant num + 1 <= var <= c + 1;
			    loop invariant result >= 0 && result < 10;
			    loop assigns var, result;
			    loop variant c - var;
			*/
			for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
