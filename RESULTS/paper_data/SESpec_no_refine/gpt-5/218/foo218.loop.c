
/*@
  // No additional predicates or logic functions are required.
*/

int foo218(int * args, int args_len, int Array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == n;
          loop invariant args == args;
          loop invariant args_len == args_len;
          loop invariant Array == Array;
          loop invariant -1 <= hi < n || (hi == -1 && i == 0);
          loop invariant 0 <= i <= n;
          loop invariant i <= hi + 1;
          loop invariant (result == -1) || (0 <= result < n && args[result] == Array);
          loop assigns result, hi, i;
            */
            while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == Array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < Array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
            
		return result;
}
