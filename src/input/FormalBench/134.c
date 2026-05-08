int foo134(int num);

int foo134(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
		return result;
}
