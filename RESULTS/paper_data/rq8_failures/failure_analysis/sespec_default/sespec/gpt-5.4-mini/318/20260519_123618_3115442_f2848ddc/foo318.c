
/*@
  assigns \nothing;
  ensures (num == 1) ==> \result == 1;
  ensures (num != 1) ==> \result >= 0;
*/
int foo318(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		
        /*@
          loop invariant 2 <= c;
          loop invariant 0 <= result;
          loop assigns c, result;
        */
            for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
            
		return result;
}
