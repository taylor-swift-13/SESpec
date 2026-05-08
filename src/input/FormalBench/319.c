int foo319(int num);

int foo319(int num) {

		int result = 1;
		while ((num & 1) == 0) {
			num >>= 1;
			result++;
		}
		return result;
}
