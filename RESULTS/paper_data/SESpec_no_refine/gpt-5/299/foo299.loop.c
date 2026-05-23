
/*@
  // No additional predicates or logic functions are required.
*/

int foo299(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array == \at(array, Pre);
          loop invariant data_len == \at(data_len, Pre);
          loop invariant data == \at(data, Pre);
          loop invariant (array <= 0) ==> (i == 0 && top == array - 1);
          loop invariant (array > 0) ==> (0 <= i <= top <= array - 1);
          loop assigns i, top;
            */
            while (i < top) {
			int p = i + (top - i) / 2;
			if (data[p] < data[p + 1]) {
				i = p + 1;
			} else {
				top = p;
			}
		}
            
		return i;
}
