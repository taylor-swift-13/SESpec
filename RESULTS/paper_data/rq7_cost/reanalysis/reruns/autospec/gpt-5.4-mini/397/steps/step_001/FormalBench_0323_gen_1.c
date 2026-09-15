int evenPowerSum(int p);

int evenPowerSum(int p) {

		int even = 0;
		/*@
		loop invariant 1 <= c <= p + 1;
		loop invariant even >= 0;
		loop invariant \exists integer k; 0 <= k < c ==> even == \sum(integer i; 1 <= i < c; (2*i)*(2*i)*(2*i)*(2*i));
		loop assigns c;
		loop assigns even;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}
