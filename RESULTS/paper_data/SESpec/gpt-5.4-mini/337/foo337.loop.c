
int foo337(int num) {

		int ret = 0;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant j >= 2;
              loop invariant 0 <= ret <= j;
              loop assigns j, ret, num;
            */
            for (int j = 2; j <= num; j++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant j >= 2;
              loop invariant 0 <= ret <= j;
              loop assigns ret, num;
            */
            while (num % j == 0) {
				ret = j;
				num /= j;
			}
            
		}
            
		return ret;
}
