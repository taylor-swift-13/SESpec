
/*@
  logic integer max_positive(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] > 0 ? (a[hi - 1] > max_positive(a, lo, hi - 1) ? a[hi - 1] : max_positive(a, lo, hi - 1)) : max_positive(a, lo, hi - 1));
*/

/*@
  requires \valid(positions + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len >= 0;
  assigns \nothing;
  ensures \forall integer i; 0 <= i < positions_len ==> positions[i] <= \result || positions[i] <= 0;
  ensures \forall integer i; 0 <= i < positions_len && positions[i] > 0 ==> \result >= positions[i];
  ensures \result == 0 ==> \forall integer i; 0 <= i < positions_len ==> positions[i] <= 0;
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
