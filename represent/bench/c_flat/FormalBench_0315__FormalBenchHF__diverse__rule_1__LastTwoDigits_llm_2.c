int lastTwoDigits(int num);

int lastTwoDigits(int num) {

		int ret = 1;
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}
