
        /*@
        */
        
int foo202(int * ints, int ints_len, int array) {

		int find = 0;
		int min = 0;
		int offset = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= min <= array;
          loop invariant 1 <= offset <= array;
          loop invariant 0 <= find;
          loop assigns find, min, offset;
            */
            while (min < array && offset < array) {
			if (ints[min] == ints[offset]) {
				min++;
				offset++;
				find++;
			} else if (ints[min] > ints[offset]) {
				min++;
			} else {
				offset++;
			}
		}
            

		return find;
}
