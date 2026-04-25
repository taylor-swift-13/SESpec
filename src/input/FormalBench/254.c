int foo254(int size);

int foo254(int size) {

		int result = 0;
		int total = 0;
		for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
		return result / total;
}
