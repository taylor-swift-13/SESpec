
/*@
predicate foo181_dummy = \true;
*/

/*@
  requires 0 <= array_len;
  requires 0 < count <= array_len;
  requires \valid_read(array + (0 .. array_len - 1));
  assigns \nothing;
  ensures 1 <= \result <= count;
  ensures count > 0 ==> \result != 0;
  ensures count == 0 ==> \result == 0;
*/
int foo181(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant count <= 0 || (0 <= r <= top && top < count);
          loop assigns r, top;
            */
            while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			if (array[i] > array[r]) {
				r = i;
			} else {
				top = i;
			}
		}
            
		return r + 1;
}
