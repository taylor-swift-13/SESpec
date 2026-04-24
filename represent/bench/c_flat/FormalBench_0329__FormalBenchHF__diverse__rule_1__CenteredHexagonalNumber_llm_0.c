int centeredHexagonalNumber(int size);

int centeredHexagonalNumber(int size) {

		int center = 1;
		while (size > 0) {
			size--;
			center += 6 * size;
		}
		return center;
}
