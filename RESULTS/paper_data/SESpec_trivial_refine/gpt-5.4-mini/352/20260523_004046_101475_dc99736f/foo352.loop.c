
        /*@
        */
        
int foo352(int number) {

		int result = 0;
		int ret = 0;
		int total = number;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ret >= 0;
          loop invariant result >= 0;
          loop invariant total >= 0 || ret == 0;
          loop invariant total == (number >> ret);
          loop assigns result, ret, total;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ result;
}
