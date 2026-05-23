
/*@
  logic integer max0(int* a, integer lo, integer hi) =
    lo >= hi ? 0 :
    (max0(a, lo, hi - 1) >= a[hi - 1] ? max0(a, lo, hi - 1) : a[hi - 1]);
*/

/*@ requires positions_len >= 0; */
int foo309(int * positions, int positions_len) {

		int largest = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= positions_len;
          loop invariant 0 <= largest;
          loop invariant largest == max0(positions, 0, index);
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k], Pre);
          loop assigns index, largest;
            */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
            
		return largest;
}
