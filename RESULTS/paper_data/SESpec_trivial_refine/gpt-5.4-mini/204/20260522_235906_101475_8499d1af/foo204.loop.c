
/*@
requires ints_len >= array;
requires array >= 1;
*/

int foo204(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= offset && offset <= array && 1 <= max && max <= array && 0 <= find;
          loop invariant \true;
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
