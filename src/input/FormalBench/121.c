int foo121(int * i, int i_len, int array);

int foo121(int * i, int i_len, int array) {

		int ret = 0;
		int stop = array - 1;
		while (ret <= stop) {
			int cur = ret + (stop - ret) / 2;
			if (i[cur] == cur) {
				return cur;
			} else if (i[cur] < cur) {
				ret = cur + 1;
			} else {
				stop = cur - 1;
			}
		}
		return -1;
}
