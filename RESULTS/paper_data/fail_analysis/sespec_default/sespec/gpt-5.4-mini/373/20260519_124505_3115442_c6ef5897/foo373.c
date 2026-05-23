
/*@
  assigns \nothing;
  
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
