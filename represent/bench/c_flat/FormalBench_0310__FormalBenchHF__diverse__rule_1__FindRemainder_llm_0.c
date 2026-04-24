int findRemainder(int * args, int args_len, int array, int mask);

int findRemainder(int * args, int args_len, int array, int mask) {

		long l = 1;
		for (int index = 0; index < array; index++) {
			l *= args[index];
		}
		return (int) (l % mask);
}
