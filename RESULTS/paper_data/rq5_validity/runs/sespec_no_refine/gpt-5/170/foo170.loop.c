
/*@
  // No additional predicates or logic functions are required.
*/

int foo170(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant arr_len >= 0;
              loop invariant arr == \at(arr,Pre);
              loop invariant arr_len == \at(arr_len,Pre);
              loop invariant -1 <= stop <= \at(arr_len,Pre) - 1;
              loop invariant 0 <= ret <= \at(arr_len,Pre);
              loop invariant ret <= stop + 1;
              loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
              loop assigns ret, stop, r;
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
