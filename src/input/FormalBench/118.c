int foo118(int * args, int args_len, int array);

int foo118(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		while (result <= top) {
			int i = (result + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				result = i + 1;
			} else {
				top = i - 1;
			}
		}
		return result;
}
