int foo175(int num);

int foo175(int num) {

		int result = 0;
		for (int c = 2; c <= num; c++) {
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
}
