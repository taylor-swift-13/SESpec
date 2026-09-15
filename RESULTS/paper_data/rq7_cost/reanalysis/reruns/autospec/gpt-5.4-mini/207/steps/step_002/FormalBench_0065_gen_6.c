int findExtra(int * args, int args_len, int * arr, int arr_len, int array);

int findExtra(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int len = 0;
		/*@
		loop invariant ret <= args_len;
		loop invariant len <= arr_len;
		loop invariant 0 <= ret;
		loop invariant 0 <= len;
		loop invariant ret + len <= args_len + arr_len;
		loop invariant ret >= len || len >= ret;
		loop invariant ret - len <= args_len;
		loop invariant ret <= args_len;
		loop invariant ret <= args_len && len <= arr_len;
		loop invariant ret + len <= args_len + arr_len;
		loop invariant len <= arr_len;
		loop invariant 0 <= ret;
		loop invariant 0 <= ret + len;
		loop invariant 0 <= len;
		loop assigns ret;
		loop assigns len;
		*/
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
