/*@
    requires \valid(args + (0..args_len-1));
    requires \valid(arr + (0..arr_len-1));
    requires args_len >= 0 && arr_len >= 0;
    ensures \result >= 0 && \result < (array == 0 ? args_len : arr_len);
    assigns \nothing;
*/
int findExtra(int * args, int args_len, int * arr, int arr_len, int array);

int findExtra(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		/*@
		    loop invariant 0 <= ret <= args_len;
		    loop invariant 0 <= r <= arr_len;
		    loop invariant \forall integer i; 0 <= i < ret ==> args[i] != arr[r];
		    loop invariant \forall integer j; 0 <= j < r ==> args[ret] != arr[j];
		    loop assigns ret, r;
		    loop variant args_len - ret + arr_len - r;
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
