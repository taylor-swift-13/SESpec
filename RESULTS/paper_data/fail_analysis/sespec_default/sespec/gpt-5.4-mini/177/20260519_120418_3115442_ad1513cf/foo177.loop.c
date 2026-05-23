
/*@
  logic integer occurs(int* arr, integer lo, integer hi, int value) =
    lo >= hi ? 0
             : occurs(arr, lo, hi - 1, value) + (arr[hi - 1] == value ? 1 : 0);
*/

int foo177(int * arr, int arr_len, int array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (i >= 0));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (hi < \at(arr_len,Pre)));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (end >= 0));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
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
