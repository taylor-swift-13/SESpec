
/*@
logic integer nb_div(integer n, integer b) =
  (b <= 0) ? 0 : nb_div(n, b - 1) + (((n % b) == 0) ? 1 : 0);
*/

int foo374(int number) {

		int div = 0;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant div == nb_div(number, c - 1);
          loop invariant c >= 1;
          loop assigns c, div;
            */
            for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				div++;
			}
		}
            
		return div;
}
