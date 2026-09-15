
/*@
  logic integer max_prefix_pos(int *positions, integer lo, integer hi) =
    lo >= hi ? 0 :
    (positions[lo] > 0 && positions[lo] > max_prefix_pos(positions, lo + 1, hi)
      ? positions[lo]
      : max_prefix_pos(positions, lo + 1, hi));
*/

/*@
  requires \valid(&positions[0] + (0..positions_len-1));
  requires \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= 100;
  requires positions_len > 0;
  requires positions_len < 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer i; 0 <= i < positions_len ==> \result >= positions[i] || positions[i] <= 0;
*/
int foo212(int * positions, int positions_len) {

		int largest = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre);
          loop invariant 0 <= index <= positions_len;
          loop invariant largest >= 0;
          loop invariant \forall integer k; 0 <= k < index ==> largest >= positions[k] || positions[k] <= 0;
          loop assigns index, largest;
            */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
            
		return largest;
}
