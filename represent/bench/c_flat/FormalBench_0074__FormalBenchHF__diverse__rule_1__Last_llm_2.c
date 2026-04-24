int last(int * args, int args_len, int x, int y);

int last(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				p = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}

		return p;
}
