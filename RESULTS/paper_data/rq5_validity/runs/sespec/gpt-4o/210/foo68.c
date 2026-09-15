
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
  predicate unchanged_array_ranges{L1,L2}(int** ranges, integer len) =
    \forall integer i, j; 0 <= i < len && 0 <= j < 2 ==> \at(ranges[i][j], L1) == \at(ranges[i][j], L2);
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires \valid(ranges + (0..ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0..1));
  requires \forall integer i; 0 <= i < ranges_len ==> 0 <= ranges[i][0] <= 100 && 0 <= ranges[i][1] <= 100;
  requires ranges_len > 0;
  requires ranges_len < 100;
  requires array > 0 && array <= ranges_len;
  requires count >= 0 && count < arr_len;
  requires \forall integer r; 0 <= r < ranges_len ==> ranges[r][1] < arr_len; // Ensure "top" is within bounds
  requires \forall integer r1, r2; 0 <= r1 < r2 < ranges_len ==> ranges[r1][1] < ranges[r2][0]; // Ensure ranges do not overlap
  requires count >= ranges[array - 1][0] && count <= ranges[array - 1][1]; // Ensure count is within the bounds of the first range
  assigns \nothing;
  ensures \forall integer r; 0 <= r < array ==> unchanged_array_ranges{Pre,Here}(ranges, ranges_len);
  ensures \result == arr[count];
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
          loop invariant unchanged_array_ranges{Pre,Here}(ranges, ranges_len);
          loop invariant count >= 0 && count < arr_len; // Ensure count remains within bounds
          loop invariant -1 <= r < array;
          loop assigns r;
          loop variant r;
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
