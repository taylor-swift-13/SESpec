
/*@
  // No extra predicates or logic functions are required.
*/

int foo215(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \valid_read(args + (0 .. args_len - 1));
          loop invariant -1 <= p < args_len || p == -1;
          loop invariant -1 <= r < args_len || args_len <= 0;
          loop invariant 0 <= i <= args_len || args_len <= 0;
          loop invariant r < y ==> y <= args_len;
          loop invariant 0 <= i && r < y ==> i <= r + 1;
          loop invariant 0 <= i && r < y ==> 0 <= i && r < y;
          loop assigns i, r, p;
            */
            while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				p = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}
            

		return p;
}
