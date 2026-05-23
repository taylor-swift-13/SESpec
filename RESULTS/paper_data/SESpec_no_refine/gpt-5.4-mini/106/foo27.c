
/*@
  logic integer count_occ{L}(int* a, integer lo, integer hi, int v) =
    lo >= hi ? 0
             : count_occ(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns end, found, hi;
  ensures (\result == -1 && \forall integer i; 0 <= i < arr_len ==> arr[i] != array) ||
          (\result >= 0 && \result < arr_len && arr[\result] == array &&
           (\result == arr_len - 1 || arr[\result + 1] != array));
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
  ensures arr == \at(arr, Pre);
  ensures arr_len == \at(arr_len, Pre);
  ensures array == \at(array, Pre);
*/
int foo27(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= found <= hi + 1));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k], Pre);
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
