
/*@
  logic integer count_rows(int **ranges, integer lo, integer hi) =
    lo >= hi ? 0 : count_rows(ranges, lo, hi - 1) + 1;
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
  assigns count;
  ensures 0 <= count <= \old(ranges_len);
  ensures \result == arr[count];
*/
int foo68(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

	/*@
      loop invariant (r >= 0) ==> (((count == \at(count,Pre))&&(array == \at(array,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= count <= \at(ranges_len,Pre)));
      loop invariant (!(r >= 0)) ==> ((count == \at(count,Pre))&&(array == \at(array,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
      loop invariant array == \at(array,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \valid_read(ranges + (0 .. \at(array,Pre) - 1));
      loop invariant \valid_read(arr + (0 .. arr_len - 1));
      loop invariant 0 <= count <= \at(ranges_len,Pre);
      loop assigns r, j, top, count;
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
