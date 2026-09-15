int evenPowerSum(int p);

 /*@
     requires p >= 0;
     assigns \nothing;
     ensures \result == 16 * (\sum integer i=1..p i*i*i*i);
 */
int evenPowerSum(int p) {

		int odd = 0;
		/*@
		    loop invariant 1 <= c <= p+1;
		    loop invariant odd == 16 * (\sum integer i=1..(c-1) i*i*i*i);
		    loop assigns c, odd;
		    loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
