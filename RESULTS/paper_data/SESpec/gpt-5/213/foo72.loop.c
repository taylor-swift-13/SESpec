
/*@ predicate ranges_unchanged{L1,L2}(int** ranges,
                                      integer rows,
                                      integer cols,
                                      integer lo,
                                      integer hi) =
      \at(ranges, L1) == \at(ranges, L2) &&
      0 <= lo <= hi <= rows &&
      cols >= 2 &&
      (\forall integer k; lo <= k < hi ==> \at(ranges[k], L1) == \at(ranges[k], L2)) &&
      (\forall integer k; lo <= k < hi ==> \at(ranges[k][0], L1) == \at(ranges[k][0], L2)) &&
      (\forall integer k; lo <= k < hi ==> \at(ranges[k][1], L1) == \at(ranges[k][1], L2));
*/

int foo72(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

    /*@
      loop invariant rotations == \at(rotations,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);

      loop invariant i <= rotations - 1;
      loop invariant (i >= 0) ==> (0 <= i < rotations);

      loop assigns i, index;
    */
    for (int i = rotations - 1; i >= 0; i--) {
        int left = ranges[i][0];
        int right = ranges[i][1];
        if (left <= index && right >= index) {
            if (index == left) {
                index = right;
            } else {
                index = index - 1;
            }
        }
    }

    return arr[index];
}
