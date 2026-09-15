/*@
    requires n <= c;
    assigns \nothing;
    ensures \result >= 0 && \result <= 9;
*/
int computeLastDigit(int n, int c);

 /*@
    requires n <= c;
    assigns \nothing;
    ensures \result >= 0 && \result <= 9;
*/
int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			/*@
			    loop invariant n + 1 <= index <= c + 1;
			    loop invariant 0 <= result <= 9;
			    loop invariant result == (\at(result,Pre) * \product(integer k; n + 1 <= k < index; k % 10)) % 10;
			    loop assigns index, result;
			    loop variant c - index + 1;
			*/
			for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
			return result % 10;
		}
}
