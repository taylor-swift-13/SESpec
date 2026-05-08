int foo109(int * args, int args_len, int start, int stop);

int foo109(int * args, int args_len, int start, int stop) {

		int result = start;
		int total = stop;
		int mid;

		while (result <= total) {
			mid = (result + total) / 2;
			int i = args[mid];

			if (i == mid) {
				result = mid + 1;
			} else if (i < mid) {
				result = mid + 1;
			} else {
				total = mid - 1;
			}
		}
		return result;
}
