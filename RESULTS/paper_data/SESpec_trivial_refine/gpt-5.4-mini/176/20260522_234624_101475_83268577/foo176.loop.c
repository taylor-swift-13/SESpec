
/*@
predicate sorted{L}(int *arr, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> arr[i] <= arr[j];
*/
        
int foo176(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= found;
          loop invariant hi < arr_len;
          loop invariant arr_len < 0 || found <= hi + 1;
          loop assigns found, hi, end;
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
