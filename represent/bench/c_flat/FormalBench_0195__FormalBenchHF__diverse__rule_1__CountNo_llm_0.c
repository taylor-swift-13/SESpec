int countNo(int code, int b, int l, int m);

int countNo(int code, int b, int l, int m) {

		int ret = 0;
		for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				ret++;
			}
			if (ret == b) {
				return c;
			}
		}
		return -1;
}
