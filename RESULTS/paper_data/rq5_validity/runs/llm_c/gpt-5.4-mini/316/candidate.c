/*@
    requires number >= 1;
    assigns \nothing;
    ensures number == 1 ==> \result == 1;
    ensures number > 1 ==> \result >= 0;
*/
int countFac(int number);

 /*@
    requires number >= 1;
    assigns \nothing;
    ensures number == 1 ==> \result == 1;
    ensures number > 1 ==> \result >= 0;
*/
int countFac(int number) {

		int result = 0;
		if (number == 1)
			return 1;
		/*@
		    loop invariant 2 <= c;
		    loop invariant c <= number / c + 1;
		    loop invariant result >= 0;
		    loop assigns c, result;
		    loop variant number - c;
		*/
		for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
		return result;
}
