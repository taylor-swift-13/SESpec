
/*@ 
  logic integer max_prefix(int* a, integer hi) =
    hi <= 0 ? 0
            : (max_prefix(a, hi - 1) >= (a[hi - 1] > 0 ? a[hi - 1] : 0) 
               ? max_prefix(a, hi - 1) 
               : (a[hi - 1] > 0 ? a[hi - 1] : 0));
*/

/*@ 
  requires positions_len >= 0;
  requires positions_len == 0 || \valid_read(positions + (0 .. positions_len-1));
  assigns \nothing;
  ensures \result == max_prefix(positions, positions_len);
  ensures positions_len == 0 ==> \result == 0;
  ensures positions_len > 0 ==> \result >= 0;
*/
int foo307(int * positions, int positions_len) {

    int largest = 0;

    /*@
      loop invariant 0 <= count <= positions_len;
      loop invariant largest >= 0;
      loop invariant largest == max_prefix(positions, count);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k], Pre);
      loop invariant count == 0 ==> largest == 0;
      loop invariant count == positions_len ==> largest == max_prefix(positions, positions_len);
      loop assigns count, largest;
    */
    for (int count = 0; count < positions_len; count++) {
        if (positions[count] > 0 && positions[count] > largest) {
            largest = positions[count];
        }
    }

    return largest;
}
