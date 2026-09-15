int lastTwoDigits(int num);

int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		loop invariant 1 <= number <= num + 1;
		loop invariant ret >= 1;
		loop invariant ret == \at(ret,Pre) * \product(integer k, 1, number-1, k);
		loop assigns number;
		loop assigns ret;
		*/
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}
