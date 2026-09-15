/*@
    requires number >= 1;
    assigns \nothing;
    behavior one:
        assumes number == 1;
        ensures \result == 1;
    behavior ge2:
        assumes number > 1;
        ensures \result >= 0;
        ensures \result == \numof integer k; 2 <= k <= number / k && number % k == 0;
    complete behaviors one, ge2;
    disjoint behaviors one, ge2;
*/
int countFac(int number) {

		int result = 0;
		if (number == 1)
			return 1;
		/*@
		    loop invariant 2 <= c <= number;
		    loop invariant result >= 0;
		    loop invariant result == \numof integer k; 2 <= k < c && k <= number / k && number % k == 0;
		    loop assigns c, result;
		    loop variant number - c + 1;
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
