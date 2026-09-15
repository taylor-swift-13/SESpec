
        /*@
        logic boolean is_odd(integer x) = x % 2 != 0;
        */
        
int foo265(int * ints, int ints_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index;
          loop invariant 0 <= start <= index;
          loop assigns index, start, ret;
            */
            for (int index = 0; index < array; index++) {
			if (ints[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = ints[index];
				}
			}
		}
            
		return ret;
}
