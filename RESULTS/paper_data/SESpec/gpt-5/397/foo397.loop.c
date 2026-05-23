
/*@
  logic integer pow4(integer x) = x * x * x * x;
*/

/*@
  logic integer sum_pow4(integer n) =
    n <= 0 ? 0 : sum_pow4(n - 1) + pow4(n);
*/
        
int foo397(int p) {

		int even = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant p == \at(p,Pre);

          loop invariant 1 <= c;
          loop invariant (p >= 0) ==> (c <= p + 1);

          loop invariant 0 <= even;
          loop invariant even == 16 * sum_pow4(c - 1);

          loop invariant \true;
          loop invariant (c > p) ==> (even == 16 * sum_pow4(p));

          loop assigns c, even;
            */
            for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
            
		return even;
}
