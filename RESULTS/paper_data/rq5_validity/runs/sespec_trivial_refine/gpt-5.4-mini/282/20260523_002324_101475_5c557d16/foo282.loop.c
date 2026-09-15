
/*@
predicate divides(integer n, integer d) = d != 0 && n % d == 0;
*/
        
const char * foo282(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c == 1 || c <= num + 1;
          loop invariant 0 <= result <= c - 1;
          loop invariant result == \numof int i; 1 <= i < c && divides(num, i);
          loop assigns c, result;
            */
            for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
