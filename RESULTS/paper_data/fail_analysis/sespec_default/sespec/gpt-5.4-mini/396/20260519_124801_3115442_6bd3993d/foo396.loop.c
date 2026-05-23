
/*@
  logic integer pow4(integer x) = x * x * x * x;
  logic integer sum_pow4(integer n) = n <= 0 ? 0 : sum_pow4(n - 1) + pow4(2 * n);
*/

int foo396(int p) {

		int even = 0;
		
        /*@
          loop invariant p == \at(p,Pre);
        */
            for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
            
		return even;
}
