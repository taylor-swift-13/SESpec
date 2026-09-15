
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

int foo176(int num) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns j, ret, num;
            */
            for (int j = 2; j <= num; j++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant ret == 0 || ret >= 2;
              loop assigns num, ret;
            */
            while (num % j == 0) {
				ret = j;
				num /= j;
			}
            
		}
            
		return ret;
}
