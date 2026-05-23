int countFac(int num);

/*@
    assigns \nothing;
    ensures num == 1 ==> \result == 1;
    ensures num != 1 ==>
        \result == \numof(integer j; 2 <= j && j <= num / j && num % j == 0);
*/
int countFac(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		/*@
		    loop invariant 2 <= c;
		    loop invariant result >= 0;
		    loop invariant result == \numof(integer j; 2 <= j && j < c && j * j <= num && num % j == 0);
		    loop assigns c, result;
		    loop variant num - c * c + 1;
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
