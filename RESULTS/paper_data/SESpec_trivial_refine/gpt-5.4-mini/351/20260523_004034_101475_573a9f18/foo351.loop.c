
/*@
logic integer even_mask(integer n) =
  n <= 0 ? 0 : even_mask(n-1) + (((n-1) % 2 == 0) ? (1 << (n-1)) : 0);
*/

int foo351(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ret >= 0;
          loop invariant total == (number >> ret);
          loop assigns i, ret, total;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ i;
}
