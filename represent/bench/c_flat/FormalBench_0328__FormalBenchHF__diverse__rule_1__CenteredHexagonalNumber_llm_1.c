int centeredHexagonalNumber(int num);

int centeredHexagonalNumber(int num) {

		int center = 1;
		while (num > 0) {
			num--;
			center += 6 * num;
		}
		return center;
}
