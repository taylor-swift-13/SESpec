
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

      loop invariant (array >= 0) ==> (-1 <= r <= array - 1);
      loop invariant (r >= 0) ==> (0 <= r < array);

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
