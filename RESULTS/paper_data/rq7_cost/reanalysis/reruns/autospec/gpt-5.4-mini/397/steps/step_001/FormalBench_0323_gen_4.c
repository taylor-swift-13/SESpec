int evenPowerSum(int p);

int evenPowerSum(int p) {

		int even = 0;
		/*@
		loop invariant 0 <= c <= p + 1;
		loop invariant even >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k);
		loop assigns c;
		loop assigns even;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}
