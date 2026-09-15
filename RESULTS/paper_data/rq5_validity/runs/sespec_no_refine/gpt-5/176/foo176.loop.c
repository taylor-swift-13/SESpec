
/*@ 
    logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
      lo >= hi ? 0
               : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ 
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid_read(\at(arr,Pre) + (0 .. \at(arr_len,Pre)-1));
  requires \forall integer i; 0 <= i+1 < \at(arr_len,Pre) ==> \at(arr,Pre)[i] <= \at(arr,Pre)[i+1];
  assigns \nothing;
*/
int foo176(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (0 <= found && found <= hi + 1 && hi < \at(arr_len,Pre));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(found == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr,Pre)[k] ;
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
