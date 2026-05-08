int foo265(int number);

int foo265(int number) {

		int ret = 0;
		while (number > 0) {
			if ((number & 1) == 1) {
				ret++;
			}
			number = number >> 1;
		}
		return ret;
}
