int countNo(int code, int b, int l, int c);

/*@
    requires code != 0;
    assigns \nothing;
    /* If the function returns -1 then for every i in [l..c] the number of j in [l..i]
       with j % code != 0 is strictly less than b (i.e. b was never reached). */
    ensures \result == -1 <=>
        (\forall integer i; l <= i <= c ==>
            \sum integer j; l <= j <= i; ((j % code) != 0 ? 1 : 0) < b);
    /* If the function returns a value r != -1 then r is in [l..c] and the number
       of j in [l..r] with j % code != 0 is exactly b, and for every i < r that
       count is strictly less than b (first position reaching b). */
    ensures \result != -1 ==>
        (l <= \result <= c &&
         \sum integer j; l <= j <= \result; ((j % code) != 0 ? 1 : 0) == b &&
         (\forall integer i; l <= i < \result ==>
             \sum integer j; l <= j <= i; ((j % code) != 0 ? 1 : 0) < b));
*/
int countNo(int code, int b, int l, int c) {

		int ret = 0;
		/*@
		    loop invariant l <= loop <= c + 1;
		    loop invariant ret >= 0;
		    loop invariant ret == \sum integer j; l <= j <= loop-1; ((j % code) != 0 ? 1 : 0);
		    loop assigns loop, ret;
		    loop variant c - loop + 1;
		*/
		for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
		return -1;
}
