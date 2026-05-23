
/*@
logic integer sum4(integer n) = 
  n <= 0 ? 0 : sum4(n - 1) + 16 * n * n * n * n;
*/
        
int foo396(int p) {

		int even = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant even == sum4(c - 1);
          loop invariant c >= 1;
          loop assigns c, even, count;
            */
            for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
            
		return even;
}
