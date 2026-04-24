int centeredHexagonalNumber(int size);

int centeredHexagonalNumber(int size) {

		int N = 1;
		while (size > 0) {
			size--;
			N += 6 * size;
		}
		return N;
}
