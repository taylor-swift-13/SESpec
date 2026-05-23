
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ 
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo175(int * arr, int arr_len, int Array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (0 <= i <= \at(arr_len,Pre) && -1 <= hi < \at(arr_len,Pre) && 0 <= end < \at(arr_len,Pre));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (i == 0 || hi == \at(arr_len,Pre) - 1 || end >= 0));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (hi == \at(arr_len,Pre) - 1 || i <= hi + 1));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (end >= 0 || i == 0));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((end == 0)&&(hi == \at(arr_len,Pre) - 1)&&(i == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop assigns end, i, hi;
            */
            while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == Array) {
				if (end == arr_len - 1
						|| arr[end + 1] != Array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < Array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
            
		return -1;
}
