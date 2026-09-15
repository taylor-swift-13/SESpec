
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires \valid(ranges + (0..ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0..ranges_cols-1));
  requires arr_len > 0 && arr_len < 100;
  requires ranges_len > 0 && ranges_len < 100;
  requires width >= 0 && width < arr_len; // Ensure initial width is valid
  assigns arr[0..arr_len-1]; // No local variables in assigns
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
  ensures \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0..ranges_cols-1));
  ensures arr[\result] == \old(arr[\result]); // Ensure the value at the result index is unchanged
*/
int foo67(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

        /*@
          loop invariant \forall integer k; 0 <= k < ranges_len ==> \valid(ranges[k] + (0..ranges_cols-1));
          loop invariant \forall integer k; 0 <= k < arr_len ==> \valid(arr + k);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant array == \at(array, Pre);
          loop invariant ranges_cols == \at(ranges_cols, Pre);
          loop invariant ranges_rows == \at(ranges_rows, Pre);
          loop invariant ranges_len == \at(ranges_len, Pre);
          loop invariant ranges == \at(ranges, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns width; // Local variable, allowed in loop assigns
          loop variant r;
        */
        for (int r = array - 1; r >= 0; r--) {
            int j = ranges[r][0];
            int top = ranges[r][1];
            if (j <= width && top >= width) {
                if (width == j) {
                    width = top;
                } else {
                    width = width - 1;
                }
            }
        }

        return arr[width];
}
