
/*@ 
  logic integer upd_count(int **ranges, integer r, integer c0) =
    r < 0 ? c0
          : (
              ( ranges[r][0] <= upd_count(ranges, r-1, c0)
                && ranges[r][1] >= upd_count(ranges, r-1, c0) )
                ? ( upd_count(ranges, r-1, c0) == ranges[r][0]
                    ? ranges[r][1]
                    : upd_count(ranges, r-1, c0) - 1
                  )
                : upd_count(ranges, r-1, c0)
            );
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \at(ranges_len,Pre) > 0 && \at(ranges_len,Pre) < 100;
  requires \valid(arr + (0 .. arr_len-1));
  requires \valid(ranges + (0 .. ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0 .. 1));
  assigns \nothing;
  ensures count == \at(count,Pre) || count == upd_count(ranges, array-1, \at(count,Pre));
*/
int foo68(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

        /*@
          loop invariant array == \at(array,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer ii; 0 <= ii < arr_len ==> arr[ii] == \at(arr[ii],Pre);
          loop invariant \forall integer ii; 0 <= ii < ranges_len ==> (\forall integer k; 0 <= k < 2 ==> ranges[ii][k] == \at(ranges[ii][k],Pre));
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
