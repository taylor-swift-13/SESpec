

/*@
  requires arr_len >= 0;
  requires ranges_len >= 0;
  requires array >= 0;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires \valid_read(ranges + (0 .. ranges_len-1));
  // each ranges[r] points to at least two readable ints
  requires \forall integer r; 0 <= r < ranges_len ==> \valid_read(ranges[r] + (0 .. 1));
  // initial count within bounds of arr
  requires 0 <= count < arr_len;
  // loop will iterate over r = array-1 .. 0; ensure those indices are valid into ranges
  requires array <= ranges_len;
  // updates keep count within bounds: tops are within arr range, and decrements never underflow
  requires \forall integer r; 0 <= r < array ==> (0 <= ranges[r][0] <= ranges[r][1] < arr_len);
  requires \forall integer r; 0 <= r < array ==> ( !(ranges[r][0] <= count && ranges[r][1] >= count) || (count == ranges[r][0] ? ranges[r][1] < arr_len : count > 0) );
  assigns \nothing;
*/
int foo210(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

    /*@
      loop invariant array == \at(array,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);

      loop invariant \forall integer k; 0 <= k < ranges_len ==> ranges[k] == \at(ranges[k], Pre);

      loop invariant (array >= 0) ==> (-1 <= r && r <= array - 1);
      loop invariant (r >= 0) ==> (0 <= r && r < array);

      loop invariant \true;

      loop assigns r, count;
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
