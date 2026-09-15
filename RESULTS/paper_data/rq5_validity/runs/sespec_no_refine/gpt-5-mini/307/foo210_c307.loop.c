
/*@
  logic integer max_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (max_prefix(a, lo, hi - 1) >= a[hi - 1] ? max_prefix(a, lo, hi - 1) : a[hi - 1]);
*/

/*@
  requires \valid_read(positions + (0 .. positions_len-1));
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100;
  ensures 0 <= \result;
  ensures \result == max_prefix(\at(positions,Pre), 0, \at(positions_len,Pre));
*/
int foo210_c307(int * positions, int positions_len) {

		int largest = 0;
		
            
        /*@
          loop invariant 0 <= count <= positions_len;
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer i; 0 <= i < positions_len ==> positions[i] == \at(positions[i],Pre);
          loop assigns count, largest;
        */
            for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
            
		return largest;
}
