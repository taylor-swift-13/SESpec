int foo132(int number);

int foo132(int number) {

		int result = 0;
		if (number == 1)
			return 1;
		for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
		return result;
}
