int foo110(int * args, int args_len, int start, int stop);

int foo110(int * args, int args_len, int start, int stop) {

		int found = start;
		int total = stop;
		int mid;

		while (found <= total) {
			mid = (found + total) / 2;
			int i = args[mid];

			if (i == mid) {
				found = mid + 1;
			} else if (i < mid) {
				found = mid + 1;
			} else {
				total = mid - 1;
			}
		}
		return found;
}
