
int foo208(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant -1 <= r <= num - 1;
      loop invariant 0 <= num;
      loop invariant (r >= 0) ==> (0 <= r < num);
      loop invariant arr == \at(arr, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant ranges == \at(ranges, Pre);
      loop invariant ranges_len == \at(ranges_len, Pre);
      loop invariant ranges_rows == \at(ranges_rows, Pre);
      loop invariant ranges_cols == \at(ranges_cols, Pre);
      loop invariant num == \at(num, Pre);
      loop invariant \forall integer k; 0 <= k < ranges_len ==> ranges[k] == \at(ranges[k], Pre);
      loop invariant (r >= 0) ==> (j == ranges[r][0]);
      loop invariant (r >= 0) ==> (top == ranges[r][1]);
      loop invariant (r < 0) ==> (0 <= count < arr_len);
      loop assigns r, j, top, count;
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
