
/*@
  // No additional predicates or logic functions are required.
*/

int foo179(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant count == count;
          loop invariant array_len == array_len;
          loop invariant array == array;
          loop invariant 0 <= r <= top <= count - 1;
          loop invariant 0 <= count - 1 ==> 0 <= r && r < count;
          loop assigns r, top;
            */
            while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int end = (r + top) / 2;
			if (array[end] > array[r]) {
				r = end;
			} else {
				top = end;
			}
		}
            
		return r + 1;
}
