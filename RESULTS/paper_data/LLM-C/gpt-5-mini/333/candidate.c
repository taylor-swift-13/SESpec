/*@
    logic integer product_mod10(integer i, integer j) =
        i > j ? 1 : ((i % 10) * product_mod10(i+1, j));
*/

int computeLastDigit(int n, int c);

/*@
    requires \true;
    assigns \nothing;
    behavior equal:
        assumes n == c;
        ensures \result == 1;
    behavior distant:
        assumes c - n >= 5;
        ensures \result == 0;
    behavior between:
        assumes n != c && c - n < 5;
        ensures 0 <= \result && \result < 10;
        ensures \result == product_mod10(n+1, c) % 10;
    complete behaviors equal, distant, between;
    disjoint behaviors equal, distant, between;
*/
int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
            /*@
                loop invariant var >= n + 1;
                loop invariant 0 <= result && result < 10;
                loop invariant result == product_mod10(n+1, var-1) % 10;
                loop assigns var, result;
                loop variant (var <= c+1 ? c+1 - var : 0);
            */
			for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
