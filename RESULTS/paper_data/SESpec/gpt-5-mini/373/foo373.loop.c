
/*@
  logic integer count_divs(integer n, integer upto) =
    upto <= 0 ? 0 :
    ( (n % upto == 0) ? 1 + count_divs(n, upto-1) : count_divs(n, upto-1) );
*/


int foo373(int number) {

		int div = 0;
		
            
        /*@
          loop invariant (index <= \at(number,Pre)) ==> (div >= 0);
          loop invariant number == \at(number,Pre);
          loop assigns index, div;
        */
            for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
            
		return div;
}
