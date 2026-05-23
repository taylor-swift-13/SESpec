
/*@
logic boolean divides(integer n, integer d) = (d != 0) && (n % d == 0);
*/

/*@
logic integer divisor_count(integer n, integer k) =
  k <= 0 ? 0 : divisor_count(n, k - 1) + (divides(n, k) ? 1 : 0);
*/
/*@
  requires \true;
  assigns \nothing;
  ensures \result == \null ==> \false;
  ensures \result != \null;
*/
const char * foo280(int number) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result >= 0;
          loop invariant result <= c - 1;
          loop invariant c >= 1;
          loop assigns c, result;
            */
            for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
