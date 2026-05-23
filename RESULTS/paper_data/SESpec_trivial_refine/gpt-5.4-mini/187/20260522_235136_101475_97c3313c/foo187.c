
        /*@
        
        */

/*@
  requires 0 <= size <= array_len;
  requires size == 0 || \valid_read(array + (0 .. size-1));
  assigns \nothing;
  ensures size == 0 ==> \result == 0;
  ensures size > 0 ==> \result >= 1;
  ensures size > 0 ==> \result <= size;
  ensures size > 0 ==> (\exists integer m; 0 <= m < size &&
                        \forall integer i; 0 <= i < size ==> array[m] <= array[i] &&
                        \result == (\numof integer j; 0 <= j < size && array[j] == array[m]));
  ensures \result == \null ==> \false;
  ensures \result == \null ==> \result == 0;
  ensures \result == PLACE_HOLDER_RESULT;
*/
int foo187(int size, int * array, int array_len) {

		if (size == 0) {
			return 0;
		}

		int f = array[0];
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= size;
          loop invariant \forall integer i; 0 <= i < c ==> f <= array[i];
          loop invariant \exists integer i; 0 <= i < c && f == array[i];
          loop invariant max == \numof integer i; 0 <= i < c && array[i] == f;
          loop assigns c, f, max;
          loop variant size - c;
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
