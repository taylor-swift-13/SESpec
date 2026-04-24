int apSum(int p, int b, int c);

int apSum(int p, int b, int c) {

		int ret = 0;
		for (int count = 0; count < b; count++) {
			ret += (p + count * c);
		}
		return ret;
}
