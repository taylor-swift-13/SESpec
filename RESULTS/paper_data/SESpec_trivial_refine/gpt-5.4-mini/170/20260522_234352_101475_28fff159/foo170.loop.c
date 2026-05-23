
/*@
predicate bounds(int ret, int stop, int arr_len) =
  0 <= ret && ret <= arr_len && -1 <= stop && stop < arr_len;
*/

int foo170(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
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
