int foo122(int * args, int args_len, int array);

int foo122(int * args, int args_len, int array) {

		int i = 0;
		int stop = array - 1;
		while (i <= stop) {
			int cur = i + (stop - i) / 2;
			if (args[cur] == cur) {
				return cur;
			} else if (args[cur] < cur) {
				i = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
}
