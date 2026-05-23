/*@
    requires \valid(args + (0..args_len-1));
    requires \valid(arr + (0..arr_len-1));
    requires args_len >= 0 && arr_len >= 0;
    ensures 0 <= \result <= args_len;
    ensures \result < args_len ==> (\forall integer i; 0 <= i < \result ==> args[i] == arr[i]);
    ensures \result == args_len ==> (\forall integer i; 0 <= i < args_len ==> args[i] == arr[i]);
    assigns \nothing;
*/
int findExtra(int * args, int args_len, int * arr, int arr_len, int array);

int findExtra(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int len = 0;
		/*@
		    loop invariant 0 <= ret <= args_len;
		    loop invariant 0 <= len <= arr_len;
		    loop invariant \forall integer i; 0 <= i < ret ==> args[i] == arr[i];
		    loop assigns ret, len;
		    loop variant args_len - ret + arr_len - len;
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
