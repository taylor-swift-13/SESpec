
/*@
  predicate valid_read_range(int *a, integer n) = \valid_read(a + (0 .. n-1));
*/

int foo62_c204(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == array;
          loop invariant ints_len == ints_len;
          loop invariant ints == ints;
          loop invariant 0 <= find <= offset && 0 <= find <= max;
          loop assigns offset, max, find;
            */
            while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}
            

		return find;
}
