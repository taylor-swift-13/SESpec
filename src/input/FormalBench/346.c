int foo346(int num, int b, int c);

int foo346(int num, int b, int c) {

		int result = 0;
		for (int count = 0; count < b; count++) {
			result += (num + count * c);
		}
		return result;
}
