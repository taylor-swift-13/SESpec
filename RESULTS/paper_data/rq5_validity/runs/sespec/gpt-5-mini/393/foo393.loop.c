
/*@ 
  logic integer fact(integer n) = n <= 1 ? 1 : n * fact(n-1);
*/

int foo393(int num) {

		int ret = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant loop >= 1;
          loop invariant (loop <= num + 1) || (num < 1);
          loop invariant ret == fact(loop - 1);
          loop assigns ret, loop;
          loop variant num - loop + 1;
            */
            for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}
            
		int remainder = (int) (ret % 100);
		return remainder;
}
