
/*@
  predicate unchanged_outside(int *a, int *old_a, integer n, integer lo, integer hi) =
    \forall integer k; 0 <= k < n && (k < lo || k > hi) ==> a[k] == old_a[k];
*/

int foo170(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		
        /*@
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((stop == \at(arr_len,Pre) - 1) && (ret == 0) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)));
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_outside(arr, \at(arr,Pre), arr_len, ret, stop);
          loop assigns ret, stop;
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
