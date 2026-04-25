int foo347(int p, int b, int c);

int foo347(int p, int b, int c) {

		int ret = 0;
		for (int count = 0; count < b; count++) {
			ret += (p + count * c);
		}
		return ret;
}
