
/*@
  logic integer min(integer a, integer b) = a < b ? a : b;
  logic integer max(integer a, integer b) = a > b ? a : b;

  /*@
    predicate unchanged_array_ranges(int** ranges, integer len, integer rows, integer cols) =
      \forall integer i, j; 0 <= i < len && 0 <= j < cols ==> ranges[i][j] == \at(ranges[i][j], Pre);
  */
*/

int foo72(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

    /*@
      loop invariant (i >= 0) ==> (((index == \at(index,Pre))&&(rotations == \at(rotations,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || 
                                   (\exists integer k; i <= k < rotations && ranges[k][0] <= \at(index,Pre) && ranges[k][1] >= \at(index,Pre)));
      loop invariant (!(i >= 0)) ==> ((index == \at(index,Pre))&&(rotations == \at(rotations,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
      loop invariant rotations == \at(rotations,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant unchanged_array_ranges(ranges, ranges_len, ranges_rows, ranges_cols);
      loop assigns i, left, right, index;
    */
    for (int i = rotations - 1; i >= 0; i--) {
        int left = ranges[i][0];
        int right = ranges[i][1];
        if (left <= index && right >= index) {
            if (index == left) {
                index = right;
            } else {
                index = index - 1;
            }
        }
    }

    return arr[index];
}
