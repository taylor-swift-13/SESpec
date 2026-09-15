
/*@ 
  logic integer max_prefix(int* positions, integer lo, integer hi) =
    lo >= hi ? 0 :
    (positions[lo] > max_prefix(positions, lo + 1, hi) ? positions[lo] : max_prefix(positions, lo + 1, hi));
*/

int foo308(int * positions, int positions_len) {

		int result = 0;
		
        /*@
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < \at(positions_len,Pre) ==> positions[k] == \at(positions[k],Pre);
          loop invariant result >= 0;
          loop invariant \forall integer k; 0 <= k < index ==> positions[k] <= result;
          loop invariant (index < \at(positions_len,Pre)) ==> (result >= 0);
          loop invariant (index < \at(positions_len,Pre)) ==> (((result == 0)&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre))) || (result >= 0));
          loop invariant (!(index < \at(positions_len,Pre))) ==> (result >= 0);
          loop assigns index, result;
        */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
            
		return result;
}
