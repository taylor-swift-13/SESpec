
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

int foo177(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns j, result, num;
            */
            for (int j = 2; j <= num; j++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop assigns result, num;
            */
            while (num % j == 0) {
				result = j;
				num /= j;
			}
            
		}
            
		return result;
}