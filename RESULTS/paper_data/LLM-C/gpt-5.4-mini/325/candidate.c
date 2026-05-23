/*@
    assigns \nothing;
    ensures \result >= 0 && \result <= 9;
*/
int firstDigit(int num);

 /*@
    assigns \nothing;
    ensures \result >= 0 && \result <= 9;
*/
int firstDigit(int num) {

		int first = 1;
		/*@
		    loop invariant 2 <= j <= num + 1;
		    loop invariant first > 0;
		    loop assigns j, first;
		    loop variant num - j + 1;
		*/
		for (int j = 2; j <= num; j++) {
			first *= j;
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
