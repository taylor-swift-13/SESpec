int findExtra(int * args, int args_len, int * arr, int arr_len, int array);

/*@
    requires args_len >= 0;
    requires arr_len >= 0;
    requires args_len == 0 || \valid(args + (0 .. args_len - 1));
    requires arr_len == 0 || \valid(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= \max(args_len, arr_len);
*/
int findExtra(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		/*@
		    loop invariant 0 <= ret <= args_len;
		    loop invariant 0 <= r <= arr_len;
		    loop assigns ret, r;
		    loop variant (args_len - ret) + (arr_len - r);
		*/
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
