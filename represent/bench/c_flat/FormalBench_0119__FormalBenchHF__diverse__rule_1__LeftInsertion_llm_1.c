int leftInsertion(int * args, int args_len, int Array);

int leftInsertion(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
}
