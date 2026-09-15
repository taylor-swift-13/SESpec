
/*@
  logic integer max_in_prefix(int* array, integer len) =
    len <= 0 ? 0 : max_in_prefix(array, len - 1) > array[len - 1] ? max_in_prefix(array, len - 1) : array[len - 1];
*/

/*@
  predicate unchanged_array{L1, L2}(int* array, integer len) =
    \forall integer i; 0 <= i < len ==> \at(array[i], L1) == \at(array[i], L2);
*/

/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns \nothing;
  ensures unchanged_array{Pre, Post}(positions, positions_len);
  ensures \result == max_in_prefix(positions, positions_len);
*/
int foo212(int * positions, int positions_len) {

    int largest = 0;

    /*@
      loop invariant unchanged_array{Pre, Here}(positions, positions_len);
      loop invariant 0 <= index <= positions_len;
      loop invariant largest >= 0;
      loop invariant \forall integer i; 0 <= i < index ==> largest >= positions[i];
      loop invariant largest == max_in_prefix(positions, index);
      loop assigns largest, index;
      loop variant positions_len - index;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > largest) {
            largest = positions[index];
        }
    }

    return largest;
}
