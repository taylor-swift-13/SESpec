

/*@
  requires 0 <= arr_len;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;

  requires 0 <= ranges_len;
  requires \valid(&ranges[0] + (0..ranges_len-1));
  requires \forall integer r; 0 <= r < ranges_len ==> \valid(ranges[r] + (0..1));

  requires 0 <= num <= ranges_len;
  requires 0 <= count < arr_len;

  // Each interval [ranges[r][0], ranges[r][1]] must lie within array bounds
  requires \forall integer r; 0 <= r < num ==> 0 <= ranges[r][0] <= ranges[r][1] < arr_len;

  assigns \nothing;

  ensures arr == \at(arr, Pre) && arr_len == \at(arr_len, Pre) &&
          ranges == \at(ranges, Pre) && ranges_len == \at(ranges_len, Pre) &&
          ranges_rows == \at(ranges_rows, Pre) && ranges_cols == \at(ranges_cols, Pre) &&
          num == \at(num, Pre) && count == \at(count, Pre);

  ensures 0 <= \result && \result <= 100;
*/
int foo208(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {

    /*@
      loop invariant -1 <= r <= num - 1;
      loop invariant 0 <= num <= ranges_len;
      loop invariant (r >= 0) ==> (0 <= r < num);
      loop invariant (r >= 0) ==> (r < ranges_len);
      loop invariant \forall integer k; 0 <= k < num ==> 0 <= ranges[k][0] <= ranges[k][1] < arr_len;
      loop invariant arr == \at(arr, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant ranges == \at(ranges, Pre);
      loop invariant ranges_len == \at(ranges_len, Pre);
      loop invariant ranges_rows == \at(ranges_rows, Pre);
      loop invariant ranges_cols == \at(ranges_cols, Pre);
      loop invariant \forall integer k; 0 <= k < ranges_len ==> ranges[k] == \at(ranges[k], Pre);
      loop invariant 0 <= count < arr_len;
      loop assigns r, count;
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
