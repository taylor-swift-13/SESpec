int foo315(int num);

int foo315(int num) {

		int ret = 1;
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
}
