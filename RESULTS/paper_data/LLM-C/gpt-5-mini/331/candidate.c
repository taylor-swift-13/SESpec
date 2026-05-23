int computeLastDigit(int n, int c);

/*@
    requires n <= c;
    assigns \nothing;
    ensures 0 <= \result && \result <= 9;
    behavior equal:
        assumes n == c;
        ensures \result == 1;
    behavior zero:
        assumes c - n >= 5;
        ensures \result == 0;
    behavior small_range:
        assumes 0 <= c - n && c - n < 5 && n < c;
        ensures \result == (\product integer i; n+1 <= i <= c; (i % 10)) % 10;
    complete behaviors equal, zero, small_range;
    disjoint behaviors equal, zero, small_range;
*/
int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			/*@
			    loop invariant n+1 <= index <= c+1;
			    loop invariant 0 <= result && result <= 9;
			    loop invariant result == (\product integer j; n+1 <= j <= index-1; (j % 10)) % 10;
			    loop assigns index, result;
			    loop variant c+1 - index;
			*/
			for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
			return result % 10;
		}
}
