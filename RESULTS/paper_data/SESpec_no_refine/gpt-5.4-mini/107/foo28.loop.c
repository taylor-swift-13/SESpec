
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo28(int * arr, int arr_len, int array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= i <= hi + 1 && hi < arr_len && 0 <= end < arr_len && arr_len == \at(arr_len,Pre) && arr == \at(arr,Pre) && array == \at(array,Pre)));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= i <= hi + 1 && hi < arr_len && 0 <= end < arr_len && arr_len == \at(arr_len,Pre) && arr == \at(arr,Pre) && array == \at(array,Pre)));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= i <= hi + 1 && hi < arr_len && 0 <= end < arr_len && end <= hi + 1 && arr_len == \at(arr_len,Pre) && arr == \at(arr,Pre) && array == \at(array,Pre)));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant 0 <= i <= arr_len;
          loop invariant -1 <= hi < arr_len;
          loop invariant 0 <= end < arr_len;
          loop invariant i <= hi + 1;
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
