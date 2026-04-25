int foo194(int code, int b, int l, int c);

int foo194(int code, int b, int l, int c) {

		int ret = 0;
		for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
		return -1;
}
