/*@ 
    requires num >= 0;
    ensures \result >= 0 && \result < 100;
    assigns \nothing;
*/
int lastTwoDigits(int num);

int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		loop invariant 1 <= number <= num + 1;
		loop invariant ret == \prod(integer k = 1; k < number; k);
		loop assigns number, ret;
		loop variant num - number;
		*/
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}
