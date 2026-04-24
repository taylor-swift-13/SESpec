int apSum(int p, int b, int c);

int apSum(int p, int b, int c) {

		int result = 0;
		for (int count = 0; count < b; count++) {
			result += (p + count * c);
		}
		return result;
}
