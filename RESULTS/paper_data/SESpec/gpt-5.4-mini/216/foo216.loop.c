
/*@
  requires \at(array_len,Pre) > 0 && \at(array_len,Pre) < 100;
*/
int foo216(int * array, int array_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant k == -1 || array[k] == x;
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant y == \at(y,Pre);
          loop assigns k, i, r;
            */
            while (i <= r) {
			int tmp = (i + r) / 2;
			if (array[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (array[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}
            

		return k;
}
