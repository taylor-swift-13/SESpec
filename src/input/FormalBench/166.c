const char * foo166(int num);

const char * foo166(int num) {

		int result = 0;
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
