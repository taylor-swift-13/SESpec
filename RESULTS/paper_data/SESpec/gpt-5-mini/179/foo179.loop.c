
/*@
  predicate unchanged_array{L}(int* a, integer len) =
    \forall integer i; 0 <= i < len ==> a[i] == \at(a[i], L);
*/
        
int foo179(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant count == \at(count,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant unchanged_array{Pre}(array, array_len);
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
