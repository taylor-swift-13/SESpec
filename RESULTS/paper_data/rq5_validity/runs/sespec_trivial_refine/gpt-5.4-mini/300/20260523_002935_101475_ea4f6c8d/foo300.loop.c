
/*@
predicate in_bounds(int i, int n) = 0 <= i < n;
*/

int foo300(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		
            /*@
          loop invariant 0 <= found;
          loop invariant top < Array;
          loop assigns found, top;
            */
            while (found < top) {
			int i = found + (top - found) / 2;
			if (array[i] < array[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
            
		return found;
}
