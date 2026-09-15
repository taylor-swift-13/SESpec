
/*@
  logic integer min(integer a, integer b) = a < b ? a : b;
  logic integer max(integer a, integer b) = a > b ? a : b;

  /*@
    predicate unchanged_array_ranges(int** ranges, integer len, integer rows, integer cols) =
      \forall integer i, j; 0 <= i < len && 0 <= j < cols ==> ranges[i][j] == \at(ranges[i][j], Pre);
  */
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires \valid(&ranges[0] + (0..ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> \valid(&ranges[i][0] + (0..ranges_cols-1));
  requires \forall integer i; 0 <= i < ranges_len ==> 0 <= ranges[i][0] <= ranges[i][1] < arr_len;
  requires ranges_len > 0;
  requires ranges_len < 100;
  requires rotations >= 0;
  requires rotations <= ranges_len;
  requires 0 <= index < arr_len;
  assigns index;
  ensures \result == arr[index];
  ensures 0 <= index < arr_len;
  ensures unchanged_array_ranges(ranges, ranges_len, ranges_rows, ranges_cols);
*/
int foo72(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

    /*@
      loop invariant 0 <= i < rotations ==> 
                     (\forall integer k; i <= k < rotations ==> 
                        ranges[k][0] <= index <= ranges[k][1] ==> 
                        (index == ranges[k][0] ? index == ranges[k][1] : index == \at(index, Here) - 1));
      loop invariant i < 0 ==> index == \at(index, Pre);
      loop invariant rotations == \at(rotations, Pre);
      loop invariant ranges_cols == \at(ranges_cols, Pre);
      loop invariant ranges_rows == \at(ranges_rows, Pre);
      loop invariant ranges_len == \at(ranges_len, Pre);
      loop invariant ranges == \at(ranges, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop invariant unchanged_array_ranges(ranges, ranges_len, ranges_rows, ranges_cols);
      loop invariant 0 <= index < arr_len;
      loop assigns i, left, right, index;
      loop variant i;
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
