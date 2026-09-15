
/*@
  // Compute resulting count after processing ranges indices in [0..r]
  // starting from initial count `c0`. We treat `ranges` as a 2D array
  // ranges[i][0] = j_i, ranges[i][1] = top_i.
  //
  // The semantics of processing one range i on current count c is:
  //   if (j_i <= c && top_i >= c) {
  //     if (c == j_i) c := top_i;
  //     else c := c - 1;
  //   }
  // else c unchanged.
  //
  // The recursive function processes indices 0..r (inclusive).
  logic integer upd_count(int **ranges, integer r, integer c0) =
    r < 0 ? c0
          : (
              // get current range endpoints
              (\let j = ranges[r][0]; \let top = ranges[r][1];
                (j <= upd_count(ranges, r-1, c0) && top >= upd_count(ranges, r-1, c0))
                  ? (
                      upd_count(ranges, r-1, c0) == j ? top : upd_count(ranges, r-1, c0) - 1
                    )
                  : upd_count(ranges, r-1, c0)
              )
            );
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \at(ranges_len,Pre) > 0 && \at(ranges_len,Pre) < 100;
  requires \valid(arr + (0 .. arr_len-1));
  requires \valid(ranges + (0 .. ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0 .. 1));
*/
int foo68(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

        /*@
          loop invariant -1 <= r && r < \at(array,Pre);
          // When r >= 0, count equals the result of processing indices r..(array-1)
          // But our upd_count is defined processing 0..r, so we express the
          // relation in terms of the initial array index: the value of count
          // after processing ranges with indices in [r .. array-1] starting from
          // the initial count is equal to upd_count(ranges, array-1, \at(count,Pre))
          // then "unprocessing" 0..(r-1). To keep it simple and sound we state:
          loop invariant (r >= 0) ==> (count == upd_count(ranges, r, \at(count,Pre)));
          // If r < 0 nothing changed w.r.t. Pre (we processed all ranges)
          loop invariant (!(r >= 0)) ==> ((count == \at(count,Pre)) &&
                                          (array == \at(array,Pre)) &&
                                          (ranges_cols == \at(ranges_cols,Pre)) &&
                                          (ranges_rows == \at(ranges_rows,Pre)) &&
                                          (ranges_len == \at(ranges_len,Pre)) &&
                                          (ranges == \at(ranges,Pre)) &&
                                          (arr_len == \at(arr_len,Pre)) &&
                                          (arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          // array elements and ranges pointers/contents are unchanged
          loop invariant \forall integer ii; 0 <= ii < arr_len ==> arr[ii] == \at(arr[ii],Pre);
          loop invariant \forall integer ii; 0 <= ii < ranges_len ==> (\forall integer k; 0 <= k < 2 ==> ranges[ii][k] == \at(ranges[ii][k],Pre));
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
