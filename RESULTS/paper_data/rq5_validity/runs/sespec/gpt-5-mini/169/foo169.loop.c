
/*@ 
  predicate unchanged_array(int* arr, integer arr_len) =
    \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
@*/
        
int foo169(int * arr, int arr_len) {

		int r = 0;
		int stop = arr_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= \at(arr_len,Pre) - 1 ==> 0 <= r && r <= \at(arr_len,Pre) - 1;
          loop invariant 0 <= \at(arr_len,Pre) - 1 ==> 0 <= stop && stop <= \at(arr_len,Pre) - 1;
          loop invariant 0 <= \at(arr_len,Pre) - 1 ==> r <= stop + 1;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns r, stop, i;
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
