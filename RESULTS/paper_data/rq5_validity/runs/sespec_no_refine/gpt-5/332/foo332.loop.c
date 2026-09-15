
/*@
  logic integer prod_mod10_range(integer a, integer b) =
    (b < a) ? 1 :
    (prod_mod10_range(a, b - 1) * ((b % 10 + 10) % 10)) % 10;
*/

int foo332(int num, int c) {

		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c == \at(c,Pre);
          loop invariant num == \at(num,Pre);
          loop assigns var, result;
            */
            for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
            
			return result % 10;
		}
}
