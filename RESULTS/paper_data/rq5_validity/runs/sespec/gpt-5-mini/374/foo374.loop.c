
/*@ 
  logic integer number_of_divisors_up_to(integer n, integer c) =
    c <= 0 ? 0 :
    number_of_divisors_up_to(n, c-1) + ((n % c == 0) ? 1 : 0);
*/

int foo374(int number) {

	int div = 0;
		
	/*@
	  loop invariant 1 <= c;
	  loop invariant number == \at(number,Pre);
	  loop invariant div >= 0;
	  loop invariant (c <= \at(number,Pre)) ==> (div == number_of_divisors_up_to(\at(number,Pre), c-1));
	  loop assigns c, div;
	*/
	for (int c = 1; c <= number; c++) {
		if (number % c == 0) {
			div++;
		}
	}
            
	return div;
}
