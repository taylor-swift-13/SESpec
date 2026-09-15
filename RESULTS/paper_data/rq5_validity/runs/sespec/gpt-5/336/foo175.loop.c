
int foo175(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= 2;
          loop invariant result == 0 || result <= c;
          loop assigns c, result, num;
            */
            for (int c = 2; c <= num; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant c >= 2;
              loop invariant result == 0 || result <= c;
              loop assigns result, num;
            */
            while (num % c == 0) {
				result = c;
				num /= c;
			}
            
		}
            
		return result;
}
