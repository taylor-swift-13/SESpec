/*@
    requires code != 0;
    requires l <= m;
    requires b >= 0;
    assigns \nothing;
    ensures \result == -1 || (l <= \result <= m);
    ensures \result != -1 ==> 
        (\forall integer c; l <= c < \result ==> c % code == 0 || (\numof integer d; l <= d <= c && d % code != 0) < b);
*/
int countNo(int code, int b, int l, int m);

 /*@
    requires code != 0;
    requires l <= m;
    requires b >= 0;
    assigns \nothing;
    ensures \result == -1 || (l <= \result <= m);
*/
int countNo(int code, int b, int l, int m) {

		int result = 0;
		/*@
		    loop invariant l <= c <= m + 1;
		    loop invariant 0 <= result;
		    loop invariant result == \numof integer x; l <= x < c && x % code != 0;
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
