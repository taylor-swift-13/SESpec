
/*@
  logic integer count_range_step(integer count, integer j, integer top) =
    (j <= count && top >= count) ? (count == j ? top : count - 1) : count;

  logic integer count_range_prefix(int **ranges, integer r, integer count) =
    r <= 0 ? count
           : count_range_prefix(ranges, r - 1, count_range_step(count_range_prefix(ranges, r - 1, count), ranges[r - 1][0], ranges[r - 1][1]));
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
  ensures count == count_range_prefix(ranges, array, \old(count));
  ensures \result == arr[count_range_prefix(ranges, array, \old(count))];
*/
int foo68(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

  /*@
    loop invariant 0 <= r + 1 <= array;
    loop invariant array == \at(array,Pre);
    loop invariant ranges_cols == \at(ranges_cols,Pre);
    loop invariant ranges_rows == \at(ranges_rows,Pre);
    loop invariant ranges_len == \at(ranges_len,Pre);
    loop invariant ranges == \at(ranges,Pre);
    loop invariant arr_len == \at(arr_len,Pre);
    loop invariant arr == \at(arr,Pre);
    loop invariant count == count_range_prefix(ranges, array - (r + 1), \at(count,Pre));
    loop invariant \forall integer k; 0 <= k < array ==> \valid_read(ranges[k] + (0..1));
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
