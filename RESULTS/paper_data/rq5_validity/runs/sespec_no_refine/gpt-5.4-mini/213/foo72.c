
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires \valid(&ranges[0] + (0..ranges_len-1));
  requires \forall integer i; 0 <= i < ranges_len ==> 0 <= ranges[i] <= 100;
  requires ranges_len > 0;
  requires ranges_len < 100;
  assigns index;
  ensures 0 <= index < arr_len;
  ensures \result == arr[index];
*/
int foo72(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

    /*@
      loop invariant (i >= 0) ==> (((index == \at(index,Pre))&&(rotations == \at(rotations,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= index < arr_len));
      loop invariant (!(i >= 0)) ==> ((index == \at(index,Pre))&&(rotations == \at(rotations,Pre))&&(ranges_cols == \at(ranges_cols,Pre))&&(ranges_rows == \at(ranges_rows,Pre))&&(ranges_len == \at(ranges_len,Pre))&&(ranges == \at(ranges,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
      loop invariant rotations == \at(rotations,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
      loop assigns i, left, right, index;
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
