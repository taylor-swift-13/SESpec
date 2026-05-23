/*@
    requires number >= 0;
    assigns \nothing;
    ensures \result >= 1;
*/
int divisor(int number);

int divisor(int number) {

		int div = 0;
		/*@
		    loop invariant 1 <= index <= number + 1;
		    loop invariant 0 <= div <= index - 1;
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
