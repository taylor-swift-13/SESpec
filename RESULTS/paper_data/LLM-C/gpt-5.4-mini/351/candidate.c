/*@
    requires number >= 0;
    assigns \nothing;
    ensures \result == (number ^ (
        (0 <= number) ? (
            (\let int i = 0;
             \let int ret = 0;
             \let int total = number;
             \result)
        ) : 0
    ));
*/
int evenBitToggleNumber(int number);

int evenBitToggleNumber(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		/*@
		    loop invariant total >= 0;
		    loop invariant i >= 0;
		    loop invariant ret >= 0;
		    loop assigns i, ret, total;
		    loop variant total;
		*/
		while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ i;
}
