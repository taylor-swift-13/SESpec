int divisor(int number);

/*@
    requires number >= 0;
    assigns \nothing;
    ensures 0 <= \result <= number;
    ensures \result == \numof integer i; 1 <= i <= number && number % i == 0;
*/
int divisor(int number) {

		int div = 0;
		/*@
		    loop invariant 1 <= index <= number + 1;
		    loop invariant 0 <= div <= number;
		    loop invariant div == \numof integer j; 1 <= j < index && number % j == 0;
		    loop assigns index, div;
		    loop variant number - index + 1;
		*/
		for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
		return div;
}
