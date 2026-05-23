
/*@
  logic integer max_prefix(int *positions, integer lo, integer hi) =
    lo >= hi ? 0 :
    (max_prefix(positions, lo, hi - 1) > positions[hi - 1] ?
      max_prefix(positions, lo, hi - 1) : positions[hi - 1]);
*/

int foo211(int * positions, int positions_len) {

		int result = 0;
		
            /*@
          loop invariant result >= 0;
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre);
          loop assigns index, result;
            */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
            
		return result;
}
