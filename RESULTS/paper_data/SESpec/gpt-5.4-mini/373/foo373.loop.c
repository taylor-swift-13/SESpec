
/*@
  logic integer count_divisors(integer n, integer i) =
    i <= 0 ? 0 : count_divisors(n, i - 1) + ((n % i == 0) ? 1 : 0);
*/

int foo373(int number) {

		int div = 0;
		
        /*@
          loop invariant 1 <= index;
          loop invariant index >= 1;
          loop invariant 0 <= div;
          loop invariant div <= index - 1;
          loop invariant div == count_divisors(number, index - 1);
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
