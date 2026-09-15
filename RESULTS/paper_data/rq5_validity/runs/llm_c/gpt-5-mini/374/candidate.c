int divisor(int number);

/*@
    requires number >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures number == 0 ==> \result == 0;
    ensures number >= 1 ==>
        \result == \sum integer i; 1 <= i <= number; ((number % i) == 0 ? 1 : 0);
*/
int divisor(int number) {

		int div = 0;
		/*@
		    loop invariant 1 <= c <= number + 1;
		    loop invariant div == \sum integer i; 1 <= i < c; ((number % i) == 0 ? 1 : 0);
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
