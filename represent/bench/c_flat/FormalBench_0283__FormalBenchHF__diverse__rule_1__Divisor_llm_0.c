int divisor(int number);

int divisor(int number) {

		int div = 0;
		for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				div++;
			}
		}
		return div;
}
