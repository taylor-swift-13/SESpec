
/*@
  predicate array_unchanged{L1, L2}(int *arr, integer n) =
    \forall integer k; 0 <= k < n ==> \at(arr[k], L1) == \at(arr[k], L2);
*/
        
int foo169(int * arr, int arr_len) {

		int r = 0;
		int stop = arr_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= r <= arr_len;
          loop invariant -1 <= stop < arr_len;
          loop invariant r <= stop + 1;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant array_unchanged(arr, \at(arr_len,Pre));
          loop assigns i, r, stop;
            */
            while (r <= stop) {
			int i = r + (stop - r) / 2;
			if (i < stop
					&& arr[i] > arr[i + 1]) {
				return i + 1;
			} else if (i > r
					&& arr[i] < arr[i - 1]) {
				return i;
			}
			if (arr[i] >= arr[r]) {
				r = i + 1;
			} else {
				stop = i - 1;
			}
		}
            
		return 0;
}
