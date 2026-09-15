
int foo359(int size) {

		int ret = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant size == \at(size,Pre);
          loop invariant 0 <= total;
          loop assigns c, ret, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
            
		return ret / total;
}
