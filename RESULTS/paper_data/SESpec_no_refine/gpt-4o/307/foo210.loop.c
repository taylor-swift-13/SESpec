
/*@
  logic integer max_element(int* array, integer begin, integer end) =
    begin >= end ? 0 : 
    (\max(array[begin], max_element(array, begin + 1, end)));
*/

/*@
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100;
  requires \valid(positions + (0 .. \at(positions_len,Pre) - 1));
  ensures \result == max_element(positions, 0, \at(positions_len,Pre));
*/
int foo210(int * positions, int positions_len) {

    int largest = 0;

    /*@
      loop invariant 0 <= count <= \at(positions_len,Pre);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop assigns count, largest;
    */
    for (int count = 0; count < positions_len; count++) {
        if (positions[count] > 0 && positions[count] > largest) {
            largest = positions[count];
        }
    }

    return largest;
}
