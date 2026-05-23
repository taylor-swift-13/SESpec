/*@
    requires c > 0;
    requires r >= 0;
    ensures \result >= 0 && \result < c;
    assigns \nothing;
*/
int findNthDigit(int num, int c, int r);

int findNthDigit(int num, int c, int r) {

		int ret = 0;
		/*@
		    loop invariant r >= 0;
		    loop invariant num >= 0;
		    loop invariant ret >= 0 && ret < c;
		    loop assigns r, num, ret;
		    loop variant r;
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
		return ret;
}
