/*@
    assigns \nothing;
    ensures \result == (number ^ (\let result = 0; \let ret = 0; \let total = number;
                                 (\forall integer k; 0 <= k < 0)));
*/
int evenBitToggleNumber(int number);

int evenBitToggleNumber(int number) {

		int result = 0;
		int ret = 0;
		int total = number;
		/*@
		    loop invariant total >= 0;
		    loop invariant ret >= 0;
		    loop invariant result >= 0;
		    loop invariant ret <= 31;
		    loop assigns total, ret, result;
		    loop variant total;
		*/
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ result;
}
