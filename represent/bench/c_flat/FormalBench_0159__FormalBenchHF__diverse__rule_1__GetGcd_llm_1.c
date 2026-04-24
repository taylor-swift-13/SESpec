int getGcd(int * args, int args_len);

int getGcd(int * args, int args_len) {

		int ret = 0;
		int tmp = args[0];
		for (int j = 1; j < args_len; j++) {
			if (args[j] > tmp) {
				ret = ret > tmp ? ret : tmp;
			} else {
				tmp = args[j];
			}
		}
		return ret;
}
