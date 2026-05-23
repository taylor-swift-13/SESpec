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
		    loop assigns c, even, tmp;
		    loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}
