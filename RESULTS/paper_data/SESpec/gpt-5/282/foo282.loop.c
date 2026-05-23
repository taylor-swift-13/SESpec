
/*@
  logic integer cntdiv(integer n, integer lo, integer hi) =
    lo >= hi ? 0
             : cntdiv(n, lo, hi - 1) + (n % (hi - 1) == 0 ? 1 : 0);
*/

const char * foo282(int num) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \at(num,Pre) < 1 ==> c == 1;
          loop invariant \at(num,Pre) >= 1 ==> 1 <= c <= \at(num,Pre) + 1;

          loop invariant num == \at(num,Pre);

          loop invariant result == cntdiv(num, 1, c);
          loop invariant 0 <= result <= c - 1;

          loop invariant result > 0 ==> (\exists integer k; 1 <= k < c && num % k == 0);
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
