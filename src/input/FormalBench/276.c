int foo276(int value, int k, int z);

int foo276(int value, int k, int z) {

		int result = 0;
		for (int c = 1; c <= value; c++) {
			if ((c % k) == z) {
				result = c;
			}
		}
		return result;
}
