
/*@
  logic integer apply_ranges(int** ranges, integer lo, integer hi, integer w) =
    lo >= hi ? w
             : (
                 (ranges[hi-1][0] <= w && ranges[hi-1][1] >= w)
                   ? (ranges[hi-1][0] == w
                        ? apply_ranges(ranges, lo, hi-1, ranges[hi-1][1])
                        : apply_ranges(ranges, lo, hi-1, w - 1))
                   : apply_ranges(ranges, lo, hi-1, w)
               );
*/

/*@
  requires arr_len >= 0;
  requires \valid(arr + (0 .. arr_len - 1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] && arr[i] <= 100;
  requires ranges_rows >= 0 && ranges_cols >= 2;
  requires \valid(ranges + (0 .. ranges_rows - 1));
  requires \forall integer i; 0 <= i < ranges_rows ==>
             \valid(ranges[i] + (0 .. ranges_cols - 1));
  requires \forall integer i, j; 0 <= i < ranges_rows && 0 <= j < ranges_cols ==>
             0 <= ranges[i][j] && ranges[i][j] <= 100;
  requires 0 <= width && width < arr_len;
  requires 0 <= array && array <= ranges_rows;
  assigns \nothing;
  ensures 0 <= apply_ranges(ranges, 0, array, \old(width)) && apply_ranges(ranges, 0, array, \old(width)) < arr_len;
  ensures \result == arr[ apply_ranges(ranges, 0, array, \old(width)) ];
  ensures 0 <= \result && \result <= 100;
  ensures array == \at(array,Pre);
  ensures ranges_len == \at(ranges_len,Pre);
*/
int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

    /*@
      loop invariant -1 <= r && r < array;
      loop invariant 0 <= arr_len;
      loop invariant apply_ranges(ranges, r+1, array, \at(width,Pre)) == width;
      loop invariant (r < 0) ==> (width == apply_ranges(ranges, 0, array, \at(width,Pre)));
      loop invariant \forall integer k; r+1 <= k && k < array ==>
                        (apply_ranges(ranges, k, array, \at(width,Pre)) ==
                         apply_ranges(ranges, r+1, array, \at(width,Pre)));
      loop invariant array == \at(array,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer k; 0 <= k && k < ranges_len ==>
                        ranges[k][0] == \at(ranges[k][0],Pre) && ranges[k][1] == \at(ranges[k][1],Pre);
      loop assigns width;
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
