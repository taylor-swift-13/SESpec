
/*@
  logic integer count_divs(integer n, integer c) =
    c <= 2 ? 0 :
    count_divs(n, c - 1) + (n % (c - 1) == 0 ? 1 : 0);
*/

int foo318(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		
        /*@
          loop invariant 2 <= c;
          loop invariant 0 <= result;
          loop invariant result <= c - 2;
          loop invariant result == count_divs(num, c);
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
