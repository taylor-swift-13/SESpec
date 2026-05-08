int foo325(int value);

int foo325(int value) {

		int result = 0;
		while (value > 0) {
			value /= 10;
			result++;
		}
		return result;
}
