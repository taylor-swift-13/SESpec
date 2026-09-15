
/*@
  logic integer count_occ{L}(int* array, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_occ(array, lo, hi - 1, v) + (array[hi - 1] == v ? 1 : 0);
*/

int foo45(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (c < \at(size,Pre)) ==> (((max == 1)&&(f == array[0])&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))&&(size == \at(size,Pre))) || (f <= array[0]));
          loop invariant (c < \at(size,Pre)) ==> (((max == 1)&&(f == array[0])&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre))&&(size == \at(size,Pre))) || (max >= 1));
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant \forall integer k; 0 <= k < c ==> array[k] == \at(array[k],Pre);
          loop assigns c, f, max;
            */
            for (int c = 1; c < size; c++) {
			if (f > array[c]) {
				f = array[c];
				max = 1;
			} else if (f == array[c]) {
				max++;
			}
		}
            
		return max;
}
