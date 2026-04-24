int cubeSum(int size);

int cubeSum(int size) {

		int result = 0;
		for (int j = 1; j <= size; j++) {
			result += (2 * j) * (2 * j) * (2 * j);
		}
		return result;
}
