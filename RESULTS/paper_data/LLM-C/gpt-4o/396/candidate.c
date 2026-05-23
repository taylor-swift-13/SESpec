/*@
    requires p >= 0;
    ensures \result >= 0;
    ensures \result == \sum(1 <= c <= p, (2 * c) * (2 * c) * (2 * c) * (2 * c));
*/
int evenPowerSum(int p);

int evenPowerSum(int p) {

		int even = 0;
		/*@
		    loop invariant 1 <= c <= p + 1;
		    loop invariant even == \sum(1 <= k < c, (2 * k) * (2 * k) * (2 * k) * (2 * k));
		    loop assigns c, even;
		    loop variant p - c;
		*/
		for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
}
