
        /*@
        */
        
int foo372(int num) {

		int div = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 0 <= c <= num + 1;
          loop invariant div == \numof int k; 1 <= k < c && num % k == 0;
          loop assigns c, div;
            */
            for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
            
		return div;
}
