
/*@
  requires rotations >= 0;
  requires arr_len > 0;
  requires \valid(arr + (0..arr_len-1));
  requires ranges_len == rotations;
  requires \valid(ranges + (0..ranges_len-1));
  requires \forall integer k; 0 <= k < ranges_len ==> \valid(ranges[k] + (0..1));
  requires 0 <= index && index < arr_len;
  requires \forall integer k; 0 <= k < ranges_len ==>
             (0 <= ranges[k][0] && ranges[k][0] <= ranges[k][1] && ranges[k][1] < arr_len);

  assigns \nothing;

  ensures \valid_read(\at(arr,Pre) + (0..arr_len-1));
  ensures (\exists integer k; 0 <= k < arr_len && \result == \at(arr[k], Pre));
*/
int foo213(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

    /*@
      loop invariant -1 <= i && i < rotations;
      loop invariant 0 <= arr_len;
      loop invariant 0 <= rotations;
      loop invariant \forall integer k; 0 <= k < rotations ==> \valid(ranges[k] + (0..1));
      loop invariant arr == \at(arr,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant rotations == \at(rotations,Pre);

      loop invariant (i >= 0) ==> (0 <= index && index < arr_len);

      loop invariant \forall integer k; 0 <= k < ranges_len ==>
                       (0 <= \at(ranges[k],Pre)[0] && \at(ranges[k],Pre)[0] <= \at(ranges[k],Pre)[1] && \at(ranges[k],Pre)[1] < arr_len);

      loop invariant (!(i >= 0)) ==> (0 <= index && index < arr_len);

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
