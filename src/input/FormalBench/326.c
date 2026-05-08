int foo326(int number);

int foo326(int number) {

		int result = 0;
		while (number > 0) {
			number /= 10;
			result++;
		}
		return result;
}
