int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index);

/*@ 
  requires arr_len > 0;
  requires 0 <= index < arr_len;

  requires rotations >= 0;

  // validity of arrays
  requires \valid_read(arr + (0 .. arr_len-1));
  requires rotations == 0 || \valid_read(ranges + (0 .. rotations-1));
  requires rotations == 0 || ranges_cols >= 2;
  requires \forall integer i; 0 <= i < rotations ==> \valid_read(ranges[i] + (0 .. 1));

  // each range is within array bounds and well-formed
  requires \forall integer i; 0 <= i < rotations ==> 
            0 <= ranges[i][0] <= ranges[i][1] < arr_len;

  assigns \nothing;

  // postconditions
  ensures 0 <= index < arr_len;
  ensures \result == arr[index];
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

        /*@
          loop invariant -1 <= i < rotations;
          loop invariant 0 <= index < arr_len;
          loop assigns i, index;
          loop variant i+1;
        */
        for (int i = rotations - 1; i >= 0; i--) {
            /*@ assert 0 <= i < rotations; */
            int left = ranges[i][0];
            int right = ranges[i][1];
            /*@ assert 0 <= left <= right < arr_len; */
            if (left <= index && right >= index) {
                if (index == left) {
                    index = right;
                } else {
                    index = index - 1;
                }
                /*@ assert 0 <= index < arr_len; */
            }
        }
        /*@ assert 0 <= index < arr_len; */
        return arr[index];
}
