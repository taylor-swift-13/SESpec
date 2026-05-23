
/*@
  assigns \nothing;
*/
const char * foo282(int num) {

		int result = 0;
		
        /*@
          loop invariant 0 <= result <= c - 1;
          loop invariant num == \at(num,Pre);
          loop assigns c, result;
        */
        for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				result++;
			}
		}
            
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}
