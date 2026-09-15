
/*@
  logic integer max_in_range(int* array, integer begin, integer end) =
    begin >= end ? 0 : 
    (array[begin] > max_in_range(array, begin + 1, end) ? array[begin] : max_in_range(array, begin + 1, end));
*/

/*@
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100;
  requires \valid(positions + (0 .. \at(positions_len,Pre) - 1));
  assigns \nothing;
*/
int foo211(int * positions, int positions_len) {

    int result = 0;

    /*@
      loop invariant 0 <= index <= \at(positions_len,Pre);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop assigns index, result;
      loop variant \at(positions_len,Pre) - index;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > result) {
            result = positions[index];
        }
    }

    return result;
}
