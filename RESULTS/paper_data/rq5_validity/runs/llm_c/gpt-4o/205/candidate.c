/*@
    requires \valid_read(args+(0..args_len-1));
    requires \valid_read(arr+(0..arr_len-1));
    requires args_len >= 0 && arr_len >= 0;
    ensures 0 <= \result < args_len || 0 <= \result < arr_len;
    ensures \result == args_len ==> \forall integer i; 0 <= i < args_len ==> (\exists integer j; 0 <= j < arr_len && args[i] == arr[j]);
    ensures \result < args_len ==> (\forall integer i; 0 <= i < \result ==> (\exists integer j; 0 <= j < arr_len && args[i] == arr[j])) && (\forall integer j; 0 <= j < arr_len ==> (\exists integer i; 0 <= i < \result && args[i] == arr[j]));
    assigns \nothing;
*/
int findExtra(int * args, int args_len, int * arr, int arr_len, int Array);

int findExtra(int * args, int args_len, int * arr, int arr_len, int Array) {

		int ret = 0;
		int len = 0;
		/*@
		    loop invariant 0 <= ret <= args_len;
		    loop invariant 0 <= len <= arr_len;
		    loop invariant \forall integer i; 0 <= i < ret ==> (\exists integer j; 0 <= j < len && args[i] == arr[j]);
		    loop invariant \forall integer j; 0 <= j < len ==> (\exists integer i; 0 <= i < ret && args[i] == arr[j]);
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
