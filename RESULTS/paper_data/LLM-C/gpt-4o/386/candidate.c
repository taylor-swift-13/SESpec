/*@
    requires b > 0;
    requires r >= 0;
    ensures \result >= 0 && \result < b;
    assigns \nothing;
*/
int findNthDigit(int num, int b, int r);

int findNthDigit(int num, int b, int r) {

		int result = 0;
		/*@
		    loop invariant r >= 0;
		    loop invariant num >= 0;
		    loop invariant result >= 0 && result < b;
		    loop assigns r, num, result;
		    loop variant r;
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
}
