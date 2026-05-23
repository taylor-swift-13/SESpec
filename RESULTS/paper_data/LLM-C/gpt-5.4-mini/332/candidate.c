/*@
    requires num <= c;
    assigns \nothing;
    ensures \result == 1 <==> num == c;
    ensures \result == 0 <==> (c - num) >= 5;
    ensures num < c && (c - num) < 5 ==> 0 <= \result <= 9;
*/
int computeLastDigit(int num, int c);

 /*@
    requires num <= c;
    assigns \nothing;
    ensures \result == 1 <==> num == c;
    ensures \result == 0 <==> (c - num) >= 5;
    ensures num < c && (c - num) < 5 ==> 0 <= \result <= 9;
*/
int computeLastDigit(int num, int c) {

		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
			/*@
			    loop invariant num + 1 <= var <= c + 1;
			    loop invariant 0 <= result <= 9;
			    loop assigns var, result;
			    loop variant c - var + 1;
			*/
			for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
