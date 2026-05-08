int foo215(int number);

int foo215(int number) {

		int result = 0;
		int ret = 0;
		int total = number;
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ result;
}
