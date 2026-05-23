int divisor(int number);

/*@ 
  requires number >= 1;
  assigns \nothing;
  ensures \result == \numof integer i; 1 <= i <= number && number % i == 0;
  ensures 1 <= \result <= number;
*/
int divisor(int number) {

		int div = 0;
		/*@
		  loop invariant 1 <= index <= number + 1;
		  loop invariant 0 <= div <= index - 1;
		  loop invariant div == \numof integer i; 1 <= i < index && number % i == 0;
		  loop assigns div, index;
		  loop variant number - index + 1;
		*/
		for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
		return div;
}
