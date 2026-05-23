
/*@ predicate valid_read_slice{L}(int *a, integer n) =
      n >= 0 && \valid_read(a + (0..n-1));
*/

/*@ predicate sorted_nondecr{L}(int *a, integer n) =
      \forall integer i,j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

int foo27(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant 0 <= found;
          loop invariant hi <= \at(arr_len,Pre) - 1;
          loop invariant (found <= hi) ==> (0 <= end && end < \at(arr_len,Pre));
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
