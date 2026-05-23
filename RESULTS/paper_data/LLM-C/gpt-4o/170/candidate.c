/*@
    requires \valid(arr+(0..arr_len-1));
    requires arr_len > 0;
    ensures \result >= 0 && \result < arr_len;
    ensures \forall integer i; 0 <= i < arr_len ==> 
             arr[(\result + i) % arr_len] >= arr[(\result + i - 1 + arr_len) % arr_len];
    assigns \nothing;
*/
int findRotationCount(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		/*@
        loop invariant 0 <= ret <= arr_len;
        loop invariant 0 <= stop < arr_len;
        loop assigns ret, stop;
        loop variant stop - ret;
        */
		while (ret <= stop) {
			int r = ret + (stop - ret) / 2;
			if (r < stop
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				stop = r - 1;
			}
		}
		return 0;
}
