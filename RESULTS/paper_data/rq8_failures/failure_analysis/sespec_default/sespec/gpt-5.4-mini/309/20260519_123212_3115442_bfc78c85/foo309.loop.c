
/*@ 
  logic integer max_pos(int *positions, integer lo, integer hi) =
    lo >= hi ? 0
              : (positions[hi - 1] > 0 && positions[hi - 1] > max_pos(positions, lo, hi - 1)
                 ? positions[hi - 1]
                 : max_pos(positions, lo, hi - 1));
*/

int foo309(int * positions, int positions_len) {

		int largest = 0;
		
            /*@
          loop invariant largest >= 0;
          loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= largest || positions[k] <= 0;
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
