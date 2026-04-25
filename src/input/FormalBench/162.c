int foo162(int diff);

int foo162(int diff) {

		int ret = 0;
		int max = 0;
		for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
		for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return ret - max;
}
