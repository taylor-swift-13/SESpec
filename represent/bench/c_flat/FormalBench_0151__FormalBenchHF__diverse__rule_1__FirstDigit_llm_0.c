int firstDigit(int num);

int firstDigit(int num) {

		int first = 1;
		for (int c = 2; c <= num; c++) {
			first *= c;
		}
		int result = 0;
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}
