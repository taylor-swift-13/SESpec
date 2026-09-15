
/*@
  logic integer max_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (max_prefix(a, lo, hi - 1) > a[hi - 1] ? max_prefix(a, lo, hi - 1) : a[hi - 1]);
*/

/*@
  logic integer max_positive_in_range(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ( max_positive_in_range(a, lo, hi - 1) > (a[hi - 1] > 0 ? a[hi - 1] : 0)
                 ? max_positive_in_range(a, lo, hi - 1)
                 : (a[hi - 1] > 0 ? a[hi - 1] : 0) );
*/
/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre);
  ensures \result == max_positive_in_range(positions, 0, positions_len);
*/
int foo211(int * positions, int positions_len) {

    int result = 0;
        
    /*@
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre);
      loop invariant 0 <= result <= 100;
      loop invariant 0 <= index <= positions_len;
      loop invariant result == max_positive_in_range(positions, 0, index);
      loop assigns index, result;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > result) {
            result = positions[index];
        }
    }
            
    return result;
}
