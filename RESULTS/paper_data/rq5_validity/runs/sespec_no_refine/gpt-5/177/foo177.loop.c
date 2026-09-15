
/*@
  // no extra logic/predicate needed
*/

int foo177(int * arr, int arr_len, int array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant arr == \at(arr,Pre);
              loop invariant arr_len == \at(arr_len,Pre);
              loop invariant array == \at(array,Pre);
              loop invariant \valid_read(arr + (0 .. arr_len-1));
              loop invariant 0 <= arr_len-1 ==> -1 <= hi < arr_len;
              loop invariant 0 <= arr_len-1 ==> 0 <= i <= hi + 1;
              loop invariant 0 <= arr_len-1 ==> \forall integer k; 0 <= k < i ==> arr[k] <= array;
              loop invariant 0 <= arr_len-1 ==> \forall integer k; hi < k < arr_len ==> arr[k] > array;
              loop assigns end, i, hi;
            */
            while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
            
		return -1;
}
