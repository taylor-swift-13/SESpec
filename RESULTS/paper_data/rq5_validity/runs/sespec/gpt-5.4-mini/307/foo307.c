
/*@ 
  requires positions_len >= 0;
  requires \valid_read(positions + (0..positions_len-1));
  assigns \nothing;
  
  ensures \result >= 0;
  ensures positions_len == 0 ==> \result >= 0 ;
  ensures \forall integer k; 0 <= k < positions_len ==> \result >= positions[k];
  ensures \result == 0 ==> (\forall integer k ; 0 <= k < positions_len ==> positions[k] <= 0);
*/
int foo307(int * positions, int positions_len) {

		int largest = 0;
		
        /*@
          loop invariant 0 <= count <= positions_len;
          loop invariant largest >= 0;
          loop invariant positions_len == \at(positions_len,Pre);
          loop invariant positions == \at(positions,Pre);
          loop invariant \forall integer k; 0 <= k < count ==> positions[k] <= largest;
          loop invariant count == positions_len ==> (\forall integer k; 0 <= k < positions_len ==> positions[k] <= largest);
          loop invariant (count < \at(positions_len,Pre)) ==> (\forall integer k; 0 <= k < count ==> positions[k] <= largest);
          loop invariant \forall integer k; 0 <= k < positions_len ==> positions[k] == \at(positions[k],Pre);
          loop assigns count, largest;
        */
        for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
            
		return largest;
}
