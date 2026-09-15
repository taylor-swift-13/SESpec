
/*@
  logic integer count_eq{L}(int** ranges, integer lo, integer hi, int* p) =
    lo >= hi ? 0
             : count_eq(ranges, lo, hi - 1, p) + (ranges[hi - 1] == p ? 1 : 0);
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
  assigns width;
  ensures arr == \at(arr,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures ranges == \at(ranges,Pre);
  ensures ranges_len == \at(ranges_len,Pre);
  ensures ranges_rows == \at(ranges_rows,Pre);
  ensures ranges_cols == \at(ranges_cols,Pre);
  ensures array == \at(array,Pre);
  ensures \result == arr[width];
*/
int foo67(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

    /*@
      loop invariant (r >= 0) ==> (((width == \at(width,Pre))&&(array == \at(array,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (PLACE_HOLDER_width));
      loop invariant (!(r >= 0)) ==> ((width == \at(width,Pre))&&(array == \at(array,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
      loop invariant array == \at(array,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_ranges ;
      loop assigns r, j, top, width;
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
