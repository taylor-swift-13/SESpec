
/*@
  logic integer range_count(int** ranges, integer lo, integer hi, integer count) =
    (lo >= hi) ? count
               : ((ranges[hi - 1][0] <= count && ranges[hi - 1][1] >= count) ?
                  ((count == ranges[hi - 1][0]) ? ranges[hi - 1][1] : count - 1)
                  : range_count(ranges, lo, hi - 1, count));
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires \valid(ranges + (0..ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0..ranges_cols-1));
  requires ranges_cols == 2;
  requires num >= 0 && num <= ranges_len;
  requires count >= 0 && count < arr_len;
  ensures \result == arr[range_count(ranges, 0, num, count)];
  ensures \forall integer i; 0 <= i < ranges_len ==> \forall integer j; 0 <= j < ranges_cols ==> ranges[i][j] == \at(ranges[i][j], Pre);
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
  assigns \nothing;
*/
int foo208(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {
    /*@
      loop invariant -1 <= r < num;
      loop invariant 0 <= r + 1 <= num;
      loop invariant count == range_count(ranges, r + 1, num, \at(count, Pre));
      loop invariant \forall integer k; 0 <= k < ranges_len ==> \valid(ranges[k] + (0..ranges_cols-1));
      loop invariant ranges_cols == \at(ranges_cols, Pre);
      loop invariant ranges_rows == \at(ranges_rows, Pre);
      loop invariant ranges_len == \at(ranges_len, Pre);
      loop invariant ranges == \at(ranges, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop invariant num == \at(num, Pre);
      loop invariant \forall integer k; 0 <= k < ranges_len ==> \forall integer j; 0 <= j < ranges_cols ==> ranges[k][j] == \at(ranges[k][j], Pre);
      loop assigns count;
      loop variant r;
    */
    for (int r = num - 1; r >= 0; r--) {
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
