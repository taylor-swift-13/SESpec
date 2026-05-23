
/*@
*/

/*@
  requires 0 <= arr_len;
  requires \valid_read(arr + (0 .. arr_len - 1));

  requires 0 <= ranges_len;
  requires 0 <= ranges_rows;
  requires 0 <= ranges_cols;
  requires ranges_rows >= rotations;
  requires ranges_cols >= 2;
  requires \valid_read(ranges + (0 .. rotations - 1));
  requires \forall integer i; 0 <= i < rotations ==> \valid_read(ranges[i] + (0 .. 1));
  requires \forall integer i; 0 <= i < rotations ==>
              0 <= ranges[i][0] <= ranges[i][1] < arr_len;

  requires 0 <= index < arr_len;
  assigns \nothing;
  ensures \result == \null ==> \true;
  ensures \result == arr[foo213_index_after_rotations{Pre}(ranges, rotations, index)];
  ensures 0 <= foo213_index_after_rotations{Pre}(ranges, rotations, index) < arr_len;
  ensures \forall integer i; 0 <= i < rotations ==>
            (ranges[i][0] <= foo213_index_after_rotations{Pre}(ranges, rotations, index) &&
             foo213_index_after_rotations{Pre}(ranges, rotations, index) <= ranges[i][1]) ==
            (foo213_index_after_rotations{Pre}(ranges, rotations, index) == ranges[i][0] ||
             foo213_index_after_rotations{Pre}(ranges, rotations, index) == ranges[i][0] - 1);
*/
int foo213(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant -1 <= i < rotations;
          loop invariant 0 <= index < arr_len;
          loop assigns i, index, left, right;
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
