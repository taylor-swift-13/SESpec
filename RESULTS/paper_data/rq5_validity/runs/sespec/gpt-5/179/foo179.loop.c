
int foo179(int * array, int array_len, int count) {

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
          loop invariant array == \at(array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant count == \at(count,Pre);
          loop invariant (count > 0) ==> (0 <= r && r <= top && top <= \at(count,Pre) - 1);
          loop invariant (count > 0) ==> (1 <= r + 1 && r + 1 <= \at(count,Pre));
          loop invariant (count <= 0) ==> (r == 0 && top == \at(count,Pre) - 1);
          loop invariant (r >= top) ==> ((count > 0) ==> (1 <= r + 1 && r + 1 <= \at(count,Pre)));
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
