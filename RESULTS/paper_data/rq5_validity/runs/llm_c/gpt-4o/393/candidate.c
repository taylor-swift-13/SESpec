/*@ 
    requires num >= 0;
    ensures \result >= 0 && \result < 100;
    assigns \nothing;
*/
int lastTwoDigits(int num);

int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		loop invariant 1 <= loop <= num + 1;
		loop invariant ret == \product(1, loop - 1, \lambda integer k; k);
		loop assigns loop, ret;
		loop variant num - loop;
		*/
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int remainder = (int) (ret % 100);
		return remainder;
}
