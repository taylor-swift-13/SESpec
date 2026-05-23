
/*@
  // Number of odd integers in the inclusive range [1..n]
  logic integer odd_count(integer n) =
    n <= 0 ? 0 : (n / 2) + (n % 2);

  // Sum of odd integers in the inclusive range [1..n]
  // For odd n = 2k+1: sum = (k+1)^2; for even n = 2k: sum = k^2
  logic integer sum_odds_upto(integer n) =
    n <= 0 ? 0 :
    ((n % 2) == 1 ? ((n/2 + 1) * (n/2 + 1)) : ((n/2) * (n/2)));
*/

int foo359(int size) {

		int ret = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant size == \at(size,Pre);
          loop assigns c, ret, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
            
		return ret / total;
}
