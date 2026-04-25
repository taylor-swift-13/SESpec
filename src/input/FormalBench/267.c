int foo267(int number);

int foo267(int number) {

		int result = 0;
		while (number > 0) {
			if ((number & 1) == 1) {
				result++;
			}
			number = number >> 1;
		}
		return result;
}
