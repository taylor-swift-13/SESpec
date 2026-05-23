
/*@
  logic integer max_positive(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] > 0 ? \max(a[hi - 1], max_positive(a, lo, hi - 1)) : max_positive(a, lo, hi - 1));
*/

int foo308(int * positions, int positions_len) {

    int result = 0;

    /*@
      loop invariant 0 <= result;
      loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= result || positions[k] <= 0;
      loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k], Pre);
      loop invariant positions_len == \at(positions_len, Pre);
      loop invariant positions == \at(positions, Pre);
      loop assigns index, result;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > result) {
            result = positions[index];
        }
    }

    return result;
}
