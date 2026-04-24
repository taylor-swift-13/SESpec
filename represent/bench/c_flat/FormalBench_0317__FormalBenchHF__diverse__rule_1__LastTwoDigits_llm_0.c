int lastTwoDigits(int num);

int lastTwoDigits(int num) {

		int ret = 1;
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int result = (int) (ret % 100);
		return result;
}
