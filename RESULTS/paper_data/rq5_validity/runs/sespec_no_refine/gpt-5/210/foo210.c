
/*@
  // Helper to relate r with how many rows have been processed so far.
  logic integer processed_len(integer array, integer r) =
    (r < 0) ? array : (array - 1 - r);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires \valid(&ranges[0] + (0..ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> 0 <= ranges[i] <= 100;
  requires ranges_len > 0;
  requires ranges_len < 100;
  assigns \nothing;   
  ensures \result == arr[count];
  ensures \result == arr[count];
*/
int foo210(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

        /*@ 
          loop invariant array == \at(array,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant -1 <= r <= array - 1;
          loop invariant 0 <= processed_len(array, r) <= array;
          loop assigns r, count, j, top;
        */
            for (int r = array - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= count && top >= count) {
				if (count == j) {
					count = top;
				} else {
					count = count - 1;
				}
			}
		}
            
		return arr[count];
}
