
/*@
  logic integer max_pos(int *a, integer lo, integer hi) =
    (hi <= lo) ? 0 :
      ((a[hi - 1] > 0 && a[hi - 1] > max_pos(a, lo, hi - 1))
        ? a[hi - 1]
        : max_pos(a, lo, hi - 1));
*/

/*@
  requires positions_len >= 0;
  requires \valid_read(positions + (0 .. positions_len-1));
  assigns \nothing;
  ensures \result == max_pos(positions, 0, positions_len);
*/
int foo309(int * positions, int positions_len) {

		int largest = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= \at(positions_len,Pre);
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < \at(positions_len,Pre) ==> positions[k] == \at(positions[k],Pre);

          loop invariant 0 <= largest;
          loop invariant largest == max_pos(positions, 0, index);

          loop invariant \forall integer k; 0 <= k < index ==> (positions[k] > 0 ==> positions[k] <= largest);
          loop invariant (largest == 0) ==> (\forall integer k; 0 <= k < index ==> positions[k] <= 0);

          loop assigns index, largest;
            */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
            
		return largest;
}
