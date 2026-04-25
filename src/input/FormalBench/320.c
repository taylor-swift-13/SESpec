int foo320(int num);

int foo320(int num) {

		int ret = 1;
		while ((num & 1) == 0) {
			num >>= 1;
			ret++;
		}
		return ret;
}
