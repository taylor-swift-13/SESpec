
/*@
  requires \at(count,Pre) > 0;
  requires \valid_read(array + (0 .. count - 1));
*/
int foo179(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= r <= top;
          loop invariant top < \at(count,Pre);
          loop invariant 0 <= r < \at(count,Pre);
          loop invariant count == \at(count,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \valid_read(array + (0 .. \at(count,Pre) - 1));
          loop invariant \forall integer i; 0 <= i < r ==> 0 <= i < \at(count,Pre);
          loop invariant \forall integer i; 0 <= i < top + 1 ==> 0 <= i < \at(count,Pre);
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
