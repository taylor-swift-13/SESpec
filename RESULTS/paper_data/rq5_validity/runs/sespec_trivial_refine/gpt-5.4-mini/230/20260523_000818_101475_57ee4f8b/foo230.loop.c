
/*@
*/

/*@ 
  requires 0 <= pairs_len;
  requires valid_pairs(pairs, pairs_len);
*/

int foo230(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 0 <= index <= total;
          loop invariant 0 <= count;
          loop assigns count, index, k;
            */
            for (int index = 0; index < total - 1; index++) {
			
            
        
            /*@
          loop invariant 0 <= index <= total - 1;
          loop invariant index + 1 <= k <= total;
          loop invariant 0 <= count;
          loop assigns count, k;
            */
            for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
            
		}
            
		return count;
}
