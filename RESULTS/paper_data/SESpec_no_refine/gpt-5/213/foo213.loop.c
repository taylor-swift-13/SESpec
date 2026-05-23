
/*@
  // No additional predicates or logic functions needed.
*/

int foo213(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

        /*@ 
          loop invariant arr == \at(arr,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant rotations == \at(rotations,Pre);
          loop invariant -1 <= i <= rotations - 1;
          loop invariant 0 <= index < arr_len;
          loop assigns i, index;
        */
            /*@
          loop invariant -1 <= i <= rotations - 1;
          loop invariant arr == \at(arr,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant ranges == \at(ranges,Pre);
          loop invariant ranges_len == \at(ranges_len,Pre);
          loop invariant ranges_rows == \at(ranges_rows,Pre);
          loop invariant ranges_cols == \at(ranges_cols,Pre);
          loop invariant rotations == \at(rotations,Pre);
          loop invariant 0 <= index < arr_len;
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
