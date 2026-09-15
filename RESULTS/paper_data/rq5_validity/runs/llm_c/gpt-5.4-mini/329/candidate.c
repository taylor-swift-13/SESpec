/*@
    requires diff >= 0;
    ensures \result == (\sum(integer j = 1; j <= diff; j) j * j * j) - (\sum(integer j = 1; j <= diff; j) j);
    assigns \nothing;
*/
int difference(int diff);

int difference(int diff) {

		int ret = 0;
		int max = 0;
		/*@
		    loop invariant 1 <= j <= diff + 1;
		    loop invariant ret == (\sum(integer k = 1; k < j; k++) k * k * k);
		    loop assigns j, ret;
		    loop variant diff - j + 1;
		*/
		for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
		/*@
		    loop invariant 1 <= j <= diff + 1;
		    loop invariant max == (\sum(integer k = 1; k < j; k++) k);
		    loop assigns j, max;
		    loop variant diff - j + 1;
		*/
		for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return ret - max;
}
