/*@
    requires 0 <= number <= 12;
    assigns \nothing;
    ensures 1 <= \result <= 9;
*/
int firstDigit(int number);

int firstDigit(int number) {

		int first = 1;
		/*@
		    loop invariant c >= 2;
		    loop invariant c <= number + 1 || number < 2;
		    loop invariant first >= 1;
		    loop assigns c, first;
		    loop variant number - c + 2;
		*/
		for (int c = 2; c <= number; c++) {
			first *= c;
		}
		int result = 0;
		/*@
		    loop invariant first >= 0;
		    loop invariant 0 <= result <= 9;
		    loop assigns first, result;
		    loop variant first;
		*/
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}
