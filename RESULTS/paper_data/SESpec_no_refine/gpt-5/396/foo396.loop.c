
/*@
  logic integer poly4_sum(integer n) =
    (n <= 0) ? 0
             : (n * (n + 1) * (2*n + 1) * (3*n*n + 3*n - 1)) / 30;
*/

int foo396(int p) {

		int even = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns c, even;
            */
            for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
            
		return even;
}
