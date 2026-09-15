
/*@
  // no additional predicates or logic functions needed
*/

int foo336(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant result == 0 || (2 <= result && result <= c-1);
              loop invariant num >= 0;
              loop invariant c >= 2 ==> c <= \at(num,Pre);
              loop assigns c, result, num;
            */
            for (int c = 2; c <= num; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant c >= 2;
              loop invariant c <= num;
              loop invariant result == 0 || result == c;
              loop invariant num > 0;
              loop assigns num, result;
            */
            while (num % c == 0) {
				result = c;
				num /= c;
			}
            
		}
            
		return result;
}
