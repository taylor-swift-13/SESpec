int countDigit(int number);

int countDigit(int number) {

		int result = 0;
		while (number > 0) {
			number /= 10;
			result++;
		}
		return result;
}
