
/*@
  predicate PLACE_HOLDER_div(integer index, integer number, integer div) =
    div == 0;
*/

int foo282(int number) {

		int div = 0;
		
        /*@
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
