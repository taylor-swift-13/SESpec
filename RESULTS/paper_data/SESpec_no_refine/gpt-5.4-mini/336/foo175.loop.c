
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

int foo175(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (c <= \at(num,Pre)) ==> (((result == 0)&&(num == \at(num,Pre))) || (result <= num));
          loop assigns c, result, num;
            */
            for (int c = 2; c <= num; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns result, num;
            */
            while (num % c == 0) {
				result = c;
				num /= c;
			}
            
		}
            
		return result;
}
