/*@
    requires n <= c;
    assigns \nothing;
    ensures 0 <= \result <= 9;
*/
int computeLastDigit(int n, int c);

 /*@
    requires n <= c;
    assigns \nothing;
    ensures 0 <= \result <= 9;
*/
int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			/*@
			    loop invariant n + 1 <= var <= c + 1;
			    loop invariant 0 <= result <= 9;
			    loop assigns var, result;
			    loop variant c - var + 1;
			*/
			for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
