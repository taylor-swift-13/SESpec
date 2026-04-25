int foo308(int * values, int values_len, int array, int mask);

int foo308(int * values, int values_len, int array, int mask) {

		long l = 1;
		for (int index = 0; index < array; index++) {
			l *= values[index];
		}
		return (int) (l % mask);
}
