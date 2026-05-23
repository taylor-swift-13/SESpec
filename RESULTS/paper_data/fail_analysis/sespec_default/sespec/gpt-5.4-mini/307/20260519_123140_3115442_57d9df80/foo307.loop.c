
/*@ 
  logic integer max_prefix(int *positions, integer lo, integer hi) =
    lo >= hi ? 0
             : (positions[hi - 1] > max_prefix(positions, lo, hi - 1) ? positions[hi - 1] : max_prefix(positions, lo, hi - 1));
*/

int foo307(int * positions, int positions_len) {

		int largest = 0;
		
        /*@
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre);
          loop invariant largest >= 0;
          loop assigns count, largest;
            */
            for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
            
		return largest;
}
