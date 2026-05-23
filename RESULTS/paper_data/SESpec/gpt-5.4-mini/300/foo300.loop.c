
int foo300(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= found;
          loop invariant top < Array;
          loop invariant Array == \at(Array,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          
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
