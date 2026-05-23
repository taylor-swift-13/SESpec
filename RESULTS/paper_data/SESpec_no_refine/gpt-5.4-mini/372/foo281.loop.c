
/*@ logic integer count_divisors(integer n, integer c) =
      c <= 0 ? 0 :
      count_divisors(n, c - 1) + ((c <= n && n % c == 0) ? 1 : 0);
*/

int foo281(int num) {

		int div = 0;
		
        /*@
          loop invariant num == \at(num,Pre);
          loop assigns c, div;
        */
            for (int c = 1; c <= num; c++) {
			if (num % c == 0) {
				div++;
			}
		}
            
		return div;
}
