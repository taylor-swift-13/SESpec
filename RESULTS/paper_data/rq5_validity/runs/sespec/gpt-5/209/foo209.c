

/*@
  requires arr_len >= 0;
  requires \valid(arr + (0 .. arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;

  requires ranges_len >= 0;
  requires \valid(ranges + (0 .. ranges_len-1));
  requires 0 <= array ==> array <= ranges_len;
  requires \forall integer r; 0 <= r < array ==> \valid(ranges[r] + (0 .. 1));
  // ensure width stays a valid index when updated
  requires 0 <= width < arr_len;
  requires \forall integer r; 0 <= r < array ==> 0 <= ranges[r][0] < arr_len;
  requires \forall integer r; 0 <= r < array ==> 0 <= ranges[r][1] < arr_len;

  assigns \nothing;

  // result relation

  // result bounds
  ensures 0 <= \result <= 100;

  // frame conditions: arrays unchanged
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
  ensures \forall integer k; 0 <= k < ranges_len ==> \valid(ranges[k]) ==> (\forall integer c; 0 <= c <= 1 ==> ranges[k][c] == \at(ranges[k][c], Pre));
  ensures \forall integer k; 0 <= k < ranges_len ==> ranges[k] == \at(ranges[k], Pre);
*/
int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

        /*@
          loop invariant array == \at(array, Pre);
          loop invariant ranges == \at(ranges, Pre);
          loop invariant arr == \at(arr, Pre);
          loop invariant ranges_len == \at(ranges_len, Pre);
          loop invariant ranges_rows == \at(ranges_rows, Pre);
          loop invariant ranges_cols == \at(ranges_cols, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant (r >= 0) ==> (0 <= r && r < array);
          loop invariant 0 <= width < arr_len;
          loop invariant (r == array - 1) ==> (width == \at(width, Pre));
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
