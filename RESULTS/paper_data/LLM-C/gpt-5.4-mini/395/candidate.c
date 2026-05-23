/*@
    requires p >= 0;
    assigns \nothing;
    ensures \result ==
        \sum(1, p, \lambda integer c; 
            (2 * c) * (2 * c) * (2 * c) * (2 * c));
*/
int evenPowerSum(int p);

 /*@
    requires p >= 0;
    assigns \nothing;
    ensures \result ==
        \sum(1, p, \lambda integer c; 
            (2 * c) * (2 * c) * (2 * c) * (2 * c));
*/
int evenPowerSum(int p) {

		int odd = 0;
		/*@
		    loop invariant 1 <= c <= p + 1;
		    loop invariant odd ==
		        \sum(1, c - 1, \lambda integer k;
		            (2 * k) * (2 * k) * (2 * k) * (2 * k));
		    loop assigns c, odd, tmp;
		    loop variant p - c + 1;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
