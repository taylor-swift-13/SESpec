
/*@
  logic integer max_prefix_pos(int* a, integer hi) =
    hi <= 0 ? 0
            : (let m = max_prefix_pos(a, hi - 1) in (a[hi - 1] > 0 && a[hi - 1] > m ? a[hi - 1] : m));
*/

/*@
  ensures positions == \at(positions,Pre);
  ensures positions_len == \at(positions_len,Pre);
  assigns \nothing;
  ensures \result == max_prefix_pos(positions, positions_len);
*/
int foo307(int * positions, int positions_len) {

		int largest = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count <= positions_len;
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant largest == max_prefix_pos(positions, count);
          loop assigns count, largest;
            */
            for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
            
		return largest;
}
