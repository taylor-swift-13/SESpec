
/*@
*/

int foo307(int * positions, int positions_len) {

		int largest = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant positions_len < 0 || (0 <= count && count <= positions_len);
          loop invariant largest >= 0;
          loop invariant \forall integer i; 0 <= i < count ==> positions[i] <= largest;
          loop invariant largest == 0 || (\exists integer i; 0 <= i < count && positions[i] == largest);
          loop assigns count, largest;
            */
            for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
            
		return largest;
}
