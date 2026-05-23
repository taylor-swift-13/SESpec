
/*@
  logic integer max_in_prefix(int* array, integer len) =
    len <= 0 ? 0 : max_in_prefix(array, len - 1) > array[len - 1] ? max_in_prefix(array, len - 1) : array[len - 1];
*/

/*@
  predicate unchanged_array{L1, L2}(int* array, integer len) =
    \forall integer i; 0 <= i < len ==> \at(array[i], L1) == \at(array[i], L2);
*/

int foo212(int * positions, int positions_len) {

    int largest = 0;

    /*@
      loop invariant unchanged_array{Pre, Here}(positions, positions_len);
      loop assigns index, largest;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > largest) {
            largest = positions[index];
        }
    }

    return largest;
}
