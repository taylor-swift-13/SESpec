
/*@
  logic integer digit_product_mod10(integer start, integer end) =
    start >= end ? 1 : ((start % 10) * digit_product_mod10(start + 1, end)) % 10;
*/

int foo332(int num, int c) {

		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
			
            /*@
          loop invariant num + 1 <= var;
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
