int getInvCount(int * args, int args_len, int num);

int getInvCount(int * args, int args_len, int num) {

		int ret = 0;

		for (int index = 0; index < num; index++) {
			for (int c = index + 1; c < num; c++) {
				if (args[index] > args[c]) {
					ret++;
				}
			}
		}
		return ret;
}
