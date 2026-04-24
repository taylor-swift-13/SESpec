int findMaxVal(int value, int p, int dy);

int findMaxVal(int value, int p, int dy) {

		int result = 0;
		for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
}
