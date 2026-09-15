
        

/*@
  assigns \nothing;
  ensures \result == 0 || \result >= 2;
*/
int foo175(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= 2;
          loop invariant result == 0 || result >= 2;
          loop assigns c, result, num;
            */
            for (int c = 2; c <= num; c++) {
			
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant c >= 2;
              loop invariant result == 0 || result >= 2;
              loop assigns num, result;
            */
            while (num % c == 0) {
				result = c;
				num /= c;
			}
            
		}
            
		return result;
}
