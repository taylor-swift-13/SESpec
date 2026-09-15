
/*@
  predicate unchanged_array{L}(int *a, integer len) =
    \forall integer k; 0 <= k < len ==> a[k] == \at(a[k],L);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires \at(count,Pre) != 0;
  requires \at(array_len,Pre) > 0;
  requires \at(array_len,Pre) < 100;
  assigns \nothing;
*/
int foo181(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= r;
          loop invariant top <= \at(count,Pre) - 1;
          loop invariant array_len == \at(array_len,Pre);
          loop invariant count == \at(count,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant unchanged_array{Pre}(array, array_len);
          loop invariant (0 < \at(count,Pre) - 1) ==>
                          ( (top == \at(count,Pre) - 1 && r == 0)
                            || array[r] >= array[top] );
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
