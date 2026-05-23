/*@ 
    requires args_len >= 0;
    requires arr_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= args_len;
    ensures 0 <= \result <= arr_len;
*/
int findExtra(int * args, int args_len, int * arr, int arr_len, int Array);

 /*@ 
    requires args_len >= 0;
    requires arr_len >= 0;
    requires \valid_read(args + (0 .. args_len - 1));
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= args_len;
    ensures 0 <= \result <= arr_len;
*/
int findExtra(int * args, int args_len, int * arr, int arr_len, int Array) {

		int ret = 0;
		int len = 0;
		/*@
		    loop invariant 0 <= ret <= args_len;
		    loop invariant 0 <= len <= arr_len;
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
