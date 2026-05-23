/*@
    requires num >= 2;
    assigns \nothing;
    ensures \result >= 0 && \result <= 9;
*/
int firstDigit(int num);

 /*@
    requires num >= 2;
    assigns \nothing;
    ensures \result >= 0 && \result <= 9;
*/
int firstDigit(int num) {

		int first = 1;
		/*@
		    loop invariant 2 <= c <= num + 1;
		    loop invariant first > 0;
		    loop assigns c, first;
		    loop variant num - c + 1;
		*/
		for (int c = 2; c <= num; c++) {
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
