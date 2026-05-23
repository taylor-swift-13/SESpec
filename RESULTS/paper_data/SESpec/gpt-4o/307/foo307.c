
/*@
  logic integer max_positive(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : \max(a[hi - 1] > 0 ? a[hi - 1] : 0, max_positive(a, lo, hi - 1));
*/

/*@
  requires \valid_read(positions + (0..positions_len-1));
  requires positions_len >= 0;
  ensures \result == max_positive(positions, 0, positions_len);
  ensures \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k], Pre);
  assigns \nothing;
*/
int foo307(int * positions, int positions_len) {

    int largest = 0;

    /*@
      loop invariant 0 <= count <= positions_len;
      loop invariant largest == max_positive(positions, 0, count);
      loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k], Pre);
      loop invariant positions_len == \at(positions_len, Pre);
      loop invariant positions == \at(positions, Pre);
      loop assigns count, largest;
    */
    for (int count = 0; count < positions_len; count++) {
        if (positions[count] > 0 && positions[count] > largest) {
            largest = positions[count];
        }
    }

    return largest;
}
