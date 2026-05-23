
/*@
  logic integer max_pos(int* a, integer lo, integer hi) =
    lo >= hi ? 0 :
    (let m = max_pos(a, lo, hi - 1) in
     (a[hi - 1] > 0 && a[hi - 1] > m) ? a[hi - 1] : m);
*/

int foo308(int * positions, int positions_len) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= positions_len;
          loop invariant result == max_pos(positions, 0, index);
          loop assigns index, result;
            */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
            
		return result;
}
