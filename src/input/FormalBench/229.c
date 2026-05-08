int foo229(int * args, int args_len);

int foo229(int * args, int args_len) {

		int first = 0;
		for (int num = 0; num < args_len; num++) {
			if (args[num] % 2 == 0) {
				first = args[num];
				break;
			}
		}
		return first;
}
