
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
  predicate unchanged_array_ranges{L1, L2}(int** ranges, integer rows, integer cols) =
    \forall integer i, j; 0 <= i < rows && 0 <= j < cols ==> \at(ranges[i][j], L1) == \at(ranges[i][j], L2);
*/

int foo68(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

        /*@
          loop invariant (r >= 0) ==> (((count == \at(count,Pre))&&(array == \at(array,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (count >= 0 && count < arr_len));
          loop invariant (!(r >= 0)) ==> ((count == \at(count,Pre))&&(array == \at(array,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array_ranges{Pre,Here}(ranges, ranges_rows, ranges_cols);
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
