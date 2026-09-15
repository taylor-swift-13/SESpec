/*@
    requires number >= 0;
    assigns \nothing;
    ensures \result >= 1;
*/
int divisor(int number);

 /*@
    requires number >= 0;
    assigns \nothing;
    ensures \result >= 1;
*/
int divisor(int number) {

		int div = 0;
		/*@
		    loop invariant 1 <= c <= number + 1;
		    loop invariant div >= 0;
		    loop invariant div == \numof{integer k; 1 <= k < c && number % k == 0};
		    loop assigns c, div;
		    loop variant number - c + 1;
		*/
		for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				div++;
			}
		}
		return div;
}
