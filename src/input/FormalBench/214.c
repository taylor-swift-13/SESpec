int foo214(int number);

int foo214(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ i;
}
