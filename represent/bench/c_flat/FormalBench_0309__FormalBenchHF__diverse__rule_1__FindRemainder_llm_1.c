int findRemainder(int * array, int array_len, int num, int mask);

int findRemainder(int * array, int array_len, int num, int mask) {

		long l = 1;
		for (int index = 0; index < num; index++) {
			l *= array[index];
		}
		return (int) (l % mask);
}
