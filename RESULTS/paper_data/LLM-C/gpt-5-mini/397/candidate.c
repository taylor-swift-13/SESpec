int evenPowerSum(int p);

 /*@
     requires p >= 0;
     assigns \nothing;
     ensures \result == \sum integer k; 1 <= k <= p; 16*k*k*k*k;
 */
int evenPowerSum(int p) {

		int even = 0;
		/*@
		    loop invariant 1 <= c && c <= p + 1;
		    loop invariant even == \sum integer i; 1 <= i < c; 16*i*i*i*i;
		    loop assigns c, even, tmp;
		    loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}
