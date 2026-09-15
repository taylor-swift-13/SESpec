int evenPowerSum(int p);

int evenPowerSum(int p) {

		int odd = 0;
		/*@
		loop invariant 1 <= c <= p + 1;
		loop invariant odd == \sum(integer i, 1, c-1, (2*i)*(2*i)*(2*i)*(2*i));
		loop assigns c;
		loop assigns odd;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
