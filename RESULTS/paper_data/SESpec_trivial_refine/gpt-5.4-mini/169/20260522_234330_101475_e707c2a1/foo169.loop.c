
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

int foo169(int * arr, int arr_len) {

		int r = 0;
		int stop = arr_len - 1;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= r;
          loop invariant stop < arr_len;
          loop assigns r, stop;
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
