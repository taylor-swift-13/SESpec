int getGcd(int * args, int args_len);

int getGcd(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		for (int j = 1; j < args_len; j++) {
			if (args[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = args[j];
			}
		}
		return g;
}
