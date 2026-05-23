/*@ 
    requires number > 0;
    ensures \result >= 1;
    ensures \result == \card(\set{ i | 1 <= i <= number && number % i == 0 });
    assigns \nothing;
*/
int divisor(int number);

int divisor(int number) {

		int div = 0;
		/*@
		loop invariant 1 <= index <= number + 1;
		loop invariant div == \card(\set{ i | 1 <= i < index && number % i == 0 });
		loop assigns index, div;
		loop variant number - index;
		*/
		for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
		return div;
}
