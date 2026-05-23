int findExtra(int * args, int args_len, int * arr, int arr_len, int array);

 /*@
    requires args_len >= 0;
    requires arr_len >= 0;
    requires \valid_read(args + (0 .. args_len-1)) || args_len == 0;
    requires \valid_read(arr + (0 .. arr_len-1)) || arr_len == 0;
    assigns \nothing;
    ensures 0 <= \result <= \max(args_len, arr_len);
    ensures \exists integer r, l;
             0 <= r <= args_len &&
             0 <= l <= arr_len &&
             (r == \result || l == \result) &&
             (r == args_len || l == arr_len);
 */
int findExtra(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int len = 0;
		/*@
		    loop invariant 0 <= ret <= args_len;
		    loop invariant 0 <= len <= arr_len;
		    loop invariant ret >= 0 && len >= 0;
		    loop assigns ret, len;
		    loop variant (args_len - ret) + (arr_len - len);
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
