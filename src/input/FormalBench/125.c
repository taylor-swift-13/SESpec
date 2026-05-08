int foo125(int count);

int foo125(int count) {

		int ret = 0;
		for (int c = 1; c <= count; c++) {
			int j = c;
			while (j != 0) {
				if ((j & 1) == 0) {
					ret++;
				}
				j = j >> 1;
			}
		}
		return ret;
}
