/*@
    requires p >= 0;
    assigns \nothing;
    ensures \result == \sum integer i; 1 <= i <= p; (2*i)*(2*i)*(2*i)*(2*i);
*/
int evenPowerSum(int p);

int evenPowerSum(int p) {

		int even = 0;
		/*@
		    loop invariant 1 <= c <= p+1;
		    loop invariant even == \sum integer i; 1 <= i <= c-1; (2*i)*(2*i)*(2*i)*(2*i);
		    loop assigns c, even;
		    loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
		return even;
}
