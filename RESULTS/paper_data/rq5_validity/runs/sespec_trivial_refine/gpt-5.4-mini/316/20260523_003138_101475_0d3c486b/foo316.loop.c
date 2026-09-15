
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

int foo316(int number) {

		int result = 0;
		if (number == 1)
			return 1;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= result && result <= c - 2;
          loop invariant c >= 2;
          loop assigns c, result;
            */
            for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
            
		return result;
}
