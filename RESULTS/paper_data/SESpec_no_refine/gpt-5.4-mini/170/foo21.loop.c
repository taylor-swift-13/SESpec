
/*@
  logic integer unchanged_array(int *arr, integer lo, integer hi) =
    lo >= hi ? 1 :
    (arr[lo] == \at(arr[lo], Pre) && unchanged_array(arr, lo + 1, hi));
*/

int foo21(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		
        /*@
          loop invariant 0 <= ret <= \at(arr_len,Pre);
          loop invariant -1 <= stop < \at(arr_len,Pre);
          loop invariant ret <= stop + 1;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer i; 0 <= i < \at(arr_len,Pre) ==> arr[i] == \at(arr[i],Pre);
          loop assigns r, ret, stop;
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
