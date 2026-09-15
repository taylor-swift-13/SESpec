
/*@
  /* no additional logic or predicate definitions are needed */
*/

const char * foo164(int number) {

		int result = 0;
		
        /*@
          loop invariant (c <= \at(number,Pre)) ==> (result >= 0 && result <= c - 1);
          loop invariant (!(c <= \at(number,Pre))) ==> ((result == 0)&&(number == \at(number,Pre)));
          loop invariant number == \at(number,Pre);
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
