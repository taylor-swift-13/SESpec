
/*@ logic integer count_divisors_upto(integer number, integer c) =
      (c <= 2) ? 0 : count_divisors_upto(number, c - 1) + ((number % (c - 1) == 0) ? 1 : 0);
*/

int foo316(int number) {

		int result = 0;
		if (number == 1)
			return 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= c;
          loop invariant 0 <= result;
          loop invariant result <= c - 2;
          loop invariant result == count_divisors_upto(number, c);
          loop invariant \forall integer d; 2 <= d < c && number % d == 0 ==> result >= 1;
          loop invariant \exists integer d; 2 <= d < c && number % d == 0 ==> result > 0;
          loop invariant (c <= number / c) ==> (result >= 0);
          loop invariant (!(c <= number / c)) ==> (result >= 0);
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
