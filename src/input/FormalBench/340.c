int foo340(int size);

int foo340(int size) {

		int result = 0;
		for (int c = 1; c <= size; c++) {
			result += (2 * c) * (2 * c) * (2 * c);
		}
		return result;
}
