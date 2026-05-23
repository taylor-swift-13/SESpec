
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires rotations >= 0;
  requires \valid(arr + (0 .. arr_len - 1));
  requires \valid(ranges + (0 .. rotations - 1));
  requires \forall integer k; 0 <= k < rotations ==> \valid(ranges[k] + (0 .. 1));
  requires \forall integer k; 0 <= k < rotations ==> 0 <= ranges[k][0] <= ranges[k][1] < arr_len;
  ensures \result == arr[index];
*/
int foo213(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

    /*@
      loop invariant -1 <= i < rotations;
      loop invariant \forall integer k; 0 <= k < rotations ==> 0 <= ranges[k][0] <= ranges[k][1] < arr_len;
      loop invariant \forall integer k; i <= k < rotations ==> 
                       (ranges[k][0] <= index <= ranges[k][1] ==> 
                        (index == ranges[k][1] || index == ranges[k][0] - 1 || index >= ranges[k][0]));
      loop invariant rotations == \at(rotations, Pre);
      loop invariant ranges_cols == \at(ranges_cols, Pre);
      loop invariant ranges_rows == \at(ranges_rows, Pre);
      loop invariant ranges_len == \at(ranges_len, Pre);
      loop invariant ranges == \at(ranges, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
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
