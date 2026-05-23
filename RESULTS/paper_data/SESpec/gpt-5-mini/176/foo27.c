
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \forall integer i; 0 <= i+1 < arr_len ==> arr[i] <= arr[i+1];
  assigns \nothing;
  ensures arr_len == \at(arr_len,Pre);
  ensures array == \at(array,Pre);
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i],Pre);
*/
int foo27(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /*@
          loop invariant 0 <= found <= \at(arr_len,Pre);
          loop invariant -1 <= hi <= \at(arr_len,Pre) - 1;
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==>
                        (count_eq(arr, 0, \at(arr_len,Pre), array) ==
                         count_eq(arr, 0, \at(arr_len,Pre), array));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || ((found >= 0) && (hi >= -1)));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer i; 0 <= i < \at(arr_len,Pre) ==> \at(arr[i],Pre) == arr[i];
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
