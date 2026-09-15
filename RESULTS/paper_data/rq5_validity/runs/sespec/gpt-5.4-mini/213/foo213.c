/*@
  logic integer foo213_rot_index{L}(int **ranges, integer rotations, integer index) =
    rotations <= 0
    ? index
    : (ranges[rotations - 1][0] <= index && index <= ranges[rotations - 1][1]
       ? (index == ranges[rotations - 1][0]
          ? ranges[rotations - 1][1]
          : index - 1)
       : index);
*/

/*@
  requires arr_len > 0;
  requires 0 <= index < arr_len;
  requires \valid_read(arr + (0..arr_len-1));
  requires rotations >= 0;
  requires ranges_len >= rotations;
  requires \valid_read(ranges + (0..ranges_len-1));
  requires \forall integer k; 0 <= k < rotations ==> \valid_read(ranges[k] + (0..1));
  requires \forall integer k; 0 <= k < rotations ==> 0 <= ranges[k][0] < arr_len;
  requires \forall integer k; 0 <= k < rotations ==> 0 <= ranges[k][1] < arr_len;
  assigns \nothing;

  ensures \true;
*/
int foo213(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

    /*@
      loop invariant i < rotations;
      loop invariant 0 <= index < arr_len;
      loop invariant rotations == \at(rotations,Pre);
      loop invariant ranges_cols == \at(ranges_cols,Pre);
      loop invariant ranges_rows == \at(ranges_rows,Pre);
      loop invariant ranges_len == \at(ranges_len,Pre);
      loop invariant ranges == \at(ranges,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer j; 0 <= j < arr_len ==> arr[j] == \at(arr[j],Pre);
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