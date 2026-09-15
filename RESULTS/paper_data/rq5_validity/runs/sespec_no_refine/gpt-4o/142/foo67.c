
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  predicate unchanged_array_ranges(int** ranges, integer rows, integer cols) =
    \forall integer i, j; 0 <= i < rows && 0 <= j < cols ==> ranges[i][j] == \at(ranges[i][j], Pre);
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
  requires array > 0;
  requires array <= ranges_len;
  assigns width;
  ensures \forall integer r; 0 <= r < array ==> 
            (ranges[r][0] <= \old(width) && ranges[r][1] >= \old(width)) ==>
            (width == ranges[r][1] || width == \old(width) - 1);
  ensures \result == arr[width];
*/
int foo67(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

        /*@
          loop invariant 0 <= r + 1 <= array;
          loop invariant \forall integer k; r + 1 <= k < array ==> 
            (ranges[k][0] <= \at(width, Pre) && ranges[k][1] >= \at(width, Pre)) ==>
            (width == ranges[k][1] || width == \at(width, Pre) - 1);
          loop invariant \forall integer i, j; 0 <= i < ranges_rows && 0 <= j < ranges_cols ==> 
            ranges[i][j] == \at(ranges[i][j], Pre);
          loop invariant \valid(&arr[0] + (0..arr_len-1));
          loop invariant \valid(&ranges[0] + (0..ranges_len-1));
          loop invariant \forall integer i; 0 <= i < ranges_len ==> \valid(&ranges[i][0] + (0..ranges_cols-1));
          loop invariant 0 <= width < arr_len;
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
