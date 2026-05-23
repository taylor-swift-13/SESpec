/*@
    requires diff >= 0;
    ensures \result == (\sum integer i; 1 <= i <= diff; i * i * i) - (\sum integer i; 1 <= i <= diff; i);
    assigns \nothing;
*/
int difference(int diff);

int difference(int diff) {

		int ret = 0;
		int max = 0;

		/*@
		loop invariant 1 <= j <= diff + 1;
		loop invariant ret == (\sum integer i; 1 <= i < j; i * i * i);
		loop assigns j, ret;
		loop variant diff - j;
		*/
		for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}

		/*@
		loop invariant 1 <= j <= diff + 1;
		loop invariant max == (\sum integer i; 1 <= i < j; i);
		loop assigns j, max;
		loop variant diff - j;
		*/
		for (int j = 1; j <= diff; j++) {
			max += j;
		}

		return ret - max;
}
