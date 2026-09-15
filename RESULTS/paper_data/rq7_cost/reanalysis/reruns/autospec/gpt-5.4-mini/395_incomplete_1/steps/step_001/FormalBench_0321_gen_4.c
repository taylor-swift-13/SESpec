int evenPowerSum(int p);

int evenPowerSum(int p) {

		int odd = 0;
		/*@
		loop invariant 1 <= c <= p + 1;
		loop invariant odd >= 0;
		loop invariant odd == \sum(integer k, 1, c - 1, (2 * k) * (2 * k) * (2 * k) * (2 * k));
		loop assigns c;
		loop assigns odd;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
