

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires \valid(&ranges[0] + (0..ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> 0 <= ranges[i] <= 100;
  requires ranges_len > 0;
  requires ranges_len < 100;
  assigns \nothing, width;
  ensures \result == arr[width];
*/
int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

  /*@
    loop invariant array == \at(array, Pre);
    loop invariant ranges == \at(ranges, Pre);
    loop invariant ranges_len == \at(ranges_len, Pre);
    loop invariant ranges_rows == \at(ranges_rows, Pre);
    loop invariant ranges_cols == \at(ranges_cols, Pre);
    loop invariant arr == \at(arr, Pre);
    loop invariant arr_len == \at(arr_len, Pre);
    loop invariant \forall integer i, j; 0 <= i < ranges_rows && 0 <= j < ranges_cols ==> ranges[i][j] == \at(ranges[i][j], Pre);
    loop assigns r, width;
  */
  for (int r = array - 1; r >= 0; r--) {
    int j = ranges[r][0];
    int top = ranges[r][1];
    if (j <= width && top >= width) {
      if (width == j) {
        width = top;
      } else {
        width = width - 1;
      }
    }
  }

  return arr[width];
}
