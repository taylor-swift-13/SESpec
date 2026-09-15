
/*@
predicate divides(integer a, integer b) = \exists integer k; b == a * k;
*/

int foo336(int num) {

		int result = 0;
		
            /*@
          loop invariant c >= 2;
          loop invariant result == 0 || result >= 2;
          loop invariant result <= c;
          loop assigns c, result, num;
            */
            for (int c = 2; c <= num; c++) {
			
            /*@
          loop invariant num > 0 && c >= 2;
          loop invariant result == 0 || result >= 2;
          loop invariant result <= c;
          loop assigns result, num;
            */
            while (num % c == 0) {
				result = c;
				num /= c;
			}
            
		}
            
		return result;
}
