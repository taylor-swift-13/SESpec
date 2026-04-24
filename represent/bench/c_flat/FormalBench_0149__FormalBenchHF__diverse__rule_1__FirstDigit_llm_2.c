int firstDigit(int number);

int firstDigit(int number) {

		int first = 1;
		for (int c = 2; c <= number; c++) {
			first *= c;
		}
		int result = 0;
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}
