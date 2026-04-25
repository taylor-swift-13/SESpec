int foo120(int * args, int args_len, int array);

int foo120(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
}
