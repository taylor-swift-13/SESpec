
/*@
  logic integer count_divisors(integer n, integer k) =
    k <= 0 ? 0 :
    count_divisors(n, k - 1) + ((k > 0 && n % k == 0) ? 1 : 0);
*/

int foo373(int number) {

		int div = 0;
		
        /*@
          loop invariant number == \at(number,Pre);
          loop invariant div >= 0;
          loop assigns index, div;
        */
            for (int index = 1; index <= number; index++) {
			if (number % index == 0) {
				div++;
			}
		}
            
		return div;
}
