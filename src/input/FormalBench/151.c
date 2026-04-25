int foo151(int num);

int foo151(int num) {

		int first = 1;
		for (int c = 2; c <= num; c++) {
			first *= c;
		}
		int result = 0;
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}
