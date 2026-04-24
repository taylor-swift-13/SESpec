int evenBitToggleNumber(int num);

int evenBitToggleNumber(int num) {

		int result = 0;
		int ret = 0;
		int total = num;
		while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return num ^ result;
}
