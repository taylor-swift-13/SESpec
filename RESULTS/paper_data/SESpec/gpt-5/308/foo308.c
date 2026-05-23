
/*@ logic integer max_pos(int* a, integer lo, integer hi) =
      lo >= hi ? 0
    : (a[hi - 1] > 0 && a[hi - 1] > max_pos(a, lo, hi - 1)
       ? a[hi - 1]
       : max_pos(a, lo, hi - 1));
*/

/*@
  requires positions_len >= 0;
  requires \valid_read(positions + (0 .. positions_len-1));
  assigns \nothing;
  ensures \result == max_pos(positions, 0, positions_len);
  ensures \result >= 0;
  ensures (\forall integer k; 0 <= k < positions_len ==> positions[k] <= \result || positions[k] <= 0);
  ensures (\exists integer k; 0 <= k < positions_len && positions[k] > 0) ==> \result > 0;
  ensures \forall integer k; 0 <= k < positions_len && positions[k] > 0 ==> positions[k] <= \result;
  ensures \result > 0 ==> (\forall integer k; 0 <= k < positions_len && positions[k] == \result ==> positions[k] > 0);
  ensures \result == max_pos(positions, 0, positions_len);
*/
int foo308(int * positions, int positions_len) {

    int result = 0;

    /*@
      loop invariant 0 <= index <= positions_len;
      loop invariant positions_len >= 0;
      loop invariant \valid_read(positions + (0 .. positions_len-1));
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k], Pre);
      loop invariant result == max_pos(positions, 0, index);
      loop invariant result >= 0;
      loop invariant \forall integer k; 0 <= k < index && positions[k] > 0 ==> positions[k] <= result;
      loop invariant (index >= positions_len) ==> (result == max_pos(positions, 0, positions_len));
      loop assigns index, result;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > result) {
            result = positions[index];
        }
    }

    return result;
}
