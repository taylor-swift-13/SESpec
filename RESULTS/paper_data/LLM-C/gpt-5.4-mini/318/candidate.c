/*@
    requires num >= 1;
    assigns \nothing;
    ensures num == 1 ==> \result == 1;
    ensures num > 1 ==> \result >= 0;
*/
int countFac(int num);

 /*@
    requires num >= 1;
    assigns \nothing;
    ensures num == 1 ==> \result == 1;
    ensures num > 1 ==> \result >= 0;
*/
int countFac(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		/*@
		    loop invariant 2 <= c <= num / c + 1;
		    loop invariant result >= 0;
		    loop assigns c, result;
		    loop variant num - c;
		*/
		for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
		return result;
}
