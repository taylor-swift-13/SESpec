int foo337(int num);

int foo337(int num) {

		int ret = 0;
		for (int j = 2; j <= num; j++) {
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
}
