
/*@
  logic integer count_val(int *array, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_val(array, lo, hi - 1, v) + (array[hi - 1] == v ? 1 : 0);
*/

int foo45(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant size == \at(size,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
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
