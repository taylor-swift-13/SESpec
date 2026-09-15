/*@
  logic integer pow10(integer k) =
    k <= 0 ? 1 : 10 * pow10(k-1);
*/

/*@
    requires c != 0;
    requires r >= 0;
    assigns \nothing;
    ensures 0 <= \result < 10;
    ensures \result == (((\old(num) * pow10(\old(r))) / c) % 10);
*/
int findNthDigit(int num, int c, int r) {

		int result = 0;
		/*@
		    loop invariant 0 <= r <= \old(r);
		    loop invariant \exists integer q; \old(num) * pow10(\old(r) - r) == q * c + num && result == q % 10;
		    loop assigns r, num, result;
		    loop variant r;
		*/
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}
