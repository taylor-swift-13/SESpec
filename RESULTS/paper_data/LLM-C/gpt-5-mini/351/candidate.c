/*@
    requires number >= 0;
    requires number < (1 << (8 * sizeof(int) - 1));
    assigns \nothing;
    /* The result is obtained by toggling every even-indexed bit (0-based)
       among the bits that are part of `number`'s binary representation. */
    ensures \forall integer k; 0 <= k < 8 * sizeof(int) ==>
        ( ( (number >> k) == 0 )
            ? ( ((\result >> k) & 1) == ((number >> k) & 1) )
            : ( (k % 2 == 0)
                ? ( ((\result >> k) & 1) == 1 - ((number >> k) & 1) )
                : ( ((\result >> k) & 1) == ((number >> k) & 1) )
              )
        );
    /* Equivalent characterization: result == number ^ mask where mask has
       bits set at even positions k for which (number >> k) != 0. */
    ensures \result == number ^ (\sum integer k; 0 <= k < 8 * sizeof(int);
                                  ((number >> k) == 0 ? 0 : (k % 2 == 0 ? (1 << k) : 0)));
*/
int evenBitToggleNumber(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		/*@
		    loop invariant ret >= 0;
		    loop invariant total >= 0;
		    loop invariant total == number >> ret;
		    loop invariant \forall integer j; 0 <= j < ret ==>
		        (((i >> j) & 1) == (j % 2 == 0 ? 1 : 0));
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
