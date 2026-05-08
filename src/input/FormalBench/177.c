int foo177(int num);

int foo177(int num) {

		int result = 0;
		for (int j = 2; j <= num; j++) {
			while (num % j == 0) {
				result = j;
				num /= j;
			}
		}
		return result;
}
