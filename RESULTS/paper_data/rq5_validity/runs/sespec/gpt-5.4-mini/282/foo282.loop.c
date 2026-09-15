
/*@
  logic integer divcount(integer n, integer lo, integer hi) =
    lo >= hi ? 0
             : divcount(n, lo, hi - 1) + ((hi - 1) != 0 && n % (hi - 1) == 0 ? 1 : 0);
*/

const char * foo282(int num) {

		int result = 0;
		
        /*@
          loop invariant 1 <= c;
          loop invariant num == \at(num,Pre);
          loop invariant 0 <= result;
          loop invariant result == divcount(num, 1, c);
          loop invariant \forall integer k; 1 <= k < c ==> (num % k == 0 ==> result >= 1);
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
