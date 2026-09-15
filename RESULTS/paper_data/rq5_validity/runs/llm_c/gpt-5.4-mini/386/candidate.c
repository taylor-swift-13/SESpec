/*@
    requires b > 0;
    requires r >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int findNthDigit(int num, int b, int r);

 /*@
    requires b > 0;
    requires r >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int findNthDigit(int num, int b, int r) {

		int result = 0;
		/*@
		    loop invariant r >= 0;
		    loop invariant b > 0;
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
