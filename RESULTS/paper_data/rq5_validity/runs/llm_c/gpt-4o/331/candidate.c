/*@
    requires n >= 0 && c >= 0;
    ensures \result >= 0 && \result < 10;
    ensures n == c ==> \result == 1;
    ensures (c - n) >= 5 ==> \result == 0;
    assigns \nothing;
*/
int computeLastDigit(int n, int c);

int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			/*@
			    loop invariant n + 1 <= index <= c + 1;
			    loop invariant result >= 0 && result < 10;
			    loop assigns index, result;
			    loop variant c + 1 - index;
			*/
			for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
			return result % 10;
		}
}
