int foo281(int num);

int foo281(int num) {

		int div = 0;
		for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
		return div;
}
