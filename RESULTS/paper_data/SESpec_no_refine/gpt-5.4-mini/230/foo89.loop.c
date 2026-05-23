
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
*/

int foo89(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		
            /*@
              loop invariant 0 <= index <= total - 1;
              loop invariant total == pairs_len;
              loop invariant pairs_len == \at(pairs_len,Pre);
              loop invariant pairs == \at(pairs,Pre);
              loop invariant array == \at(array,Pre);
              loop invariant count >= 0;
              loop assigns index, count;
            */
            for (int index = 0; index < total - 1; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 0 <= index <= total - 1;
              loop invariant count >= 0;
              loop assigns index, count;
            */
            for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
            
		}
            
		return count;
}
