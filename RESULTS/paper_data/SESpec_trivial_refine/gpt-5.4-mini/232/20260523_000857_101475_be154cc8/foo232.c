
/*@
predicate dummy_pred = \true;
*/

/*@
*/

        
/*@
  requires pairs_len >= 0;
  requires pairs_len <= 1 || \valid_read(pairs + (0 .. pairs_len - 1));
  assigns \nothing;
  ensures \result == \sum(0, 0);
  ensures pairs_len <= 1 ==> \result == 0;
  ensures 0 <= \result;
  ensures \result == \sum(0, 0) || \result >= 0;
  ensures \result == \null ==> \true;
*/

int foo232(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count;
          loop invariant 0 <= index;
          loop invariant index <= total;
          loop assigns count, index, c;
            */
            for (int index = 0; index < total - 1; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count;
          loop invariant index + 1 <= c <= total;
          loop invariant 0 <= index < total;
          loop assigns c, count;
            */
            for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
            
		}
            
		return count;
}
