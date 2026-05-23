
/*@
  logic integer count_divisors_up_to(integer n, integer k) =
    (k <= 0) ? 0 :
    count_divisors_up_to(n, k - 1) + ((k > 0 && k <= n && n % k == 0) ? 1 : 0);
*/

int foo373(int number) {

		int div = 0;
        
        /*@
          loop invariant number == \at(number,Pre);
          loop invariant div >= 0;
          loop invariant (index <= \at(number,Pre)) ==> (div >= 0) ;
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
