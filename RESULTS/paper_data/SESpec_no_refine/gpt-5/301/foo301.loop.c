
/*@
  // no additional predicates or logic functions are needed
*/

int foo301(int * data, int data_len, int array) {

		int found = 0, top = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == \at(array,Pre);
          loop invariant data_len == \at(data_len,Pre);
          loop invariant data == \at(data,Pre);
          loop invariant 0 <= found;
          loop invariant found <= top;
          loop invariant top <= array - 1;
          loop invariant \forall integer k; 0 <= k < array ==> data[k] == \at(data[k], Pre);
          loop assigns found, top;
            */
            while (found < top) {
			int i = found + (top - found) / 2;
			if (data[i] < data[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
            
		return found;
}
