
/*@
  logic integer max_in_array(int* array, integer len) =
    len <= 0 ? 0 : (array[len - 1] > max_in_array(array, len - 1) ? array[len - 1] : max_in_array(array, len - 1));
*/

/*@
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100;
  requires \valid(positions + (0..\at(positions_len,Pre)-1));
*/
int foo212(int * positions, int positions_len) {

    int largest = 0;

    /*@
      loop invariant 0 <= index <= \at(positions_len,Pre);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop assigns index, largest;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > largest) {
            largest = positions[index];
        }
    }

    return largest;
}
