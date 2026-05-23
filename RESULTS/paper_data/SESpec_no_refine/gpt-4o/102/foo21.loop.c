
/*@
  logic integer unchanged_array{L1,L2}(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> \at(arr[i],L1) == \at(arr[i],L2);
*/

/*@
  logic integer is_sorted(int* arr, integer lo, integer hi) =
    lo >= hi - 1 ? 1 : (arr[lo] <= arr[lo + 1] && is_sorted(arr, lo + 1, hi));
*/

/*@
  logic integer is_partitioned(int* arr, integer lo, integer hi, integer pivot) =
    lo >= hi ? 1 : 
    (arr[lo] < pivot ? is_partitioned(arr, lo + 1, hi, pivot) : 0);
*/

int foo21(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((stop == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (PLACE_HOLDER_ret));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((stop == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (PLACE_HOLDER_stop));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((stop == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_arr ;
          loop assigns r, ret, stop;
            */
            while (ret <= stop) {
			int r = ret + (stop - ret) / 2;
			if (r < stop
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				stop = r - 1;
			}
		}
            
		return 0;
}
