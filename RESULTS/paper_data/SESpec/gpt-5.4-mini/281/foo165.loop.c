
/*@ logic integer count_divisors_upto(int n, integer i) =
      i <= 1 ? 0
             : count_divisors_upto(n, i - 1) + (n % (int)(i - 1) == 0 ? 1 : 0);
*/

const char * foo165(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num == \at(num,Pre);
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
