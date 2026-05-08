int foo161(int diff);

int foo161(int diff) {

		int result = 0;
		int max = 0;
		for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
		for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
}
