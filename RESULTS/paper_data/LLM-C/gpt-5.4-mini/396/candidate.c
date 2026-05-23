/*@
    requires p >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int evenPowerSum(int p);

 /*@
    requires p >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int evenPowerSum(int p) {

		int even = 0;
		/*@
		    loop invariant 1 <= c <= p + 1;
		    loop invariant even >= 0;
		    loop assigns c, even, count;
		    loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
}
