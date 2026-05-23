
/*@
*/

int foo399(int value) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result >= 0;
          loop invariant value >= 0;
          loop assigns value, result;
            */
            while (value > 0) {
			value /= 10;
			result++;
		}
            
		return result;
}
