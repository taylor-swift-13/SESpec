
/*@ 
  requires ints_len >= 0;
  requires \valid_read(ints + (0 .. ints_len-1));
  requires 0 <= array && array <= ints_len;
*/

int foo204(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= offset && offset <= max;
          loop invariant (array == 0) ==> (max == 1);
          loop invariant (array > 0) ==> (1 <= max && max <= array);
          loop invariant 0 <= find && find <= max;
          loop invariant array == \at(array,Pre);
          loop invariant ints_len == \at(ints_len,Pre);
          loop invariant ints == \at(ints,Pre);
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
