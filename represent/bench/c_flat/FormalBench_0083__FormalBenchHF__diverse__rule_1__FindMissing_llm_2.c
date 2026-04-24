int findMissing(int * args, int args_len, int array);

int findMissing(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		for (int num = 1; num <= array; num++) {
			if (args[num - 1] == num) {
				found = num;
			} else if (args[num - 1] != num) {
				return num;
			}
		}
		return found;
}
