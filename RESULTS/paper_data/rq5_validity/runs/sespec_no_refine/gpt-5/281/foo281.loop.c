
/*@
  logic integer count_div(integer n, integer lo, integer hi) =
    lo >= hi ? 0 : count_div(n, lo, hi - 1) + ((n % (hi - 1) == 0) ? 1 : 0);
*/

const char * foo281(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= result <= index - 1;
          loop invariant result == count_div(num, 1, index);
          loop assigns index, result;
            */
            for (int index = 1; index <= num; index++) {
			if (num % index == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
