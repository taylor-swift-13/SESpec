int apSum(int num, int b, int c);

int apSum(int num, int b, int c) {

		int result = 0;
		for (int count = 0; count < b; count++) {
			result += (num + count * c);
		}
		return result;
}
