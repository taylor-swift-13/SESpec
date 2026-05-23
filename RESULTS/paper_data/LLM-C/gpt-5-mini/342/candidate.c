int countNo(int code, int b, int l, int m);

/*@
    requires code != 0;
    requires b >= 0;
    requires l <= m + 1;
    assigns \nothing;
    ensures \result == -1 <==> (\num_of integer i; l <= i <= m && (i % code) != 0) < b;
    ensures \result != -1 ==> (l <= \result <= m
                                && (\num_of integer i; l <= i <= \result && (i % code) != 0) == b
                                && \forall integer j; l <= j < \result ==> (\num_of integer i; l <= i <= j && (i % code) != 0) < b);
*/
int countNo(int code, int b, int l, int m) {

		int result = 0;
		/*@
		    loop invariant l <= c <= m+1;
		    loop invariant result >= 0;
		    loop invariant result == (\num_of integer i; l <= i < c && (i % code) != 0);
		    loop assigns c, result;
		    loop variant m - c + 1;
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
