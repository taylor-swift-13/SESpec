int first(int * args, int args_len, int array, int n);

int first(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
		return result;
}
