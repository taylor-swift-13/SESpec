int findNthDigit(int num, int c, int r);

int findNthDigit(int num, int c, int r) {

		int result = 0;
		while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}
