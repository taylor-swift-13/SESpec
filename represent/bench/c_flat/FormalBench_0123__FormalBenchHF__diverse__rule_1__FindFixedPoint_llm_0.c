int findFixedPoint(int * args, int args_len, int array);

int findFixedPoint(int * args, int args_len, int array) {

		int ret = 0;
		int stop = array - 1;
		while (ret <= stop) {
			int i = ret + (stop - ret) / 2;
			if (args[i] == i) {
				return i;
			} else if (args[i] < i) {
				ret = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return -1;
}
