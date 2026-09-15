int evenPowerSum(int p);

int evenPowerSum(int p) {

		int odd = 0;
		/*@
		loop invariant 0 <= c <= p + 1;
		loop invariant odd >= 0;
		loop invariant \exists integer s; odd == s;
		loop assigns c;
		loop assigns odd;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
