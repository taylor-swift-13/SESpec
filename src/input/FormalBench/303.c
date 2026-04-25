int foo303(int num, int c, int r);

int foo303(int num, int c, int r) {

		int ret = 0;
		while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
		return ret;
}
