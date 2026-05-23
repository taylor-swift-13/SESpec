/*@
    requires code != 0;
    requires l <= c;
    ensures \result == -1 || (l <= \result <= c && \let count = (\numof integer i; l <= i <= \result && i % code != 0); count == b);
    assigns \nothing;
*/
int countNo(int code, int b, int l, int c) {

		int ret = 0;
		/*@
		loop invariant l <= loop <= c + 1;
		loop invariant 0 <= ret <= b;
		loop invariant \forall integer i; l <= i < loop ==> (i % code != 0 ==> ret >= 1);
		loop invariant \forall integer i; l <= i < loop ==> (ret == b ==> \result == i);
		loop assigns loop, ret;
		loop variant c - loop;
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
