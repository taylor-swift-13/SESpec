
/*@ logic integer count_divisors(integer n, integer k) =
      k <= 0 ? 0 :
      count_divisors(n, k - 1) + ((n % k) == 0 ? 1 : 0);
*/

int foo372(int num) {

		int div = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c;
          loop invariant div == count_divisors(num, c - 1);
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
