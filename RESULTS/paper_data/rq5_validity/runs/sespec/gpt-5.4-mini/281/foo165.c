
/*@
  logic integer count_divisors_upto(integer num, integer n) =
    n <= 0 ? 0 :
    count_divisors_upto(num, n - 1) + (n <= num && num % n == 0 ? 1 : 0);
*/

/*@
  assigns \nothing;
*/
const char * foo165(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num == \at(num,Pre);
          loop invariant 0 <= result;
          loop invariant 1 <= index;
          loop invariant result == count_divisors_upto(num, index - 1);
          loop invariant result <= index - 1;
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
