/*@
    requires p >= 0;
    ensures \result == \sum(1 <= c <= p, (2 * c) * (2 * c) * (2 * c) * (2 * c));
*/
int evenPowerSum(int p);

int evenPowerSum(int p) {

		int odd = 0;
		/*@
		    loop invariant 1 <= c <= p + 1;
		    loop invariant odd == \sum(1 <= k < c, (2 * k) * (2 * k) * (2 * k) * (2 * k));
		    loop assigns c, odd, tmp;
		    loop variant p - c;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
