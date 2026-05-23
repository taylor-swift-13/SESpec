
        /*@
        */
        
int foo203(int * array, int array_len, int Array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= offset <= Array;
          loop invariant 1 <= max <= Array;
          loop invariant 0 <= find <= offset;
          loop invariant find < max;
          loop assigns offset, max, find;
            */
            while (offset < Array && max < Array) {
			if (array[offset] == array[max]) {
				offset++;
				max++;
				find++;
			} else if (array[offset] > array[max]) {
				offset++;
			} else {
				max++;
			}
		}
            

		return find;
}
