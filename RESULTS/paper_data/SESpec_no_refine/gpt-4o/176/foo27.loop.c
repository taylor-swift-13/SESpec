
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer max(int* array, integer begin, integer end) =
    end <= begin ? 0 : max(array, begin, end - 1) > array[end - 1] ? max(array, begin, end - 1) : array[end - 1];
*/

/*@
  logic integer min(int* array, integer begin, integer end) =
    end <= begin ? 0 : min(array, begin, end - 1) < array[end - 1] ? min(array, begin, end - 1) : array[end - 1];
*/


int foo27(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (PLACE_HOLDER_found));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (PLACE_HOLDER_hi));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (PLACE_HOLDER_end));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant PLACE_HOLDER_ARRAY_arr ;
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
