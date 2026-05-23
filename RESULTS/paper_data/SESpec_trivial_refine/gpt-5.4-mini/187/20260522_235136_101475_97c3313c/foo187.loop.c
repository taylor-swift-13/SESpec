
        /*@
        
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
