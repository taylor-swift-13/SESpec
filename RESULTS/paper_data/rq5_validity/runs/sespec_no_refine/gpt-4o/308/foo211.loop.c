
/*@
  logic integer max_in_range(int* array, integer begin, integer end) =
    begin >= end ? 0 : 
    (array[begin] > max_in_range(array, begin + 1, end) ? array[begin] : max_in_range(array, begin + 1, end));
*/

/*@
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100;
  requires \valid(positions + (0 .. \at(positions_len,Pre) - 1));
  ensures \result == max_in_range(positions, 0, \at(positions_len,Pre));
*/
int foo211(int * positions, int positions_len) {

    int result = 0;

    /*@
      loop invariant 0 <= index <= \at(positions_len,Pre);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop assigns index, result;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > result) {
            result = positions[index];
        }
    }

    return result;
}
