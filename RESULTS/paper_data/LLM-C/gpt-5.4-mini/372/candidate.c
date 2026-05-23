/*@
    requires num >= 0;
    assigns \nothing;
    ensures \result >= 1;
*/
int divisor(int num);

int divisor(int num) {

		int div = 0;
		/*@
		    loop invariant 1 <= c <= num + 1;
		    loop invariant div >= 0;
		    loop invariant div <= c - 1;
		    loop assigns c, div;
		    loop variant num - c + 1;
		*/
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
		return div;
}
