
        /*@
        true
        */
        
int foo394(int num) {

		int ret = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant true;
          loop invariant 1 <= loop <= num + 1;
          loop invariant ret >= 1;
          loop assigns ret, loop;
            */
            for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
            
		int result = (int) (ret % 100);
		return result;
}
