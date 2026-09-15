
/*@
  predicate divides(integer n, integer d) = d != 0 && n % d == 0;
*/

/*@
  requires number >= 1;
*/
int foo316(int number) {

		int result = 0;
		if (number == 1)
			return 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= c;
              loop invariant c <= number + 1;

              loop invariant 0 <= result;
              loop invariant result <= c - 2;

              loop invariant \forall integer d; 2 <= d < c ==> d > 0;
              loop invariant \forall integer d; 2 <= d < c ==> (d <= number / d);

              loop invariant result == 0 ==> \forall integer d; 2 <= d < c ==> !divides(number, d);
              loop invariant \forall integer d; 2 <= d < c ==> (divides(number, d) ==> result >= 1);

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
