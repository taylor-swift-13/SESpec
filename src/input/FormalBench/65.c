int foo65(int * args, int args_len, int * arr, int arr_len, int array);

int foo65(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int len = 0;
		while (ret < args_len && len < arr_len) {
			if (args[ret] < arr[len]) {
				ret++;
			} else if (args[ret] > arr[len]) {
				len++;
			} else {
				ret++;
				len++;
			}
		}
		return ret < args_len ? ret : len;
}
