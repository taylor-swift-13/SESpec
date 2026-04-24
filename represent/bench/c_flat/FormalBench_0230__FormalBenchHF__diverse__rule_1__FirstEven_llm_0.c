int firstEven(int * args, int args_len);

int firstEven(int * args, int args_len) {

		int result = 0;
		for (int num = 0; num < args_len; num++) {
			if (args[num] % 2 == 0) {
				result = args[num];
				break;
			}
		}
		return result;
}
