
        /*@
        predicate is_divisor(integer n, integer d) = d != 0 && n % d == 0;
        */
        
int foo318(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= result;
          loop invariant 2 <= c;
          loop invariant result <= c - 2;
          loop assigns result, c;
            */
            for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
            
		return result;
}
