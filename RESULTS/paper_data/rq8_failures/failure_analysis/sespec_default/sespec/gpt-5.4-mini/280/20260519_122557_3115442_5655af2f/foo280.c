
/*@
  assigns \nothing;
*/
const char * foo280(int number) {

		int result = 0;
		
            /*@
              loop invariant number == \at(number,Pre);
              loop invariant (c <= \at(number,Pre)) ==> (result >= 0);
              loop assigns c, result;
            */
            for (int c = 1; c <= number; c++) {
			if (number % c == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
