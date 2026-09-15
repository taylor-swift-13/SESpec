
        /*@
        
        */

/*@
  requires positions_len >= 0;
  requires \valid_read(positions + (0 .. positions_len - 1));
  assigns \nothing;
  ensures \result == max_positive(positions, positions_len);
  ensures \result >= 0;
  ensures \forall integer i; 0 <= i < positions_len && positions[i] > 0 ==> positions[i] <= \result;
  ensures \result == 0 <==> \forall integer i; 0 <= i < positions_len ==> positions[i] <= 0;
  ensures \result > 0 ==> \exists integer i; 0 <= i < positions_len && positions[i] == \result && positions[i] > 0;
*/
int foo308(int * positions, int positions_len) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= positions_len;
          loop invariant result >= 0;
          loop invariant \forall integer i; 0 <= i < index ==> positions[i] <= 0 || positions[i] <= result;
          loop assigns index, result;
            */
            for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
            
		return result;
}
