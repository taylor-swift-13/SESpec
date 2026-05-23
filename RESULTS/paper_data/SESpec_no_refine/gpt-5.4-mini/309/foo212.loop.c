
/*@
  logic integer max_prefix_pos(int *positions, integer lo, integer hi) =
    lo >= hi ? 0 :
    (positions[lo] > 0 && positions[lo] > max_prefix_pos(positions, lo + 1, hi)
      ? positions[lo]
      : max_prefix_pos(positions, lo + 1, hi));
*/

int foo212(int * positions, int positions_len) {

		int largest = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre);
          loop assigns index, largest;
            */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
            
		return largest;
}
