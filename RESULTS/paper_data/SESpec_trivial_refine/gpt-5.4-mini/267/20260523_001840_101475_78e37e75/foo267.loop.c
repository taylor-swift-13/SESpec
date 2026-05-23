
/*@
logic integer odd_count(int *a, integer n) =
  n <= 0 ? 0 : odd_count(a, n - 1) + ((a[n - 1] % 2) != 0 ? 1 : 0);
*/

int foo267(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index;
          loop invariant index <= array || array < 0;
          loop invariant 0 <= start <= index;
          loop invariant ret == 0 || ret % 2 != 0;
          loop assigns index, start, ret;
            */
            for (int index = 0; index < array; index++) {
			if (args[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = args[index];
				}
			}
		}
            
		return ret;
}
