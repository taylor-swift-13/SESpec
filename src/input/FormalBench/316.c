int foo316(int num);

int foo316(int num) {

		int ret = 1;
		for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
		int remainder = (int) (ret % 100);
		return remainder;
}
