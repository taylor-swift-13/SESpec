
/*@ 
  logic integer maxpos(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi-1] > 0 ? (maxpos(a, lo, hi-1) >= a[hi-1] ? maxpos(a, lo, hi-1) : a[hi-1])
                            : maxpos(a, lo, hi-1));
*/

/*@ 
  assigns \nothing;
  ensures \result >= 0;
*/
int foo309(int * positions, int positions_len) {

		int largest = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@ 
          loop invariant 0 <= index;
          loop invariant 0 <= largest;
          loop invariant largest == maxpos(positions, 0, index);
          loop invariant \forall integer k; 0 <= k < index ==> positions[k] == \at(positions[k], Pre);
          loop invariant (index < \at(positions_len,Pre)) ==> (largest >= 0);
          loop invariant (index < \at(positions_len,Pre)) ==> (((largest == 0)&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre))) || (largest == maxpos(positions, 0, index)));
          loop invariant (!(index < \at(positions_len,Pre))) ==> ((largest == 0 && (\forall integer k; 0 <= k < positions_len ==> positions[k] <= 0)) || (largest == maxpos(positions, 0, positions_len)));
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
