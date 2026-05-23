
/*@
  requires arr_len >= 0;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
*/
int foo176(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
        /*@
          loop invariant 0 <= found;
          loop invariant hi < arr_len;
          loop invariant 0 < arr_len ==> hi < arr_len;
          loop invariant found <= hi + 1;
          loop invariant 0 <= end;
          loop invariant 0 < arr_len ==> found <= arr_len;
          loop invariant 0 < arr_len ==> 0 <= end < arr_len;
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant (0 <= arr_len - 1) ==> (found <= hi + 1);
          loop invariant (0 <= arr_len - 1) ==> (((end == 0)&&(hi == arr_len - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (found <= hi + 1));
          loop invariant (0 <= arr_len - 1) ==> (((end == 0)&&(hi == arr_len - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (hi < arr_len));
          loop invariant (0 <= arr_len - 1) ==> (((end == 0)&&(hi == arr_len - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= end < arr_len));
          loop invariant (!(0 <= arr_len - 1)) ==> ((end == 0)&&(hi == arr_len - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
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
