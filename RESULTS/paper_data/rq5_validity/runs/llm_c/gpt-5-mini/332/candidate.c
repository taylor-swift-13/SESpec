int computeLastDigit(int num, int c);

/*@
    assigns \nothing;
    behavior equal:
        assumes num == c;
        ensures \result == 1;
    behavior large_diff:
        assumes c - num >= 5;
        ensures \result == 0;
    behavior small_range:
        assumes num != c && c - num < 5;
        ensures \result == (\product integer v; num+1 <= v <= c; v % 10) % 10;
    complete behaviors equal, large_diff, small_range;
    disjoint behaviors equal, large_diff, small_range;
*/
int computeLastDigit(int num, int c) {

		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
			/*@
			    loop invariant num+1 <= var <= c+1;
			    loop invariant result == (\product integer v; num+1 <= v < var; v % 10) % 10;
			    loop assigns var, result;
			    loop variant c+1 - var;
			*/
			for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
