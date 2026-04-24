int getGcd(int * arg, int arg_len);

int getGcd(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		for (int j = 1; j < arg_len; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
		return g;
}
