
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
    requires \valid_read(arr + (0 .. arr_len - 1));
*/
int foo176(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
        /*@
          loop invariant 0 <= found <= arr_len;
          loop invariant -1 <= hi < arr_len;
          loop invariant 0 <= end < arr_len;
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \valid_read(arr + (0 .. arr_len - 1));
          loop assigns end, found, hi;
        */
        while (found <= hi) {
			end = (found + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					found = end + 1;
				}
			} else if (arr[end] < array) {
				found = end + 1;
			} else {
				hi = end - 1;
			}
		}
            
		return -1;
}
