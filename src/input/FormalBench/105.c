int foo105(int * args, int args_len, int num);

int foo105(int * args, int args_len, int num) {

		int ret = 0;

		for (int index = 0; index < num; index++) {
			for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
		}
		return ret;
}
