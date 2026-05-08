int foo193(int code, int b, int l, int m);

int foo193(int code, int b, int l, int m) {

		int result = 0;
		for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				result++;
			}
			if (result == b) {
				return c;
			}
		}
		return -1;
}
