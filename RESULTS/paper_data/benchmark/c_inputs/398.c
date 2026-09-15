int foo398(int number);

int foo398(int number) {

		int ret = 0;
		while (number > 0) {
			number /= 10;
			ret++;
		}
		return ret;
}
