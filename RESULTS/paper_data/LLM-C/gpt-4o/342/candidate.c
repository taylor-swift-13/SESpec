/*@
    requires code != 0;
    requires l <= m;
    ensures \result == -1 || (l <= \result <= m && \let count = (\num_of integer c; l <= c <= \result && c % code != 0); count == b);
    assigns \nothing;
*/
int countNo(int code, int b, int l, int m);

int countNo(int code, int b, int l, int m) {

		int result = 0;
		/*@
		loop invariant l <= c <= m + 1;
		loop invariant result >= 0;
		loop invariant \let count = (\num_of integer i; l <= i < c && i % code != 0); count == result;
		loop assigns c, result;
		loop variant m - c;
		*/
		for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				result++;
			}
			if (result == b) {
				return c;
			}
		}
		return -1;
}
