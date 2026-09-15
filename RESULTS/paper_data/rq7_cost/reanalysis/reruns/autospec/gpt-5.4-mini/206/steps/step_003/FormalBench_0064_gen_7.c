int findExtra(int * args, int args_len, int * arr, int arr_len, int array);

int findExtra(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		/*@
		loop invariant 0 <= ret <= args_len;
		loop invariant 0 <= r <= arr_len;
		loop invariant ret + r <= args_len + arr_len;
		loop invariant ret == 0 || r == 0 || ret + r >= 1;
		loop invariant ret == 0 || r == 0 || args[ret-1] <= arr[r-1];
		loop invariant \forall integer i; 0 <= i < ret ==> args[i] <= array;
		loop invariant \forall integer j; 0 <= j < r ==> arr[j] <= array;
		loop invariant \forall integer i; 0 <= i < ret ==> \forall integer j; 0 <= j < r ==> args[i] <= arr[j];
		loop invariant ret == 0 || r == 0 || ret + r >= 1;
		loop invariant ret == 0 || r == 0 || args[ret-1] <= arr[r-1];
		loop invariant ret <= args_len;
		loop invariant ret <= args_len && r <= arr_len;
		loop invariant ret + r == 0 || ret + r >= 0;
		loop invariant ret + r <= args_len + arr_len;
		loop invariant r <= arr_len;
		loop invariant \forall integer j; 0 <= j < r ==> arr[j] <= array;
		loop invariant \forall integer i; 0 <= i < ret ==> args[i] <= array;
		loop invariant \forall integer i; 0 <= i < ret ==> \forall integer j; 0 <= j < r ==> args[i] <= arr[j];
		loop invariant 0 <= ret;
		loop invariant 0 <= ret + r;
		loop invariant 0 <= r;
		loop assigns ret;
		loop assigns r;
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
