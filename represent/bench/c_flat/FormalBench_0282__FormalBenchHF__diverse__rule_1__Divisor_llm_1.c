int divisor(int number);

int divisor(int number) {

		int div = 0;
		for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
		return div;
}
