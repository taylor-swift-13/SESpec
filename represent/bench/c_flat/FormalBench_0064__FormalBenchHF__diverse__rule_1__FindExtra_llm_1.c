int findExtra(int * args, int args_len, int * arr, int arr_len, int array);

int findExtra(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		while (ret < args_len && r < arr_len) {
			if (args[ret] < arr[r]) {
				ret++;
			} else if (args[ret] > arr[r]) {
				r++;
			} else {
				ret++;
				r++;
			}
		}
		return ret < args_len ? ret : r;
}
