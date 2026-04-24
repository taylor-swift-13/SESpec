int findMaxVal(int value, int p, int z);

int findMaxVal(int value, int p, int z) {

		int result = 0;
		for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
}
