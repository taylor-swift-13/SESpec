
/*@
  logic integer max_prefix(int* a, integer n) =
    n <= 0 ? 0 : (max_prefix(a, n - 1) >= a[n - 1] ? max_prefix(a, n - 1) : a[n - 1]);
*/

/*@
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100 ;
  assigns \nothing;
  ensures \result == max_prefix(positions, \at(positions_len,Pre));
  ensures \result == max_prefix(positions, positions_len);
*/
int foo309(int * positions, int positions_len) {

    int largest = 0;
        
    /*@
      loop invariant 0 <= index <= \at(positions_len,Pre);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop invariant \forall integer k; 0 <= k < \at(positions_len,Pre) ==> positions[k] == \at(positions[k], Pre);
      loop invariant largest == max_prefix(positions, index);
      loop invariant (index < \at(positions_len,Pre)) ==> (positions[index] <= largest || positions[index] > largest);
      loop invariant (index < \at(positions_len,Pre)) ==> (((largest == 0)&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre))) || (max_prefix(positions, index) >= 0));
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop invariant \forall integer k; 0 <= k < \at(positions_len,Pre) ==> positions[k] == \at(positions[k], Pre) ;
      loop assigns index, largest;
    */
    for (int index = 0; index < positions_len; index++) {
        if (positions[index] > 0 && positions[index] > largest) {
            largest = positions[index];
        }
    }
        
    return largest;
}
