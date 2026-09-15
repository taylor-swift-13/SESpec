
/*@
*/

int foo132(int number) {

		int result = 0;
		if (number == 1)
			return 1;
		
        /*@
          loop invariant result >= 0;
          loop invariant result <= number;
          loop invariant number >= 2;
          loop invariant \true;
        */
        /*@
          loop invariant (!(c <= number / c)) ==> ();
          loop assigns c, result;
        */
        for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
            
		return result;
}
