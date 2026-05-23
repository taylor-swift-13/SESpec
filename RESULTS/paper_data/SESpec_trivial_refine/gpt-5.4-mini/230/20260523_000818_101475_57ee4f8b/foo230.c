
/*@
*/

/*@
  requires 0 <= pairs_len;
  requires valid_pairs(pairs, pairs_len);
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= (pairs_len * (pairs_len - 1)) / 2;
  ensures \result == 0 <==> \forall integer i, j; 0 <= i < j < pairs_len ==> pairs[i] == pairs[j];
  ensures \result > 0 <==> \exists integer i, j; 0 <= i < j < pairs_len && pairs[i] != pairs[j];
  ensures pairs_len <= 1 ==> \result == 0;
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
