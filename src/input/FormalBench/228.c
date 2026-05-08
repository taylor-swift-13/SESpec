int foo228(int * args, int args_len);

int foo228(int * args, int args_len) {

		int result = 0;
		for (int index = 0; index < args_len; index++) {
			if (args[index] % 2 == 0) {
				result = args[index];
				break;
			}
		}
		return result;
}
