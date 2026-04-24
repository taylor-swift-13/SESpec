int computeLastDigit(int n, int c);

int computeLastDigit(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
			return result % 10;
		}
}
