int lastTwoDigits(int num);

int lastTwoDigits(int num) {

		int ret = 1;
		/*@
		loop invariant 1 <= number <= num + 1;
		loop invariant ret >= 1;
		loop invariant ret % 2 == 0 || ret % 2 == 1;
		loop invariant number <= num + 1;
		loop invariant ret == \at(ret,Pre) * \product(1, number - 1);
		loop invariant ret == \product(1, number-1);
		loop invariant ret == \product(1, number - 1, \lambda integer k; k);
		loop invariant ret == \product(1, number - 1);
		loop invariant ret == \prod(integer k = 1, number-1) k;
		loop invariant ret == \prod(1, number - 1);
		loop invariant ret == \at(ret,Pre) * \product(integer k, 1, number-1, k);
		loop invariant ret == \at(ret, Pre) * \product(1, number - 1);
		loop invariant ret == (\product integer k; 1 <= k < number; k);
		loop invariant number <= num + 1;
		loop invariant 1 <= ret;
		loop invariant 1 <= number;
		loop invariant 0 < ret;
		loop assigns ret;
		loop assigns number;
		*/
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}
